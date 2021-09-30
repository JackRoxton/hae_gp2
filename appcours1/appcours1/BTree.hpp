#pragma once
struct Node {

public:
	int value = 0;
	Node* left = nullptr;
	Node* right = nullptr;

	Node() {

	}
};

class BTree {
public:
	Node* root = nullptr;
	
	BTree(){

	}

	void Add(Node* nod) {
		if (root = nullptr) {
			root = nod;
			return;
		}

		Node* curr = root;
		bool done = false;
		do{
			if(nod->value > curr->value){
				if (curr->right != nullptr) {
					curr->right = nod;
					done = true;
				}
				curr->right = curr;
			}
			else {
				if (curr->left != nullptr) {
					curr->left = nod;
					done = true;
				}
				else {
					curr->left = curr;
				}
			}
		} while(!done);
		delete curr;
	}
	
	void PrintRight() {

	}

	void PrintLeft() {

	}

};