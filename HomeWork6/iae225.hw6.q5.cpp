#include <iostream>
#include <string>

using namespace std;

int main(){

	const int SIZE = 3;
	string strings[SIZE];

	for(int i = 0 ; i < SIZE ; i++){
		cin >> strings[i];
	}

	cout << strings[2] << ", " << strings[0] << " " << strings[1].at(0) << ".";

	return 0;

}