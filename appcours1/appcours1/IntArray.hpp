#pragma once
class IntArray {
	int* data = nullptr;

public:

	IntArray() {
		//alloc dynamique des data tailler "suffisamment grand"
		data = new int[65536];
	}

	void set(int idx, int value) {
		//r�cup donn�e idx et affecter value
		data[idx] = value;
	}

	int get(int idx) {
		//r�cup la value � la case idx et return
		return data[idx];
	}
};
//realloc et template