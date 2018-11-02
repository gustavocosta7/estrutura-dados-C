#include <stdio.h>
#include "implementacao.h"
#include <locale.h>

int opcao;

void menu()
{
	system("cls");
	system("TITLE Dicionario/Gcosta");
	printf("\n\n\t\t\t\tDicion�rio de Palavras\n");
	printf("\n\t\t\t\t<1> INSERIR");
	printf("\n\t\t\t\t<2> IMPRIMIR");
	printf("\n\t\t\t\t<3> PESQUISA");
	printf("\n\t\t\t\t<4> EDITAR");
	printf("\n\t\t\t\t<5> REMOVER");
	printf("\n\t\t\t\t<6> ORDENAR LISTA DE LETRAS  [BUBBLE SORT]");
	printf("\n\t\t\t\t<7> ORDENAR PALAVRAS DE UM N� DE LETRAS \n\t\t\t\t    [BUBBLE SORT]");
	printf("\n\t\t\t\t<9> SAIR");
	
	printf("\n\n\t\t\t\tOP��O : ");
	
	scanf("%d",&opcao);		
	
}

int main()
{
	setlocale(LC_ALL,"portuguese");
    inicia();
    leitura();
    
    char tempPalavra[20];
	
    do
    {	    
	    menu();
	    printf("Retonou com %d",opcao);
	    getchar();
	    switch(opcao)
	    {
	    	case 1 :
	    		system("cls");
				printf("\nDigite uma palavra pra ser Inserida: ");
				fgets(tempPalavra,sizeof(tempPalavra),stdin);
				insere(tempPalavra);
				gravar(tempPalavra);break;
				
	    	case 2 :
				system("cls");
				imprimir();break;
				
	    	
	    	case 3 : 
				system("cls");
				pesquisa();break;
				
			case 4 :
				system("cls");
				editar();break;
				
			case 5 :
				system("cls");
				remover();break;
				
			case 6:
				 system("cls");
				 ordenarLtrBubble();break;
			
			case 7:
				system("cls");
				Ordenar_plvLetras();break;
				
			default:
				printf("\nOp��o inv�lida");getchar();break;
		}
	    	
	}while(opcao != 9);
    
    
}
