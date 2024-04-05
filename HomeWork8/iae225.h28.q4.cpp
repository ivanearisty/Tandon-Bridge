#include <iostream>
#include <algorithm> 

using namespace std;

int houseRobberSimple(int array [], int logicalSize, int trueSize);
int houseRobberSimpleHelper(int array [], int logicalSize, int trueSize);

int main () {
	int columns[] = {0, 3, 80, 6, 57, 10};
	// int columns[] = {0, 3, 80, 6, 10, 57};
	// int columns[] = {3, 2};
	// int columns[] = {3, 2, 9};
	// int columns[] = {3};
	// int columns[] = {};
    int n = sizeof(columns) / sizeof(columns[0]);
    
    cout << "Minimum total cost: " << houseRobberSimpleHelper(columns, n, n) << endl;
    return 0;
}

//assuming that we cant use memoization
int houseRobberSimple(int array [], int logicalSize, int trueSize)
{
	if(logicalSize == 0) return array[0];
	if(logicalSize == 1) return array[1] + array[0];

	int oneStep = houseRobberSimple(array, logicalSize-1, trueSize);
	int onetwoStep = houseRobberSimple(array, logicalSize-2, trueSize);

	int lowestCost = min(oneStep, onetwoStep);

	return lowestCost + array[logicalSize];
	
}

int houseRobberSimpleHelper(int array[], int logicalSize, int trueSize)
{
	if(trueSize == 0) return 0;
	if(trueSize == 1) return array[0];
	if(trueSize == 2) return array[0] + array[1];
	return houseRobberSimple(array, logicalSize - 1, trueSize);
}
