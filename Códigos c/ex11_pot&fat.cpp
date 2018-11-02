#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


int i;
int vetor_base[20],vetor_resul[20];
float vetor_exp[20];
int pot[20],fat[20];

using namespace std;

int exp(int a , float b){

	
	for(i = 0; i<20; i++)
	{
		pot[i]= pow(vetor_base[i],vetor_exp[i]);
		//demonstrar cout<<endl<<"resultado ["<<(i+1)<<"]"<<pot[i];
	}
	
}
int fatorial(int b)
{
	int f,mult,result;
	for( i = 0; i<20; i++ )
	{
	
	int n;
	result=1;
	f=1;
	int contador=1;
	
	do
	{
		f=f*contador;
		contador++;
	}
	while(contador<=vetor_exp[i]);
	
	fat[i]=f;
	//demonstrar cout<<"\nÉ"<<fat[i];
	}
	
	
}
	



int main()
{
    setlocale(LC_ALL,"Portuguese");
	int a,b;
	cout<<"PROGRAMA FATORIAL E EXPOENTE";
	
	for(i = 0; i<20; i++)
	{
		vetor_base[i] = rand()%7;
		while(vetor_base[i] == 0  || vetor_base[i]==1)
		{
		   vetor_base[i] = rand()%5;
	     
		}
		vetor_exp[i]=rand()%7;
	    while(vetor_exp[i]==0 || vetor_exp[i]==1 )
		 {	
		 	vetor_exp[i]=rand()%5;
		 }              
  	

		
	    cout<<"\nbase:["<<(i+1)<<"]"<<vetor_base[i]<<" exp:["<<(i+1)<<"]"<<vetor_exp[i];
    }
	//Demonstrar;
	//expoente
	exp(vetor_base[i],vetor_exp[i]);
	
	//fatorial
	fatorial(vetor_exp[i]);
	
	cout<<endl;
	
	for(i = 0; i<20 ; i++)
	{
		vetor_resul[i]=pot[i]+fat[i];
		
		cout<<"\nO resultado <"<<(i+1)<<"> é: "<<vetor_resul[i];
	}
	
}
