#pragma once
/*#include <stdio.h>
#include <stdlib.h>*/

template<typename Type>

class List {
public:
	Type val = {};
	List*	next = nullptr;

	List(Type elem) {
		val = elem;
	}

	List(Type elem, List* _next) {
		val = elem;
		next = _next;
	}

	List* push_first(Type key) {
		auto l = new List(key);
		l->next = this;
		return l;
	}

	List* remove(Type key) {
		if (val == key) {
			List* n = next;
			delete this;
			return n;
		}
		else {
			if (next)
				next->remove(key);
			return this;
		}
	};

	List* push_back(Type key) {
		if (!next) {
			next = new List(key);
		}
		else {
			next->push_back(key);
		}
		return this;
	}
};

