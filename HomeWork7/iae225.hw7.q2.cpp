#include <iostream>
#include <string>

using namespace std;

/**
 * Two strings are anagrams if the letters can be rearranged to form each other.
 * For example, “Eleven plus two” is an anagram of “Twelve plus one”.
 * Each string contains one ‘v’, three ‘e’s, two ‘l’s, etc.
 * Write a program that determines if two strings are anagrams.
 * The program should not be case sensitive and should disregard any punctuation or spaces.
 */

const int LETTERS_IN_ENGLISH_ALPHABET = 26;

int *arrayFactory(string s);

int main()
{

	string s1, s2;
	int *s1Arr, *s2Arr;

	cout << "Insert the first string" << endl;
	getline(cin, s1);

	cout << "Insert the second string" << endl;
	getline(cin, s2);

	s1Arr = arrayFactory(s1);
	s2Arr = arrayFactory(s2);

	// for(int i = 0 ; i < LETTERS_IN_ENGLISH_ALPHABET ; i++){
	// 	cout << s1Arr[i] << ", " << s2Arr[i] << " ;  ";
	// }

	for (int i = 0; i < LETTERS_IN_ENGLISH_ALPHABET; i++)

		if (s1Arr[i] != s2Arr[i])
		{
			cout << "Not Anagrams";
			delete[] s1Arr;
			delete[] s2Arr;
			return 0;
		}

	cout << "Anagrams";
	delete[] s1Arr;
	delete[] s2Arr;
	return 0;
}

int *arrayFactory(string s)
{
	typedef int *IntPtr;
	IntPtr p = new int[LETTERS_IN_ENGLISH_ALPHABET];

	for (int i = 0; i < s.length(); i++)
	{

		char curr = s.at(i);

		if (curr >= 'A' && curr <= 'Z')
		{
			p[curr - 'A']++;
		}
		else if (curr >= 'a' && curr <= 'z')
		{
			p[curr - 'a']++;
		}
	}

	return p;
}
