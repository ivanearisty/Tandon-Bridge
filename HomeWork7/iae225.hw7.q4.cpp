/**
 *
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string *createWordsArray(string sentence, int &outWordsArrSize);

int main()
{

	string s;
	int wordsArrSize;
	cout << "Type a sentence with words separated by a single space:" << endl;
	getline(cin, s);

	string *s_out = createWordsArray(s, wordsArrSize);

	for (int i = 0; i < wordsArrSize; i++)
	{
		cout << " \"" << s_out[i] << "\" ,";
	}
	cout << " with a size: " << wordsArrSize;

	delete[] s_out;

	return 0;
}

string *createWordsArray(string sentence, int &outWordsArrSize)
{
	outWordsArrSize = 0;
	vector<string> v;
	int left = 0, right = sentence.find(' ');

	while (right != string::npos)
	{

		v.push_back(sentence.substr(left, right - left));

		left = right + 1;
		right = sentence.find(' ', left);
	}

	v.push_back(sentence.substr(left, sentence.length() - left));

	string *arr = new string[v.size()];

	for (int i = 0; i < v.size(); i++)
	{
		arr[i] = v[i];
	}

	outWordsArrSize = v.size();

	return arr;
}
