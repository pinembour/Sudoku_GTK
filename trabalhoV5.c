/*Universidade da Beira Interior - Tecnologias e Sistemas de Informacao
  Faculdade de Engenharia - Departamento de Informatica
  Interaccao Humana com o Computador (6627)
  Jogo Sudoku em programacao C com interface grafico GTK+
  
  Trabalho desenvolvido por David Melo - Nr 24698
  
  Nao implementado:
  -O programa nao gera numeros aleatorios,o tabuleiro tera que ser introduzido manual
  -Sao apresentado as mensagens de informacao sobre os valores mal introduzidos na consola.*/

#include <gtk/gtk.h> // importar o header do GTK+
#include <stdio.h>

int valores[9][9]; //Variavel Global para guardar os valores da tabela do Sudoku
GtkWidget *tabuleiro[9][9];

// protótipos das funções
void verificaValores();

void criaNovaTabela(){
	int i,j;
	char *caracter=" ";
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			valores[9][9]=0;
			//Edita para cada entrada do tabuleiro o caracter espaco
			gtk_entry_set_text( GTK_ENTRY(tabuleiro[i][j]), caracter );
		}
	}
}

void questao_sair(GtkWidget *widget, gpointer window){
    GtkResponseType result;
    GtkWidget *dialog;

  //Texto a apresentar na janela, ao lado do icon 'Ponto de Interrogacao'
  dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT,
	GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Tem a certeza que deseja sair?");

  //Mostra o texto presente no widget dialog
  gtk_window_set_title(GTK_WINDOW(dialog), "Sair do Sudoku");
  
  //Executa o funcao de dialogo e recebe como parametro o resultado sim/nao
  result = gtk_dialog_run(GTK_DIALOG(dialog));
    
    //Se o resultado for Sim o programa principal e' fechado
    if (result == GTK_RESPONSE_YES){
            gtk_main_quit();
    }
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
  // um ponteiro para um objeto GtkWidget
  GtkWidget *window, *table, *vbox;
  
  //Variaveis para a toolbar e botoes
  GtkWidget *toolbar, *sephorizontal;
  GtkToolItem *new, *check, *sepvertical, *exit; //novo,verificar,separador,sair
  
  //Variaveis das Cores que e definida (red=0, green=0, blue=0, pixel=0)
  GdkColor blue = {0, 0x0000, 0x0000, 0xffff};
//  GdkColor green = {0, 0x0000, 0xffff, 0x0000}; //Nao foram implementadas
//  GdkColor red = {0, 0xffff, 0x0000, 0x0000};
  int i,j;

  // inicializamos o GTK+ e as bibliotecas de suporte
  gtk_init(&argc, &argv);

  // vamos criar uma nova janela e definir seu título
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width(GTK_CONTAINER (window), 10);
  gtk_window_set_title(GTK_WINDOW(window), "Sudoku em C com libraria GTK+ por David Melo");
  
  //Não permitir maximizar a janela
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  
  //Define o tamanho em pixels da janela 480*540
  gtk_widget_set_size_request (window, 480, 540);
  
  //Define a borda entre o conteudo da janela e o limite da janela
  gtk_container_set_border_width(GTK_CONTAINER(window),20);

  //Liga o botao X da janela ao programa,para ao clicar encerrar o programa
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  
  //Cria uma box vertical para colocar a toolbar
  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window),vbox);
  toolbar = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
  gtk_container_set_border_width(GTK_CONTAINER(toolbar), 2);

  //Cria um botao para eliminiar o jogo actual e iniciar um novo
  new = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), new, -1);
  
  //Cria um botao para testar o jogo actual  
  check = gtk_tool_button_new_from_stock(GTK_STOCK_APPLY);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), check, -1);

  //Cria um separador para afastar os botoes
  sepvertical = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sepvertical, -1);
   
  //Cria um botao para sair do programa
  exit = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exit, -1);

  //***Inicializa a toolbar,colocando a toolbar dentro da vbox
  gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);
  
  //Botao new apaga todos os elementos da tabela
  g_signal_connect(G_OBJECT(new), "clicked", 
        G_CALLBACK(criaNovaTabela), NULL);
  
  //Botao check chama o programa para validar as linhas e colunas
  g_signal_connect(G_OBJECT(check), "clicked", 
        G_CALLBACK(verificaValores), NULL);

  //Ao clicar no botao exit executa o dialogo se deseja ou não sair
  g_signal_connect(G_OBJECT(exit), "clicked", 
        G_CALLBACK(questao_sair), NULL);
  //Ao clicar no X da janela,o programa encerra sem questionar
  g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);
  
  //***Inicializa o separador horizontal entre a toolbar e a tabela
  sephorizontal = gtk_hseparator_new();
  gtk_box_pack_start(GTK_BOX(vbox),sephorizontal,FALSE,FALSE,2);
  
  // cria uma tabela para inserir as caixas de texto
  table = gtk_table_new (9, 9, TRUE);
  
  GtkAttachOptions expandmode= GTK_EXPAND | GTK_FILL;
  // Definir qual é o campo na tabela a inserir a caixa de texto

  for(i=0;i<9;i++){
  	for(j=0;j<9;j++){
  		// Define que o widget tabuleiro são entradas de texto
  		tabuleiro[i][j]= gtk_entry_new();
 		
  		// Limita o numero de caracteres a introduzir na entry para 1
  		gtk_entry_set_max_length( GTK_ENTRY(tabuleiro[i][j]), 1);

  		//Define o tamanho das entradas de texto
  		gtk_widget_set_size_request(tabuleiro[i][j],45,45);
  		
  		//Define a localizacao de cada entrada de texto
  		gtk_table_attach (GTK_TABLE (table), tabuleiro[i][j],  i, i+1, j, j+1, expandmode, expandmode, 0, 0);
  		
  		//Altera a cor da moldura de cada caixa para azul
  		if(( i < 3 || i > 5) && (j < 3 || j > 5)){ //Pinta os cantos
  			gtk_widget_modify_bg(tabuleiro[i][j], GTK_STATE_NORMAL, &blue);
  		}
  		if((i >= 3 && i <= 5) && (j >= 3 && j <= 5)){ //Pinta os centrais
  			gtk_widget_modify_bg(tabuleiro[i][j], GTK_STATE_NORMAL, &blue);
  		}
  	}
  }
  
    //Adicionar cinco pixels de espaçamento entre cada linha e cada coluna
    gtk_table_set_row_spacings(GTK_TABLE(table), 5);
    gtk_table_set_col_spacings(GTK_TABLE(table), 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    
  //***Incorpora a table dentro da vbox
  gtk_box_pack_start(GTK_BOX(vbox), table, FALSE, FALSE, 5);

  // exibimos a janela
  gtk_widget_show_all(window);

  // entramos no loop principal do GTK+
  gtk_main();

  // a aplicação GTK+ foi fechada, vamos sair
  return 0;
}

void verificaValores(GtkWidget *widget, gpointer window){
	int i,j,retoma=0;
	gchar *string;
	GtkWidget *dialog;
	
  //Copia os valores presentes no widget tabuleiro para o matriz valores
  for(i=0;i<9;i++){
  	for(j=0;j<9;j++){	
		string = gtk_entry_get_text(GTK_ENTRY(tabuleiro[i][j]));
		valores[i][j]=atoi(string);
	}
  }
	
	for(i=0;i<9;i++)
		retoma += linha(i);

	for(j=0;j<9;j++)
		retoma += coluna(j);
	
	//Compara a soma dos valores dos returns,se for diferente de 0 e' porque existem valores mal introduzidos no tabuleiro
	if(retoma == 0){
		printf("Apresenta a janela de dialogo OK!VENCEU!\n"); //printf apenas para testes
  		//Texto a apresentar na janela, ao lado do icon de informacao
		dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Sudoku com valores introduzidos correctamente! VENCEU!", "title");
	
		//Titulo da janela de informacao
		gtk_window_set_title(GTK_WINDOW(dialog), "Sudoku OK!");
	}
	else{
		printf("Apresenta a janela de warning\n"); //printf apenas para testes
		//Texto a apresentar na janela, ao lado do icon de warning
		dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Contem valores introduzidos incorrectamente.");

		//Titulo da janela de informacao
		gtk_window_set_title(GTK_WINDOW(dialog), "Verifique os valores");
	}
	//Mostra o texto presente no widget dialog
	gtk_dialog_run(GTK_DIALOG(dialog));
	//Fecha a janela de dialogo,ao clicar em OK ou no X
	gtk_widget_destroy(dialog);
}

int coluna(int I){ //Valida a coluna
	int marcador[9]={0,0,0,0,0,0,0,0,0},i,d,j;
 
	for(j=0;j<9;j++){ //Percorre um vector da matriz a procura de numeros repetidos
		d = valores[I][j];
		if(marcador [d-1]==1){
			printf("Valor mal introduzido na coluna: %d.\n",I+1);
			return 1;
		}
		else
			marcador[d-1]=1;
	}
	return 0;
}

int linha(int J){ //Valida a linha
	int marcador[9]={0,0,0,0,0,0,0,0,0},i,d,j;

	for(i=0;i<9;i++){
		d = valores[i][J];
		if(marcador [d-1]==1){
			printf("Valor mal introduzido na linha: %d.\n",J+1);
			return 1;
		}
		else
			marcador[d-1]=1;
	}        
	return 0;
}
