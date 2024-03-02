#include <iostream>
#include <string>

using namespace std;

const int ASCII_SIZE = 256;

int countWordsAndLetters(int arr[], string s);
void printWords(int words);
void printLetterCount(int arr[]);

int main()
{

	int arr[ASCII_SIZE] = {0};
	string s;

	cout << "Please enter a line of text:" << endl;
	getline(cin, s);

	int words = countWordsAndLetters(arr, s);

	printWords(words);
	printLetterCount(arr);

	return 0;
}

int countWordsAndLetters(int arr[], string s)
{
	int words = 0;
	bool inWord = false;
	for (int i = 0; i < s.length(); i++)
	{
		char curr = s.at(i);

		if (curr == ' ' || curr == ',' || curr == '.' || curr == '\n')
		{

			if (inWord)
				words++;
			inWord = false;
			continue;
		}

		// check if the current selection is a alphabetic
		if ((curr >= 'A' && curr <= 'Z') || (curr >= 'a' && curr <= 'z'))
		{
			arr[curr]++;
			inWord = true;
		}
	}

	if (inWord)
		words++;

	return words;
}

void printWords(int words)
{
	cout << words << "\twords" << endl;
}

void printLetterCount(int arr[])
{
	for (int i = 0; i < 26; i++)
	{
		int currLetterCount = arr[i + 'a'] + arr[i + 'A'];
		if (currLetterCount <= 0)
			continue;
		cout << currLetterCount << "\t" << static_cast<char>(i + 'a') << endl;
	}
}
