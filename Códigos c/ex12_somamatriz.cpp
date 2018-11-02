#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	int a[4][4],b[4][4],c[4][4];
	int i,j;
	
	cout<<"PROGRAMA:SOMA DE MATRIZES";
	cout<<"\nAs matrizes tem valor:";
	cout<<endl;
	
	
	for( i = 0; i<4; i++)
	{
		for( j = 0; j<4; j++)
		{
		a[i][j]= rand()%10;
		cout<<"\no valor da matriz em ["<<(i+1)<<"]["<<(j+1)<<"] é : "<<a[i][j];
	    }
	}
	cout<<endl<<endl<<endl;
		for( i = 0; i<4; i++)
	{
		for( j = 0; j<4; j++)
		{
		b[i][j]= rand()%10;
		cout<<"\no valor da matriz em ["<<(i+1)<<"]["<<(j+1)<<"] é : "<<b[i][j];
	    }
	}
	
	cout<<"\n\nA soma das duas matrizes é: ";
	
	for(i = 0; i<4; i++)
	{
		cout<<"\n";
		for(j = 0; j<4; j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			cout<<"\n\n O resultado da matriz em ["<<(i+1)<<"]["<<(j+1)<<"] é : "<<c[i][j];
		}
	}
	
	
	cout<<"\n\n";
	
	
}
