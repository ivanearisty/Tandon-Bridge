#include <iostream>
#include <string>
using namespace std;

int main(){
    int number;
    string binaryRepresentation = "";

    cout << "Enter decimal number: ";
    cin >> number;
    cout << "The binary representation of " << number;
    if(number < 0){
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    if(number == 0){
        binaryRepresentation = "0";
    }

    while(number > 0){
        binaryRepresentation = (number % 2 == 0 ? "0" : "1") + binaryRepresentation;
        number /= 2;
    }

    cout << " is " << binaryRepresentation << endl;

    return 0;
}
