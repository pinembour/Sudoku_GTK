#ifndef SUDOKU_H
#define SUDOKU_H

//Structure contenant la position actuelle dans la grille et la valeur à ajouter
struct Pos{
	int i;
	int j;
	int val;
};


// prototypes des fonctions
void quitter();

void bienvenue();
void ecrireVal();
void valeursPossible();
int testerValeurs(int, int, int);
void verifierValeurs();

int colonne(int);
int ligne(int);
int carre(int);

int valeurs[9][9]; //Variable globale pour sauvegarder les valeurs du sudoku
GtkWidget *tableau[9][9];

#endif
