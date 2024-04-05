#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> v[3];

void fill(int &threes, int &fours, int &fives);
void addToVector(int curr, int &digits, int &sumOfDigits);

int main (){
	int threes = 0;
	int fours  = 0;
	int fives  = 0;
	fill(threes,fours,fives);

	for(int i = 0 ; i < 3 ; i++){
		int size = v[i].size();
		for(int j = 0 ; j < size ; j++){
			cout << v[i].at(j) << endl;
		}
	}

	cout << "Summation of all the digits in all the 3 digits integers: " << threes << endl;
	cout << "Summation of all the digits in all the 4 digits integers: " << fours << endl;
	cout << "Summation of all the digits in all the 5 digits integers: " << fives << endl;

	return 0;
}

void fill(int &threes, int &fours, int &fives)
{
	cout << "Please enter a sequence of positive integers (each integer will have\nat least 3 decimal digits and at most 5 decimal digits and first\ndigit of each integer won’t be 0), each one in a separate line. End\nyour sequence by typing -1:" << endl;

	int curr = 0; 

	while(true){
		cin >> curr;
		if(curr == -1) break;

		int digits = 0;
		int sumOfDigits = 0;

		addToVector(curr, digits, sumOfDigits);
		if(digits == 3) threes += sumOfDigits;
		if(digits == 4) fours += sumOfDigits;
		if(digits == 5) fives += sumOfDigits;

	}

}

void addToVector(int curr, int &digits, int &sumOfDigits)
{
	int copy = curr;
	while(curr > 0){
		sumOfDigits += curr % 10;
		curr /= 10;
		digits++;
	}
	v[digits - 3].push_back(copy);
}
