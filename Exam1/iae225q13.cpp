#include <iostream>
using namespace std;

int main(){
	
	int n = 0;
	cout << "Please enter a positive odd integer:" << endl;
	cin >> n;

	for(int i = 0 ; i < n + 1 ; i++){

		int lineType = i % 2;

		//if the line that we are trying to print is significcant then we have to do our shape stuff,
		//if it's not just fill the whole thing with astericks
		if(lineType == 0){
			//calculate and print the spaces
			int spaces = (n-i)/2;
			for(int j = 0 ; j < spaces ; j++){
				cout << " ";
			}
			
			//print the asteriscks
			for(int j = 0 ; j < i + 1 ; j++){
				cout << "*";
			}

		}else{
			for(int j = 0 ; j < n ; j++){
				cout << "*";
			}
		}

		cout << endl;
	}


	return 0;
}