#include <iostream>
using namespace std;

struct Tree {
	int data;
	Tree* left;
	Tree* right;
	Tree(int val) {
		data = val;
		left = right = NULL;
	}
};
void Insert(Tree*& root, int val) {
	if (!root) {
		root = new Tree(val);
		return;
	}
	if (val > root->data) {
		Insert(root->right, val);
	}
	else {
		Insert(root->left, val);
	}
}

void Ascending(Tree*& root) {
	if (!root) {
		return;
	}
	Ascending(root->left);
	cout << root->data << endl;
	Ascending(root->right);
}

void Decending(Tree*& root) {
	if (!root) {
		return;
	}
	Decending(root->right);
	cout << root->data << endl;
	Decending(root->left);
}

int main() {
	Tree* root = NULL;
	Insert(root, 8);
	Insert(root, 9);
	Insert(root, 4);
	Insert(root, 7);
	Insert(root, 11);
	Insert(root, 5);
	Insert(root, 10);
	Insert(root, 6);
	cout << "Output:" << endl;
	cout << "Ascending:" << endl;
	Ascending(root);
	cout << "Decending:" << endl;
	Decending(root);
	return 0;
}