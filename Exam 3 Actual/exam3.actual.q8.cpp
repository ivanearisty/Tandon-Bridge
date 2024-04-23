#include <iostream>
#include <fstream>

using namespace std;

int main () {

	ifstream left;
	ifstream right;
	ofstream output;

	left.open("1.txt");
	right.open("2.txt");
	output.open("3.txt");

	int leftCurr;
	int rightCurr;

	left >> leftCurr;
	right >> rightCurr;

	while(!left.eof() && !right.eof()){

		while(leftCurr < rightCurr){
			output << leftCurr;
			output << '\n';
			if(left.eof()) break;
			left >> leftCurr;
		}
		while(rightCurr <= leftCurr){
			output << rightCurr;
			output << '\n';
			if(right.eof()) break;
			right >> rightCurr;
		}
	}

	if(left.eof() && right.eof()){
		if(leftCurr > rightCurr){
			output << rightCurr << '\n';
			output << leftCurr;
		}else{
			output << leftCurr << '\n';
			output << rightCurr;
		}
	} else if(left.eof()){
		output << rightCurr << '\n';
		while(true){
			if(right.eof()) break;
			right >> rightCurr;
			output << rightCurr << '\n';
		}
		output << rightCurr << '\n';
	}else if(right.eof()){
		output << leftCurr << '\n';
		while(true){
			if(left.eof()) break;
			left >> leftCurr;
			output << leftCurr << '\n';
		}
		output << leftCurr << '\n';
	}

	return 0;
}