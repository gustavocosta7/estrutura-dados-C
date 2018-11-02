#include <stdlib.h>
#include <stdio.h>

struct arvoreLetras{
	char letra;
	struct arvoreLetras *esq, *dir;
	
};

struct arvoreLetras *raiz;

void inicia()
{
	raiz = NULL;
}

 void inserir(struct arvoreLetras **raiz, char tempLetra){
     if(raiz == NULL)
	 {
			raiz = (struct arvoreLetras*) malloc(sizeof(struct arvoreLetras));
         	raiz->dir = NULL;
        	raiz->esq = NULL;
    		raiz->letra = tempLetra;
     }
	 else
	 {
         if(letra < raiz->letra)
              inserir(&(*raiz)->esq,tempLetra));
         else
              inserir(&(*raiz)->dir,tempLetra));
     }
 }
 
 
 void exibirEmOrdem(struct arvoreLetras *raiz){
    if(raiz != NULL){
        exibirEmOrdem(raiz->esq);
        printf("\n%i", raiz->letra);
        exibirEmOrdem(raiz->dir);
    }
}
