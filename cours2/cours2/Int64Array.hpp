#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include <string.h>

class Int64Array {
public:
	int64_t* data;
	int maxSize = 0;
	int curSize = 0;

	Int64Array(int size = 0) {
		data = (int64_t*)malloc(size * sizeof(int64_t));
		setZero(size);
		maxSize = size;
	}

	void setZero(int size);
	void setZero(int idx, int size);

	~Int64Array() {
		free(data);
		data = nullptr;
		maxSize = 0;
		curSize = 0;
	}

	void ensure(int size);
	void set_unsafe(int pos, int64_t elem);
	void set(int pos, int64_t elem);
	void push_back(int64_t elem);
protected:
	void shift_right(int idx, int size);
	void test_order(int idx, int64_t elem);
	int test_order_int(int idx, int64_t elem);
	void clear();
	void swap(int a, int b);
public:
	void push_front(int64_t elem);
	void insert(int idx, int64_t elem);
	void insert_ordered(int64_t elem);
	void append_sorted(const int64_t* arr, int sz);

	void load_Sorted(const int* arr, int sz);
	void load(const int64_t* arr, int sz);
	void insertionSort(const int64_t* arr, int sz);
	int bSearch(int dtmin,int dtmax,int64_t key);

	int64_t& get(int idx) {
		ensure(idx + 1);
		if (idx >= curSize) {
		curSize = idx + 1;
		}
		return data[idx];
	}
	int64_t& operator[](int idx) {
		return get(idx);
	}
};