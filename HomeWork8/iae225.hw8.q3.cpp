#include <iostream>
#include <algorithm> 
#include <climits>

using namespace std;


int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main () {

	int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15}; int res1, res2, res3, res4;
	res1 = minInArray1(arr, 10);
	res2 = minInArray2(arr, 0, 9);
	cout << res1 << " " << res2 << endl; //should both be -9
	res3 = minInArray2(arr, 2, 5);
	res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2]) 
	cout << res3 << " " << res4 << endl; //should both be 3
	return 0;
}

/// @brief when called, returns the value of the lowest integer in the array 
/// @param arr an array of integers
/// @param arrSize its logical size
/// @return the minimum value out of all the elements
int minInArray1(int arr[], int arrSize)
{
	if(arrSize == 1)
	{
		return arr[0];
	}
	return min(arr[arrSize-1] , minInArray1(arr,arrSize-1));
}

/// @brief when called, returns the value of the lowest integer in the array 
/// @param arr an array of integers
/// @param low lower bound, inclusive, of the range to search
/// @param high upper bound, inclusive, of the range to search
/// @return the minimum value out of the elements in the range
int minInArray2(int arr[], int low, int high)
{
	if(low > high) return INT_MAX;

	if(low == high) return arr[low];
	
	int mid = low + (high - low)/2;
	
	int left = minInArray2(arr , low , mid);
	int right = minInArray2(arr , mid + 1 , high);

	return min(left, right);
}
