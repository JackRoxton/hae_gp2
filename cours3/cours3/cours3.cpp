#include "pch.h"
#include <iostream>
#include <vector>
#include "Int64Array.hpp"
#include "List.hpp"
#include "Tree.hpp"

int _main()
{
	typedef List<double> ListD;
	typedef List<float> ListF;
	typedef List<int> ListI;
	typedef List<std::string> ListS;

	ListD* v0 = new ListD(66);
	ListF* f0 = new ListF(67);
	ListI* i0 = new ListI(68);
	ListS* s0 = new ListS("69");

	f0 = f0->push_back(97);
	s0 = s0->push_first("96");

	std::vector<double> vd = {0.0,1.0,2.0};
	vd.push_back(13);
	vd[0] = 14;
	for (int i = 0; i < vd.size; i++) {
		printf("%f", vd[i]);
	}

	for (auto f : vd) {
		printf("%f", f);
	}

	for (auto iter = vd.begin(); iter != vd.end();) {
		if (*iter == 1.0) {
			iter = vd.erase(iter);
		}
		else {
			iter++;
		}
	}

	return 0;
}

int main() {

	Tree<float>* tf = new Tree<float>(66.0f);
	Tree<std::string>* ts = new Tree<std::string>("sapin");


	return 0;
}