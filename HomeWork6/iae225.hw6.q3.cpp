#include <iostream>

using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int &arrSize);
void splitParity(int arr[], int arrSize);
void swap(int &a, int &b);
void printArray(int arr[], int arrSize);

int main()
{
	int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {3,12,5,20,4,5,9,0};
    int arr2Size = 8;
    int arr3[10] = {3, 6, 0, 1, 12};
    int arr3Size = 5;

	reverseArray(arr1, arr1Size);
	printArray(arr1, arr1Size);
	removeOdd(arr2, arr2Size);
	printArray(arr2, arr2Size);
	splitParity(arr3, arr3Size);
	printArray(arr3, arr3Size);

	return 0;
}

/// @brief When called, reorders the elements of the array to appear in reverse order.
/// @param arr an array of integers
/// @param arrSize the size of the array
void reverseArray(int arr[], int arrSize)
{

	int left = 0;
	int right = arrSize - 1;

	while (left < right)
	{

		swap(arr[left], arr[right]);

		left++;
		right--;
	}
}

/// @brief alters arr so that the only numbers in it at the end are the even ones, which should remain
/// in their original relative order.
/// @param arr an array of integers
/// @param arrSize its size
void removeOdd(int arr[], int &arrSize)
{
	const int initial_size = arrSize;
	int right = 0;
	int left = 0;

	while (right < initial_size)
	{
		// even
		if (arr[right] % 2 == 0)
		{
			swap(arr[left], arr[right]);
			left++;
		}
		else
		{ // odd
			arrSize--;
			arr[right] = 0;
		}
		right++;
	}
}

/// @brief changes the order of numbers in arr so that all the odd numbers will appear first, and all
/// the even numbers will appear last. Note that the inner order of the odd numbers and the
/// inner order of the even numbers don’t matter.
/// @param arr an array of integers
/// @param arrSize its size
void splitParity(int arr[], int arrSize)
{

	int left = 0;
	int right = arrSize - 1;

	while (left < right)
	{

		if (arr[left] % 2 == 1)
		{
			left++;
		}
		else
		{
			swap(arr[right], arr[left]);
			right--;
		}
	}
}

void printArray(int arr[], int arrSize)
{
	int i;
	for (i = 0; i < arrSize; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void swap(int &a, int &b)
{
	int temp = b;
	b = a;
	a = temp;
}

/*
In all three functions, you are not allowed to use an auxiliary array (a temporary local array).
Pay attention to the running time of your functions. For each one of the functions above, an
efficient implementation would run in a linear time (that is Θ(𝑎𝑟𝑟𝑆𝑖𝑧𝑒)).
*/