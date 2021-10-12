#pragma once

#include <cstdlib>
#include <cstring>

struct IntTree {
	int			value = 0.0;

	IntTree*	fg = nullptr;
	IntTree*	fd = nullptr;

};

int			count(IntTree* head);
IntTree*	create(int value);
IntTree*	insert(IntTree* head, int value);
IntTree*	remove(IntTree* head, int value);
IntTree*	merge(IntTree* a, IntTree* b);

