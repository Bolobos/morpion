#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <dos.h>


#define TAILLE 9

void afficheLigne(void);					//affichage dans la console de la ligne qui va constituer les lignes de la grille
void afficheValeur(int x_int_code);			//affichage dans la console de chaque valeur selon une valeur d'entree
void afficheLigneBis(void);					//affichage dans la console de la derni�re ligne 
int verifie(int x_tabInt_jeuATester[]);		//fonction donn�e par l'ennonc� qui va retourner une valeur qui indiquera l'etat du jeu

void Color(WORD Attributes);
