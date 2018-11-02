#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct arvore{
	char letra;
	struct arvore *esq,*dir;
	struct listaPalavra *palavras;
}; 

struct listaPalavra{
	char portuguese[20];
	struct listaPalavra *prox,*ant;
};

struct arvore *raiz = NULL;

arvore* inserir(arvore *aux, char letra)
{
	if(aux == NULL)
	{
		aux = new arvore();
		aux->letra = letra;
		aux->dir = NULL;
		aux->esq = NULL;
	}
	else if(letra < aux->letra)
		aux->esq = inserir(aux->esq,letra);
	else
		aux->dir = inserir(aux->dir,letra);
	
	return aux;
}

void exibirEmOrdem(arvore *aux,listaPalavra* pPercorre)
{
	if(aux != NULL)
	{
		
		pPercorre = aux->palavras;
		exibirEmOrdem(aux->esq,pPercorre);
		printf("%c", aux->letra);
		printf("\n\t\t------------------------------------------------");
		while(pPercorre != NULL)
		{
			printf("\n\t\t%s", pPercorre->portuguese);
			printf("\n");
			pPercorre = pPercorre->prox;
		}
		printf("\n\t\t------------------------------------------------\n\n");
		exibirEmOrdem(aux->dir,pPercorre);
	}
}

void procuraEinsere(char *tempPalavraPT, arvore* aux_arvore)
{

	//cria , aloca e inicializa o aux
	listaPalavra *aux;
	aux = new listaPalavra();
	aux->prox = NULL;aux->ant = NULL;
	strcpy(aux->portuguese,tempPalavraPT);
	
	//percorre a lista para encontrar a letra
	if(aux_arvore != NULL)
	{
		if(aux_arvore->letra == aux->portuguese[0])
		{
			//caso encontre a letra na arvore, cria dois ponteiros, que inserem no final da lista;
			listaPalavra *ppercorre = aux_arvore->palavras;
			listaPalavra *ppercorre_in = aux_arvore->palavras;
			if(ppercorre == NULL)
			{
				aux_arvore->palavras = aux;
			
			}
			else
			{
				while(ppercorre != NULL)
				{
					if(ppercorre_in->prox == NULL)
					{
						ppercorre -> prox = aux;
						aux->prox = NULL;
						aux->ant = ppercorre;
						ppercorre = NULL;			
					}
					else
					{
						ppercorre = ppercorre->prox;
						ppercorre_in = ppercorre;
					}
						
				}
			}
			
		}
		else if(tempPalavraPT[0] < aux_arvore->letra)
		     procuraEinsere(tempPalavraPT,aux_arvore->esq);
		else
			 procuraEinsere(tempPalavraPT,aux_arvore->dir);
	}
	
}


int main()
{
	listaPalavra *pPercorre;
	char templetra[20];
	FILE *Arq;
	Arq = fopen("palavras.txt","r");
	fscanf(Arq,"%s\n",&templetra);
	raiz = inserir(raiz,templetra[0]);
	procuraEinsere(templetra,raiz);
	fscanf(Arq,"%s\n",&templetra[0]);
	raiz = inserir(raiz,templetra[0]);
	procuraEinsere(templetra,raiz);
	fclose(Arq);
	exibirEmOrdem(raiz,pPercorre);
}



