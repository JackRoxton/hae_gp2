#pragma once
struct Node {

public :
	int value =  0;
	Node* next = NULL;

	Node() {

	}
};

class CList {
public:
	int* data = nullptr;
	Node* first = NULL;
	Node* current = first;
	Node* last = NULL;

	CList() {
		
	}

	void Next() {
		current.next = current;
	}
};