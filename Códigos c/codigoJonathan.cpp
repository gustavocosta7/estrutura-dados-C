#include <stdio.h> 
#include <stdlib.h> 

// ============================================ Structs ============================================

struct Lista_Palavra{    	
	char palavra[30];
	struct Lista_Palavra *Prox, *Ant; 
}; 
struct Lista_Palavra *Primeiro, *Ultimo; 

struct Lista_Letra{    	
	char letra;
	struct Lista_Palavra * lisPalavra;
	struct Lista_Letra *lProx, *lAnt; 
}; 
struct Lista_Letra *lPrimeiro, *lUltimo; 

// ============================= Inicialização das Filas ============================================

void inicializarFILAPALAVRAS(){           
	Primeiro = NULL;     
	Ultimo = Primeiro;      
} 

void inicializarFILALETRA(){      
	lPrimeiro = NULL;      
	lUltimo = lPrimeiro;     
} 

// ================================== Inserção das Filas ======================================
void inserirListaLETRA(char letr){      

	struct Lista_Letra *aux;      
	aux = (struct Lista_Letra*)malloc(sizeof(struct Lista_Letra));
	printf("erro aqui!");
	getchar();
	aux->letra = letr;   
	aux->lisPalavra = NULL;
	lUltimo->lProx = aux;      
	aux->lAnt = lUltimo;     
	lUltimo = lUltimo->lProx;      
	aux->lProx = NULL; 
	printf("erro aqui!");
} 
void inserirListaPALAVRA(const char plvra[]){      

		struct Lista_Letra *ltr;   
		ltr = lPrimeiro;   
		struct Lista_Palavra * y;
		y = (struct Lista_Palavra*)malloc(sizeof(struct Lista_Palavra));
		sprintf(y->palavra, plvra);  
		
		while(ltr != NULL){     

			if(plvra[0] == ltr->letra){
				
				// Lista de Listas > Inserindo Palavra na Letra :P
				ltr->lisPalavra = y;
				Ultimo->Prox = y;      
				y->Ant = Ultimo;     
				Ultimo = Ultimo->Prox;      
				y->Prox = NULL; 
				ltr = NULL;
				// ==============================================  
			}
			else
				ltr = ltr->lProx;  		
		} 		
}
// ====================== Impressão ==================================
void ImprimirLetrasPalavras(){   
	struct Lista_Letra *x;   
	struct Lista_Palavra * y;
	x = lPrimeiro;   
	
	while(x != NULL){     
			
		printf("\n\nLetra: %c",x->letra);
		y =  x->lisPalavra;
		// ==========================================
		if(y == NULL)
			printf("Sem palavras!");
		else{ 
			while(y != NULL){     
				printf("\nPalavra: %s", y->palavra);     
				y = y->Prox; 		
			} 
		}
		// ==========================================
		x = x->lProx;   
	} 
}     
 
int main() {    
	inicializarFILAPALAVRAS();   
	inicializarFILALETRA(); 
			
	inserirListaLETRA('a');
	inserirListaLETRA('b');
	inserirListaLETRA('c');
	inserirListaLETRA('t');
			
	inserirListaPALAVRA("abacate");
	inserirListaPALAVRA("amora"); 
	inserirListaPALAVRA("tangirina");
			      
	ImprimirLetrasPalavras();  
}
