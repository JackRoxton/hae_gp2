// appcours1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "IntArray.hpp"
#include "BTree.hpp"
//#include "CList.hpp"


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


int Countc(const char* maChaine, char c) {
	//renvoie le nombre d'occurences de c dans ma chaine
	//(maChaine est un tableau de char)
	//parcourir le tableau
	//si l'élément à l'idx courant = c incrémenter le résultat
	//renvoyer le résultat
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
	for (int i = 0; i <= len; i++){
		chain[i] = cpy[i];
	}
}

void Strncpy(char* chain, const char* cpy, int len) {
	for (int i = 0; i < len; i++) {
		chain[i] = cpy[i];
	}
}*/

int Strlen(const char* chaine) {
	int res = 0;
	while (chaine[res] != 0) {
		res = res + 1;
	}
	return res;
}

int main()
{
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

	BTree BinaryTree;

	for (int i = 0; i < 10; i++) {
		Node* nod = new Node();
		nod->value = i;
		BinaryTree.Add(nod);
	}

	return 0;
}
