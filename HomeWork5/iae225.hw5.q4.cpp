#include <iostream>
#include <cmath>

using namespace std;

void printDivisors(int num) {
    
	if (num <= 0) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return;
    }

    int limit = sqrt(num); // O(sqrt(num))
	
	//1
    for (int i = 1; i <= limit; i++) {
        if (num % i == 0) {
            cout << i << " ";
        }
    }
	
	//2
    for (int i = limit; i >= 1; i--) {
        if (num % i == 0 && i != num / i) {
            cout << num / i << " ";
        }
    }

	//O(2sqrt(num)) -> O(sqrt(num))

    cout << endl;
}

int main() {
    int num;
	
	cout << "Please enter a positive integer >= 2: ";
	cin >> num;

    printDivisors(num);

    return 0;
}
