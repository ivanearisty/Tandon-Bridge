#include <iostream>
using namespace std;

int main() {
    
    long minutes = 0; 
    long temp;
    cout << "Please enter the number of days John has worked: ";
    cin >> temp;
    minutes += temp * 1440;

    cout << "Please enter the number of hours John has worked: ";
    cin >> temp;
    minutes += temp * 60;

    cout << "Please enter the number of minutes John has worked: ";
    cin >> temp;
    minutes += temp;

    cout << "Please enter the number of days Bill has worked: ";
    cin >> temp;
    minutes += temp * 1440;

    cout << "Please enter the number of hours Bill has worked: ";
    cin >> temp;
    minutes += temp * 60;

    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> temp;
    minutes += temp;

    int days = minutes / 1440;
    minutes = minutes % 1440;
    int hours = minutes / 60;
    minutes = minutes % 60;

    cout << "The total time both of them worked together is: " << days << " days, " << hours << " hours and " << minutes << " minutes";
    return 0;
}
