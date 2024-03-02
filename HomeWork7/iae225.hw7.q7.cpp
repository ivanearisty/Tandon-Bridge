#include <iostream>
#include <vector>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() 
{

	int arr [] = {3, 1, 3, 0, 6, 4};
	int arrSize = 6;
	int resArrSize;
	int *arrp = findMissing(arr, arrSize, resArrSize);

	for (int i = 0 ; i < resArrSize ; i++){
		cout << " " << arrp[i] << " ";
	}
	cout << " with size: " << resArrSize;

	return 0;
}

/// @brief figures out what numbers are missing from a range [0,n] in an integer array
/// @param arr the original array
/// @param n numbers taken from a range of size n+1 [0,n]
/// @param resArrSize the logical size of the new array that was created
/// @return pointer to a new array that contains all the numbers in the range 0-n not in 
int *findMissing(int arr[], int n, int &resArrSize)
{
	
	bool* flags = new bool [n+1]{false};

	for (int i = 0 ; i < n ; i++) {
        if (arr[i] <= n) 
		{
            flags[arr[i]] = true;
        }
    }
	
	vector<int> v;


    for (int i = 0 ; i < n + 1 ; i++) 
	{
        if (!flags[i]) 
		{
            v.push_back(i);
        }
    }


	int* missing = new int[v.size()];
    
	for (int i = 0 ; i < v.size() ; i++) 
	{
        missing[i] = v[i];
    }

    resArrSize = v.size();
    delete[] flags;

    return missing;
}
