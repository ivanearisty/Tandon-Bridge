# include <iostream>
# include <cmath>
using namespace std;

int v1();
int v2();

int main(){
    int method = 0;
    
    do{
        cout << "Press 1 for read length, any other for other method, but 0 to exit: ";
        cin >> method;
        if(method == 1){
            v1();
        }else if(method != 0){
            v2();
        }
    }while(method != 0);

    return 0;
}

int v1(){
    int sequenceLength = 0;
    double integers = 1.0;
    int temp = 0;
    double geometricMean = 1.0;

    cout << "Please enter the length of the sequence: ";
    cin >> sequenceLength;

    if(sequenceLength <= 0){
        cout << "Error, 0 or less elements";
        return 1;
    }

    cout << "Please enter the sequence: " << endl;
    for(int i = 0 ; i < sequenceLength ; i++){
        cin >> temp;
        integers *= temp;
    }

    geometricMean = pow(integers, 1/ (double) sequenceLength);

    cout << "The geometric sequence is: " << geometricMean << endl;

    return 0;
}

int v2(){
    int sequenceLength = 0;
    double integers = 1.0;
    int temp = 0;    
    double geometricMean = 1.0;

    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << endl;

    while(true){
        cin >> temp;
        if(temp == -1) break;
        integers *= temp;
        sequenceLength++;
    }

    geometricMean = pow(integers, 1 / (double) sequenceLength);

    cout << "The geometric sequence is: " << geometricMean << endl;

    return 0;
}