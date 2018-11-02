#include <stdlib.h>
#include <stdio.h>


int main(){
	//O usuario vai entrar com valores inteiros
	int primeiro[10],segundo[10];
	
	//o terceiro vetor indica qual opera��o vai ser usada, ele � formado por caracteres [+ , - , / , *]
	char terceiro[10]  = {'+', '-', '*', '/'}; //caracteres s�o declarados como CHAR, e s�o colocados no vetor assim.
	
	//quarto vetor armazena o resultado 	
	int quarto[10];
	
	//Para entrarmos com valores em um vetor, temos que coloca-los em um la�o, do tipo FOR, WHILE, ou DO WHILE
	//Usei o FOR, que tem o contador (i), a condi��o de parada (tamanho do vetor), incremento (o i incrementa de um em um)
	for(int i = 0; i < 10; i++){
	
		printf("\nEntre com os valores do primeiro vetor : ");
		scanf("%d",&primeiro[i]);
		//assim o contador sempre atualiza, preenchendo as posi��es do vetor	
	
	}
	
	//faremos o mesmo pro segundo vetor
	//n�o tem problema se tu usar o mesmo contador(i), desde que tu declare ele dentro do parenteses do FOR. int i = 0 ---> declara��o 
	for(int i = 0; i < 10; i++){
	
		printf("\nEntre com os valores do segundo vetor : ");
		scanf("%d",&segundo[i]);
		//assim o contador sempre atualiza, preenchendo as posi��es do vetor	
	
	}
	//agora pegaremos a opera��o do usu�rio, com uma v�riavel char
	char operacao;
	fflush(stdin);
	printf("\n\nDigite a opera��o a ser feita nos vetores: ");
	operacao = getchar();
	
	//agora veremos qual opera��o o usuario escolheu
	switch(operacao){
		// o switch pega a variavel OPERACAO e compara com os casos abaixo, caso ela ache faz a opera��o dentro de um la�o for, para fazer a opera��o em todos
		// os elementos, caso n�o ele avisa ao usuario que a opera��o nao existe
		//No final de cada caso, � obrigatorio o uso do BREAK;
		case '+':
				for(int i = 0; i < 10; i++){
					quarto[i] = primeiro[i] + segundo[i];
				}
				break;
		case '-':
				for(int i = 0; i < 10; i++){
					quarto[i] = primeiro[i] - segundo[i];
				}
				break;
		case '*':
				for(int i = 0; i < 10; i++){
					quarto[i] = primeiro[i] * segundo[i];
				}
				break;
		case '/':
				for(int i = 0; i < 10; i++){
					quarto[i] = primeiro[i] / segundo[i];
				}
				break;
		default: 
				printf("\n\nOpcao invalida");
				break;
	}
	
	printf("\n");
	//No final exibe todos os resultados, usando o for para exibir todos os elementos do quarto vetor.
	for(int i = 0; i < 10; i++){
		
		printf(" | %d", quarto[i]);
	}
}
