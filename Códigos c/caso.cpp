#include <stdlib.h>
#include <stdio.h>


int main(){
	//O usuario vai entrar com valores inteiros
	int primeiro[10],segundo[10];
	
	//o terceiro vetor indica qual operação vai ser usada, ele é formado por caracteres [+ , - , / , *]
	char terceiro[10]  = {'+', '-', '*', '/'}; //caracteres são declarados como CHAR, e são colocados no vetor assim.
	
	//quarto vetor armazena o resultado 	
	int quarto[10];
	
	//Para entrarmos com valores em um vetor, temos que coloca-los em um laço, do tipo FOR, WHILE, ou DO WHILE
	//Usei o FOR, que tem o contador (i), a condição de parada (tamanho do vetor), incremento (o i incrementa de um em um)
	for(int i = 0; i < 10; i++){
	
		printf("\nEntre com os valores do primeiro vetor : ");
		scanf("%d",&primeiro[i]);
		//assim o contador sempre atualiza, preenchendo as posições do vetor	
	
	}
	
	//faremos o mesmo pro segundo vetor
	//não tem problema se tu usar o mesmo contador(i), desde que tu declare ele dentro do parenteses do FOR. int i = 0 ---> declaração 
	for(int i = 0; i < 10; i++){
	
		printf("\nEntre com os valores do segundo vetor : ");
		scanf("%d",&segundo[i]);
		//assim o contador sempre atualiza, preenchendo as posições do vetor	
	
	}
	//agora pegaremos a operação do usuário, com uma váriavel char
	char operacao;
	fflush(stdin);
	printf("\n\nDigite a operação a ser feita nos vetores: ");
	operacao = getchar();
	
	//agora veremos qual operação o usuario escolheu
	switch(operacao){
		// o switch pega a variavel OPERACAO e compara com os casos abaixo, caso ela ache faz a operação dentro de um laço for, para fazer a operação em todos
		// os elementos, caso não ele avisa ao usuario que a operação nao existe
		//No final de cada caso, é obrigatorio o uso do BREAK;
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
