#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void openInputFile(ifstream &inFile)
{

	string fileName;
	cout << "Enter the file name: ";
	cin >> fileName;

	inFile.open(fileName);

	while (!inFile)
	{
		cout << "Could not read file." << endl;
		cout << "Enter the file name: ";

		cin >> fileName;

		inFile.clear();
		inFile.open(fileName);
	}
}

template <typename T>
class LinkedList
{

private:
	class Node
	{
	public:
		T data;
		Node *next;

		Node(const T &newData, Node *newNext = nullptr) : data(newData), next(newNext) {}
	};

	Node *head;
	Node *tail;

public:
	LinkedList() : head(nullptr), tail(nullptr) {}

	~LinkedList()
	{
		Node *current = head;
		while (current != nullptr)
		{
			Node *next = current->next;
			delete current;
			current = next;
		}
		head = tail = nullptr;
	}

	void push_back(const T &newData)
	{
		Node *newNode = new Node(newData);
		if (!head)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	class Iterator
	{
	public:
		Iterator(Node *pNode) : currNode(pNode) {}

		T &operator*() const
		{
			return currNode->data;
		}

		T *operator->() const
		{
			return &(currNode->data);
		}

		// Prefix ++ overload
		Iterator &operator++()
		{
			if (currNode)
				currNode = currNode->next;
			return *this;
		}

		// neq
		bool operator!=(const Iterator &iterator) const
		{
			return currNode != iterator.currNode;
		}

		Node *getCurrNode() const
		{
			return currNode;
		}

		bool hasNext() const
		{
			return currNode->next != nullptr;
		}

	private:
		Node *currNode;
	};

	Iterator begin() const
	{
		return Iterator(head);
	}

	Iterator end() const
	{
		return Iterator(nullptr);
	}
};

class Person
{
public:
	Person() : paid(0), reinbrs(0), name(""){};
	Person(double p, double r, string n) : paid(p), reinbrs(r), name(n){};
	double paid;
	double reinbrs;
	string name;

	void toString() const
	{
		cout << name << " and paid " << paid << ".\n";
	}
};

int main()
{
	ifstream inFile;
	openInputFile(inFile);

	auto *list = new LinkedList<Person>();

	double total = 0.0;
	int people = 0;

	string line;
	while (getline(inFile, line))
	{
		if (line.empty())
			continue;

		istringstream iss(line);
		double amountPaid;
		string name;

		iss >> amountPaid;
		getline(iss, name);
		if (!iss || name.empty())
			continue;

		name.erase(name.begin());

		total += amountPaid;
		people++;

		Person person(amountPaid, 0.0, name);
		list->push_back(person);
	}

	if (people == 0)
	{
		cout << "No people found in the file." << endl;
		delete list;
		return 1;
	}

	double average = total / people;
	cout << fixed << setprecision(2);

	for (auto it = list->begin(); it != list->end(); ++it)
	{
		it->reinbrs = it->paid - average;
	}

	for (auto payer = list->begin(); payer != list->end(); ++payer)
	{
		if (payer->reinbrs > 0)
		{
			cout << payer->name << " you don't have to do anything." << endl;
			continue;
		}
		for (auto receiver = list->begin(); receiver != list->end(); ++receiver)
		{
			if (payer->reinbrs < 0)
			{
				if (receiver->reinbrs > 0)
				{

					double amount = min(-payer->reinbrs, receiver->reinbrs);

					payer->reinbrs += amount;
					receiver->reinbrs -= amount;

					cout << payer->name << ", you give " << receiver->name << " $" << amount << endl;
				}
			}
		}
	}

	cout << "In the end, you should all have spent around $" << average << endl;

	delete list;

	return 0;
}
