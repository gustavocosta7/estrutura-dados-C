#include <stdlib.h>
#include "implementacao.h"
#include <locale.h>
	
struct listaPalavra *ppercorre;


void menu()
{
	printf("\t\t\tDicionario PT -> EN");
	printf("\n\n\t\t\t1 - Inserir");
	printf("\n\t\t\t2 - Exibir (Em Ordem)");
	printf("\n\t\t\t3 - Exibir (pré Ordem)");
	printf("\n\t\t\t4 - Exibir (pós Ordem)");
	printf("\n\t\t\t5 - Consultar por letra");
	printf("\n\t\t\t6 - Pesquisar palavra");
	printf("\n\t\t\t7 - Remover letra");
	printf("\n\t\t\t8 - Remover Palavra");
	printf("\n\t\t\t0 - Sair ");
	printf("\n\n\t\t\tOpção :  ");
}

int main()
{
	system("COLOR 0B");
	setlocale(LC_ALL,"portuguese");

	int opcao = 0;
	struct arvore *raiz = NULL;
	struct arvore *aux;
	int achado;
	char letra,tempPalavraPT[20],tempPalavraEN[20],auxPalavra[20],auxPalavra1[20];
	
	FILE *arq;
	
	if((arq = fopen("palavras.txt","r")) == NULL)
	{
		fclose(arq);
		arq = fopen("palavras.txt","w");
		fclose(arq);
	}
	else
	{
	
			arq = fopen("palavras.txt","r");
			while(fscanf(arq,"%s\n",&tempPalavraPT)!= EOF && fscanf(arq,"%s\n",&tempPalavraEN) != EOF)
	   		{
	   			
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
	    		achado = 0;
	    		achado = consulta(raiz,tempPalavraPT[0],achado);
	    		if(achado == 0)
				{
							
							//insere um novo nó na raiz, com a primeira posicao da palavra em PT
							raiz = inserir(raiz,tempPalavraPT[0]);
							//achado é condição de pausa, ele consulta a arvore e se encontrar a letra já na lista pelo passo anterior adiciona no final da L. de palavras
							procuraEinsere(tempPalavraPT,tempPalavraEN,raiz,achado);
							
				}
				else
				{
							//caso já tenha uma letra tempPalavra[0] na arvore, adiciona a palavra nela, e zera o achado, para procura a posição
							achado = 0;
							procuraEinsere(tempPalavraPT,tempPalavraEN,raiz,achado);
				}
				//achado é condição de pausa, ele consulta a arvore e se enconá na trar a letra jlista pelo passo anterior adic
	
			}
			fclose(arq);
	
	}
	
	do
	{
		system("cls");
		menu();
		scanf("%d", &opcao);
		fflush(stdin);
		system("cls");
		
		switch(opcao)
		{
			//insercao
			case 1:{
						printf("\t\t\tDigite a palavra em Portugues: ");
						scanf("%s",&tempPalavraPT);
						printf("\t\t\tDigite a palavra em Inglês: ");
						scanf("%s",&tempPalavraEN);
						//procura na arvore, se ha ou não a letra 
						achado = 0;
						achado = consulta(raiz,tempPalavraPT[0],achado);
						printf("achado: %d",achado);
						getchar();
						//zero indica que não há a letra no nó
						if(achado == 0)
						{
							
							//insere um novo nó na raiz, com a primeira posicao da palavra em PT
							raiz = inserir(raiz,tempPalavraPT[0]);
							//achado é condição de pausa, ele consulta a arvore e se encontrar a letra já na lista pelo passo anterior adiciona no final da L. de palavras
							procuraEinsere(tempPalavraPT,tempPalavraEN,raiz,achado);
							
						}
						else
						{
							//caso já tenha uma letra tempPalavra[0] na arvore, adiciona a palavra nela, e zera o achado, para procura a posição
							achado = 0;
							procuraEinsere(tempPalavraPT,tempPalavraEN,raiz,achado);
						}
						gravar(tempPalavraPT,tempPalavraEN);
						break;

				}
			//exibir letras em ORDEM (ERD)
			case 2:{
						if(raiz == NULL)
						{
							printf("\t\t\tArvore vazia! Insira elementos primeiro!");
							getchar();
							break;
						}
						else
						{
							exibirEmOrdem(raiz,ppercorre);
							getchar();
						}
						break;	
				}
			//exibir letras em pre Ordem(RED)
			case 3:{
						if(raiz == NULL)
						{
							printf("\t\t\tArvore vazia! Insira elementos primeiro!");
							getchar();
							break;
						}
						else
						{
							listaPalavra *ppercorre;
							exibirEmPreOrdem(raiz,ppercorre);
							getchar();
						}
							
						break;
				}
			//exibir letras em pos Ordem(EDR)
			case 4:{
						if(raiz == NULL)
						{
							printf("\t\t\tArvore vazia! Insira elementos primeiro!");
							getchar();
							break;
						}
						else
						{
							
							aux = raiz;
							exibirEmPosOrdem(aux);
							getchar();
						}
						break;
				}
			//consultar por letra
			case 5:{
						if(raiz == NULL)
						{
							printf("\t\t\tArvore vazia! Insira elementos primeiro!");
							getchar();
							break;
						}
						else
						{
							printf("\t\t\tQual letra deseja pesquisar?: ");
							scanf("%c",&letra);
							achado = 0;
							listaPalavra *ppercorre;
							achado = consultaPorLetra(raiz,letra,achado,ppercorre);
							if(achado == 0)
							{
								printf("\n\n\t\t\tItem não encontrado!");
								getchar();
							}		
									
						}
						break;
				}
			//pesquisa de palavra
			case 6:{
					char consultaPalavra[20];
					if(raiz == NULL)
						{
							printf("\t\t\tArvore vazia! Insira elementos primeiro!");
							getchar();
							break;
						}
						else
						{
							printf("\t\t\tQual palavra deseja pesquisar?: ");
							scanf("%s",&consultaPalavra);
							achado = 0;
							listaPalavra *ppercorre;
							achado = consultaPorPalavra(raiz,consultaPalavra[0],consultaPalavra,achado,ppercorre);
							if(achado == 0)
							{
								printf("\n\n\t\t\tItem não encontrado!");
								getchar();
							}
					
						}
				
				break;
			}
			
			//remoção de letra
			case 7:{
						if(raiz == NULL)
						{
							printf("\t\t\tArvore vazia! Insira elementos primeiro!");
							getchar();
							break;
						}
						else
						{
							printf("\t\t\tQual letra deseja remover?: ");
							scanf("%c",&letra);
							achado = 0;
							achado = consulta(raiz,letra,achado);
							if(achado == 0)
							{
								printf("\n\n\t\t\tItem não encontrado!");
								getchar();
							}		
							else
							{
								raiz = remover(raiz,letra);
								printf("\n letra excluída da árvore!");
								getchar();
								FILE *removeArq;
								removeArq = fopen("palavras.txt","w");
								gravaTudo(raiz,ppercorre,removeArq);
								fclose(removeArq);
							}
			
						}
						fflush(stdin);
						break;
				}
			//remove palavra
			case 8:{
						char tempPesquisa[20],letra;
						listaPalavra *ppercorre;
						achado = 0;
						int rexclusao = 0,indice = 0;
						
						if(raiz == NULL)
						{
							printf("\t\t\tArvore vazia! Insira elementos primeiro!");
							getchar();
							break;
						}
						else
						{	
							printf("\n\t\t\tQual palavra deseja remover? (Somente PT-BR)");
							fgets(tempPesquisa,sizeof(tempPesquisa),stdin);
							
							achado = removePalavra(raiz,ppercorre,letra,tempPesquisa,achado,indice,rexclusao);	
							if(rexclusao == 1)
							{
								raiz = remover(raiz,tempPesquisa[0]);	
							}					
						}
						
						break;
			}
			//saida do programa
			case 0: break;
				
		}
	}while(opcao != 0);
}
