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
	Node* first;
	Node* current;
	Node* last;

	CList() {
		first = new Node();
		last = new Node();

		current = first;
		first->next = last;
	}

	void Add(Node* nod) {
		last->next = nod;
		last = last->next;
	}

	void Next() {
		current = current->next;
	}

	void Print() {
		current = first;
		printf("printing\n");

		while (current != nullptr) {
			printf("%d\n",current->value);
			Next();
		}
		printf("%d",last->value);
	}
};