#include <iostream>
using namespace std;

int main (){
	int n = 0;
	cin >> n;
	cout << endl;
	
	int amount = n * (n + 1);
	int left = 1;
	int right = amount;

	for(int i = 0 ; i < n ; i++){
		
		//tabs
		for(int j = 0 ; j < i ; j++){
			cout<<"--";
		}
		
		//numbers left side
		for(int j = 1; j <= n - i; j++){
			cout << left++ << "*";
		}

		int temp = 0;
		//numbers right side
		for(int j = n - i ; j > 0 ; j--){
			cout << right - j + 1;
			if(j > 1 ) cout << "*";
			temp++;
		}
		right = right - temp;

		//new line
		cout << endl;

	}

	return 0;
}

/**
 * 
 * Input : n = 3
Output :
1*2*3*10*11*12
--4*5*8*9
----6*7

Input : n = 4
Output :
1*2*3*4*17*18*19*20
--5*6*7*14*15*16
----8*9*12*13
------10*11
Input : n = 5
Output :
1*2*3*4*5*26*27*28*29*30
--6*7*8*9*22*23*24*25
----90*11*12*19*20*21
------13*14*17*18
--------15*16
*/