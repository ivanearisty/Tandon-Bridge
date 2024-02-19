#include <iostream>
using namespace std;

int main(){
	
	int currScore = 0;
	int excellentCategory = 0;
	int veryGoodCategory = 0;
	int averageCategory = 0;
	int belowAverageCategory = 0;
	int totalStudents = 0;
	int maxScore = 0;
	int minScore = 100;
	double totalScore = 0.0;
	double averageScore = 0.0;

	cout << "Please enter a sequence of numbers (integers) in between 1 and 100, each one in a separate line."<< endl << "End your sequence by typing -1:" << endl;

	while(true){
		
		//take user input
		cin >> currScore;
		
		//break if the user types 1
		if(currScore == -1) break;

		//add the student to the appropriate category
		if(currScore >= 90){
			excellentCategory++;
		}else if (currScore >= 80){
			veryGoodCategory++;
		}else if (currScore >= 70){
			averageCategory++;
		}else{
			belowAverageCategory++;
		}

		//update min and max
		maxScore = (maxScore < currScore) ? currScore : maxScore;
		minScore = (minScore > currScore) ? currScore : minScore;

		//update total students
		totalStudents++;

		//add to total score
		totalScore += currScore;

	}

	if(totalStudents == 0){
		cout << "You forgot to input a single student!" << endl;
		return 1;
	}

	//print all the info:
	cout << "Number of students in the Excellent Category: " << excellentCategory << endl;
	cout << "Number of students in the Very Good Category: " << veryGoodCategory << endl;
	cout << "Number of students in the Average Category: " << averageCategory << endl;
	cout << "Number of students in the Below Average Category: " << belowAverageCategory << endl;
	cout << "Total number of people in the given sequence of scores: " << totalStudents << endl;
	cout << "Maximum score among the given sequence of scores: " << maxScore << endl;
	cout << "Minimum score among the given sequence of scores: " << minScore << endl;
	cout << "Overall Average score of the given sequence of scores: " << totalScore / totalStudents << endl;

	return 0;
}

/*
Number of students in the Excellent Category:
Number of students in the Very Good Category:
Number of students in the Average Category:
Number of students in the Below Average Category:
Total number of students in the given sequence of scores:
Maximum score among the given sequence of scores:
Minimum score among the given sequence of scores:
Overall Average score of the given sequence of scores:
*/