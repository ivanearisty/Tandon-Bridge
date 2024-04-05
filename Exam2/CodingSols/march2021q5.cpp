#include <iostream>
#include <vector>
#include <string>

using namespace std;

void readUserInput(int &max);
void printHighestGrade(int max);
vector<int> v[101]; 

int main () {
	int max = 0;
	cout << "Please enter the lines " << endl;
	readUserInput(max);
	printHighestGrade(max);
	return 0;
}

void printHighestGrade(int max){
	cout << "Highest Grade " << max << endl;
	cout << "Students are: ";
	for(auto i : v[max]){
		cout << i << "  ";
	}
	cout << ".";
}

void readUserInput(int &max)
{
	string s;
	while(true){

		getline(cin, s);
		
		int student = stoi(s.substr(0, s.find(' ')));
		if(student == -1) break;
		int grade = stoi(s.substr(s.find(' ')+1));

		max = grade > max ? grade : max;
		v[grade].push_back(student);
	}
}
