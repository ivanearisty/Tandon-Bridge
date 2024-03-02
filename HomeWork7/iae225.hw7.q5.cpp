#include <iostream>

using namespace std;

int *getPosNums1(int *arr, int arrSize, int &outPosArrSize);
int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr);
void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize);
void getPosNums4(int *arr, int arrSize, int **outPosArrPtr, int *outPosArrSizePtr);
int countPositives(int *arr, int arrSize);

int main()
{
	int arr[] = {3, -1, -3, 0, 6, 4};
	// int arr[] = {};
	// int arr[] = {1, 2, 3, 4, 5};
	// int arr[] = {-1, -2, -3, -4, -5};
	// int arr[] = {-2, 3, -1, 5, -6, 7, 9, -11};
	// int arr[] = {42};
	// int arr[] = {-42};

	int arrSize = sizeof(arr) / sizeof(arr[0]);

	// Test getPosNums1
	int outPosArrSize1;
	int *posArr1 = getPosNums1(arr, arrSize, outPosArrSize1);
	cout << "Positive numbers (Version 1): ";
	for (int i = 0; i < outPosArrSize1; i++)
	{
		cout << posArr1[i] << " ";
	}
	cout << "\n";
	delete[] posArr1;

	// Test getPosNums2
	int outPosArrSize2;
	int *posArr2 = getPosNums2(arr, arrSize, &outPosArrSize2);
	cout << "Positive numbers (Version 2): ";
	for (int i = 0; i < outPosArrSize2; i++)
	{
		cout << posArr2[i] << " ";
	}
	cout << "\n";
	delete[] posArr2;

	// Test getPosNums3
	int *posArr3;
	int outPosArrSize3;
	getPosNums3(arr, arrSize, posArr3, outPosArrSize3);
	cout << "Positive numbers (Version 3): ";
	for (int i = 0; i < outPosArrSize3; i++)
	{
		cout << posArr3[i] << " ";
	}
	cout << "\n";
	delete[] posArr3;

	// Test getPosNums4
	int *posArr4;
	int outPosArrSize4;
	getPosNums4(arr, arrSize, &posArr4, &outPosArrSize4);
	cout << "Positive numbers (Version 4): ";
	for (int i = 0; i < outPosArrSize4; i++)
	{
		cout << posArr4[i] << " ";
	}
	cout << "\n";
	delete[] posArr4;

	return 0;
}

/// @brief When called, creates new array containing only the positive numbers from arr.
/// @param arr original array
/// @param arrSize original array size
/// @param outPosArrSize new array size
/// @return the base address of the array (containing the positive numbers)
int *getPosNums1(int *arr, int arrSize, int &outPosArrSize)
{

	outPosArrSize = countPositives(arr, arrSize);

	int *posArr = new int[outPosArrSize];

	int j = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		if (arr[i] > 0)
		{
			posArr[j++] = arr[i];
		}
	}

	return posArr;
}

/// @brief When called, creates new array containing only the positive numbers from arr.
/// @param arr original array
/// @param arrSize original array size
/// @param outPosArrSize pointer to the array size of ouput array
/// @return the base address of the array (containing the positive numbers)
int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr)
{

	*outPosArrSizePtr = countPositives(arr, arrSize);

	int *posArr = new int[*outPosArrSizePtr];

	int j = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		if (arr[i] > 0)
		{
			posArr[j++] = arr[i];
		}
	}

	return posArr;
}

/// @brief When called, creates new array containing only the positive numbers from arr.
/// @param arr original array
/// @param arrSize original array size
/// @param outPosArr pointer to the base address of the array
/// @param outPosArrSize new array size
void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize)
{

	outPosArrSize = countPositives(arr, arrSize);

	outPosArr = new int[outPosArrSize];

	int j = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		if (arr[i] > 0)
		{
			outPosArr[j++] = arr[i];
		}
	}
}

/// @brief When called, creates new array containing only the positive numbers from arr.
/// @param arr original array
/// @param arrSize original array size
/// @param outPosArrPtr double pointer used to modify the address that the caller's pointer variable points to.
/// 					allows the function to allocate memory and make the caller's pointer point to this new array.
/// @param outPosArrSizePtr pointer to an integer variable that holds the new array size
void getPosNums4(int *arr, int arrSize, int **outPosArrPtr, int *outPosArrSizePtr)
{

	*outPosArrSizePtr = countPositives(arr, arrSize);

	*outPosArrPtr = new int[*outPosArrSizePtr];

	int j = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		if (arr[i] > 0)
		{
			(*outPosArrPtr)[j++] = arr[i];
		}
	}
}

/// @brief When called, returns the number of positive integers in arr
/// @param arr original array
/// @param arrSize original array size
/// @return number of positive integers in arr
int countPositives(int *arr, int arrSize)
{
	int positives = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		if (arr[i] > 0)
		{
			positives++;
		}
	}
	return positives;
}
