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


int sub(int a, int b) {
	return add(a, -b);
};

int mul(int a, int b) {
	if (b == 0 || a == 0) {
		return 0;
	}
	if (b == 1) {
		return a;
	}

	if (b > 0) {
		return -mul(a, -b);
	}
	else {
		return add(a, mul(a, sub(0,b)));
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
	if (a < b) {
		return 0;
	}

	return 1 + divi(sub(a,b), b);
};
int mod(int a, int b) {

}; // reste de la division

int len(int vecX, int vecY); // avec les fonctions precédentes




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


	int toto = add(3, 5);
	int tata = sub(3, 5);
	//int tutu = mul(3, 5);
	int tete = divi(6, 3);

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
