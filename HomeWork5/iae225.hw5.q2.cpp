#include <iostream>

using namespace std;

//function declarations

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);
void print(int m, char symbol);

/*Your program should interact with the user to read the number of triangles in the tree and the character filling the tree.*/

int main(){

	int triangles; 
	char character;

	cout << "How many triangles?" << endl;
	cin >> triangles;
	cout << "What character?" << endl;
	cin >> character;

	printPineTree(triangles, character);

	return 0;
}

void printShiftedTriangle(int n, int m, char symbol){
	m = m + n - 1;
	for(int i = 0 ; i < n ; i++){

		print(m-i, ' ');

		cout << symbol;

		print(i*2, symbol);

		cout << endl;
	}

}

void printPineTree(int n, char symbol){
	
	if(n <= 0) return;

	for(int i = 0 ; i < n ; i++){
		printShiftedTriangle(i+2, n-i-1, symbol);
	}
}

void print(int m, char symbol){
	for(int i = 0 ; i < m ; i++){
		cout << symbol;
	}
}