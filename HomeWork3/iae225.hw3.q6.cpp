#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

enum DayOfWeek {
    Mo, Tu, We, Th, Fr, Sa, Su
};

DayOfWeek getDayOfWeek(const string& dayShortened) {
    if (dayShortened == "Mo") return Mo;
    if (dayShortened == "Tu") return Tu;
    if (dayShortened == "We") return We;
    if (dayShortened == "Th") return Th;
    if (dayShortened == "Fr") return Fr;
    if (dayShortened == "Sa") return Sa;
    if (dayShortened == "Su") return Su;
    throw invalid_argument("Invalid day of the week.");
}

int main() {
    const double rateSaturdayAndSunday = .15;
    const double rateOffPeakWeekdayHours = .25;
    const double ratePeakWeekdayHours = .40;
    double bill;
    int hours, minutes, lengthOfCall;
    char c;
    bool isPeak;
    string dayShortened;

    cout << "Please input the time the call started (HH:MM): ";
    cin >> hours >> c >> minutes;
    cout << "Please input the day of week: (Mo	Tu	We	Th	Fr	Sa	Su)";
    cin >> dayShortened;
    cout << "Please input the length of the call in minutes: ";
    cin >> lengthOfCall;

    isPeak = (hours >= 8 && ((hours < 18) || (hours == 18 && minutes == 0))) ? true : false;

    DayOfWeek day = getDayOfWeek(dayShortened);

    switch(day) {
        case Sa:
        case Su:
            bill = lengthOfCall * rateSaturdayAndSunday;
            break;

        default:
            if(isPeak) 
                bill = lengthOfCall * ratePeakWeekdayHours;
            else
                bill = lengthOfCall * rateOffPeakWeekdayHours;
            break;
    }


    cout << "The cost of the call is: " << bill;

    return 0;
}
