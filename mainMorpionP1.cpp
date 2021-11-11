#include "morpion.h"

int l_tabInt_morpion[TAILLE] = { 0,0,0,0,0,0,0,0,0 };				//déclaration du tableau qui nous servira de morpion
int l_int_joueur = 0;				//joueur qui joue
int l_int_input = 0;				//variable d'entree
int iBcl = 0;						//variable de boucle
int l_int_temp = 0;					//variable de temporisation
int l_int_gagne = 0;				//variable retournant le gagnant
int l_int_cpt = 0;					//compteur pour jouer chacun son tour
int l_int_cpt2 = 0;					//compteur pour voir si la grille est complète

//jeu normal
void jeu1(void) {

	//instructions
	do {
		
		//choix du joueur qui doit jouer
		l_int_joueur = (l_int_cpt % 2) + 1;

		system("CLS");				//permet d'effacer le contenu de la console

		//mise en place du tableau du morpion
		afficheLigne();
		afficheValeur(l_tabInt_morpion[6]);
		afficheValeur(l_tabInt_morpion[7]);
		afficheValeur(l_tabInt_morpion[8]);
		afficheLigne();
		afficheValeur(l_tabInt_morpion[3]);
		afficheValeur(l_tabInt_morpion[4]);
		afficheValeur(l_tabInt_morpion[5]);
		afficheLigne();
		afficheValeur(l_tabInt_morpion[0]);
		afficheValeur(l_tabInt_morpion[1]);
		afficheValeur(l_tabInt_morpion[2]);
		afficheLigneBis();

		//saisie utilisateur
		printf("Joueur %i joue\n", l_int_joueur);
		scanf("%i", &l_int_input);

		//vérification des cases existantes et libre
		if ((l_int_input <= 9) && (l_int_input > 0) && (l_tabInt_morpion[l_int_input - 1] != 1) && (l_tabInt_morpion[l_int_input - 1] != 2)) {
			if (l_int_joueur == 1) {
				l_tabInt_morpion[l_int_input - 1] = 1;
			}
			else{
				l_tabInt_morpion[l_int_input - 1] = 2;
			}
		}
		else {
			l_int_cpt2--;				//décrémentation du compteur 2
		}

		l_int_temp = 0;				//réinitialisation de la temporisation

		//Calcul Lignes
		for (iBcl = 0; iBcl < TAILLE; iBcl = iBcl + 3) {
			l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 1] * l_tabInt_morpion[iBcl + 2];
			if (l_int_temp == 1) {
				l_int_gagne = 1;
			}
			else if (l_int_temp == 8) {
				l_int_gagne = 2;
			}
			else {}
		}

		//Calcul Colones
		for (iBcl = 0; iBcl < 3; iBcl++) {
			l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 3] * l_tabInt_morpion[iBcl + 6];
			if (l_int_temp == 1) {
				l_int_gagne = 1;
			}
			else if (l_int_temp == 8) {
				l_int_gagne = 2;
			}
			else {}
		}

		//Calcul Diagonales
		for (iBcl = 0; iBcl < 3; iBcl = iBcl + 2) {
			if (iBcl == 0) {
				l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 4] * l_tabInt_morpion[iBcl + 8];
			}
			else {
				l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 2] * l_tabInt_morpion[iBcl + 4];
			}
			if (l_int_temp == 1) {
				l_int_gagne = 1;
			}
			else if (l_int_temp == 8) {
				l_int_gagne = 2;
			}
			else {}
		}

		l_int_cpt++;
		l_int_cpt2++;

	} while ((l_int_cpt2 < 9) && (l_int_gagne != 1) && (l_int_gagne != 2));				//condition lors d'un gagnant ou d'un match nul ou lorsqu'il y n'y a plus de place
}

//enlevement de case
void jeu2(void) {

	//reservation option 2
	int l_int_enlever = 0;				//variable du tirage aléatoire

	//instructions
	srand(time(NULL));				//fonction pour avoir un réel aléatoire
	do {

		//choix du joueur qui doit jouer
		l_int_joueur = (l_int_cpt % 2) + 1;

		system("CLS");				//permet d'effacer le contenu de la console

		//mise en place du tableau du morpion
		afficheLigne();
		afficheValeur(l_tabInt_morpion[6]);
		afficheValeur(l_tabInt_morpion[7]);
		afficheValeur(l_tabInt_morpion[8]);
		afficheLigne();
		afficheValeur(l_tabInt_morpion[3]);
		afficheValeur(l_tabInt_morpion[4]);
		afficheValeur(l_tabInt_morpion[5]);
		afficheLigne();
		afficheValeur(l_tabInt_morpion[0]);
		afficheValeur(l_tabInt_morpion[1]);
		afficheValeur(l_tabInt_morpion[2]);
		afficheLigneBis();

		//saisie utilisateur
		printf("Joueur %i joue\n", l_int_joueur);
		scanf("%i", &l_int_input);

		//vérification des cases existantes et libre
		if ((l_int_input <= 9) && (l_int_input > 0) && (l_tabInt_morpion[l_int_input - 1] != 1) && (l_tabInt_morpion[l_int_input - 1] != 2)) {
			if (l_int_joueur == 1) {
				l_tabInt_morpion[l_int_input - 1] = 1;
			}
			else if (l_int_joueur == 2) {
				l_tabInt_morpion[l_int_input - 1] = 2;
			}
			else {}
		}
		else {}


		//Calcul Lignes :
		l_int_temp = 0;
		for (iBcl = 0; iBcl < TAILLE; iBcl = iBcl + 3) {
			l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 1] * l_tabInt_morpion[iBcl + 2];
			if (l_int_temp == 1) {
				l_int_gagne = 1;
			}
			else if (l_int_temp == 8) {
				l_int_gagne = 2;
			}
			else {}
		}

		//Calcul Colones
		for (iBcl = 0; iBcl < 3; iBcl++) {
			l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 3] * l_tabInt_morpion[iBcl + 6];
			if (l_int_temp == 1) {
				l_int_gagne = 1;
			}
			else if (l_int_temp == 8) {
				l_int_gagne = 2;
			}
			else {}
		}

		//Calcul Diagonales
		for (iBcl = 0; iBcl < 3; iBcl = iBcl + 2) {
			if (iBcl == 0) {
				l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 4] * l_tabInt_morpion[iBcl + 8];
			}
			else {
				l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 2] * l_tabInt_morpion[iBcl + 4];
			}
			if (l_int_temp == 1) {
				l_int_gagne = 1;
			}
			else if (l_int_temp == 8) {
				l_int_gagne = 2;
			}
			else {}
		}

		//Option 2 : effacement aléatoire d'une case de la grille
		if((l_int_gagne != 1) && (l_int_gagne != 2)) {
			l_int_enlever = rand() % 9;				//tirage aléatoire de 0 à 8
			l_tabInt_morpion[l_int_enlever] = 0;
		}

		l_int_cpt++;			//incrémentation du compteur 1


		//Arrêtez le programme
		for (iBcl = 0; iBcl < TAILLE; iBcl++) {
			if ((l_tabInt_morpion[iBcl] == 1) || (l_tabInt_morpion[iBcl] == 2)) {
				l_int_cpt2++;
			}
		}


		if (l_int_cpt2 < 9) {		
			l_int_cpt2 = 0;
		}

	} while ((l_int_cpt2 < 9) && (l_int_gagne != 1) && (l_int_gagne != 2));//condition lors d'un gagnant ou d'un match nul ou lorsqu'il y n'y a plus de place
}

//temps limite
void jeu3(void) {

	//reservations option 3:
	int l_int_ms = 0;				//temps sauvegarde au depart du boucle
	int l_int_ms2 = 0;				//temps sauvegarde dans la boucle

	do {

		//choix du joueur qui doit jouer
		l_int_joueur = (l_int_cpt % 2) + 1;


		system("CLS");				//permet d'effacer le contenu de la console

		//mise en place du tableau du morpion
		afficheLigne();
		afficheValeur(l_tabInt_morpion[6]);
		afficheValeur(l_tabInt_morpion[7]);
		afficheValeur(l_tabInt_morpion[8]);
		afficheLigne();
		afficheValeur(l_tabInt_morpion[3]);
		afficheValeur(l_tabInt_morpion[4]);
		afficheValeur(l_tabInt_morpion[5]);
		afficheLigne();
		afficheValeur(l_tabInt_morpion[0]);
		afficheValeur(l_tabInt_morpion[1]);
		afficheValeur(l_tabInt_morpion[2]);
		afficheLigneBis();

		printf("Joueur %i joue\n", l_int_joueur);

		l_int_ms = GetTickCount();
		l_int_ms2 = GetTickCount();

		l_int_input = 0;

		do {
			l_int_input = kbhit();
			//if (((GetTickCount() - l_int_ms2) <= 1000) == 0) {
				//beep(0,1000);
			//	l_int_ms2 = GetTickCount();

			//}
		} while (((GetTickCount() - l_int_ms) <= 3000) && (l_int_input == 0));

		if (l_int_input == 1) {

			l_int_cpt2++;
			scanf("%i", &l_int_input);

			//vérification des cases existantes et libre
			if ((l_int_input <= 9) && (l_int_input > 0) && (l_tabInt_morpion[l_int_input - 1] != 1) && (l_tabInt_morpion[l_int_input - 1] != 2)) {
				if (l_int_joueur == 1) {
					l_tabInt_morpion[l_int_input - 1] = 1;
				}
				else if (l_int_joueur == 2) {
					l_tabInt_morpion[l_int_input - 1] = 2;
				}
				else {}
			}
			else {
				l_int_cpt2--;
			}
		}
		else {}

		//Calcul Lignes :
		l_int_temp = 0;
		for (iBcl = 0; iBcl < TAILLE; iBcl = iBcl + 3) {
			l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 1] * l_tabInt_morpion[iBcl + 2];
			if (l_int_temp == 1) {
				l_int_gagne = 1;
			}
			else if (l_int_temp == 8) {
				l_int_gagne = 2;
			}
			else {}
		}

		//Calcul Colones
		for (iBcl = 0; iBcl < 3; iBcl++) {
			l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 3] * l_tabInt_morpion[iBcl + 6];
			if (l_int_temp == 1) {
				l_int_gagne = 1;
			}
			else if (l_int_temp == 8) {
				l_int_gagne = 2;
			}
			else {}
		}

		//Calcul Diagonales
		for (iBcl = 0; iBcl < 3; iBcl = iBcl + 2) {
			if (iBcl == 0) {
				l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 4] * l_tabInt_morpion[iBcl + 8];
			}
			else {
				l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 2] * l_tabInt_morpion[iBcl + 4];
			}
			if (l_int_temp == 1) {
				l_int_gagne = 1;
			}
			else if (l_int_temp == 8) {
				l_int_gagne = 2;
			}
			else {}
		}

		l_int_cpt++;

	} while ((l_int_cpt2 < 10) && (l_int_gagne != 1) && (l_int_gagne != 2) && (l_int_temp < 10));			//condition lors d'un gagnant ou d'un match nul ou lorsqu'il y n'y a plus de place
}

void main(void) {

	//Reservations :
	int l_int_choix = 0;

	//Instructions :

	//Choix du mode de jeu
	printf("Veuillez choisir votre mode de jeu :\n1 : jeu normal\n2 : enlevement de case\n3 : temps limite\n");
	scanf("%i", &l_int_choix);
	switch(l_int_choix){
	case 1:				//jeu normal
		jeu1();
		break;
	case 2:				//enlevement de case
		jeu2();
		break;
	case 3:				//temps limite
		jeu3();
		break;
	default:
		printf("Choix non reconnu.");
	}

	system("CLS");
	afficheLigne();
	afficheValeur(l_tabInt_morpion[6]);
	afficheValeur(l_tabInt_morpion[7]);
	afficheValeur(l_tabInt_morpion[8]);
	afficheLigne();
	afficheValeur(l_tabInt_morpion[3]);
	afficheValeur(l_tabInt_morpion[4]);
	afficheValeur(l_tabInt_morpion[5]);
	afficheLigne();
	afficheValeur(l_tabInt_morpion[0]);
	afficheValeur(l_tabInt_morpion[1]);
	afficheValeur(l_tabInt_morpion[2]);
	afficheLigneBis();

	if (l_int_gagne == 1) {
		printf("JOUEUR 1 GAGNANT");
	}

	else if (l_int_gagne == 2) {
		printf("JOUEUR 2 GAGNANT");
	}

	else {
		printf("MATCH NUL");
	}
}