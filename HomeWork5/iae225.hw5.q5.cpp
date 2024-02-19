#include <iostream>
#include <cmath>

using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {
    
    int M;

    cout << "Enter a positive integer M (>= 2): ";
    cin >> M;

    if (M < 2) {
        cout << "Invalid input.";
        return 1;
    }

    cout << "Perfect numbers between 2 and " << M << ":" << endl;
    for (int i = 2; i <= M; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
        }
    }

    cout << "\nAmicable number pairs between 2 and " << M << ":" << endl;
    
	for (int i = 2; i <= M; i++) {
        int countDivs, sumDivs;
        analyzeDividors(i, countDivs, sumDivs);

        if (sumDivs != i && sumDivs <= M) {
            int partnerCountDivs, partnerSumDivs;
            analyzeDividors(sumDivs, partnerCountDivs, partnerSumDivs);

            if (partnerSumDivs == i && sumDivs < i) {
                cout << "(" << sumDivs << ", " << i << ") ";
            }
        }
    }

    cout << endl;

    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){
	
	if(num < 2) {
		return;
	}

	outCountDivs = 1;
    outSumDivs = 1;

    int limit = sqrt(num);

    for (int i = 2; i <= limit; i++) {
        if (num % i == 0) {
            outCountDivs++;
            outSumDivs += i;

            if (i != num / i) {
                outCountDivs++;
                outSumDivs += num / i;
            }
        }
    }

	return;
}

bool isPerfect(int num) {
	if(num < 2) {
		cout << "Error.";
		return false;
	}

	int CountDivs = 0;
	int SumDivs = 0;

	analyzeDividors(num, CountDivs, SumDivs);

	if (SumDivs == num) return true;
	else return false;
}