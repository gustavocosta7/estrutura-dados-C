#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct lista{
	char info[20];
	struct lista *prox;
	
};

struct lista *pInicio;
struct lista *pFim;

void inicia()
{
	pInicio = NULL;
	pFim = pInicio;
}

void insere()
{
	struct lista *aux;
	aux = (struct lista*)malloc(sizeof(struct lista));
	char informa[20];
	printf("\nDigite alguma string\n");
	fflush(stdin);
	fgets(informa,20,stdin);
	strcpy(aux->info,informa);
	aux->prox = NULL;	
	
	if(pInicio == NULL)
	{
		pInicio = aux;
		aux = NULL;
		pFim = pInicio;
	}
	else
	{
		pFim->prox = aux;
		pFim = pFim->prox;
		pFim->prox = NULL;
		aux = NULL;
	}
}

void imprimir()
{
	struct lista *pPercorre;
	
	pPercorre = pInicio;
	
	while(pPercorre !=NULL)
	{
		printf(" \n String : %s",pPercorre->info);
		pPercorre = pPercorre->prox;
	}
	fflush(stdin);
	getchar();
	
}

void trocadorBubbleSort(struct lista *auxiliar_A, struct lista *auxiliar_B)
{
	char tempInfo[20];
	strcpy(tempInfo,auxiliar_A->info);
	strcpy(auxiliar_A->info,auxiliar_B->info);
	strcpy(auxiliar_B->info,tempInfo);
}
	
void ordenaBubbleSort()
{
	int flag,i;
	struct lista *auxiliar1;
	struct lista *auxiliar2;
	auxiliar2 = NULL;
	
	if(pInicio == NULL)
		return;
		
		do
		{
			flag = 0;
			auxiliar1 = pInicio;
			while(auxiliar1->prox != auxiliar2)
			{
				if((strcmp(auxiliar1->info,auxiliar1->prox->info)) > 0)
				{
					trocadorBubbleSort(auxiliar1,auxiliar1->prox);
					flag = 1;
				}
				auxiliar1 = auxiliar1->prox;	
			}
			auxiliar2 = auxiliar1;
		}while(flag != 0);	
}


int main()
{
	int opcao;
	
	do{
		printf("Digite uma opcao: \n");
		printf("\n1 - Insere");
		printf("\n2 - Imprime");
		printf("\n\nOpcao: ");
		scanf("%d",&opcao);
		system("cls");
		switch(opcao)
		{
			case 1: insere();break;
			case 2: imprimir();break;
			case 3: ordenaBubbleSort();break;
			case 7: exit(0);break;
		}
		system("cls");
	}while(opcao != 7);
	
}
