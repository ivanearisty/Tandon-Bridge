#include <iostream>

using namespace std;

double eApprox(int n);

// Running time of O(Iterations * N)
int main()
{

	const int iterations = 15;

	cout.precision(30);
	for (int n = 1; n <= iterations; n++)
	{
		cout << "n = " << n << '\t' << eApprox(n) << endl;
	}
	return 0;
}

/**
 * implementation of O(N) in eAprox
 */
double eApprox(int n)
{

	double approximation = 1.0;
	double term = 1.0;

	for (int i = 1; i < n; i++)
	{
		term /= i;
		approximation += term;
	}

	return approximation;
}