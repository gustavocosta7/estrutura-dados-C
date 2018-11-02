//C�digo para Ordenar um vetor de 10 inteiros.
#include<stdio.h>
#include<stdlib.h>
#define TAM 10

void quick(int vet[], int esq, int dir){
    int pivo = esq, i,ch,j;         //Declara��o das variav�s e inicializa��o do pivo com o primeiro algarismo da sequencia
    for(i=esq+1;i<=dir;i++){        //Percorre todos os espa�os do vetor
        j = i;                      //atribui��o de valor
        if(vet[j] < vet[pivo]){     //verifica se o vetor da posi��o pivo � maior que de outra posi��o
         ch = vet[j];               //ch recebe o valor que � menor
         while(j > pivo){           //repete enquanto o j que � a posi��o do algarismo menor que o pivo ficar na posi��o 0
            vet[j] = vet[j-1];      //reorganiza a posi��o de vetores
            j--;                    //decremento para a organiza��o
         }
         vet[j] = ch;               // atribui��o da variavel menor que o pivo na posi��o inicial
         pivo++;                    // aumenta a posi��o do pivo em uma unidade
        }  
    }
    if(pivo-1 >= esq){              // verifica se o valor do pivo � maior que o final do vetor.
        quick(vet,esq,pivo-1);      //final da execurs�o da fun��o
    }
    if(pivo+1 <= dir){              //verifica se o valor do pivo � menor, indicando que ainda estar dentro das limita��es do vetor
        quick(vet,pivo+1,dir);      //chama a fun��o para eecutar novamente
    }
 }

int main(){
    int vet[TAM],i;                 //Declara a variavel i e o vetor vet com 10 posi��es de 0 a 9.
    printf("Digite 10 numeros");    //Imprime na tela a mensagem.
    for(i=0;i<TAM;i++)              //Percorrertodo os espa�os do vetor
        scanf("%d",&vet[i]);        //armazena os dados coletados todo no vetor
    quick(vet,0,TAM-1);             //Chama a fun��o quick com os tres parametros: o vetor, 0 o inicio do vetor e o fim.    
    for(i=0;i<TAM;i++)              //percorre o vetor
        printf("%d ",vet[i]);       //imprime o vetor reorganizado
    printf("\n");
    return 0;
}
