/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions. 
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>
#include <cassert>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data)
        : data(data),
          color(RED),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point);
    void doubleCR(RBTNode<T> *&point);
    void singleCR(RBTNode<T> *&point);
    void doubleCCR(RBTNode<T> *&point);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
	void prettyPrint() const { root->prettyPrint(0); }
	void fixInsertion(RBTNode<T> *&point);

	int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) {
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) {
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->left;
    
	//Set grandparent's left child as parent's right child.
    grandparent->left = parent->right;

	//If what we just changed wasn't a nullptr, then update it to point to grandparent as its parent.
    if (parent->right != nullptr) {
        parent->right->parent = grandparent;
    }

	//Shift the parent up to be the new grandparent by
	//Making it's new right child the grandparent
    parent->right = grandparent;
	
	// And setting its parent to be the past parent of the grandparent that has been shifted down.
    parent->parent = grandparent->parent;
    
	// Update the grandparent's parent pointer to reflect it has shifted to be the right child of parent
	grandparent->parent = parent;

    // If we just updated the root, then we should let the RBT know that we did that
    if (parent->parent == nullptr) {
        root = parent;
    } 
	// if we didn't update the root then,
	// Update the parent of the grandparent to point to the new head pointer that is the parent
	else if (parent->parent->left == grandparent) {
        parent->parent->left = parent;
    } else {
        parent->parent->right = parent;
    }
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->right;
    
    grandparent->right = parent->left;
    
	if (parent->left != nullptr) {
        parent->left->parent = grandparent;
    }

    parent->left = grandparent;
    parent->parent = grandparent->parent;
    grandparent->parent = parent;

    if (parent->parent == nullptr) {
        root = parent;
    } else if (parent->parent->left == grandparent) {
        parent->parent->left = parent;
    } else {
        parent->parent->right = parent;
    }
}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) {               // leaf location is found so insert node
        point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
                                          // is passed by reference
        point->parent = parent;

        RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree
        
		fixInsertion(curr_node);

    } else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf location
        insert(toInsert, point->left, point);
    } else { // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}

template <class T>
void RBT<T>::fixInsertion(RBTNode<T> *&point) {
    
	// Base Case: 
	// The parent of the newly inserted node is black, aka there is nothing to see here,
	// or the newly inserted node is the root, so we just set it to be black because the root is
	// always black
    if (point->parent == nullptr || point->parent->color == BLACK) {
        if (point->parent == nullptr) {
            point->color = BLACK;
        }
        return;
    }

	// Setting Relatives:
    RBTNode<T> *parent = point->parent;
    RBTNode<T> *grandparent = parent->parent;
    RBTNode<T> *uncle = (parent == grandparent->left) ? grandparent->right : grandparent->left;

    // Case 1: Parent and Uncle Nodes Are Red

	// If both the parent and uncle of the new node are red, 
	// this causes a violation since no two red nodes should be adjacent. 
	// The solution is to recolor the parent and uncle to black and the grandparent to red, 
	// then recursively fix potential violations at the grandparent.

    if (uncle != nullptr && uncle->color == RED && parent->color == RED) {
        parent->color = BLACK;
        uncle->color = BLACK;
        grandparent->color = RED;
        fixInsertion(grandparent);
        return;
    }

    // Case 2: 

	// If the node and its parent are misaligned (triangular configuration with grandparent), 
	// a rotation is needed to line them up (straighten the configuration) for the next step.

    if (point == parent->right && parent == grandparent->left) {
        singleCCR(parent); 
        point = point->left; 
    } else if (point == parent->left && parent == grandparent->right) {
        singleCR(parent); 
        point = point->right; 
    }

    // Case 3:
	
	// After potential adjustments in Case 2, 
	// a final rotation around the grandparent is required based on the node's alignment
	// with its parent.
	//
	// After rotation, colors of the parent (new root of the subtree) and grandparent,
	// are swapped to maintain RB properties.

    parent = point->parent;
    grandparent = parent->parent;

    if (point == parent->left) {
        singleCR(grandparent); 
    } else {
        singleCCR(grandparent); 
    }

    parent->color = BLACK;
    grandparent->color = RED;
}

template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }
    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */
    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
    cout<<endl;
    cout<<"---------------------"<<endl;
    cout<<endl;
    RBT<int> c;
    count = 5;
    for (int i = count; i > 0; i--) {
        c.insert(i);
    }
    c.prettyPrint();
    /* EXPECTED OUTPUT:
                    Data: 5
                    COLOR: BLACK
    Data: 4
    COLOR: BLACK
                                    Data: 3
                                    COLOR: RED
                    Data: 2
                    COLOR: BLACK
                                    Data: 1
                                    COLOR: RED
    */
    height = c.height();
    assert(height <= 2 * log2(count));
}