#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Int64Array.hpp"
/*
#pragma region MyRegion


int StrLen(char* a) {
	if (a == nullptr) {
		return NULL;
	}
	if (!*a) {
		return 0;
	}
	return 1 + StrLen(a + 1);
}

int StrCmp(const char* a, const char* b) {
	if (a == nullptr || b == nullptr) {
		return NULL;
	}
	if (!*a && !*b) {
		return 0;
	}
	if (!*a || *a < *b) {
		return -1;
	}
	if (!*b || *a > *b) {
		return 1;
	}
	return StrCmp(a + 1, b + 1);
}

char* EndOfString(char* a) {
	if (a == nullptr) {
		return nullptr;
	}
	if (*a == 0) {
		return a;
	}
	return EndOfString(a + 1);
}

char* StrCpy(char* a, const char* b) {
	if (a == nullptr || b == nullptr) {
		return nullptr;
	}
	if (!*b) {
		*a = 0;
		return a;
	}
	*a = *b;
	return StrCpy(a + 1, b + 1);
}

char* StrCat(char* a, const char* b) {
	if (a == nullptr || b == nullptr) {
		return nullptr;
	}
	if (!*b) {
		return a;
	}
	char* cat = EndOfString(a);
	return StrCpy(cat, b);
}

char* StrStr(char* a, char* b) {
	if (a == nullptr || b == nullptr) {
		return nullptr;
	}
	if (!*a || !*b) {
		return nullptr;
	}
	if (*a == *b) {
		if (StrCmp(a,b) == 0) {
			return a;
		}
	}
	return StrStr(a + 1, b);
}

char* StrChr(const char* a, char b) {
	if (a == nullptr || b == NULL) {
		return nullptr;
	}
	if (!*a) {
		return nullptr;
	}
	if (*a == b) {
		return (char*)a;
	}
	return StrChr(a + 1, b);
}

//bonus

char* StrrChr(char* a, char b) { // marche po
	if (a == nullptr || b == NULL) {
		return nullptr;
	}
	if (a) {
		a = EndOfString(a);;
	}
	if (*a == b) {
		return (char*)a;
	}
	return StrrChr(a - 1, b);
}

int main()
{
	char a[50] = "oui";
	StrLen(a);

	char b[50] = "non";
	StrCmp(a, a);
	StrCmp(a, b);
	StrCmp(b, a);

	StrCat(a, b);

	StrStr(a, b);

	StrChr(a, 'u');

	StrrChr(a, 'o');

	return 0;
}
#pragma endregion
*/

int main() {

	Int64Array arr(16);
	for (int i = 0; i < 18; i++) {
		arr.set(i,i);
	}
	arr.push_back(18);
	arr.push_front(19);
	arr.insert(3, 20);

	return 0;
}
