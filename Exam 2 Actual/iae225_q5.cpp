#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool moreEvens(string S);
int moreEvensRecur(string S, int index);

int main (){
	string s1 = "123456";
	string s2 = "01234526";
	string s3 = "2";
	string s4 = "22334512378";
	cout << moreEvens(s1) << endl;
	cout << moreEvens(s2) << endl;
	cout << moreEvens(s3) << endl;
	cout << moreEvens(s4) << endl;
	return 0;
}

/// @brief The above function is given a non-empty numeric string S that will only contain
// 			decimal character digits and returns true if there are more even numbers
/// @param S a string of character digits
/// @return true if more evens. false if equal or less evens.
bool moreEvens(string S)
{
	if(S.length() == 0) return false;
	return moreEvensRecur(S, S.length()-1) > 0 ? true : false;
}

int moreEvensRecur(string S, int index)
{
	//base case:
	if(index == 0){
		char ch = S.at(index);
		if(ch == '0' || ch == '2' || ch == '4' || ch == '6' || ch == '8'){
			return 1;
		}else{
			return -1;
		}
	}
	//recursion steps
	int countSoFar = moreEvensRecur(S, index - 1);
	char c = S.at(index);
	int evenOrOdd = 0;
	if(c == '0' || c == '2' || c == '4' || c == '6' || c == '8'){
		evenOrOdd = 1;
	}else{
		evenOrOdd = -1;
	}

	return countSoFar + evenOrOdd; 
}