#include "pch.h"
#include "IntList.hpp"

IntList* append(IntList* l, int value) {
	IntList *v = (IntList*)malloc(sizeof(IntList));
	l->next = v;
	v->value = value;
	return nullptr;
} 

IntList* remove(IntList* l, int value) {
	if (!l) {
		return nullptr;
	}
	if (value == l->value) {
		IntList* rest = l->next;
		free(l);
		return rest;
	}
	l->next = remove(l->next, value);
	return nullptr;
}

int length(IntList* l) {
	if (!l) {
		return 0;
	}
	return 1 + length(l->next);
}

IntList* appendFirst(IntList* l, int value) {
	IntList * v = (IntList*)malloc(sizeof(IntList));
	v->value = value;
	v->next = l;

	return v;
}

IntList* appendLast(IntList* l, int value) {
	if (!l) {
		return appendFirst(l, value);
	}

	if (l->next) {
		/*IntList *v ;
		l->next = v;
		v->value = value;
		return v;*/
		return appendLast(l->next, value);
	}
	l->next = appendFirst(nullptr, value);
	return l;
}