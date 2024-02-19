#include <iostream>

using namespace std;

//function declarations
int fib(int n);

int main(){
	int n = 0;
	
	cout << "Please enter a positive integer: ";
	cin >> n;

	cout << fib(n);

	return 0;
}

int fib(int n){
	
	int curr = 1;
	int prev = 1;
	int iter = 1;
	int temp = 0;

	while(iter < n) {
		temp = curr;
		curr = curr + prev;
		prev = temp;
		iter++;
	}

	return prev;
}