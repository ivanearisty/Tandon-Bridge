/*
Implementations guidelines:
1. The user can guess at most 5 times.
2. Before each guess the program announces:
• An updated guessing-range, taking in to account previous guesses and responses.
• The number of guesses that the user has left.
3. If the user guessed correctly, the program should announce that, and also tell how many
guesses the user used.
4. If the user guessed wrong, and there are still guesses left, the program should tell the
user if the number (it chose) is bigger or smaller than the number that the user guessed.
5. If the user didn’t guess the number in all of the 5 tries, the program should reveal the
number it chose.
6. Follow the execution examples below for the exact format.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	int guesses = 0, lowerBound = 1, upperBound = 100;
	const int allowedGuesses = 5;
	int guess;

	srand(time(0));
	int answer = (rand()%100)+1;

	cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

	while (true)
	{
		cout << "Range: [" << lowerBound << ", " << upperBound << "], Number of guesses left: " << allowedGuesses - guesses <<"\nYour guess: ";
		cin >> guess;

		if(guess == answer){
			cout << "Congrats! You guessed my number in " << guesses + 1 << " guess(es).";
			return 0;
		}else if(guesses + 1 == allowedGuesses){
			break;
		}else if(guess < answer){
			cout << "Wrong! My number is bigger." << endl;
			lowerBound = guess + 1;
		}else{
			cout << "Wrong! My number is smaller." << endl;
			upperBound = guess - 1;
		}
		
		guesses++;
	}
	
	cout << "Out of guesses! My number is: " << answer;

	return 0;
}