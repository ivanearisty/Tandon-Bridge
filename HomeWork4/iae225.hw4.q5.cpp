/*
Write a program that asks the user to input a positive integer n, and prints a textual image of an
hourglass made of 2n lines with asterisks.
*/

# include <iostream>
using namespace std;

int main(){

    int n = 0;

    cout << "How many lines do you want to print? ";
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        // spaces
        for(int j = n - i ; j < n ; j++) cout << " ";
        // asteriscks
        for(int k = i + 1; k < n ; k++) cout << "**";
        cout << "*" << endl;
    }

    for(int i = n - 1; i >= 0 ; i--){
        // spaces
        for(int j = n - i ; j < n ; j++) cout << " ";
        // asteriscks
        for(int k = i + 1; k < n ; k++) cout << "**";
        cout << "*" << endl;
    }



    return 0;
}