// cours 1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "IntArray.hpp"

/*void Memcpy(char* dst, const char* src, int len) {
	for (int i = 0; i < len; i++) {
		dst[i] = src[i];
	}
}

const char * StrChr(const char* grange, char chat) {
	while (*grange) {
		if (*grange == chat) {
			return grange;
		}
		grange++;
	}
	return nullptr;
};

const char * StrStr(const char * meuleDeFoin, const char * aiguille) {
	int len = std::strlen(aiguille);
	bool flag;

	while (*meuleDeFoin) {
		flag = false;
		for (int i = 0; i < len; i++) {
			if (aiguille[i] != meuleDeFoin[i]) {
				meuleDeFoin++;
				flag = true;
				break;
			}
		}
		if (!flag) {
			return meuleDeFoin;
		}
	}
	return nullptr;
};*/

int add(int a, int b) {
	if (b == 0) {
		return a;
	}

	if(b>0){
		return 1+ add(a, b - 1);
	}
	else {
		return -1+ add(a, b + 1);
	}

};

int addEx(int a, int b,int tmp) {
	if (b == 0) {
		return a + tmp;
	}

	return 1 + addEx(a, b - 1, 1 + tmp);
};


int sub(int a, int b) {
	return add(a, -b);
};

int mul(int a, int b) {
	if (b == 0 || a == 0) {
		return 0;
	}

	if (b < 0) {
		return -mul(a, -b);
	}
	else {
		return add(a, mul(a, b - 1));
	}
};

int mulEx(int a, int b, int tmp) {
	if (b == 0 || a == 0) {
		return tmp;
	}

	if (b < 0) {
		return mulEx(-a, -b,tmp);
	}
	else {
		return mulEx(a, b - 1,tmp+a);
	}
};

int divi(int a, int b) {

	if (a == 0) {
		return 0;
	}
	if (b == 0) {
		return 0;
	}
	if (b == 1) {
		return a;
	}


	if (a < 0)   return  sub(0, divi(sub(0, a), b));
	if (a < b) {
		return 0;
	}

	return 1 + divi(sub(a,b), b);
};

int diviEx(int a, int b, int tmp) {

	if (a == 0) {
		return tmp;
	}
	if (b == 0) {
		return 0;
	}
	if (b == 1) {
		return a + tmp;
	}

	if (a < 0) {
		return tmp;
	}
	if (a < b) {
		return tmp;
	}

	return diviEx(sub(a, b), b,tmp+1);
};

int mod(int a, int b) {
	/*if (a == 0) {
		return 0;
	}
	if (b == 0) {
		return 0;
	}

	if (a >= b) {
		return mod(sub(a, b),b);
	}
	else if(a<0){
		return - mod(sub(-a,b),b);
	}
	else {
		return a;
	}*/

	return a - divi(a, b)*b;
};

/*int powe(int a, int coeff) {
	if (coeff > 1) {
		return 0;//powe(mul(a, a),coeff-1);
	}
	else if(coeff == 0){
		return a;
	}
}

int squr(int a) {
	return powe(a,0.5);
}*/

int len(int vecX, int vecY) {
	return (add(vecX, vecY));
};

int Strlen(const char* a) {
	if (!*a) {
		return *a;
	}
	a += 1;
	return 1 + Strlen(a);
}

void Strcpy(char* a, const char* b) {
	if (!*b) {
		return;
	}
	*a = *b;
	return Strcpy(a+1, b+1);
}

void Strncpy(char* a, const char* b, int nChr) {
	if (nChr <= 0) {
		return;
	}
	*a = *b;
	return Strncpy(a+1, b+1, nChr-1);
}

void ZeroMemory(void* ptr, int nByt) { 
	if (nByt <= 0) {
		return;
	}
	char* mem = (char*)ptr;
	mem[0] = 0;
	ZeroMemory(mem + 1, nByt - 1);
}

void Memcpy(void* dst, const void* src, int nByt) {
	if (nByt <= 0) {
		return;
	}
	char* mDst = (char*)dst;
	const char* mSrc = (const char*)src;
	mDst[0] = mSrc[0];
	Memcpy(mDst + 1, mSrc + 1, nByt - 1);
}

const char* StrChr(const char* a, char b) {
	if (a == nullptr) {
		return nullptr;
	}
	if (!*a) {
		return 0;
	}
	if (*a == b) {
		return a;
	}
	return StrChr(a + 1, b);
}

bool IsPrefix(const char* a, const char* b) {
	if (a == nullptr || b == nullptr) {
		return false;
	}
	if (b[0] == 0) {
		return true;
	}
	if (a[0] == b[0]) {
		return IsPrefix(a + 1, b + 1);
	}
	return false;
}

const char* StrStr(const char* a, const char* b) {
	if (a == nullptr || b == nullptr) {
		return nullptr;
	}
	if (!*a||!*b) {
		return 0;
	}
	if (IsPrefix(a,b)) {
		return a;
	}
	return StrStr(a + 1, b);
}

char* FindEnd(char* a) {
	if (a[0] != 0) {
		return FindEnd(a + 1);
	}
	return a;
}

char* StrCat(char* a, const char* b) {
	if (a == nullptr || b == nullptr) {
		return nullptr;
	}
	char* end = FindEnd(a);
	Strcpy(end, b);
	return a;
}

bool StrCmp(const char* a, const char* b) {
	if (a == nullptr || b == nullptr) {
		throw "non";
	}
	if (a[0] == 0 && b[0] == 0) {
		return 0;
	}
	if (b[0] > a[0]) {
		return -1;
	}
	if (a[0] > b[0]) {
		return 1;
	}
	if (a[0] == b[0]) {
		return StrCmp(a + 1, b + 1);
	}
}


int main()
{
	/*int list[150]; static
	int * toto = malloc(150*sizeof(int)); dynamic
	int * toto = new int[150]; dynamic*/
	IntArray arr(150);

	for (int i = 0; i < 150; i++) {
		arr.set(i,i*i);
	}

	/*std::function<void(int)> foo = [](int val) {
		printf("%d\n",val);
	};
	arr.iter(foo);
	
	int s[4] = { 0,1,2,3 };
	IntArray* maCopie = IntArray::fromArray(s,4);
	maCopie->print();

	int s[4] = { 0,0,0,0 };
	int t[4] = { 0,1,2,3 };

	Memcpy((char*)s, (char*)t, 4 * sizeof(int));
	printf("%s", s);

	const char* toto = StrStr("dormir", "mir");*/
	/*int toto = add(3, 5);
	int tata = sub(3, 5);
	int tutu = mul(3, 5);
	int tete = divi(6, 3);
	int titi = mod(8, 3);
	int tyty = len(4, 5);*/
	/*int toto = Strlen("toto");
	int tota = Strlen("bonjour");
	char tata[4] = "oui";
	char tato[4] = "non";
	Strcpy(tata, tato);
	Strncpy(tata, tato, 1);
	char tutu[14] = "quelque chose";
	ZeroMemory(tutu, 256);
	char tuto[12] = "je sais pas";
	Memcpy(tutu, tuto, 6);*/

	const char* toto = "bonjour";
	const char* tota = StrChr(toto, 'o');

	const char* tata = "au revoir";
	const char* tato = StrStr(tata, "revoir");

	char titi[25] = "ah bon ";
	char* tito = StrCat(titi, "bah oui");

	bool tete = StrCmp("oui", "oui") == 0;
	bool tetu = StrCmp("ouI", "oui") == -1;
	bool teto = StrCmp("oui", "ouI") == 1;

	int calcEx = mulEx(9, 3, 0);

	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
