# include <iostream>
#include <string>
using namespace std;

int main (){

    string name;
    int currYear, gradYear, difference;


    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your graduation year: ";
    cin >> gradYear;
    cout << "Please enter the current year: ";
    cin >> currYear;

    difference = gradYear - currYear;

    if(difference <= 0)
        cout << name << " you are Graduated";
    else if(difference <= 1)
        cout << name << " you are a Senior";
    else if(difference <= 2)
        cout << name << " you are a Junior";
    else if(difference <= 3)
        cout << name << " you are a Sophomore";
    else if(difference <= 4)
        cout << name << " you are a Freshman";
    else
        cout << name << " you are not in college yet";
    return 0;
}