/*
Implementation	requirements:	
1. Use	a	switch statement.
2. You	are	not	allowed	to	include	and	use	the	math	librar

Define	the	following	constants:
const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;
Write	a	program	that	asks	the	user	to	enter	a	Real	number,	then	it	asks	the	user	to	enter	the
method	by	which	they	want	to	round	that	number	(floor,	ceiling	or	to	the	nearest	integer).	
The	program	will	then	print	the	rounded	result.

*/

# include <iostream>
using namespace std;

int main (){

    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;
    int method, roundedNumber;
    double userInputNumber;

    cout << "Please enter a rational number in decimal form:" << endl;
    cin >> userInputNumber;
    cout << "Choose your rounding method: \n 1. Floor Round \n 2. Ceiling Round \n 3. Round to nearest whole number" << endl;
    cin >> method;

    switch(method){

        case 1:
            roundedNumber = (int) userInputNumber;
            break;
        
        case 2:
            roundedNumber = (int) userInputNumber + 1;
            break;
        
        default:
            roundedNumber = (int) userInputNumber;
            if(userInputNumber - roundedNumber >= .5) roundedNumber += 1;
            break;
    }

    cout << "Here is your rounded number: " << roundedNumber;

    return 0;
}