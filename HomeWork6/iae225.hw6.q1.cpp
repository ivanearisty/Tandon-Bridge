#include <iostream>
#include <climits>

using namespace std;

int minInArray(int arr[], int arrSize);
void fill_up_twenty(int arr[], int arrSize);
void printOccurences(int arr[], int arrSize, int number);
const int ARR_SIZE = 20;

int main (){

	int arr [ARR_SIZE];
	int min = 0;

	fill_up_twenty(arr, ARR_SIZE);
	min = minInArray(arr, ARR_SIZE);

	// for (int i = ARR_SIZE - 1; i >= 0; i--) cout << arr[i] << endl;

	cout << "The minimum value is " << min << ", and it is located in the following indices: "; 
	
	printOccurences(arr, ARR_SIZE, min);

	return 0;
}

int minInArray(int arr[], int arrSize){
	int min = INT_MAX;
	for(int i = 0 ; i < arrSize ; i++) min = min < arr[i] ? min : arr[i] ;
	return min;
}

void fill_up_twenty(int arr[], int arrSize){
	cout << "Please enter 20 integers separated by a space" << endl;
	int count = 0;
	int num;
	do {
   		cin >> num;
		arr[count++] = num;
	} while (count < arrSize);
}

void printOccurences(int arr[], int arrSize, int number){
	for(int i = 0 ; i < arrSize ; i++) if(arr[i] == number) cout << i << " ";
}