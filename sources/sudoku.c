
/* Travail Orgiginal : Universidade da Beira Interior - Tecnologias e Sistemas de Informacao
  Faculdade de Engenharia - Departamento de Informatica
  Interaccao Humana com o Computador (6627)
  Jogo Sudoku em programacao C com interface grafico GTK+
  
  Trabalho desenvolvido por David Melo - Nr 24698
  
  Traducion en français, améliorations et ajout de fonctions : Université de Technologie de Belfort-Montbéliard
  Tronc commun
  LP25 - Initiation au système Linux et programmation en Langage C Système
  Programmer le jeu « Smart Sudoku »
  
  Travail effectué par Maxime Suratteau*/




#include <gtk/gtk.h> //Header de GTK+ 
#include <stdio.h>
#include "sudoku.h"
#include "tables.h"
#include "itoa.h"

void quitter(GtkWidget *widget, gpointer window){
	GtkResponseType result;
	GtkWidget *dialog;

	//Texte affiché dans la boîte de dialogue, à droite de l'icone 'Point d'Interrogation'
	dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Êtes-vous sûr de vouloir quitter ?");

	//Afficher le texte dans le widget de dialogue
	gtk_window_set_title(GTK_WINDOW(dialog), "Quitter");

	//Exécuter la fonction du dialogue et recevoir en paramètre le résultat oui/non
	result = gtk_dialog_run(GTK_DIALOG(dialog));

	//Si le résultat est oui, on quitte le programme
	if (result == GTK_RESPONSE_YES){
		gtk_main_quit();
	}
	gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
	// Pointeur sur un objet GtkWidget
	GtkWidget *window, *table, *vbox;

	//Variables pour la barre d'outil et les boutons
	GtkWidget *toolbar, *sephorizontal;
	GtkToolItem *new1, *new2, *new3, *check, *sepvertical, *exit; //nouveau 1 2 et 3, vérifier, séparateur, sortir

	//Variables de couleur définies (red=0, green=0, blue=0, pixel=0)
	GdkColor blue = {0, 0x0000, 0x0000, 0xffff};
	//  GdkColor green = {0, 0x0000, 0xffff, 0x0000}; //Pas implémentées
	//  GdkColor red = {0, 0xffff, 0x0000, 0x0000};
	int i,j;

	// Initialisation de GTK+ et des bibliothèques de suport
	gtk_init(&argc, &argv);

	// On créé une nouvelle boîte et on défini son titre
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_container_set_border_width(GTK_CONTAINER (window), 10);
	gtk_window_set_title(GTK_WINDOW(window), "Sudoku en C avec la librairie GTK+");

	//On la rend non-redimentionnable
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

	//On définit sa taille : 490*550
	gtk_widget_set_size_request (window, 490, 600);

	//On définit la bordure entre le contenu et le bord de la boîte
	gtk_container_set_border_width(GTK_CONTAINER(window),20);

	//On lie le bouton de fermeture au programme, pour que lorsqu'on clique, le programme se ferme
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	//On créé une boîte verticale pour la barre d'outil
	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window),vbox);
	toolbar = gtk_toolbar_new();
	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
	gtk_container_set_border_width(GTK_CONTAINER(toolbar), 2);

	//On ajoute le bouton new1
	new1 = gtk_tool_button_new(NULL,"1");
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), new1, -1);

	//On ajoute le bouton new2
	new2 = gtk_tool_button_new(NULL,"2");
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), new2, -1);

	//On ajoute le bouton new3
	new3 = gtk_tool_button_new(NULL,"3");
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), new3, -1);

	//On ajoute le bouton vérifier  
	check = gtk_tool_button_new_from_stock(GTK_STOCK_APPLY);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), check, -1);

	//On ajoute un séparateur
	sepvertical = gtk_separator_tool_item_new();
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sepvertical, -1);

	//On ajoute un bouton pour quitter
	exit = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exit, -1);

	//On initialise la barre d'outil dans la vbox
	gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);

	//On lie le bouton new1 à la table1
	g_signal_connect(G_OBJECT(new1), "clicked", 
			G_CALLBACK(nouvelleTable1), NULL);

	//On lie le bouton new2 à la table2
	g_signal_connect(G_OBJECT(new2), "clicked", 
			G_CALLBACK(nouvelleTable2), NULL);

	//On lie le bouton new3 à la table3
	g_signal_connect(G_OBJECT(new3), "clicked", 
			G_CALLBACK(nouvelleTable3), NULL);

	//Le bouton vérifie valide les lignes et les colonnes
	g_signal_connect(G_OBJECT(check), "clicked", 
			G_CALLBACK(verifierValeurs), NULL);


	//Quand on clique sur le bouton pour quitter, afficher un dialogue pour savoir si on veut réellement quitter
	g_signal_connect(G_OBJECT(exit), "clicked", 
			G_CALLBACK(quitter), NULL);
	//Si on clique sur la croix de la barre de fenêtre, on ferme sans boîte de dialoque
	g_signal_connect_swapped(G_OBJECT(window), "destroy",
			G_CALLBACK(gtk_main_quit), NULL);

	//Séparateur horizontal entre la barre d'outil et la table
	sephorizontal = gtk_hseparator_new();
	gtk_box_pack_start(GTK_BOX(vbox),sephorizontal,FALSE,FALSE,2);

	//On créé une table pour insérer les boîtes de texte
	table = gtk_table_new (9, 9, TRUE);

	GtkAttachOptions expandmode= GTK_EXPAND | GTK_FILL;
	// Definir le champ dans la table pour insérer la zone de texte

	for(i=0;i<9;i++){
		for(j=0;j<9;j++){

			//On définit la structure pos
			struct Pos *pos = malloc(sizeof(*pos));
			pos->i=i;
			pos->j=j;

			//On définit les cases comme des boîtes de texte
			tableau[i][j]= gtk_entry_new();
			
			//Si on appuie sur entrée en séléctionnant une boîte alors on rentre dans valeursPossible()
			g_signal_connect(G_OBJECT(tableau[i][j]), "activate", 
					G_CALLBACK(valeursPossible), pos);


			//Maximum 1 caractère
			gtk_entry_set_max_length( GTK_ENTRY(tableau[i][j]), 1);

			//Taille : 45*45
			gtk_widget_set_size_request(tableau[i][j],45,45);

			//On définit leur position
			gtk_table_attach (GTK_TABLE (table), tableau[i][j],  i, i+1, j, j+1, expandmode, expandmode, 0, 0);

			//On change la couleur du cadre des cases en bleu
			if(( i < 3 || i > 5) && (j < 3 || j > 5)){ //Coins
				gtk_widget_modify_bg(tableau[i][j], GTK_STATE_NORMAL, &blue);
			}
			if((i >= 3 && i <= 5) && (j >= 3 && j <= 5)){ //Centres
				gtk_widget_modify_bg(tableau[i][j], GTK_STATE_NORMAL, &blue);
			}
		}
	}

	//5 pixels d'espace entre les lignes et les colonnes et 10 toutes les 3 lignes et 3 colonnes pour former des carrés de 3*3
	gtk_table_set_row_spacings(GTK_TABLE(table), 5);
	gtk_table_set_row_spacing(GTK_TABLE(table), 2, 20);
	gtk_table_set_row_spacing(GTK_TABLE(table), 5, 20);
	gtk_table_set_col_spacings(GTK_TABLE(table), 5);
	gtk_table_set_col_spacing(GTK_TABLE(table), 2, 20);
	gtk_table_set_col_spacing(GTK_TABLE(table), 5, 20);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	//On ajoute la table dans la vbox
	gtk_box_pack_start(GTK_BOX(vbox), table, FALSE, FALSE, 5);
	
	//On charge la table 1
	nouvelleTable1();

	//On affiche la pop-up bienvenue()
	g_signal_connect(G_OBJECT(window), "show", 
			G_CALLBACK(bienvenue), NULL);


	//On affiche la fenêtre
	gtk_widget_show_all(window);


	//On entre dans le main
	gtk_main();

	//Quand l'application GTK+ se termine, on quitte
	return 0;
}

void ecrireVal(GtkWidget *widget, gpointer user_data){ //Ecrit la valeur choisie dans sa case
	//On traite le pointeur sur la structure pos
	struct Pos *pos = user_data;

	//On récupère le parent du widget qui a appellé la fonction
	GtkWidget *parent = gtk_widget_get_toplevel(widget);

	//On récupère la valeur à ecrire
	gint valeur = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(widget), "valeur"));

	//On ecrit la valeur
	gtk_entry_set_text( GTK_ENTRY(tableau[pos->i][pos->j]), ITOA(valeur) );

	//On détruit le parent
	gtk_widget_destroy(parent);
}	

void valeursPossible(GtkWidget *widget, gpointer user_data){//Cherche les valeurs possible pour une case donnée


	//On traite le pointeur sur la structure pos
	struct Pos *pos = user_data;

	int possible;
	GtkWidget *dialog, *vbox2, *toolbar2;
	GtkToolItem *valOk[10];

	//On créé une nouvelle fenêtre pour afficher les valeurs possibles
	dialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_container_set_border_width(GTK_CONTAINER (dialog), 20);
	gtk_window_set_title(GTK_WINDOW(dialog), "Valeurs possibles");
	gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
	gtk_widget_set_size_request(dialog, 270, 100);

	vbox2 = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(dialog),vbox2);
	toolbar2 = gtk_toolbar_new();

	//Pour les valeurs de 1 à 9 compris
	for(pos->val=1;pos->val<10;pos->val+=1){

		//On teste si la grille est Ok avec cette valeur
		possible = testerValeurs(pos->i,pos->j,pos->val);
		if(possible==1){

			//Si oui on créé un bouton pour pouvoir ajouter cette valeur à la grille si l'utilisateur le souhaite
			valOk[pos->val] = gtk_tool_button_new(NULL,ITOA(pos->val));
			g_object_set_data(G_OBJECT(valOk[pos->val]), "valeur", GINT_TO_POINTER(pos->val)); //On ajoute une donnée pour stocker la valeur pour la récuperer dans ecrireVal()
			g_signal_connect(G_OBJECT(valOk[pos->val]), "clicked", G_CALLBACK(ecrireVal), pos);
			gtk_toolbar_insert(GTK_TOOLBAR(toolbar2), valOk[pos->val], -1);
		}
	}

	//On affiche la fenêtre
	gtk_box_pack_start(GTK_BOX(vbox2), toolbar2, FALSE, FALSE, 5);
	gtk_widget_show_all(dialog);
}

int testerValeurs(int I, int J, int test){//On test une valeur donnée "test" dans la grille
	int i,j,retenue=0;
	const gchar *string;
	//On copie les valeurs présentes dans la table dans une matrice de valeurs
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){	
			string = gtk_entry_get_text(GTK_ENTRY(tableau[i][j]));
			valeurs[i][j]=atoi(string);
		}
	}

	//On ajoute dans le tableau la valeur "test"
	valeurs[I][J]=test;
	for(i=0;i<9;i++){
		retenue += ligne(i);
		retenue += carre(i);
		retenue += colonne(i);
	}

	//On compare la somme des valeurs des retours. Si différent de 0, alors il y a une erreur.
	if(retenue == 0){
		return 1;
	}
	else{
		return 0;
	}
}

void bienvenue(GtkWidget *widget, gpointer window){//Boîte de dialogue de bienvenue
	GtkWidget *dialog;

	//Tecte affiché
	dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Bienvenue dans ce jeu de Sudoku. Après ce pop-up, choisissez une des trois tables pré-enregistrées pour commencer à jouer. Vous pouvez à tout moment vérifier votre progression en cliquant sur le bouton de validation. Vous pouvez aussi séléctionner une case et appuyer sur Entrer pour que le jeu vous propose les chiffres possibles. Bon jeu !");

	//titre
	gtk_window_set_title(GTK_WINDOW(dialog), "Bienvenue");
	
	// Afficher le texte dans la boîte de dialogue
	gtk_dialog_run(GTK_DIALOG(dialog));
	//Fermer la boîte de dialogue si on clique sur OK ou X
	gtk_widget_destroy(dialog);
}

void verifierValeurs(GtkWidget *widget, gpointer window){//On vérifie la grille
	int i,j,retenue=0;
	const gchar *string;
	GtkWidget *dialog;

	//On copie les valeurs présentes dans la table dans une matrice de valeurs
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){	
			string = gtk_entry_get_text(GTK_ENTRY(tableau[i][j]));
			valeurs[i][j]=atoi(string);
		}
	}

	for(i=0;i<9;i++){
		retenue += ligne(i);
		retenue += carre(i);
		retenue += colonne(i);
	}

	//On compare la somme des valeurs des retours. Si différent de 0, alors il y a une erreur.
	if(retenue == 0){
		//Texte de la boîte de dialogue, à droite de l'icone
		dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Les valeurs introduites sont possible");

		//Titre de la boîte de dialogue
		gtk_window_set_title(GTK_WINDOW(dialog), "Sudoku OK!");
	}
	else{
		//Texte de la boîte de dialogue, à droite de l'icone
		dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Les valeurs introduites ne sont pas possible");

		//Titre de la boîte de dialogue
		gtk_window_set_title(GTK_WINDOW(dialog), "Verifier les valeurs");
	}
	// Afficher le texte dans la boîte de dialogue
	gtk_dialog_run(GTK_DIALOG(dialog));
	//Fermer la boîte de dialogue si on clique sur OK ou X
	gtk_widget_destroy(dialog);
}

int colonne(int I){ //Vérifier une colonne
	int marqueur[9]={0,0,0,0,0,0,0,0,0},d,j;

	for(j=0;j<9;j++){ //Parcourt un vecteur matriciel à la recherche de nombres répétés
		d = valeurs[I][j];
		if(marqueur [d-1]==1){
			return 1;
		}
		else
			marqueur[d-1]=1;
	}
	return 0;
}

int ligne(int J){ //Vérifier une ligne
	int marqueur[9]={0,0,0,0,0,0,0,0,0},i,d;

	for(i=0;i<9;i++){ //Parcourt un vecteur matriciel à la recherche de nombres répétés
		d = valeurs[i][J];
		if(marqueur [d-1]==1){
			return 1;
		}
		else
			marqueur[d-1]=1;
	}        
	return 0;
}

int carre(int I){ //Vérifier un carre

	int marqueur[9]={0,0,0,0,0,0,0,0,0},i,d,j;
	int a,b;
	a=b=0;

	//On se place à la première case de chaque carré
	switch(I){
		case 0 :
			a=0; b=0;
			break;
		case 1 :
			a=0; b=3;
			break;	
		case 2 :
			a=0; b=6;
			break;
		case 3 :
			a=3; b=0;
			break;
		case 4 :
			a=3; b=3;
			break;	
		case 5 :
			a=3; b=6;
			break;
		case 6 :
			a=6; b=0;
			break;
		case 7 :
			a=6; b=3;
			break;	
		case 8 :
			a=6; b=6;
			break;
	}

	for(i=a;i<a+3;i++){//Parcourt un vecteur matriciel à la recherche de nombres répétés
		for(j=b;j<b+3;j++){
			d = valeurs[i][j];
			if(marqueur [d-1]==1){
				return 1;
			}
			else
				marqueur[d-1]=1;
		}
	}
	return 0;
}
