#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main(){

}

class Node{
	public:
		int data;
		Node* right;
		Node* left;
		Node* parent;
		list<int>& Node::func(Node *nodePtr) const;
};

list<int>& Node::func(Node *nodePtr) const{
	list<int> myList;

	deque<Node> level; 

	level.push_front(*nodePtr);

	while(!level.empty()){
		int currLevelSize = level.size();
		//honestly i realized this level thing is kind of meaningless on a second pass,
		//but it makes it a bit more expandable i guess.
		while(currLevelSize > 0){
			
			Node *ptr = &level.front();
			level.pop_front();
			
			if(ptr->left != nullptr) level.push_back(*ptr->left);
			if(ptr->right != nullptr) level.push_back(*ptr->right);

			myList.push_back(ptr->data);
			
			currLevelSize--;
		}
	}

	return myList;

}