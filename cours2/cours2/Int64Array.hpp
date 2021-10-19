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

	Int64Array(int size) {
		data = (int64_t*) malloc(size * sizeof(int64_t));
		setZero(size);
		maxSize = size;
	}

	void setZero(int size) {
		data[size] = 0;
		if (size == 0) {
			return;
		}
		return setZero(size - 1);
	}
	void setZero(int idx, int size) {
		data[idx] = 0;
		if (idx == size) {
			return;
		}
		return setZero(idx + 1, size);
	}

	~Int64Array() {
		free(data);
		data = nullptr;
		maxSize = 0;
		curSize = 0;
	}

	void ensure(int size) {
		if (maxSize < size) {
			data = (int64_t*) realloc(data, size * sizeof(int64_t));
			setZero(maxSize, size);
			maxSize = size;
		}
	}

	void set_unsafe(int pos, int64_t elem) {
		data[pos] = elem;
	}

	void set(int pos, int64_t elem) {
		ensure(pos);
		if (data[pos] == 0) {
			curSize++;
		}
		data[pos] = elem;
	}

	void push_back(int64_t elem) {
		ensure(curSize+1);
		data[curSize] = elem;
		curSize++;
	}
protected:
	void push_right(int idx, int size) {
		if (size < idx) {
			return;
		}
		data[size + 1] = data[size];
		return push_right(idx, size - 1);
	}
public:
	void push_front(int64_t elem) {
		ensure(curSize+1);
		push_right(0,curSize);
		data[0] = elem;
		curSize++;
	}

	void insert(int idx, int64_t elem) {
		ensure(curSize+1);
		push_right(idx, curSize);
		data[idx] = elem;
		curSize++;
	}

	int64_t& operator[](int idx) {
		return get(idx);
	}

	int64_t& get(int idx) {
		ensure(idx + 1);
		if (idx >= curSize) {
		curSize = idx + 1;
		}
		return data[idx];
	}
};