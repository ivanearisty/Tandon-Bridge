# include <iostream>
# include <string>

using namespace std;

int main(){
    long int positiveInteger;
    string romanRepresentation = "";
    cout << "Enter a decimal number:" << endl;
    cin >> positiveInteger;
    
    cout << positiveInteger << " is ";

        while((positiveInteger - 1000) >= 0){
            romanRepresentation += 'M';
            positiveInteger -= 1000;
        }
        while((positiveInteger - 500) >= 0){
            romanRepresentation += 'D';
            positiveInteger -= 500;
        }
        while((positiveInteger - 100) >= 0){
            romanRepresentation += 'C';
            positiveInteger -= 100;
        }
        while((positiveInteger - 50) >= 0){
            romanRepresentation += 'L';
            positiveInteger -= 50;
        }
        while((positiveInteger - 10) >= 0){
            romanRepresentation += 'X';
            positiveInteger -= 10;
        }
        while((positiveInteger - 5) >= 0){
            romanRepresentation += 'V';
            positiveInteger -= 5;
        }
        while((positiveInteger - 1) >= 0){
            romanRepresentation += 'I';
            positiveInteger -= 1;
        }

    cout << romanRepresentation;

    return 0;
}