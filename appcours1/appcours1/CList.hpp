#pragma once
/*struct Node {

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

	void AddFirst(Node* nod) {
		nod->next = first;
		first = nod;
	}

	void AddAfter(Node* nod) {
		if (current->next == nullptr) {
			current->next = nod;
		}
		else {
			Node* temp = current->next;
			current->next = nod;
			nod->next = temp;
			delete temp;
		}
	}

	void AddLast(Node* nod) {
		last->next = nod;
		last = last->next;
	}

	void RemoveFirst() {
		Node* del = first;
		first->next = first;
		delete del;
	}

	void RemoveAfter() {
		if (current->next == nullptr) {
			return;
		}
		Node* temp = current->next;
		current->next = current->next->next;
		delete temp;
	}

	void RemoveLast(){
		Node* search = first;
		while (search->next != last){
			search = search->next;
		}
		last = search->next;
		delete search;
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
};*/