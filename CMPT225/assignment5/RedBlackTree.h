#pragma once
#include <vector>
// for debugging
//#include <iostream>

template <typename S, typename T>
class NodeT
{
public:
	NodeT(S key, T val) : left(nullptr), right(nullptr), parent(nullptr), key(key), value(val), isBlack(false) {}
	NodeT(S key, T val, bool black) : left(nullptr), right(nullptr), parent(nullptr), key(key), value(val), isBlack(black) {}
	
	S key;
	T value;
	bool isBlack;
	NodeT* left;
	NodeT* right;
	NodeT* parent;
};

template <typename S, typename T>
class RedBlackTree
{
public:
	RedBlackTree();
	RedBlackTree(const RedBlackTree& rbtree);
	RedBlackTree& operator=(const RedBlackTree& rbtree);
	~RedBlackTree();
	bool insert(S key, T val);
	bool remove(S key);
	bool search(S key) const;
	std::vector<T> search(S keyBegin, S keyEnd) const;
	std::vector<T> values() const;
	std::vector<S> keys() const;
	int size() const;
	NodeT<S, T>* getRoot() const;


	//for debugging
	//void ptree();
	//void ptreeHelp(NodeT<S,T>* nd);


private:
	NodeT<S, T>* root;
	int currentSize;

	//helper functions
	bool checkBlack(NodeT<S, T>* nd);
	void copyTree(const RedBlackTree& rbtree);
	void deleteTree(NodeT<S, T>* nd);
	void leftRotate(NodeT<S, T>* nd);
	void rightRotate(NodeT<S, T>* nd);
	void deepCopy(NodeT<S, T>* parent, NodeT<S, T>* nd, NodeT<S, T>* copyingNode) const;
	bool binSearch(NodeT<S, T>* nd, S key) const;
	void inOrderVals(NodeT<S, T>* nd, std::vector<T>& vec) const;
	void inOrderKeys(NodeT<S, T>* nd, std::vector<S>& vec) const;
	void inOrderSearch(NodeT<S, T>* nd, std::vector<T>& vec, S low, S high) const;
	void delTreeFix(NodeT<S, T>* x, NodeT<S, T>* parent, bool isLeft);
	NodeT<S, T>* predecessor(NodeT<S, T>* nd);
};

//Default constructor 
template <typename S, typename T>
RedBlackTree<S, T>::RedBlackTree() : currentSize(0), root(nullptr) {}
//Copy Constructor
//POST: deep copies rbtree
template <typename S, typename T>
RedBlackTree<S, T>::RedBlackTree(const RedBlackTree& rbtree) : currentSize(rbtree.currentSize), root(nullptr)
{
	copyTree(rbtree);
}
//Overloaded assignment operator
//POST: deep copies rbtree
template <typename S, typename T>
RedBlackTree<S, T>& RedBlackTree<S, T>::operator=(const RedBlackTree& rbtree)
{
	if (&rbtree == this) {
		return *this;
	}
	deleteTree(root);
	this->root = nullptr;
	//copying starts at root
	copyTree(rbtree);
	currentSize = rbtree.currentSize;
	return *this;
}
//Destructor
//Deallocates all dynamic memory of nodeT objects
template <typename S, typename T>
RedBlackTree<S, T>::~RedBlackTree()
{
	deleteTree(root);
}
//PRE: red black tree properties intact
//POST: creates and inserts key value pair node into red black tree while maintaining properties
//      returns true if node is added, returns false if key is not unique and nothing is added
//PARAM: key is template type S, val is template type T
template <typename S, typename T>
bool RedBlackTree<S, T>::insert(S key, T val)
{
	if (root == nullptr) {
		//root will be black
		root = new NodeT<S, T>(key, val, true);
		currentSize++;
		return true;
	}
	else {
		if (search(key) == true) { //key already exists
			return false;
		}
		else {
			currentSize++;
			NodeT<S, T>* next = root;
			NodeT<S, T>* parent = root;
			//we want to insert a red node
			NodeT<S, T>* newNode = new NodeT<S, T>(key, val, false);
			while (next != nullptr) {
				parent = next;
				if (key < parent->key) {
					next = parent->left;
				}
				else {
					next = parent->right;
				}
			}
			//while loop terminates with parent as node with null child
			if (key < parent->key) {
				parent->left = newNode;
				newNode->parent = parent;
			}
			else {
				parent->right = newNode;
				newNode->parent = parent;
			}
			//now that it's linked, fix rbtree properties
			// if newNode is root, then short circuit and condition prevents newNode->parent being evaluated
			NodeT<S, T>* y;
			while (newNode != root && newNode->parent->isBlack == false) {
				//newNode's parent is red, and since root is always black, red parent guarentees that parent has another parent
				if (newNode->parent == newNode->parent->parent->left) { 
					y = newNode->parent->parent->right;
					if (checkBlack(y) == false) { //if y.color is red
						newNode->parent->isBlack = true;
						y->isBlack = true;
						newNode->parent->parent->isBlack = false;
						newNode = newNode->parent->parent;
					}
					else { // y.color is black
						if (newNode == newNode->parent->right) {
							newNode = newNode->parent;
							leftRotate(newNode);
						}
						newNode->parent->isBlack = true;
						//newnode.p.p exists as stated before, or exists from the leftRotation
						newNode->parent->parent->isBlack = false;
						rightRotate(newNode->parent->parent);
					}
				}
				else { // newNode->parent == newNode->parent->parent->right
					y = newNode->parent->parent->left;
					if (checkBlack(y) == false) { //y.color is red
						newNode->parent->isBlack = true;
						y->isBlack = true;
						newNode->parent->parent->isBlack = false;
						newNode = newNode->parent->parent;
					}
					else { //y.color is black
						if (newNode == newNode->parent->left) {
							newNode = newNode->parent;
							rightRotate(newNode);
						}
						newNode->parent->isBlack = true;
						newNode->parent->parent->isBlack = false;
						leftRotate(newNode->parent->parent);
					}
				}
				root->isBlack = true;
			}
			return true;
		}
	}
}

//PRE: red black tree had valid properties
//POST: maintains red black tree properties after deleting node matching key and returns true
//      returns false if no node matches key parameter
//PARAM: key is template type S
template <typename S, typename T>
bool RedBlackTree<S, T>::remove(S key)
{
	//look for node first
	NodeT<S, T>* nd = root;
	while (nd != nullptr && nd->key != key) {
		if (nd->key > key) {
			nd = nd->left;
		}
		else { //nd->key < key
			nd = nd->right;
		}
	}
	//loop exited with either a nullptr or nd->key == key
	if (nd == nullptr) {
		//key is not in tree
		return false;
	}
	else {
		currentSize--;
		NodeT<S, T>* y;
		NodeT<S, T>* x;
		bool isLeft = false;
		if (nd->left == nullptr || nd->right == nullptr) {
			y = nd;
		}
		else { 
			// if nd didn't have a left child, this else statement
			// would not have been executed
			y = predecessor(nd);
		}
		if (y->left != nullptr) { 
			x = y->left;
		}
		else {
			x = y->right;
		}
		//check to make sure x is not nullptr so x->parent works
		if (x != nullptr) {
			x->parent = y->parent;
		}
		if (y->parent == nullptr) { //if y was root
			root = x;
			//no need to assign isLeft because it will skip while loop in delTreeFix
		}
		else {
			if (y == y->parent->left) {
				y->parent->left = x;
				isLeft = true;
			}
			else {
				y->parent->right = x;
				isLeft = false;
			}
		}
		//setting nd node to have y's data now
		nd->key = y->key;
		nd->value = y->value;
		NodeT<S, T>* yParent = y->parent;
		bool isYBlack = checkBlack(y);
		//delete y at this point
		delete y;
		if (isYBlack) {
			delTreeFix(x, yParent, isLeft);
		}

		return true;
	}
}

//PRE: red black tree properties intact
//POST: returns true if key exists in tree, false otherwise
//PARAM: key is template tpye S
template <typename S, typename T>
bool RedBlackTree<S, T>::search(S key) const
{
	return binSearch(root, key);
}
//PRE: red black tree properties intact
//POST: returns vector of values within the bounds of the key parameters
//PARAM: keylow and keyhigh are template type S keys for the red black tree
template <typename S, typename T>
std::vector<T> RedBlackTree<S, T>::search(S keyLow, S keyHigh) const //REMEMBER TO CHANGE TO VECTOR<T> when done
{
	NodeT<S, T>* nd = root;
	S high;
	S low;
	if (keyLow > keyHigh) {
		high = keyLow;
		low = keyHigh;
	}
	else { //keyLow <= keyHigh
		high = keyHigh;
		low = keyLow;
	}

	//traverse entire tree
	std::vector<T> vec;
	inOrderSearch(root, vec, low, high);
	return vec;
}
//PRE: red black tree properties intact
//POST: returns vector of all values in tree in ascending key order
template <typename S, typename T>
std::vector<T> RedBlackTree<S, T>::values() const  
{
	//functions similarly to inorder print
	std::vector<T> vec;
	inOrderVals(root, vec);
	return vec;
}
//PRE: red black tree properties intact
//POST: returns vector of all keys in tree in ascending key order
template <typename S, typename T>
std::vector<S> RedBlackTree<S, T>::keys() const 
{
	std::vector<S> vec;
	inOrderKeys(root, vec);
	return vec;
}
//POST: returns pointer to root of red black tree, giving full access
template <typename S, typename T>
NodeT<S, T>* RedBlackTree<S, T>::getRoot() const
{
	return root;
}
//POST: returns number of items in red black tree
template <typename S, typename T>
int RedBlackTree<S, T>::size() const
{
	return currentSize;
}


//HELPER FUNCTIONS BEGIN HERE

//search(key), insert           helper
//PRE: nd is node in red black tree, red black tree properties intact
//POST: returns true if key is in tree, otherwise false. Recursive
//PARAM: nd is same template S, T as red black tree, key is type S
template <typename S, typename T>
bool RedBlackTree<S, T>::binSearch(NodeT<S, T>* nd, S key) const
{
	if (nd == nullptr) {
		//node doesn't exist in tree
		return false;
	}
	else {
		if (nd->key > key) {
			//check left child
			return binSearch(nd->left, key);
		}
		else if (nd->key < key) {
			//check right child
			return binSearch(nd->right, key);
		}
		else { //nd->key == key
			return true;
		}
	}
}
//assignment and copy constructor helper
//POST: deep copies rbtree
template <typename S, typename T>
void RedBlackTree<S, T>::copyTree(const RedBlackTree& rbtree)
{
	if (rbtree.root != nullptr) {
		root = new NodeT<S, T>(rbtree.root->key, rbtree.root->value, rbtree.root->isBlack);
		deepCopy(root, root->left, rbtree.root->left);
		deepCopy(root, root->right, rbtree.root->right);
	}
}
//copyTree helper
//POST: deep copies nodes in the tree recursively
template <typename S, typename T>
void RedBlackTree<S, T>::deepCopy(NodeT<S, T>* parent, NodeT<S, T>* nd, NodeT<S, T>* copyingNode) const
{
	if (copyingNode != nullptr) {
		nd = new NodeT<S, T>(copyingNode->key, copyingNode->value, copyingNode->isBlack);
		nd->parent = parent;
		//no duplicate keys
		if (copyingNode->key > parent->key) {
			parent->right = nd;
		}
		else {
			parent->left = nd;
		}
		deepCopy(nd, nd->left, copyingNode->left);
		deepCopy(nd, nd->right, copyingNode->right);
	}
}
//helper to delete trees
//POST: recursively deletes every node in tree via postorder traversal
template <typename S, typename T>
void RedBlackTree<S, T>::deleteTree(NodeT<S, T>* nd)
{
	if (nd != nullptr) {
		deleteTree(nd->left);
		deleteTree(nd->right);
		delete nd;
	}
}
//POST: returns true if node is black or nullptr
template <typename S, typename T>
bool RedBlackTree<S, T>::checkBlack(NodeT<S,T>* nd)
{
	if (nd == nullptr || nd->isBlack == true) {
		return true;
	}
	else {
		return false;
	}
}

//PRE: nd must have real left child
//POST: returns predecessor node
//PARAM: nd is nodeT<S,T>
template <typename S, typename T>
NodeT<S, T>* RedBlackTree<S, T>::predecessor(NodeT<S, T>* nd)
{
	NodeT<S, T>* pred = nd->left;
	while (pred->right != nullptr) {
		pred = pred->right;
	}
	return pred;
}
//PRE: nd has a real right child
//POST: rotates subtree with nd as root leftwards
//PARAM: nd is nodeT<S, T>
template <typename S, typename T>
void RedBlackTree<S, T>::leftRotate(NodeT<S, T>* nd)
{
	//note: nd->right cannot be a nullptr
	NodeT<S, T>* y = nd->right;
	nd->right = y->left;
	if (y->left != nullptr) {
		y->left->parent = nd;
	}
	y->parent = nd->parent;
	if (nd->parent == nullptr) { //nd was root
		root = y;
	}
	else if (nd == nd->parent->left) { // nd was left child
		nd->parent->left = y;
	}
	else { //nd was right child
		nd->parent->right = y;
	}
	y->left = nd;
	nd->parent = y;
}
//PRE: nd has a real left child
//POST: rotates subtree with nd as root rightwards
//PARAM: nd is nodeT<S, T>
template <typename S, typename T>
void RedBlackTree<S, T>::rightRotate(NodeT<S, T>* nd)
{
	//note: nd->left cannot be a nullptr
	NodeT<S, T>* y = nd->left;
	nd->left = y->right;
	if (y->right != nullptr) {
		y->right->parent = nd;
	}
	y->parent = nd->parent;
	if (nd->parent == nullptr) { //nd was root
		root = y;
	}
	else if (nd == nd->parent->right) { //nd was right child
		nd->parent->right = y;
	}
	else { //nd was left child
		nd->parent->left = y;
	}
	y->right = nd;
	nd->parent = y;
}
//PRE: valid red black tree
//POST: recursively adds all keys into vector in ascending order
//PARAM: nd is NodeT<S, T>, vec is vector type S
template <typename S, typename T>
void RedBlackTree<S, T>::inOrderKeys(NodeT<S, T>* nd, std::vector<S>& vec) const
{
	if (nd != nullptr) {
		inOrderKeys(nd->left, vec);
		vec.push_back(nd->key);
		inOrderKeys(nd->right, vec);
	}
}
//PRE: valid red black tree
//POST: recursively adds all values into vector in ascending key order
//PARAM: nd is NodeT<S, T>, vec is vector type T
template <typename S, typename T>
void RedBlackTree<S, T>::inOrderVals(NodeT<S, T>* nd, std::vector<T>& vec) const
{
	if (nd != nullptr) {
		inOrderVals(nd->left, vec);
		vec.push_back(nd->value);
		inOrderVals(nd->right, vec);
	}
}
//PRE: valid red black tree
//POST: recursively adds all values within key range into vector in ascending key order
//PARAM: nd is NodeT<S, T>, vec is vector type T, low and high are same type as red black tree key (S)
template <typename S, typename T>
void RedBlackTree<S, T>::inOrderSearch(NodeT<S, T>* nd, std::vector<T>& vec, S low, S high) const
{
	if (nd != nullptr) {
		inOrderSearch(nd->left, vec, low, high);
		if (nd->key >= low && nd->key <= high) {
			vec.push_back(nd->value);
		}
		inOrderSearch(nd->right, vec, low, high);
	}
}
//PRE: parent cannot be null
//POST: fixes tree after node deletion to maintain red black tree properties
//PARAM: isLeft is boolean, true if x is parent's left child
//       parent is NodeT<S, T>* 
//       x is NodeT<S, T> (child of node that was deleted)
template <typename S, typename T>
void RedBlackTree<S, T>::delTreeFix(NodeT<S, T>* x, NodeT<S, T>* parent, bool isLeft)
{
	//if removed node was a left child, then x should be parent's left child
	//vice versa right
	//all parent != nullptr are redundant (since parent is null only if root - and then first condition in while loop is false)
	//  parent != nullptr can be used to get rid of some warning messages from visual studio
	NodeT<S, T>* y;

	while (x != root && checkBlack(x)) {
		if (x == nullptr) {
			if (isLeft) {
				y = parent->right;            
				if (checkBlack(y) == false) { // false means y is real
					y->isBlack = true;
					parent->isBlack = false;
					leftRotate(parent);
					y = parent->right;
				}
				if (checkBlack(y->left) && checkBlack(y->right)) {
					y->isBlack = false;
					//we know parent is not a nullptr, so setting x = parent will take us out of 
					//this if condition for the following iterations
					x = parent;
				}
				else {
					if (checkBlack(y->right)) {
						y->left->isBlack = true;
						y->isBlack = false;
						rightRotate(y);
						y = parent->right;
					}
					y->isBlack = parent->isBlack;
					parent->isBlack = true;
					if (checkBlack(y->right) == false) {
						y->right->isBlack = true;
					}
					leftRotate(parent);
					x = root;
				}
			}
			else { // x (nullptr) is right child of parent
				y = parent->left;
				if (checkBlack(y) == false) {
					y->isBlack = true;
					parent->isBlack = false;
					rightRotate(parent);
					y = parent->left;
				}
				if (checkBlack(y->right) && checkBlack(y->left)) {
					y->isBlack = false;
					x = parent;
				}
				else {
					if (checkBlack(y->left)) {
						y->right->isBlack = true;
						y->isBlack = false;
						leftRotate(y);
						y = parent->left;
					}
					y->isBlack = parent->isBlack;
					parent->isBlack = true;
					if (checkBlack(y->left) == false) {
						y->left->isBlack = true;
					}
					rightRotate(parent);
					x = root;
				}
			}
		}
		else { // x is not a nullptr
			//x->parent CANNOT BE INTERCHANGED WITH parent
			if (x == x->parent->left) { 
				y = x->parent->right;
				if (checkBlack(y) == false) { //y is real and is red
					y->isBlack = true;
					x->parent->isBlack = false;
					leftRotate(x->parent);
					y = x->parent->right;
				}
				if (checkBlack(y->left) && checkBlack(y->right)) {
					y->isBlack = false;
					x = x->parent;
					//go back into while loop 1 level up
				}
				else {
					if (checkBlack(y->right)) {
						//y left is real since y's left != black or right != black from above if statement
						y->left->isBlack = true;
						y->isBlack = false;
						rightRotate(y);
						y = x->parent->right;
					}
					y->isBlack = x->parent->isBlack;
					x->parent->isBlack = true;
					//make y->right black, unless it is null or already black
					if (checkBlack(y->right) == false) {
						y->right->isBlack = true;
					}
					leftRotate(x->parent);
					x = root;
					//exit while loop
				}
			}
			else { // x== x->parent->right
				y = x->parent->left;
				if (checkBlack(y) == false) {
					y->isBlack = true;
					x->parent->isBlack = false;
					rightRotate(x->parent);
					y = x->parent->left;
				}
				if (checkBlack(y->right) && checkBlack(y->left)) {
					y->isBlack = false;
					x = x->parent;
				}
				else {
					if (checkBlack(y->left)) {
						y->right->isBlack = true;
						y->isBlack = false;
						leftRotate(y);
						y = x->parent->left;
					}
					y->isBlack = x->parent->isBlack;
					x->parent->isBlack = true;
					if (checkBlack(y->left) == false) {
						y->left->isBlack = true;
					}
					rightRotate(x->parent);
					x = root;
				}
			}
		}
	}
	if (x != nullptr) {
		x->isBlack = true;
	}
}


//for debugging
//template <typename S, typename T>
//void RedBlackTree<S, T>::ptree()
//{
//	ptreeHelp(root);
//}
//template <typename S, typename T>
//void RedBlackTree<S, T>::ptreeHelp(NodeT<S, T>* nd)
//{
//	if (nd != nullptr) {
//		if (nd->isBlack == true) {
//			std::cout << nd->key << " : Black" << std::endl;
//		}
//		else {
//			std::cout << nd->key << " : Red"  << std::endl;
//		}
//		ptreeHelp(nd->left);
//		ptreeHelp(nd->right);
//	}
//}