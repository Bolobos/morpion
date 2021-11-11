#include "morpion.h"
using namespace std;											//pour les couleurs
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);				//pour les couleurs


void afficheLigne(void) {
	cprintf("\n +---+---+---+\n | ");
}
void afficheValeur(int x_int_code) {
	if (x_int_code == 1) {
		SetConsoleTextAttribute(hConsole, 10);
		printf("X");
		SetConsoleTextAttribute(hConsole, 7);
		printf(" | ");
	}
	else if (x_int_code == 2) {
		SetConsoleTextAttribute(hConsole, 12);
		printf("O");
		SetConsoleTextAttribute(hConsole, 7);
		printf(" | ");
	}
	else{
		printf("  | ");
	}
}
void afficheLigneBis(void) {
	printf("\n +---+---+---+\n ");
}

int verifie(int x_tabInt_jeuATester[]) {
	int l_int_retVal = 0;
	int l_int_gagne = 0;
	bool l_bool_gagne = 0;
	int iBcl = 0;
	int iBcl2 = 0;
	int l_tabInt_comp[24] = { 0,1,2,3,4,5,6,7,8,0,3,6,1,4,7,2,5,8,0,4,8,2,4,6 };
	for (iBcl = 0; iBcl < 24; iBcl = iBcl + 3) {
		l_int_gagne = 1;
		for (iBcl2 = 0; iBcl2 < 3; iBcl2++) {
			l_int_gagne = x_tabInt_jeuATester[l_tabInt_comp[iBcl + iBcl2]] * l_int_gagne;
		}
		if ((l_int_gagne == 1)) {
			l_int_retVal = 1;
		}
		else if (l_int_gagne == 8) {
			l_int_retVal = 2;
		}
	}
	if (l_int_retVal == 0) {
		l_int_gagne = 1;
		for (iBcl = 0; iBcl < 9; iBcl++) {
			l_int_gagne = x_tabInt_jeuATester[iBcl] * l_int_gagne;
		}
		if (l_int_gagne != 0) {
			l_int_retVal = -1;
		}
	}
	return l_int_retVal;
}