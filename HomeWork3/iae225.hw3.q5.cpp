# include <iostream>
#include <cmath>
using namespace std;

int main (){
    
    const double poundsToKilos = 0.453592;
    const double inchesToMeters = 0.0254;
    double BMI;
    int weightInPounds, heightInInches;

    cout << "Please enter your weight (In Pounds, Rounded to the Nearest Pound)" << endl;
    cin >> weightInPounds;
    cout << "Please enter your height (In Inches, Rounded to the Nearest Inch)" << endl;
    cin >> heightInInches;

    BMI = (weightInPounds * poundsToKilos) / pow((heightInInches * inchesToMeters), 2);

    if(BMI < 18.5)
        cout << "The status is Underweight";
    else if(BMI < 25)
        cout << "The status is Normal";
    else if(BMI < 30)
        cout << "The status is Overweight";
    else
        cout << "The status is Obese";

    return 0;
}