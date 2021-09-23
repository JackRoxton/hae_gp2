#pragma once
//# include <cstdlib> #include <cstring>
class IntArray {
	int* data = nullptr;
	int length;
public:

	IntArray() {
		//alloc dynamique des data tailler "suffisamment grand"
		data = new int[length = 65536];
		//data = (int*) malloc(65535*sizeofint(int));
	}

	IntArray(int length) {
		//alloc dynamique des data tailler "length"
		data = new int[length];
		this->length = length;
	}

	~IntArray() {
		//libérer la mémoire
		delete [] data;
		//free (data);
	}

	void set(int idx, int value) {
		//récup donnée idx et affecter value
		//si index hors bornes throw "exception:out of bounds"
		if (idx > length-1 || idx < 0) {
			throw "exception: out of bounds";
		}
		data[idx] = value;
	}

	int get(int idx) {
		//récup la value à la case idx et return
		//si index hors bornes throw "exception:out of bounds"
		if (idx > length-1 || idx < 0) {
			throw "exception: out of bounds";
		}
		return data[idx];
	}
};
//realloc et template