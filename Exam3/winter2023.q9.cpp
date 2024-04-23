#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main () {

	ifstream handler;
	handler.open("names.txt");
	vector<string> *names = new vector<string>();

	string currName;
	while(!handler.eof()){
		char currChar = handler.get();
		if(currChar == '\n'){
			names->push_back(string(currName));
			currName.clear();
		}else{
			currName += currChar;
		}
	}

	names->push_back(currName);

	sort(names->begin(), names->end());

	ofstream outputer;
	outputer.open("namesout.txt");

	for(auto i = names->begin() ; i != names->end() ; i++){
		outputer << *i << '\n';
	}

	return 0;
}
