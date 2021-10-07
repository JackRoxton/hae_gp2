// appcours1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "IntArray.hpp"
//#include "BTree.hpp"
//#include "CList.hpp"
#include "IntList.hpp"

#pragma region Previous
/*namespace GP2 {
	A :: trace();
}

struct Vec {
	float x = 0;
	float y = 0;
	float z = 0;
};

struct Vec4 {
	float x;
	float y;
	float z;
	float w;

	Vec4 Add(Vec4 vec){
		Vec4 res;
		res.x = x + vec.x;
		res.y = y + vec.y;
		res.z = z + vec.z;
		res.w = w + vec.w;
		printf("%f %f %f %f\n", res.x, res.y, res.z, res.w);
		return res;
	}

	void Incr() {
		Vec4 res;
		x = x + 1;
		y = y + 1;
		z = z + 1;
		w = w + 1;
		printf("%f %f %f %f\n", x, y, z, w);
	}

	Vec4 Div(Vec4 vec) {
		Vec4 res;
		res.x = x / vec.x;
		res.y = y / vec.y;
		res.z = z / vec.z;
		res.w = w / vec.w;
		printf("%f %f %f %f\n",res.x, res.y, res.z, res.w);
		return res;
	}

};

int Strlen(const char* chaine) {
	int res = 0;
	while (chaine[res] != 0) {
		res = res + 1;
	}
	return res;
}

int Countc(const char* maChaine, char c) {
	int res = 0;
	int len = Strlen(maChaine);

	for (int i = 0; i < len; i++)
	{
		if (maChaine[i] == c) {
			res = res + 1;
		}
	}

	return res;
}

void Strcpy(char* chain, const char* cpy) {
	int len = Strlen(cpy);
	for (int i = 0; i < len; i++){
		chain[i] = cpy[i];
	}
	chain[len] = 0;
}

void StrcpyHard(char* chain, const char* cpy) {
	while (*cpy) {
		*chain = *cpy;
		chain++;
		cpy++;
	}
	*chain = 0;
}

void Strncpy(char* chain, const char* cpy, int len) {
	for (int i = 0; i < len; i++) {
		chain[i] = cpy[i];
	}
}
void StrncpyHard(char* chain, const char* cpy, int len) {
	while (len-- && *cpy) {
		*chain = *cpy;
		chain++;
		cpy++;
	}
	*chain = 0;
	while (*cpy && len) {
		*chain = *cpy;
		chain++;
		cpy++;
		len--;
	}
	*chain = 0;
}*/
#pragma endregion



int main()
{
#pragma region Previous
	/*std::cout << "Hello World!\n";
	printf("0 \n");
	printf("0.5f \n");
	printf("%s \n","toto");

	for (int j = 0; j < 2; j++)
	{
		for (int i = 1; i < 10; i++)
		{
			printf("%d", i);
		}
	}
	printf("0\n");

	Toto tStatic;

	printf("%f",tStatic.x);

	//Toto*
	return 0;
	int tab[] = { 0,1,2,3 };

	int * c = &tab[0];

	*c = 0;

	printf("%d", ++*c);

	Vec* toto = new Vec();

	toto->x = 1;
	(*toto).y = 2;

	printf("%f %f", (*toto).x, toto->y);

	Vec4 vec1;
	vec1.x = 3;
	vec1.y = 6;
	vec1.z = 9;
	vec1.w = 12;

	Vec4 vec2;
	vec2.x = 1;
	vec2.y = 2;
	vec2.z = 3;
	vec2.w = 4;
	
	//vec2.Incr();
	//Vec4 res = vec1.Add(vec2);
	Vec4 res = vec1.Div(vec2);

	//int* arrData = nullptr;
	IntArray arr(16);
	//arrData = arr.data;
	for (int i = 0; i < 16; i++)
	{
		arr.set(i, i * i);
	};
	for (int i = 0; i < 16; i++)
	{
		printf("%d ", arr.get(i));
	};
	printf("\n");

	arr.get(17);*/
	/*int nbA = Countc("sapin", 'a');
	printf("nombre de a:%d\n", nbA);

	int nbB = Countc("alphabet", 'a');
	printf("nombre de a:%d\n", nbB);

	int nbC = Countc("banane", 'n');
	printf("nombre de n:%d\n", nbC);

	char str1[] = "oui";
	char str2[] = "non";

	printf("%s %s\n", str1, str2);

	Strncpy(str2, str1 , 1);

	printf("%s %s\n",str1, str2);

	CList LinkedList;

	LinkedList.first->value = 0;
	Node nod = *LinkedList.first;

	for (int i = 2; i < 10; i++) {
		Node* next = new Node();
		next->value = i;
		nod.next = next;
		LinkedList.AddLast(next);
		nod = *next;
	}

	LinkedList.Print();*/
	/*BTree BinaryTree;

	for (int i = 0; i < 10; i++) {
		Node* nod = new Node();
		nod->value = i;
		BinaryTree.Add(nod);
	}*/
	/*IntArray toto(16);
	toto.resize(18);

	for (int i = 0; i < 18; i++) {
		toto.set(i, i);
	}
	toto.insertAt(3, 25);
	toto.qsort();
	toto.print();*/
#pragma endregion

	IntList * tata = (IntList*)malloc(sizeof(IntList));
	tata->value = 70;
	tata->next = nullptr;

	if (length(tata) != 1) throw "alarm?";
	if (length(0) != 0) throw "alarm?";

	tata = appendFirst(tata, 66);
	IntList* t0 = appendLast(nullptr, 67);
	IntList* t1 = appendLast(t0, 68);
	IntList* t2 = appendLast(t1, 69);
	t2 = appendLast(t2, 70);
	
	t2 = remove(t2, 68);

	return 0;
}
