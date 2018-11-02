#include <string.h>
#include <stdio.h>

int main()
{
	char nome[20];
	char nome1[20];
	
	fgets(nome,20,stdin);
	fgets(nome1,20,stdin);

	if(strcmp(nome,nome1) < 0)
	{
		printf("o [%s]é maior",nome);
	}
	else
		printf("o [%s] é maior",nome1);
}
