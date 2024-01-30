#include <iostream>
using namespace std;

int main() {
    int dollars, cents, totalCents;
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;

    cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
    cin >> dollars >> cents;

    totalCents = dollars * 100 + cents;

    quarters = totalCents / 25;
    totalCents = totalCents % 25;

    dimes = totalCents / 10;
    totalCents = totalCents % 10;

    nickels = totalCents / 5;
    totalCents = totalCents % 5;

    pennies = totalCents;

    cout << dollars << " dollars and " << cents << " cents are: " << endl;
    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies" << endl;

    return 0;
}
