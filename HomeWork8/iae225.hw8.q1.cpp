#include <iostream>

using namespace std;

void printTriangle(int n);
void printTriangleLine(int n);
void printOppositeTriangles(int n);
void printRuler(int n);
void printMarks(int n);

int main (){
	printTriangle(4);
	cout << endl;
	printOppositeTriangles(5);
	cout << endl;
	printRuler(4);
	return 0;
}

/// @brief This function is given a positive integer n, and prints a textual image of a right triangle (aligned to the left) made of n lines with asterisks.
/// @param n a positive integer
void printTriangle(int n)
{
	if(n == 1)
	{
		printTriangleLine(n);
		return;
	}
	
	printTriangle(n - 1);
	printTriangleLine(n);
}

/// @brief Helper function for printing a triangle that takes in the amount of astericks n to be printed
/// @param n the amount of asteriscks to be printed
void printTriangleLine(int n)
{
	if (n == 0) { 
        cout << endl;
        return;
    }
    cout << "*";
    printTriangleLine(n - 1);
}

void printOppositeTriangles(int n)
{
	printTriangleLine(n);
	if(n == 1)
	{
		printTriangleLine(n);
		return;
	}
	printOppositeTriangles(n-1);
	printTriangleLine(n);
}

void printMarks(int n) 
{
    for (int i = 0; i < n; i++) 
	{
        cout << "-";
    }
    cout << endl;
}

void printRuler(int n) 
{
    if (n < 1) 
	{
        return; 
    }
    printRuler(n - 1);
    printMarks(n);
    printRuler(n - 1);

}