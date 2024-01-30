# include <iostream>
# include <vector>
using namespace std;

/*Write a program that reads a positive integer n from the user and prints out a nxn
multiplication table. The columns should be spaced by a tab.*/

int main (){

	int n = 0;
	cout << "Please enter a positive integer: ";
	cin >> n;

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cout << i * j << "\t";
		}
		cout << endl;
	}

    return 0;
}