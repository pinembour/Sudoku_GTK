#include <gtk/gtk.h> //Header de GTK+ 
#include <stdio.h>
#include "sudoku.h"
#include "tables.h"
#include "itoa.h"

void table3(){
	//3ème table de sudoku ecrite en dur.
	gtk_entry_set_text( GTK_ENTRY(tableau[0][0]), ITOA(1) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][0]), ITOA(3) );
	gtk_entry_set_text( GTK_ENTRY(tableau[2][1]), ITOA(7) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][1]), ITOA(2) );
	gtk_entry_set_text( GTK_ENTRY(tableau[4][1]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[6][1]), ITOA(4) );
	gtk_entry_set_text( GTK_ENTRY(tableau[7][1]), ITOA(8) );
	gtk_entry_set_text( GTK_ENTRY(tableau[0][2]), ITOA(4) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][2]), ITOA(9) );
	gtk_entry_set_text( GTK_ENTRY(tableau[4][2]), ITOA(3) );
	gtk_entry_set_text( GTK_ENTRY(tableau[5][2]), ITOA(5) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][2]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[1][3]), ITOA(3) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][3]), ITOA(4) );
	gtk_entry_set_text( GTK_ENTRY(tableau[4][3]), ITOA(8) );
	gtk_entry_set_text( GTK_ENTRY(tableau[6][3]), ITOA(2) );
	gtk_entry_set_text( GTK_ENTRY(tableau[1][4]), ITOA(4) );
	gtk_entry_set_text( GTK_ENTRY(tableau[2][4]), ITOA(1) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][4]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[5][4]), ITOA(9) );
	gtk_entry_set_text( GTK_ENTRY(tableau[6][4]), ITOA(3) );
	gtk_entry_set_text( GTK_ENTRY(tableau[2][5]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[6][5]), ITOA(8) );
	gtk_entry_set_text( GTK_ENTRY(tableau[7][5]), ITOA(9) );
	gtk_entry_set_text( GTK_ENTRY(tableau[0][6]), ITOA(5) );
	gtk_entry_set_text( GTK_ENTRY(tableau[1][6]), ITOA(7) );
	gtk_entry_set_text( GTK_ENTRY(tableau[2][6]), ITOA(8) );
	gtk_entry_set_text( GTK_ENTRY(tableau[4][6]), ITOA(4) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][6]), ITOA(2) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][7]), ITOA(3) );
	gtk_entry_set_text( GTK_ENTRY(tableau[7][7]), ITOA(7) );
	gtk_entry_set_text( GTK_ENTRY(tableau[0][8]), ITOA(2) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][8]), ITOA(5) );

}

void table2(){
	//2ème table de sudoku ecrite en dur.
	gtk_entry_set_text( GTK_ENTRY(tableau[0][0]), ITOA(5) );
	gtk_entry_set_text( GTK_ENTRY(tableau[1][0]), ITOA(3) );
	gtk_entry_set_text( GTK_ENTRY(tableau[4][0]), ITOA(7) );
	gtk_entry_set_text( GTK_ENTRY(tableau[0][1]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][1]), ITOA(1) );
	gtk_entry_set_text( GTK_ENTRY(tableau[4][1]), ITOA(9) );
	gtk_entry_set_text( GTK_ENTRY(tableau[5][1]), ITOA(5) );
	gtk_entry_set_text( GTK_ENTRY(tableau[1][2]), ITOA(9) );
	gtk_entry_set_text( GTK_ENTRY(tableau[2][2]), ITOA(8) );
	gtk_entry_set_text( GTK_ENTRY(tableau[7][2]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[0][3]), ITOA(8) );
	gtk_entry_set_text( GTK_ENTRY(tableau[4][3]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][3]), ITOA(3) );
	gtk_entry_set_text( GTK_ENTRY(tableau[0][4]), ITOA(4) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][4]), ITOA(8) );
	gtk_entry_set_text( GTK_ENTRY(tableau[5][4]), ITOA(3) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][4]), ITOA(1) );
	gtk_entry_set_text( GTK_ENTRY(tableau[0][5]), ITOA(7) );
	gtk_entry_set_text( GTK_ENTRY(tableau[4][5]), ITOA(2) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][5]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[1][6]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[6][6]), ITOA(2) );
	gtk_entry_set_text( GTK_ENTRY(tableau[7][6]), ITOA(8) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][7]), ITOA(4) );
	gtk_entry_set_text( GTK_ENTRY(tableau[4][7]), ITOA(1) );
	gtk_entry_set_text( GTK_ENTRY(tableau[5][7]), ITOA(9) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][7]), ITOA(5) );
	gtk_entry_set_text( GTK_ENTRY(tableau[4][8]), ITOA(8) );
	gtk_entry_set_text( GTK_ENTRY(tableau[7][8]), ITOA(7) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][8]), ITOA(9) );

}
void table1(){
	//1ere table de sudoku ecrite en dur.
	gtk_entry_set_text( GTK_ENTRY(tableau[0][0]), ITOA(9) );
	gtk_entry_set_text( GTK_ENTRY(tableau[1][0]), ITOA(2) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][0]), ITOA(3) );
	gtk_entry_set_text( GTK_ENTRY(tableau[5][0]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[2][1]), ITOA(1) );
	gtk_entry_set_text( GTK_ENTRY(tableau[4][1]), ITOA(2) );
	gtk_entry_set_text( GTK_ENTRY(tableau[5][1]), ITOA(4) );
	gtk_entry_set_text( GTK_ENTRY(tableau[6][1]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[0][2]), ITOA(5) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][2]), ITOA(1) );
	gtk_entry_set_text( GTK_ENTRY(tableau[1][3]), ITOA(4) );
	gtk_entry_set_text( GTK_ENTRY(tableau[5][3]), ITOA(7) );
	gtk_entry_set_text( GTK_ENTRY(tableau[0][4]), ITOA(1) );
	gtk_entry_set_text( GTK_ENTRY(tableau[2][4]), ITOA(3) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][4]), ITOA(4) );
	gtk_entry_set_text( GTK_ENTRY(tableau[5][4]), ITOA(2) );
	gtk_entry_set_text( GTK_ENTRY(tableau[6][4]), ITOA(7) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][4]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][5]), ITOA(1) );
	gtk_entry_set_text( GTK_ENTRY(tableau[7][5]), ITOA(8) );
	gtk_entry_set_text( GTK_ENTRY(tableau[0][6]), ITOA(8) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][6]), ITOA(2) );
	gtk_entry_set_text( GTK_ENTRY(tableau[2][7]), ITOA(7) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][7]), ITOA(2) );
	gtk_entry_set_text( GTK_ENTRY(tableau[4][7]), ITOA(8) );
	gtk_entry_set_text( GTK_ENTRY(tableau[6][7]), ITOA(9) );
	gtk_entry_set_text( GTK_ENTRY(tableau[3][8]), ITOA(6) );
	gtk_entry_set_text( GTK_ENTRY(tableau[5][8]), ITOA(1) );
	gtk_entry_set_text( GTK_ENTRY(tableau[7][8]), ITOA(3) );
	gtk_entry_set_text( GTK_ENTRY(tableau[8][8]), ITOA(7) );

}

void nouvelleTable1(){
	int i,j;
	char *caractere="";
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			valeurs[i][j]=0;
			//On efface chaque case du tableau
			gtk_entry_set_text( GTK_ENTRY(tableau[i][j]), caractere );
		}
	}
	table1();
}

void nouvelleTable2(){
	int i,j;
	char *caractere="";
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			valeurs[i][j]=0;
			//On efface chaque case du tableau
			gtk_entry_set_text( GTK_ENTRY(tableau[i][j]), caractere );
		}
	}
	table2();
}

void nouvelleTable3(){
	int i,j;
	char *caractere="";
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			valeurs[i][j]=0;
			//On efface chaque case du tableau
			gtk_entry_set_text( GTK_ENTRY(tableau[i][j]), caractere );
		}
	}
	table3();
}
