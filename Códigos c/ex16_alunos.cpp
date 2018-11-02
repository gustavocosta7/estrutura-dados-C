#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <conio2.h>
using namespace std;

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	int processo[5][5];
	int i,j,soma;
	int media;
	cout<<"PROGRAMA: CONCURSO 5 ALUNOS"<<"(De 1001 À 1005)";
	//digitar as matriculas
	for(i = 0; i<5; i++)
	{
		cout<<"\nDigite a matricula "<<(i+1)<<": ";
		cin>>processo[i][0];
		if(processo[i][0]<1001 || processo[i][0]>1005);
	    {
	    	while(processo[i][0]<1001 || processo[i][0]>1005)
	    	{
	    		cout<<"\nInválido!!"<<"\nDigite outra matricula: ";
	    		cin>>processo[i][0];
			}
		}
		system("cls");
	}
	cout<<"!Agora digite as notas :";
	//digitar as notas
	for(i= 0 ; i<5; i++)
	{
		
		
	
    	 for( j = 1; j<4; j++)
    	 {
    	 	cout<<"\nDigite a nota "<<(j)<<" da matricula<"<<(processo[i][0])<<"> ";
    	 	cin>>processo[i][j];
		 }
    	 cout<<endl<<endl;
    }	 
    //média	 -/
	cout<<endl;
	i=0; 
    while(i<5)
    {
    	
    	 soma=0;
    	 
		 for(j= 1; j<4; j++)
    	 {
    	     soma=soma+processo[i][j];
    	     j++;
    	     
		 }
		 media=soma/3;
		 
    	 processo[i][4]=media;
    	 
    	 cout<<"\nAs média são: "<<processo[i][4]<<"\n";
		 i++;   	 
	}
	
	
	//aprovador ou reprovado
	cout<<"\n\n\n*****************Boletim Geral**********************";
	cout<<"\nMatrícula |  Nota 1 | Nota 2 | Nota 3 | Média | Situação|";
	cout<<endl;
	
	for(i = 0; i<5; i++)
	{
		for(j = 0 ; j<5 ;j++)
		{
			if(processo[i][j]>10)
			{
				cout<<" |  ";
			}
			else
			{
				cout<<"    |  ";
			}
			 cout<<processo[i][j];
			
		
	    }
	     if(processo[i][4]>=7)
			{
				cout<<"  |  APROVADO  |";
			}
			else
			{
				cout<<"  |  REPROVADO  |";
			}
			cout<<"\n";
		 }
	
    }

