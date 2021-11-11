#include "morpion.h" 


void Color(WORD Attributes) {    // fonction d'affichage de couleurs
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, Attributes);
}