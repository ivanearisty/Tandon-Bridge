# include <iostream>
using namespace std;

int main(){

    double firstItemPrice, secondItemPrice, taxRate, totalPrice;
    char userInputCardHolder = 'a';    
    bool discountApplies;

    cout << "Enter Price of First Item: ";
    cin >> firstItemPrice;
    cout << "Enter Price of Second Item: ";
    cin >> secondItemPrice;
    
    while (userInputCardHolder != 'y' && userInputCardHolder != 'Y' && userInputCardHolder != 'n' && userInputCardHolder != 'N') {
        cout << "Does customer have a club card? (Y/N) ";
        cin >> userInputCardHolder;
    }

    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;
    taxRate /= 100;
    
    if(userInputCardHolder == 'y' || userInputCardHolder == 'Y'){
        discountApplies = true;
    }else{
        discountApplies = false;
    }

    cout << "Base Price: " << firstItemPrice + secondItemPrice << endl;
    totalPrice = std::min(firstItemPrice, secondItemPrice)/2 + std::max(firstItemPrice, secondItemPrice);
    if(discountApplies) totalPrice *= 0.9;
    cout << "Price After Discounts: " << totalPrice << endl;
    if(taxRate < 0){
        cout << "Error, tax rate is negative.";
        return 0;
    }
    cout << "Total Price: " << totalPrice * (1 + taxRate) << endl;

    return 0;
}
