#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>


struct arvore{
	char letra;
	struct arvore *esq,*dir;
	struct listaPalavra *palavras;
}; 

struct listaPalavra{
	char portuguese[20],english[20];
	struct listaPalavra *prox,*ant;
};


void procuraEinsere(char *tempPalavraPT,char *tempPalavraEN, arvore* aux_arvore,int achado)
{

	//cria , aloca e inicializa o aux
	listaPalavra *aux;
	aux = new listaPalavra();
	aux->prox = NULL;aux->ant = NULL;
	for(int i = 0; i < sizeof(tempPalavraPT); i++)
	{
		if(tempPalavraPT[i] == '\n')
		{
			tempPalavraPT[i] = '\0';
		}
	}
	for(int i = 0; i < sizeof(tempPalavraEN); i++)
	{
		if(tempPalavraEN[i] == '\n')
		{
			tempPalavraEN[i] = '\0';
		}
	}
	strcpy(aux->english,tempPalavraEN);
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
		     procuraEinsere(tempPalavraPT,tempPalavraEN,aux_arvore->esq,achado);
		else
			 procuraEinsere(tempPalavraPT,tempPalavraEN,aux_arvore->dir,achado);
	}
	
}

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

void exibirEmOrdem(arvore *aux, listaPalavra *ppercorre)
{
	if(aux != NULL)
	{
		
		ppercorre = aux->palavras;
		exibirEmOrdem(aux->esq,ppercorre);
		printf("%c", aux->letra);
		printf("\n\t\t------------------------------------------------");
		while(ppercorre != NULL)
		{
			printf("\n\t\t%s\t<%s> ", ppercorre->portuguese,ppercorre->english);
			ppercorre = ppercorre->prox;
		}
		printf("\n\t\t------------------------------------------------\n\n");
		exibirEmOrdem(aux->dir,ppercorre);
	}
}

void exibirEmPreOrdem(arvore *aux,listaPalavra *ppercorre)
{
	if(aux != NULL)
	{
		ppercorre = aux->palavras;
		printf("\n%c ", aux->letra);
		printf("\n\t\t------------------------------------------------");
		while(ppercorre != NULL)
		{
			printf("\n\t\t%s\t<%s> ", ppercorre->portuguese,ppercorre->english);
			ppercorre = ppercorre->prox;
		}
		printf("\n\t\t------------------------------------------------\n\n");
		exibirEmPreOrdem(aux->esq,ppercorre);
		exibirEmPreOrdem(aux->dir,ppercorre);
	}
}

void exibirEmPosOrdem(arvore *aux)
{
	listaPalavra *ppercorre;
	if(aux != NULL)
	{
		ppercorre = aux->palavras;
		exibirEmPosOrdem(aux->esq);
		exibirEmPosOrdem(aux->dir);
		printf("\n%c ", aux->letra);
		printf("\n\t\t------------------------------------------------");
		while(ppercorre != NULL)
		{
			printf("\n\t\t%s\t<%s> ", ppercorre->portuguese,ppercorre->english);
			ppercorre = ppercorre->prox;
		}
		printf("\n\t\t------------------------------------------------\n\n");
	}
}


int consulta(arvore *aux, char letra, int achado)
{
	if(aux != NULL  && achado == 0)
	{
		if(aux->letra == letra)
		{
			achado = 1;
		}
		else if(letra < aux->letra)
			achado = consulta(aux->esq,letra,achado);
		else
			achado = consulta(aux->dir,letra,achado);
	}
	
	return achado;
}


arvore* remover(arvore *aux, char letra)
{
	//cria dois ponteiros para auxiliar e guardar informações das árvores
	arvore *p,*p2;
	// se o nó for igual a pesquisa
	if(aux->letra == letra)
	{
		//se tanto o nó da direita , quanto o nó da esquerda forem iguais apaga os dois
		if(aux->esq == aux->dir)
		{
			return NULL;
		}
		else if(aux->esq == NULL)
		{
			p = aux->dir;
			delete aux;
			return p;
		}
		else if(aux->dir == NULL)
		{
			p = aux->esq;
			delete aux;
			return p;
		}
		else
		p2 = aux->dir;
		p = aux->dir;
		while(p->esq != NULL)
		{
			p=p->esq;
		}
		p->esq = aux->esq;
		delete aux;
		return p2;
	}
	else if(aux->letra < letra)
		aux->dir = remover(aux->dir, letra);
	else
		aux->esq = remover(aux->esq, letra);
	return aux;
}

int consultaPorLetra(arvore *aux, char letra, int achado,listaPalavra *ppercorre)
{
	if(aux != NULL  && achado == 0)
	{
		if(aux->letra == letra)
		{
			ppercorre = aux->palavras;
			printf("\n\t\t%c ", aux->letra);
			printf("\n\t\t------------------------------------------------");
			while(ppercorre != NULL)
			{
				printf("\n\t\t%s\t<%s> ", ppercorre->portuguese,ppercorre->english);
				printf("\n");
				ppercorre = ppercorre->prox;
			}
			printf("\n\t\t------------------------------------------------\n\n");
			achado = 1;
			fflush(stdin);
			getchar();
		}
		else if(letra < aux->letra)
			achado = consultaPorLetra(aux->esq,letra,achado,ppercorre);
		else
			achado = consultaPorLetra(aux->dir,letra,achado,ppercorre);
	}
	
	return achado;
}

int consultaPorPalavra(arvore *aux, char letra,char *tempPesquisa, int achado,listaPalavra *pPercorre)
{
	if(aux != NULL  && achado == 0)
	{
		if(aux->letra == letra)
		{
			pPercorre = aux->palavras;
			printf("\n\t\t%c ", aux->letra);
			printf("\n\t\t------------------------------------------------");
			while(pPercorre != NULL)
			{
				if(strstr(tempPesquisa,pPercorre->portuguese) != NULL)
				{
						printf("\n\t\t Tradução : %s ",pPercorre->english);
						fflush(stdin);
						getchar();
						pPercorre = NULL;
				}
				else
					pPercorre = pPercorre->prox;
			}
			printf("\n\t\t------------------------------------------------\n\n");
			achado = 1;

		}
		else if(letra < aux->letra)
			achado = consultaPorPalavra(aux->esq,letra,tempPesquisa,achado,pPercorre);
		else
			achado = consultaPorPalavra(aux->dir,letra,tempPesquisa,achado,pPercorre);
	}
	
	return achado;
}


int removePalavra(arvore *aux,listaPalavra *ppercorre,char letra,char *tempPalavra ,int achado,int indice,int rexclusao)
{
	if(aux != NULL  && achado == 0)
	{
		if(aux->letra == letra)
		{
			ppercorre = aux->palavras;
			printf("\n Tradução : %s  ", ppercorre->english);
			fflush(stdin);
			getchar();
			printf("\n%c ", aux->letra);
			while(ppercorre != NULL)
			{
				indice++;
				if(strstr(ppercorre->portuguese,tempPalavra)!= NULL)
				{
					printf("\n Tradução : %s  ", ppercorre->english);
					fflush(stdin);
					getchar();
					
					if(indice == 1)
					{
						if(ppercorre->ant == NULL && ppercorre->prox ==NULL)
						{
							rexclusao = 1;
							ppercorre = NULL;
						}
						else if(ppercorre->ant == NULL && ppercorre->prox != NULL)
						{
							aux->palavras = ppercorre->prox;
							aux->palavras->ant = NULL;
							ppercorre = NULL;
						}
					}
					else
					{
						if(ppercorre->prox == NULL && ppercorre->ant != NULL)
						{
							ppercorre->ant->prox == NULL;
							ppercorre = NULL;
						}
						else
						{
							ppercorre->ant->prox = ppercorre->prox;
							ppercorre->prox->ant = ppercorre->ant;
							ppercorre = NULL;
						}
					}
				}
				else
					ppercorre = ppercorre->prox;
			}
			achado = 1;
		}
		else if(letra < aux->letra)
			removePalavra(aux->esq,ppercorre,letra,tempPalavra,achado,indice,rexclusao);
		else
			removePalavra(aux->dir,ppercorre,letra,tempPalavra,achado,indice,rexclusao);
	}
	
	return achado,rexclusao;
}

void gravar(char *tempPalavraPT,char *tempPalavraEN)
{

    FILE *arq;
    if((arq = fopen("palavras.txt","r")) == NULL )
    {
        fclose(arq);
        arq = fopen("palavras.txt","w");
        fprintf(arq,"%s\n",tempPalavraPT);
        fprintf(arq,"%s",tempPalavraEN);
        fclose(arq);
    }
    else
    {
        arq = fopen("palavras.txt","a");
        fprintf(arq,"\n%s",tempPalavraPT);
		fprintf(arq,"\n%s",tempPalavraEN);
        fclose(arq);
    }
}


void gravaTudo(arvore *aux,listaPalavra *pPercorre,FILE *arq)
{
	if(aux != NULL)
	{
		pPercorre = aux->palavras;
		while(pPercorre != NULL)
		{
			fprintf(arq,"%s\n",pPercorre->portuguese);
       	 	fprintf(arq,"%s\n",pPercorre->english);
			pPercorre = pPercorre->prox;
		}
		gravaTudo(aux->esq,pPercorre,arq);
		gravaTudo(aux->dir,pPercorre,arq);
	}
}
