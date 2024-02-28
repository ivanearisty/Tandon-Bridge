#include <iostream>
#include <cstdlib> 
#include <iostream> 
#include <time.h> 
#include <string>

using namespace std;

int generateRandomNumber(int options);
void fillRandom(int arr[], int arrSize, int options);
void clear(int arr[], int arrSize);
void printPIN();
void printOptions(int arr[], int arrSize);
bool isValid(string userInput, int arr[], int arrSize, const string pin, const int pinSize);

int main(){

	const string pin = "12345";
	const int PIN_SIZE = 5;
	const int OPTIONS = 3;
	const int ARR_SIZE = 10;
	int arr[ARR_SIZE];
	srand(time(0));

	fillRandom(arr, ARR_SIZE, OPTIONS);

	string userInput;

	cout << "Please enter your PIN according to the following mapping:" << endl;
	printPIN();
	printOptions(arr, ARR_SIZE);
	getline(cin, userInput);

	if(isValid(userInput, arr, ARR_SIZE, pin, PIN_SIZE)){
		cout << "Your PIN is correct" << endl;
	}else{
		cout << "Your PIN is not correct" << endl;
	}

	clear(arr, ARR_SIZE);

	return 0;
}

int generateRandomNumber(int options)
{
	return (rand() % options) + 1;
}

void fillRandom(int arr[], int arrSize, int options)
{
	for(int i = 0 ; i < arrSize ; i++){
		arr[i] = generateRandomNumber(options);
	}
}

void clear(int arr[], int arrSize)
{
	for(int i = 0 ; i < arrSize ; i++){
		arr[i] = 0;
	}
}

void printPIN()
{
	cout << "PIN:\t0 1 2 3 4 5 6 7 8 9" << endl;
}

void printOptions(int arr[], int arrSize)
{
	cout << "NUM:\t";
	for(int i = 0 ; i < arrSize ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool isValid(string userInput, int arr[], int arrSize, const string pin, const int pinSize)
{
	if(userInput.length() != pinSize) return false;

	for(int i = 0 ; i < pinSize ; i++){
		if((userInput.at(i) - '0') != arr[(pin.at(i) - '0')]) return false; 
	}

	return true;
}
