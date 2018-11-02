#include <stdlib.h>
#include <stdio.h>
#include <string.h>
////////////////estruturas
int i = 0;
struct plv
{
    char palavra[20];
    struct plv *prox_Palavra;
    struct plv *ant_Palavra;

};


struct ltr{
    char letra;
    struct ltr *prox_Letra;
    struct plv *lexi;
};



//CRIA DOIS PONTEIROS PARA APONTAR PARA O INICIO E FIM DA LISTA DE LETRAS
struct ltr *pInicio;
struct ltr *pFim;




////////Fun�oes/////

void inicia()
{
    pInicio = NULL;
    pFim = pInicio;
}

void insere(char *tempPalavra)
{

	int flag = 0;
	//ALOCA O AUXILIAR DO TIPO DA LISTA DE LETRAS E O FAZ RECEBER AS INFORMA��ES PARA A LISTA
	struct ltr *aux;
    aux = (struct ltr*)malloc(sizeof(struct ltr));
    //ALOCA MEMORICA PARA A LISTA PALAVRAS, QUE POR ENQUANTO N�O PERTENCE A NENHUMA LETRA, MAS RECEBER� A PALAVRA
    struct plv *pPalavra;
    pPalavra = (struct plv*)malloc(sizeof(struct plv));
    //cria um ponteiro para varrer a lista;
    struct ltr *pPercorre_letras;
    struct plv *pPercorre_palavras;
    
    pPercorre_letras = pInicio;
    //COPIA A STRING TEMPPALAVRA PARA O CONTEUDO ONDE O PONTEIRO DO TIPO LISTA DE PALAVRAS EST� APONTANDO
	strcpy(pPalavra -> palavra,tempPalavra);
	
	pPalavra->prox_Palavra = NULL;
	pPalavra->ant_Palavra = NULL;



	//SE N�O HOUVER NENHUM ELEMENTO INSERIDO
	if(pInicio == NULL)
	{
		//O PONTEIRO AUX ALOCADO RECEBE O CONTEUDO NO PRIMEIRO INDICE DA STRING TEMPPALAVRA NA VARIAVEL LETRA
		aux->letra = tempPalavra[0];
		//O PONTEIR ALOCADO PPALAVRA � INTEGRADO NA LISTA DE LETRAS
		aux->lexi = pPalavra;
		pInicio = aux;
        pInicio ->prox_Letra = NULL;
        pPalavra = NULL;
        pFim = pInicio;
        aux = NULL;
	}
	else
	{
		//ponteiro pPercorre vai varrer a lista
		while(pPercorre_letras != NULL)
		{

			//vai comparar se a letra j� existe na lista , se existir...
			if(pPercorre_letras -> letra == tempPalavra[0])
			{

				//outro ponteiro de varri��o vai ser acionado para entrar na lista de palavras da Lista letra
				pPercorre_palavras = pPercorre_letras->lexi;
				while(pPercorre_palavras != NULL)
				{
					//VAI VERIFICAR SE CHEGOU NO ULTIMO N� PARA INSERIR
					if(pPercorre_palavras->prox_Palavra == NULL)
					{
						//ALOCA PPALAVRA NO FINAL DA LISTA DE PALAVRAS
						pPercorre_palavras->prox_Palavra = pPalavra;
						//E O PONTEIRO PPALAVRA -> ANTERIOR, APONTA PARA O PPERCORRE INTEGRANDO-O NA LISTA 
						pPalavra->ant_Palavra = pPercorre_palavras;
						pPercorre_palavras = NULL;
						pPalavra = NULL;
						pPercorre_letras = NULL;
					}
					else
						pPercorre_palavras = pPercorre_palavras->prox_Palavra;
				}
				//ACIONA O FLAG PARA DIZER QUE A OPERA��O FOI FEITA, E QUE A LETRA J� ESTAVA CONTIDA NA LISTA SEM PRECISAR ACIONAR OUTRO N�
				flag = 1;
			}
			else
			{
				pPercorre_letras = pPercorre_letras->prox_Letra;
			}
		}
		//CASO N�O TENHA UMA LETRA COM O TEMPPALAVRA[0] ENT�O � CRIADO UM NOVO N� NA LISTA DE LETRAS
		if(flag == 0)
		{
			
	    	 aux ->letra = tempPalavra[0];
	    	 //RECEBE AUX NA ULTIMA POSICAO E DEPOIS PFIM AVAN�A MAIS UM N�
			 pFim -> prox_Letra = aux;
      		 pFim = pFim -> prox_Letra; 
      		 //APONTA O FINAL DA LISTA PROXIMO PARA  NULL
      		 pFim ->prox_Letra = NULL;
      		 //E ALOCA O PONTEIRO PPALAVRA
       		 pFim ->lexi = pPalavra;
       		 aux = NULL;
		}

	}

}

//GRAVA NO ARQUIVO
void gravar(char *tempPalavra)
{

    FILE *arq;
    if((arq = fopen("palavras.txt","r")) == NULL )
    {
        fclose(arq);
        arq = fopen("palavras.txt","w");
        fprintf(arq,"%s\n",tempPalavra);
        fclose(arq);
    }
    else
    {
        arq = fopen("palavras.txt","a");
        fprintf(arq,"%s\n",tempPalavra);
        fclose(arq);
    }
}
//GRAVA TUDO
void gravar_tudo()
{
	FILE *arq;
	arq = fopen("palavras.txt","w");
	
	struct ltr *pPercorre_letras;
    struct plv *pPercorre_palavras;

    pPercorre_letras = pInicio;
    
	 while(pPercorre_letras != NULL)
	 {
	        pPercorre_palavras = pPercorre_letras ->lexi;
	        while(pPercorre_palavras != NULL)
	        {
	        	gravar(pPercorre_palavras->palavra);
	            pPercorre_palavras = pPercorre_palavras ->prox_Palavra;
	        }
	        pPercorre_letras = pPercorre_letras->prox_Letra;
	 }
	 fclose(arq);
}

//L� DO ARQUIVO
void leitura()
{
    FILE *arq;
    //CRIA A VARIAVEL TEMPORARIA
    char tempPalavra[20];
    int i = 0;
   	if((arq = fopen("palavras.txt","r"))== NULL)
	{
		fclose(arq);
		printf("\nArquivo criado!");
	}
    else
    {
        //ABRE O ARQUIVO EM MODO DE LEITURA
        arq = fopen("palavras.txt","r");

        //EXECUTA COMANDO AT� ENCONTRAR FINAL DO ARQUIVO
        while(!feof(arq))
        {
            fscanf(arq,"%s\n",tempPalavra);
            insere(tempPalavra);
    	}
        fclose(arq);
    }

}

void imprimir()
{
    struct ltr *pPercorre_letras;
    struct plv *pPercorre_palavras;

    pPercorre_letras = pInicio;

	if(pInicio == NULL)
	{
		system("cls");
		printf("\nLista vazia, insira palavras primeiro!");
		getchar();
	}
	else
	{
		 while(pPercorre_letras != NULL)
	    {
	        printf("\n\n\t\t\tLetra : %c", pPercorre_letras ->letra);
	        pPercorre_palavras = pPercorre_letras ->lexi;
	        while(pPercorre_palavras != NULL)
	        {
	            printf("\n\t\t\t\tpalavra: %s", pPercorre_palavras ->palavra);
	            pPercorre_palavras = pPercorre_palavras ->prox_Palavra;
	        }
	        pPercorre_letras = pPercorre_letras->prox_Letra;
	    }
	    getchar();
	}

}

void pesquisa()
{
	//FLAG VAI ME DIZER SE O ITEM FOI ENCONTRADO
    int flag = 0;
    //DOIS PONTEIROS PARA AS RESPECTIVAS LISTAS
    struct ltr *pPercorre_letras;
    struct plv *pPercorre_palavras;
    //VARIAVEL DE PESQUISA
	char pesquisa[20];

    pPercorre_letras = pInicio;
	
	//VERIFICA SE A LISTA EXISTE
	if(pInicio == NULL)
	{
		system("cls");
		printf("\nLista vazia, insira palavras primeiro!");
		getchar();
	}
	else
	{
			printf("\nInsira um palavra a ser pesquisada! : ");
			fgets(pesquisa,sizeof(pesquisa),stdin);
			//PERCORRE A LISTA DE LETRAS
		    while(pPercorre_letras != NULL)
		    {
		    	//ATRIBUI PONTEIRO DENTRO DA LISTA DE LETRAS PARA A LISTA DE LISTA PALAVRAS
		        pPercorre_palavras = pPercorre_letras ->lexi;
		        if(pPercorre_letras->letra == pesquisa[0])
			    {   
				    while(pPercorre_palavras != NULL)
			        {
			        	//VERIFICA  A IGUALDADE NAS INICIAIS DAS LETRAS E SE POSITIVO INICIA A BUSCA NAS PALAVRAS RESPECTIVAS DA LETRA
			        	if((strstr(pesquisa,pPercorre_palavras->palavra)) != NULL)
			        	{
			        		 printf("\n\t\t\t\tpalavra: %s", pPercorre_palavras ->palavra);
			        		 pPercorre_palavras = NULL;
			                 flag = 1;
			                 getchar();
						}
						else
						{
							//AVAN�A NA LISTA DE PALAVRAS DENTRO DA SUA RESPECTIVA LETRA
							pPercorre_palavras = pPercorre_palavras ->prox_Palavra;
						}
			           
			        }
			          //CASO J� TENHA ENCONTRA A LETRA E FEITO AS OPERA��O RETORNA NULL PARA O PONTEIRO QUE PERCORRE A LETRA
			        pPercorre_letras = NULL;
				}
				else
					//AVANCA NA LISTA CASO NAO TENHA ENCONTRADO AINDA
		        	pPercorre_letras = pPercorre_letras->prox_Letra;
		    } 
		    
	    if(flag == 0)
	    {
	    	printf("\n*A palavra n�o foi encontrada!*");
		}
	}
	getchar();

}

void remover()
{
		
	struct ltr *pPercorre_letras;
    struct plv *pPercorre_palavras;
	char choose, pesquisa[20];
	int teste = 0,teste_letra = 0;
	int i = 0;
	
    pPercorre_letras = pInicio;
	
	if(pInicio == NULL)
	{
		system("cls");
		printf("\nLista vazia, insira palavras primeiro!");
		getchar();
	}
	else
	{
			printf("\nInsira um palavra a ser removida! : ");
			fgets(pesquisa,sizeof(pesquisa),stdin);
		    while(pPercorre_letras != NULL)
		    {
		        pPercorre_palavras = pPercorre_letras ->lexi;
		        if(pPercorre_letras->letra == pesquisa[0])
			    {   
			    	teste_letra = 1;
				    while(pPercorre_palavras != NULL)
			        {
			        	i++;
			        	if((strstr(pesquisa,pPercorre_palavras->palavra)) != NULL)
			        	{
			        		teste = 1;
			        		printf("n\n\t\t\tPalavra: %s", pPercorre_palavras->palavra);
			        		
			        		if(i == 1)
			        		{
			        			//caso a palavra seja a primeira e a ultima
			        			if(pPercorre_palavras->ant_Palavra == NULL && pPercorre_palavras ->prox_Palavra  == NULL)
			        		 	{
				        		 	 printf("\n\n\t\t\tConfirmar a Exclus�o ? (S/N)\n");
	                   				 choose = getchar();
	                   				 if(choose == 's' || choose == 'S')
	                   				 {
	                   				 	//realizar corre�ao
	                   				 	pPercorre_letras->lexi = NULL;
	                   				 	pPercorre_palavras = NULL;
	                       				printf("\n\n\t\t\tExclus�o realizada!");
	                       				getchar();
	                       				fflush(stdin);
									 }
								 }
								 else
								 {	
								 	    printf("\n\t\t\titem � o primeiro da lista da sua letra");
								 		//se o no n�o for o ultimo mas o primeiro;
									 	if(pPercorre_palavras->ant_Palavra == NULL && pPercorre_palavras->prox_Palavra != NULL)
									 	{
									 		printf("\n\n\t\t\tConfirmar a Exclus�o ? (S/N)\n");
						                    choose = getchar();
						                    if(choose == 's' || choose == 'S')
						                    {
						                        pPercorre_letras->lexi = pPercorre_palavras->prox_Palavra;
						                        pPercorre_palavras = pPercorre_palavras->prox_Palavra;
						                        pPercorre_palavras->ant_Palavra = NULL;
						                        pPercorre_palavras = NULL;
						                        printf("\n\n\t\t\tExclus�o realizada!");
						                    }
									    }
								 }
							}
							else
							{
								////se o n� n�o � o primeiro , mas � o ultimo
								printf("\n\t\t\titem � o ultimo da lista da sua letra");
						       	if(pPercorre_palavras->ant_Palavra != NULL && pPercorre_palavras->prox_Palavra == NULL )
						        {
						            printf("\n\n\t\t\tConfirmar a Exclus�o ? (S/N)\n");
						            choose = getchar();
						            if(choose == 's' || choose == 'S')
						            {
						                pPercorre_palavras->ant_Palavra->prox_Palavra = NULL;
                                        pPercorre_palavras = NULL;
			                            printf("\n\n\t\t\tExclus�o realizada!");
			                        }
			                    }
			                    else
						        {
						         	//se o pnteiro nao apontar para o ultimo
            					    printf("\n\n\t\t\tConfirmar a Exclus�o ? (S/N)\n");
							        choose = getchar();
							        if(choose == 's' || choose == 'S')
							        {
							            pPercorre_palavras->ant_Palavra->prox_Palavra =pPercorre_palavras->prox_Palavra;
							            pPercorre_palavras->prox_Palavra->ant_Palavra =pPercorre_palavras->ant_Palavra;
							            pPercorre_palavras = NULL;
							            printf("\n\n\t\t\tExclus�o realizada!");
							         }
							    }
			                    
							}
							pPercorre_palavras = NULL;
						}
						else
							pPercorre_palavras = pPercorre_palavras ->prox_Palavra;
			           
			        }
			        pPercorre_letras = NULL;
				}
				else
		        	pPercorre_letras = pPercorre_letras->prox_Letra;
		    } 
		    //retorna se n�o tiver achado nenhuma palavra ou letra
	    if(teste == 0)
	    {
	    	printf("\n*A palavra n�o foi encontrada!*");
	    	getchar();
		}
		else
		{
			if(teste_letra == 0)
			{
				printf("\n\n\t\t\tN�o foi encontrada a letra!");
				getchar();
			}
		}
	}
	gravar_tudo();
	getchar();
} 

void editar()
{
	//FLAG VAI ME DIZER SE O ITEM FOI ENCONTRADO
	int flag = 0;
	//DOIS PONTEIROS PARA AS RESPECTIVAS LISTAS
    struct ltr *pPercorre_letras;
    struct plv *pPercorre_palavras;
    //VARIAVEL DE PESQUISA
	char pesquisa[20];

    pPercorre_letras = pInicio;
	//VERIFICA SE A LISTA EXISTE
	if(pInicio == NULL)
	{
		system("cls");
		printf("\nLista vazia, insira palavras primeiro!");
		getchar();
	}
	else
	{
			printf("\nInsira um palavra a ser editada! : ");
			fgets(pesquisa,sizeof(pesquisa),stdin);
			//PERCORRE A LISTA DE LETRAS
		    while(pPercorre_letras != NULL)
		    {
		    	//ATRIBUI PONTEIRO DENTRO DA LISTA DE LETRAS PARA A LISTA DE LISTA PALAVRAS
		        pPercorre_palavras = pPercorre_letras ->lexi;
		        if(pPercorre_letras->letra == pesquisa[0])
			    {   
			    	//VERIFICA  A IGUALDADE NAS INICIAIS DAS LETRAS E SE POSITIVO INICIA A BUSCA NAS PALAVRAS RESPECTIVAS DA LETRA
				    while(pPercorre_palavras != NULL)
			        {
			        	if((strstr(pesquisa,pPercorre_palavras->palavra)) != NULL)
			        	{
			        		 printf("\n\t\t\t\tpalavra: %s", pPercorre_palavras ->palavra);
			        		 printf("\n\nDigite a corre��o : ");
			        		 //SOBREESCREVE
			        		 fgets(pPercorre_palavras->palavra,sizeof(pPercorre_palavras->palavra),stdin);
			        		 pPercorre_palavras = NULL;
			                 flag = 1;
			                 getchar();
						}
						else
						{
							//AVAN�A NA LISTA DE PALAVRAS DENTRO DA SUA RESPECTIVA LETRA
							pPercorre_palavras = pPercorre_palavras ->prox_Palavra;
						}
			           
			        }
			        //CASO J� TENHA ENCONTRA A LETRA E FEITO AS OPERA��O RETORNA NULL PARA O PONTEIRO QUE PERCORRE A LETRA
			        pPercorre_letras = NULL;
				}
				else
				//AVANCA NA LISTA CASO NAO TENHA ENCONTRADO AINDA
		        	pPercorre_letras = pPercorre_letras->prox_Letra;
		    } 
		    
	    if(flag == 0)
	    {
	    	printf("\n*A palavra n�o foi encontrada!*");
		}
	}
	getchar();
	/////////CHAMA FUN��O GRAVA TUDO
	gravar_tudo();
	
}

///////////FUN��ES DE ORDENA��O//////////////////
//TROCADOR BUBBLE SORT DAS INFORMA��ES NOS N�S DA PALAVRAS
void trocadorBubbleSort_plv(struct plv *auxiliar_A, struct plv *auxiliar_B)
{
	//CRIA VARIAVEL TEMPORARIA QUE ARMAZENA INFORMACOES DO PRIMEIRO AUXILIAR (O MAIOR)
	char tempInfo[20];
	//FAZ A COPIA DOS CONTEUDOS E AS RESPECTIVAS TROCAS
	strcpy(tempInfo,auxiliar_A->palavra);
	strcpy(auxiliar_A->palavra,auxiliar_B->palavra);
	strcpy(auxiliar_B->palavra,tempInfo);
}
//ORDENACAO BUBBLE SORT NAS PALAVRAS
void Ordenacao_Bubble_palavras(struct ltr *ppercorre_letras)
{
	
	int flag;
	struct plv *auxiliar1;
	struct plv *auxiliar2;
	
	auxiliar2 = NULL;
	
	do
		{
			flag = 0;
			auxiliar1 = ppercorre_letras->lexi;
			while(auxiliar1->prox_Palavra != auxiliar2)
			{
				if((strcmp(auxiliar1->palavra,auxiliar1->prox_Palavra->palavra)) > 0)
				{
					trocadorBubbleSort_plv(auxiliar1,auxiliar1->prox_Palavra);
					flag = 1;
				}
				auxiliar1 = auxiliar1->prox_Palavra;	
			}
			auxiliar2 = auxiliar1;
		}while(flag);	
}

//FUNCAO DE ORDENAR AS PALAVRAS PESQUISANDO PELA LETRA

void Ordenar_plvLetras()
{
	int flag = 0;
	struct ltr *pPercorre_letras;
	pPercorre_letras = pInicio;
	char pesquisa[20];
	
	if(pInicio == NULL)
	{
		return;
	}
	else
	{
		printf("\n\tDigite a letra a ser pesquisada�\n\t OBS! apenas um caractere, n�o tente bugar meu programa >:( ");
		fgets(pesquisa,sizeof(pesquisa),stdin);
		
		while(pPercorre_letras != NULL)
		{
			if(pPercorre_letras->letra == pesquisa[0])
			{
				Ordenacao_Bubble_palavras(pPercorre_letras);
				pPercorre_letras = NULL;
				flag = 1;
				gravar_tudo();
			}
			else
				pPercorre_letras = pPercorre_letras->prox_Letra;
		}
	}
	
	if(flag == 0)
	{
		system("cls");
		printf("\n\t\t\tNenhuma letra identificada na lista!");
		getchar();
	}
}

//ORDENAR LETRAS
void trocadorBubbleSort_ltr(struct ltr *auxiliar_A, struct ltr *auxiliar_B)
{
	//CRIA UMA VARIAVEL TEMPORARIA QUE PEGA O CARACTERE DO AUXILIAR A E ARMAZENA
	char tempInfo; 
	
	struct plv *tempPlv_A;
	struct plv *tempPlv_B;
	
	
	tempInfo = auxiliar_A->letra;
	//ARMAZENA A LISTA DE PALAVRAS DA RESPECTIVA LETRA
	tempPlv_A = auxiliar_A->lexi;
	//TROCA AS INFORMA��ES COM O AUXILIAR B
	auxiliar_A->letra = auxiliar_B->letra;
	tempPlv_B = auxiliar_B->lexi;
	auxiliar_B->letra = tempInfo;
	//ALOCA A LISTA DE PALAVRAS NAS RESPECTIVAS LETRAS
	auxiliar_B->lexi = tempPlv_A;
	auxiliar_A->lexi = tempPlv_B;
}

void ordenarLtrBubble()
{
	char a[5],b[5];
	int flag;
	struct ltr *auxiliar1;
	struct ltr *auxiliar2;
	
	auxiliar2 = NULL;
	
	do
		{
			flag = 0;
			auxiliar1 = pInicio;
			while(auxiliar1->prox_Letra != auxiliar2)
			{
				if(auxiliar1->letra > auxiliar1->prox_Letra->letra)
				{
					trocadorBubbleSort_ltr(auxiliar1,auxiliar1->prox_Letra);
					flag = 1;
					gravar_tudo();
				}
				auxiliar1 = auxiliar1->prox_Letra;	
			}
			auxiliar2 = auxiliar1;
		}while(flag != 0);	
		
	
}




