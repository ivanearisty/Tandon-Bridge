#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main()
{

	int arr[] = {5, 2, 11, 7, 6, 4};
	int arrSize = 6;

	oddsKeepEvensFlip(arr, arrSize);

	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize)
{

	int left = 0;

	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] % 2 != 0)
		{
			if (i != left)
				swap(arr[i], arr[left]);
			left++;
		}
	}

	int right = arrSize - 1;

	while (left < right)
	{
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
}


/**
 * Implement the function: void oddsKeepEvensFlip(int arr[], int arrSize)
 * This function gets an array of integers arr and its logical size arrSize.
 * When called, it should reorder the elements of arr so that:
 * 1. All the odd numbers come before all the even numbers
 * 2. The odd numbers will keep their original relative order
 * 3. The even numbers will be placed in a reversed order (relative to their original order).
 * For example, if arr = [5, 2, 11, 7, 6, 4],
 * after calling oddsKeepEvensFlip(arr, 6), arr will be: [5, 11, 7, 4, 6, 2]
 *
 * Implementation requirements:
 * 1. Your function should run in linear time. That is, if there are n items in arr, calling
 * oddsKeepEvensFlip(arr, n) will run in 𝜃(𝑛).
 * 2. Write a main() program that tests this function.
 * 3. Note that at the end, the elements should be stored starting at the same base
 * address, as was given in arr.
 */