#include <algorithm> //pour std::max<int>()
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

	void resize(int nSize) {
		if (length >= nSize) {
			return;
		}
		
		data = (int*) realloc(data, nSize * sizeof(int));
		memset(data+length,0,(nSize-length)*sizeof(int));

		for (int i = length; i < nSize; i++) {
			data[i, 0];
		}

		length = nSize;

	}

	void insertAt(int idx, int value) {
		int len = length;
		resize(std::max<int>(idx+1,length + 1));
		for (/*len*/; len > idx; len--) {
			//int temp = data[len];
			data[len] = data[len - 1];
			//data[len - 1] = temp;
		}
		data[idx] = value;

		/*memmove
		int len = length;
		resize(std::max<int>(idx+1,length + 1));
		memmove(&data[idx+1], &data[idx],(len-idx)*sizeof(int));
		data[idx]=value;
		*/
	}

	void insert(int value) {
		int idx = 0;
		while ((idx < length) && (data[idx] < value)) {
			insertAt(idx, value);
		}
	}

	static int cmp(const void* v0, const void* v1) {
		return *(int*)v0 - *(int*)v1;
	}

	void qsort() {
		::qsort(data, length, sizeof(int), cmp);

	}

	void print() {
		for (int i=0; i < length; i++) {
			printf("%d\n", data[i]);
		}
	}


};