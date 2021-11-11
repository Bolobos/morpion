#include "morpion.h"

int l_tabInt_morpion[TAILLE] = { 0,0,0,0,0,0,0,0,0 };
int l_int_joueur = 0;					//joueur qui joue
int l_int_input = 0;					//variable d'entree
int iBcl = 0;							//variable de boucle
int l_int_temp = 0;						//variable de temporisation
int l_int_cpt = 0;						//compteur pour jouer chacun son tour
int l_int_cpt2 = 0;						//compteur pour voir si la grille est complète
int l_int_verification = 0;				//variable retournant la situation du jeu (pas fini, gagnant, nul)
int l_int_botrand = 0;					//


//jeu normal (avec l'etat du jeu de base)
void jeu1_1(void) {

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
			else {
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
				l_int_verification = 1;
			}
			else if (l_int_temp == 8) {
				l_int_verification = 2;
			}
			else {}
		}

		//Calcul Colones
		for (iBcl = 0; iBcl < 3; iBcl++) {
			l_int_temp = l_tabInt_morpion[iBcl] * l_tabInt_morpion[iBcl + 3] * l_tabInt_morpion[iBcl + 6];
			if (l_int_temp == 1) {
				l_int_verification = 1;
			}
			else if (l_int_temp == 8) {
				l_int_verification = 2;
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
				l_int_verification = 1;
			}
			else if (l_int_temp == 8) {
				l_int_verification = 2;
			}
			else {}
		}

		l_int_cpt++;
		l_int_cpt2++;

	} while ((l_int_cpt2 < 9) && (l_int_verification != 1) && (l_int_verification != 2));				//condition lors d'un gagnant ou d'un match nul ou lorsqu'il y n'y a plus de place
}

//enlevement de case
void jeu1_2(void) {

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

		//Option 2 : effacement aléatoire d'une case de la grille
		if ((l_int_verification != 1) && (l_int_verification != 2)) {
			l_int_enlever = rand() % 9;				//tirage aléatoire de 0 à 8
			l_tabInt_morpion[l_int_enlever] = 0;
		}

		l_int_verification = verifie(l_tabInt_morpion);				//verification de la situation du jeu (gagnant, match nul, ou partie pas finie)

		l_int_cpt++;			//incrémentation du compteur 1

	} while (l_int_verification == 0);				//condition lors d'un gagnant ou d'un match nul ou lorsqu'il y n'y a plus de place
}

//temps limite
void jeu1_3(void) {

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
			else{}
		}
		else {}

		l_int_verification = verifie(l_tabInt_morpion);				//verification de la situation du jeu (gagnant, match nul, ou partie pas finie)

		l_int_cpt++;

	} while (l_int_verification == 0);			//condition lors d'un gagnant ou d'un match nul ou lorsqu'il y n'y a plus de place
}

//BOT aléatoire
void jeu2_1(void) {

	srand(time(NULL));				//fonction pour un tirage al�atoire en fonction du temps (vrai aleatoire)
	
	do {

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
		printf("Joueur 1 joue\n");
		scanf("%i", &l_int_input);

		//v�rification des cases existantes et libre
		if ((l_int_input <= 9) && (l_int_input > 0) && (l_tabInt_morpion[l_int_input - 1] != 1) && (l_tabInt_morpion[l_int_input - 1] != 2)) {
			l_tabInt_morpion[l_int_input - 1] = 1;
			
		}
		else {
			l_int_cpt--;					//decrementation du compteur
		}

		//IA
		if (l_int_cpt < 8) {
			
			do {
				l_int_botrand = rand() % 9;								//tirage aleatoire de 0 a 8
			} while (l_tabInt_morpion[l_int_botrand] != 0);				//ici do while meilleur que while 
			l_tabInt_morpion[l_int_botrand] = 2;						//ecriture sur le programme
		}

		l_int_verification = verifie(l_tabInt_morpion);				//verification de la situation du jeu (gagnant, match nul, ou partie pas finie)

		l_int_cpt = l_int_cpt + 2;				//incr�mentation de 2 car le joueur et l'IA est compte

	} while (l_int_verification == 0);				//condition lors d'un gagnant ou d'un match nul ou lorsqu'il y n'y a plus de place
}

//BOT intelligent
void jeu2_2(void) {
	
	//r�servations :
	int l_int_test = 0;				//variable de temporisation pour tester les differentes possibilites a chaque tour
	int l_int_case = -1;

	//instructions :
	srand(time(NULL));				//fonction pour un tirage al�atoire en fonction du temps (vrai aleatoire)

	do {

		system("CLS");				//permet d'effacer le contenu de la console

		//mise en place de la grille du morpion
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
		printf("Joueur 1 joue\n");
		scanf("%i", &l_int_input);

		//v�rification des cases existantes et libre
		if ((l_int_input <= 9) && (l_int_input > 0) && (l_tabInt_morpion[l_int_input - 1] != 1) && (l_tabInt_morpion[l_int_input - 1] != 2)) {

			l_tabInt_morpion[l_int_input - 1] = 1;

		}
		//CALCUL DE l_int_verification si joueur gagne ( pour ne pas rester coincer dans la boucle do while de fin avec l'al�atoire)
		l_int_verification = verifie(l_tabInt_morpion);

		
		if ((l_int_verification != -1) && (l_int_verification != 1) && (l_int_verification != 2)) {
			
			//IA
			l_int_case = -1;				//reinitialisation de la valeur de l_int_case 

			//Test chance de gagner
			//(dans l'ennonce il etait mis de mettre le risque de perdre avant la chance de gagner mais l'IA est bien plus "intelligente" car vu qu'elle joue apr�s le joueur, elle gagnera � coup s�r au lieu de parer le coup du joueur apr�s)

			//boucle for pour tester chaque position du prochain coup de l'IA (imminent)
			for (iBcl = 0; iBcl < TAILLE; iBcl++) {

				if (l_tabInt_morpion[iBcl] == 0) {
					l_tabInt_morpion[iBcl] = 2;
					l_int_test = verifie(l_tabInt_morpion);
					l_tabInt_morpion[iBcl] = 0;
				}
				else {}

				//sauvegarde la case associ�e � la valeur de la case pour la jouer au tour (juste apr�s)
				if (l_int_test == 2) {
					l_int_case = iBcl;
				}
				l_int_test = 0;
			}

			//ecriture dans le tableau de l'IA
			if (l_int_case > -1) {
				l_tabInt_morpion[l_int_case] = 2;
			}

			//Sinon : Test risque de perdre
			else {
				for (iBcl = 0; iBcl < TAILLE; iBcl++) {
					if (l_tabInt_morpion[iBcl] == 0) {
						l_tabInt_morpion[iBcl] = 1;
						l_int_test = verifie(l_tabInt_morpion);
						l_tabInt_morpion[iBcl] = 0;
					}
					else {}
					if (l_int_test == 1) {
						l_int_case = iBcl;
					}
					l_int_test = 0;

				}

				//ecriture dans le tableau de l'IA
				if (l_int_case > -1) {
					l_tabInt_morpion[l_int_case] = 2;
				}

				//sinon du sinon : Tirage aleatoire de 0 a 8
				//il n'y a aucune chance que l'un des 2 joueurs gagne ou perdre, donc tirage aleatoire
				else {
					do {
						l_int_botrand = rand() % 9;
					} while (l_tabInt_morpion[l_int_botrand] != 0);				//ici do while meilleur que while !
					l_tabInt_morpion[l_int_botrand] = 2;						//ecriture dans le tableau de l'IA
				}
			}

		}
		
		//CALCUL DE VERIF (si ia gagne ou le joueur complete la derniere case avec un match nul)
		l_int_verification = verifie(l_tabInt_morpion);


	} while (l_int_verification == 0);				//condition lors d'un gagnant ou d'un match nul ou lorsqu'il y n'y a plus de place
}

void main(void) {
	//Reservations :
	int l_int_choix = 0;
	int l_int_choix2 = 1;

	//Instructions :

	//Choix du mode de jeu
	printf("Veuillez choisir votre mode de jeu :\n1 : joueur contre joueur\n2 : joueur contre BOT\n");
	scanf("%i", &l_int_choix);
	switch (l_int_choix) {
	case 1:		
		system("CLS");
		printf("Veuillez choisir votre mode de jeu :\n1 : mode normal\n2 : enlevement de case\n3 : temps limite");
		scanf("%i", &l_int_choix);
		switch (l_int_choix){				//joueur contre joueur
		case 1:
			jeu1_1();
			break;
		case 2:
			jeu1_2();
			break;
		case 3:
			jeu1_3();
			break;
		default:
			printf("Choix non reconnu.");
			break;
		}
		break;
	case 2:						//enlevement de case
		l_int_choix2 = 0;
		system("CLS");
		printf("Type de BOT :\n1 : Mode A (BOT aleatoire)\n2 : Mode B (BOT intelligent)\n");
		scanf("%i", &l_int_choix);
		switch (l_int_choix) {
		case 1 :				//BOT al�atoire
			jeu2_1();
			break;
		case 2 :				//BOT intelligent
			jeu2_2();
			break;
		default :
			printf("Choix non reconnu.");
		}
		break;
	default:
		printf("Choix non reconnu.");
	}

	//affichage grille finale
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

	//affichage resultat
	if (l_int_verification == 1) {
		printf("JOUEUR 1 GAGNANT(E)");
	}

	else if (l_int_verification == 2) {
		if (l_int_choix2) {					//condition pour savoir qui gagne si ce n'est pas le joueur 1 (IA ou joueur 2)
			printf("L'IA EST GAGNANTE");
		}
		else {
			printf("Le JOUEUR 2 GAGNANT(E)");
		}
	}

	else {
		printf("MATCH NUL");
	}
}