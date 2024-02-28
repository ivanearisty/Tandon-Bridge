#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main () {
	
	string word;
    cout << "Please enter a word: ";
    getline(cin, word);
	
	if(isPalindrome(word)){
		cout << word << " is a palindrome";
	}else{
		cout << word << " is not a palindrome";
	}

	return 0;
}

bool isPalindrome(string str){
	
	int left = 0;
	int right = str.length() - 1;

	while(left < right){
		if(str.at(left) != str.at(right)) return false;
		left++;
		right--;
	}

	return true;
}