#include <iostream>
#include <string>

using namespace std;

bool isDigit(char ch);
string replace(string text);
void addX(string text, string &out);

int main() {
    cout << "Please enter a line of text:" << endl;
    string text;
    getline(cin, text); // Reading a line of text

	if(text.length() == 0) return 1;

    string modifiedText = replace(text);
    cout << modifiedText << endl;

    return 0;
}

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9' ? true : false;
}

string replace(string text)
{
	string output;
	string temp;
	bool digitsOnly = true;

	for (int i = 0; i < text.length(); i++) {
		
		char curr = text.at(i);

		if(curr == ' '){

			if(digitsOnly){
				addX(temp, output);
			}else{
				output += temp;
			}

			temp = "";
			digitsOnly = true;
			output += " ";

			continue;
		}

		if(!isDigit(curr)){
			digitsOnly = false;
		}

		temp += curr;

    }

	if(digitsOnly){
		addX(temp, output);
	}else{
		output += temp;
	}

	return output;

}

void addX(string text, string &out)
{
	for(int i = 0 ; i < text.length() ; i++){
		out += "x";
	}
}
