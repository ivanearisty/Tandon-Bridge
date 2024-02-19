#include <iostream>

using namespace std;

int printMonthCalendar(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main() {

	int year;
	int startingDay;

	cout << "What year do you want to print?" << endl;
	cin >> year;
	cout << "What is the starting day?" << endl;
	cin >> startingDay;

	printYearCalender(year, startingDay);

    return 0;
}

bool isLeapYear(int year){
	return ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) ? true : false;
}

int printMonthCalendar(int numOfDays, int startingDay) {
    
	if (startingDay <= 0 || startingDay > 7) {
        cout << "Error: Invalid starting day. Defaulting to 1" << endl;
        startingDay = 1;
    }

    if (numOfDays < 1 || numOfDays > 31) {
        cout << "Error: Invalid number of days. Defaulting to 31" << endl;
        numOfDays = 31;
    }

    // print Mon Tue Wed Thu Fri Sat Sun Header
    cout << "Mon\tTue\tWed\tThu\tFri\tSat\tSun" << endl;

    for (int skips = 1; skips < startingDay; skips++) {
        cout << "\t";
    }

    // print the days
    for (int currDay = 1; currDay <= numOfDays; currDay++) {
		if ((currDay + startingDay - 2) % 7 == 0 && currDay != 1) {
			cout << endl;
		}
		cout << currDay << "\t";
	}

    cout << endl << endl;

    return (numOfDays + startingDay - 1) % 7 + 1;
}

void printYearCalender(int year, int startingDay){

	if(year < 0){
		cout << "Error: Year cannot be negative.";
		return;
	}

    for (int month = 1; month <= 12; month++) {
        
		switch (month) {
            case 1: cout << "January"; break;
            case 2: cout << "February"; break;
            case 3: cout << "March"; break;
            case 4: cout << "April"; break;
            case 5: cout << "May"; break;
            case 6: cout << "June"; break;
            case 7: cout << "July"; break;
            case 8: cout << "August"; break;
            case 9: cout << "September"; break;
            case 10: cout << "October"; break;
            case 11: cout << "November"; break;
            case 12: cout << "December"; break;
        }

        cout << " " << year << endl;

        int daysInMonth = 31;
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        } else if (month == 2) {
            daysInMonth = isLeapYear(year) ? 29 : 28;
        }

        startingDay = printMonthCalendar(daysInMonth, startingDay);

    }
	return;
}