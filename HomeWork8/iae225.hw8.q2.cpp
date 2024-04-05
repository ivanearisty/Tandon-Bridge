#include <iostream>
#include <cmath>

using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
	// int *array = new int[4]{ 2, -1, 3, 10 };
	int *array = new int[1]{ 2 };
	cout << sumOfSquares(array, 2) << endl;

	int *array1 = new int[4]{ 2, -1, 3, 10 };
	int *array2 = new int[4]{ -1, 2, 3, 10 };

	cout << isSorted(array1, 4) << endl;
	cout << isSorted(array2, 4) << endl;

	return 0;
}

/// @brief When called,it returns the sum of the squares of each of the values in arr.
/// @param arr array of integers
/// @param arrSize the logical size
/// @return the sum of squares of the array
int sumOfSquares(int arr[], int arrSize)
{
	if(arrSize == 0){
		return 0;
	}
	return sumOfSquares(arr, arrSize - 1) + arr[arrSize-1] * arr[arrSize-1];
}

/// @brief When called, should return true if the elements in arr are sorted in an ascending order, or false if they are not.
/// @param arr an array
/// @param arrSize the logical size
/// @return boolean saying if the array is sorted in ascending order
bool isSorted(int arr[], int arrSize)
{
	if(arrSize <= 1){
		return true;
	}
	return arr[arrSize-2] <= arr[arrSize-1] && isSorted(arr, arrSize - 1);
}