#include "pch.h"
#include <cstring>
#include "Int64Array.hpp"

void Int64Array::setZero(int size) {
	data[size] = 0;
	if (size == 0) {
		return;
	}
	return setZero(size - 1);
}

void Int64Array::setZero(int idx, int size) {
	data[idx] = 0;
	if (idx == size) {
		return;
	}
	return setZero(idx + 1, size);
}

/*void Int64Array::setZero(int idx,int size) {
	memset(0);
}*/

void Int64Array::ensure(int size) {
	if (maxSize < size) {
		data = (int64_t*)realloc(data, size * sizeof(int64_t));
		setZero(maxSize, size);
		maxSize = size;
	}
}

void Int64Array::set_unsafe(int pos, int64_t elem) {
	data[pos] = elem;
}

void Int64Array::set(int pos, int64_t elem) {
	ensure(pos);
	if (data[pos] == 0) {
		curSize++;
	}
	data[pos] = elem;
}

void Int64Array::push_back(int64_t elem) {
	ensure(curSize + 1);
	data[curSize] = elem; //set(curSize,elem)
	curSize++;
}

void Int64Array::shift_right(int idx, int size) {
	if (size < idx) {
		return;
	}
	data[size + 1] = data[size];
	return shift_right(idx, size - 1);
}

void Int64Array::push_front(int64_t elem) {
	ensure(curSize + 1);
	shift_right(0, curSize);
	data[0] = elem;  //set(0,elem)
	curSize++;
}

void Int64Array::insert(int idx, int64_t elem) {
	ensure(curSize + 1);
	shift_right(idx, curSize);
	data[idx] = elem;//set(idx,elem)
	curSize++;
}

void Int64Array::insert_ordered(int64_t elem) {
	int pos = test_order_int(0, elem);
	insert(pos, elem);
}

void Int64Array::append_sorted(const int64_t* arr, int sz) {
	if (sz <= 0) return;
	insert_ordered(arr[0]);
	append_sorted(arr + 1, sz - 1);
};

void Int64Array::test_order(int idx, int64_t elem) {
	if (idx > curSize) {
		insert(idx, elem);
	}

	if (data[idx] < elem) {
		return test_order(idx + 1, elem);
	}
	insert(idx, elem);
}

int Int64Array::test_order_int(int idx, int64_t elem) {
	if (idx >= curSize) {
		return curSize;
	}

	if (data[idx] >= elem) {
		return idx;
	}
	return test_order_int(idx + 1, elem);
}

void Int64Array::load_Sorted(const int* arr, int sz) {
	if (sz <= 0) {
		return;
	}
	insert_ordered(arr[0]);
	load_Sorted(arr + 1, sz - 1);
};
void Int64Array::load(const int64_t* arr, int sz) {
	if (sz <= 0) {
		return;
	}
	insert(curSize,arr[0]);
	load(arr + 1, sz - 1);
};

void Int64Array::clear() {
	curSize = 0;
}

/*void Int64Array::insertionSort(const int* arr, int sz) { //version que je connais
	clear();
	load(arr, sz);
	bool sortedFlag = true;

	while (sortedFlag == true) {
		sortedFlag = false;
		for (int i = 0; i < sz-1; i++) {
			if (data[i] > data[i + 1]) {
				int tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
				sortedFlag = true;
			}
		}
	}
};*/

void Int64Array::insertionSort(const int64_t* arr, int sz) {
	clear();
	load(arr, sz);
	
	for (int i = 1; i < sz; i++) {
		int j = i;
		while (j > 0 && data[j] < data[j - 1]) {
			swap(j, j - 1);
			j-=1;
		}
	}
};

static int nStep = 0;

int Int64Array::bSearch(int64_t key) {
	return _bSearch(0, curSize, key);
};

int Int64Array::_bSearch(int lo, int hi, int64_t key) { //MARCHE
	//nStep+=1;
	int piv = (hi + lo) / 2;
	int64_t val = data[piv];
	if (val == key) {
		//printf("%d , %d\n", nStep, key);
		//nStep = 0;
		return piv;
	}
	if (val < key) {
		return _bSearch(piv+1,hi, key);
	}
	else {
		return _bSearch(lo,piv-1, key);
	}
};

int Int64Array::whileBSearch(int64_t key) {
	int lo = 0;
	int hi = curSize;
	int piv = 0;
	do {
		piv = (lo + hi) / 2;
		if (data[piv] == data[key]) {
			return piv;
		}
		else if (data[piv] < data[key]) {
			lo = piv + 1;
		}
		else {
			hi = piv - 1;
		}
	} while(1);
}

void Int64Array::swap(int a, int b) {
	int tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}


