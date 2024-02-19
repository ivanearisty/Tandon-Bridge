#include <iostream>

using namespace std;

int main(){

	int myArr [4] ;

	for(int i = 0 ; i < 4 ; i++){
		myArr[i] = i;
	}

	for(auto i : myArr)
		cout << i;
		
	return 0;
}