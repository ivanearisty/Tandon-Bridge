#include <iostream>
#include <vector>

using namespace std;

void addElement(int *&arr, int &size, int &capacity, int element);
void main1();
void main2();

int main()
{

	main1();
	cout << endl;
	main2();

	return 0;
}

void addElement(int *&arr, int &size, int &capacity, int element)
{

	if (size == capacity)
	{

		int newCapacity = capacity * 2;
		int *newArr = new int[newCapacity];

		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;

		arr = newArr;
		capacity = newCapacity;
	}

	arr[size] = element;
	size++;
}

void main1()
{

	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End your input by typing -1." << endl;

	int initialCapacity = 10;
	int *v = new int[initialCapacity];
	int size = 0;
	int capacity = initialCapacity;
	int input;

	while (true)
	{
		cin >> input;

		if (input == -1)
		{
			break;
		}
		else if (input < -1)
		{
			continue;
		}
		else
		{
			addElement(v, size, capacity, input);
		}
	}

	cout << "Please enter a number you want to search: ";
	cin >> input;

	int *foundI = new int[size];
	int foundICount = 0;

	for (int i = 0; i < size; i++)
	{
		if (v[i] == input)
		{
			foundI[foundICount++] = i + 1;
		}
	}

	if (foundICount == 0)
	{
		cout << "The number " << input << " does not appear in the sequence.";
	}
	else
	{
		cout << "The number " << input << " shows in line(s)";

		for (int i = 0; i < foundICount; i++)
		{
			cout << ", " << foundI[i];
		}
	}

	// Clean up dynamically allocated memory
	delete[] v;
	delete[] foundI;
}

void main2()
{

	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End your input by typing -1." << endl;

	vector<int> v;
	int input;

	while (true)
	{

		cin >> input;

		if (input == -1)
		{
			break;
		}
		else if (input < -1)
		{
			continue;
		}
		else
		{
			v.push_back(input);
		}
	}

	cout << "Please enter a number you want to search: ";
	cin >> input;

	vector<int> l;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == input)
		{
			l.push_back(i + 1);
		}
	}

	if (l.size() == 0)
	{
		cout << "The number " << input << " does not appear in the sequence.";
		return;
	}

	cout << "The number " << input << " shows in line(s)";

	for (auto li : l)
	{
		cout << ", " << li;
	}

	return;
}
