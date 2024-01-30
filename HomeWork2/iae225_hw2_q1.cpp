#include <iostream>
using namespace std;

int main() {

    int quarters, dimes, nickels, pennies, dollars, cents;
    double total = 0;    

    cout << "Please enter number of coins: " << endl;
    cout << "# of quarters: ";
    cin >> quarters;
    cout << "# of dimes: ";
    cin >> dimes;
    cout << "# of nickels: ";
    cin >> nickels;
    cout << "# of pennies: ";
    cin >> pennies;
    
    if(quarters < 0 || dimes < 0 || nickels < 0 || pennies < 0){
        cout << "Can't have a negative number of anything.";
        return 1;
    }

    total = .25 * quarters + .10 * dimes + .05 * nickels + .01 * pennies;
    dollars = (int) total;
    cents = (int) ((total - dollars) * 100);
    
    cout << "The total is " << dollars << " dollars and " << cents << " cents";

    return 0;
}