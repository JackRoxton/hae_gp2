#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Int64Array.hpp"
#include "Chrono.hpp"
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

	/*Int64Array arr(16);
	for (int i = 0; i < 18; i++) {
		arr.set(i,i);
	}
	arr.push_back(18);
	arr.push_front(19);
	arr.insert(3, 20);

	Int64Array arrr(10);
	arrr.set(0, 0);
	arrr.set(1, 2);
	arrr.set(2, 4);
	arrr.set(3, 6);
	arrr.insert_ordered(7);*/

	/*Int64Array ar(10);
	int64_t tt[] = { 46,46,48,64,448,486,646,846 };
	int sz = sizeof(tt) / sizeof(int64_t);
	ar.data = tt;
	ar.curSize = sz;
	ar.bSearch(64);
	ar.bSearch(48);
	ar.bSearch(846);*/

	Int64Array br(21);
	for (int64_t i = 0; i < 22; i++) {
		br.insert_ordered(i);
	}
	//int64_t btt[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; truc de bourrin pas ouf pour le free (pas le droit d'accès)
	//int bsz = sizeof(btt) / sizeof(int64_t);
	//br.data = btt;
	//br.curSize = bsz;
	double t0 = getTimeStamp();
	/*br.bSearch(10);
	double t1 = getTimeStamp();
	printf("%llf\n",(t1-t0));

	double t2 = getTimeStamp();
	br.bSearch(5);
	double t3 = getTimeStamp();
	printf("%llf\n", (t3 - t2));

	double t4 = getTimeStamp();
	br.bSearch(18);*/
	for (int64_t i = 0; i < 22; i++) {
		br.bSearch(i);
	}
	double t5 = getTimeStamp();
	printf("%llf\n\n", (t5 - t0));

	double bt0 = getTimeStamp();
	/*br.whileBSearch(10);
	double bt1 = getTimeStamp();
	printf("%llf\n", (bt1 - bt0));

	double bt2 = getTimeStamp();
	br.whileBSearch(5);
	double bt3 = getTimeStamp();
	printf("%llf\n", (bt3 - bt2));

	double bt4 = getTimeStamp();
	br.whileBSearch(18);*/
	for (int64_t i = 0; i < 22; i++) {
		br.whileBSearch(i);
	}
	double bt5 = getTimeStamp();
	printf("%llf\n", (bt5 - bt0));


/*#pragma region Chrono
	Int64Array ti(1000);
	for (int i = 0; i < 1000; i++) {
		ti.insert_ordered(rand() % 11353453);
	}
	double t1 = getTimeStamp();
	printf("time elapsed insertOrder: %llf\n", (t1 - t0));

	double t2 = getTimeStamp();
	Int64Array ti2;
	//ti2.append_sorted(ar.data, arr.curSize);
	double t3 = getTimeStamp();
	printf("time elapsed appendSorted: %llf\n", (t3 - t2));

	double t4 = getTimeStamp();
	Int64Array ti3;
	ti2.insertionSort(ar.data, arr.curSize);
	double t5 = getTimeStamp();
	printf("time elapsed insertionSort: %llf\n", (t5 - t4));
#pragma endregion*/

	return 0;
}
