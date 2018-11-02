#include <iostream>
#include <cstdio>
#include <clocale>
#include <time.h>

using namespace std;


int i,j,x,linha,coluna,cont,jogada;
char tabela[3][2], figuras[3][2]={'a','b','c','a','c','b'},aux[6]={'l','n','z','d','y','x'},espelho[3][2];
int  numeracao[3][2]={11,12,21,22,31,32};
int a=clock();
    

void menu(){
	
	
	//setlocale(LC_ALL,"Portuguese");
	
	char opc;
  do
  { 
   	
	
	cout<<"********JOGO DA VELHA SUPER HARD********";
	cout<<"\n              1-iniciar";
	cout<<"\n                2-sair";
	cout<<"\n           qual a opcao: ";
	cin>>opc;
	
   }while(opc=='s'||opc=='S');

}

void jogadal()
{
     cout<<"\nescolha uma linha e uma coluna:"<<"\nLinha: ";
	cin>>linha;
	cout<<"\nColuna: ";
	cin>>coluna;
	linha--;
	coluna--;
	cont=0;
	//mostrar caractere escondido
	aux[cont]=tabela[linha][coluna];
	tabela[linha][coluna]=figuras[linha][coluna];
	
	for( i = 0; i<3; i++)
	{
		for(j = 0; j<2 ; j++)
		{
			cout<<numeracao[i][j]<<"|"<<tabela[i][j]<<"|";
		}
		cout<<"\n\n";
	}
    //jogada 2
    jogada++;
    cout<<"\nescolha uma linha e uma coluna:"<<"\nLinha: ";
	cin>>linha;
	cout<<"\nColuna: ";
	cin>>coluna;
    linha--;
    coluna--;
	cont=2;
	
	aux[cont]=tabela[linha][coluna];
	tabela[linha][coluna]=figuras[linha][coluna];
   system("cls");
   
   for( i = 0; i<3; i++)
	{
		for(j = 0; j<2 ; j++)
		{
			cout<<numeracao[i][j]<<"|"<<tabela[i][j]<<"|";
		}
		cout<<"\n\n";
	}
	
	 for( i = 0; i<3; i++)
	{
		for(j = i+1; j<2 ; j++)
		{
			  if(aux[i]==aux[j])
               {
               cont=1;
               break;
               
               }
                else
                {
                    cont=0;
                }
            
        }
        
		
	}
	if(cont>=1)
            {
                
                cout<<"\ncontinue";
                
            }
    if(cont == 0)
    {
    	
     system("cls");
        for( i = 0; i<3; i++)
        {
            for( j = 0; j<2; j++)
            {
                tabela[i][j]=espelho[i][j];
                cout<<numeracao[i][j]<<"|"<<tabela[i][j]<<"|";
            }
        }
    }
    
    jogada++;
}

int main()
{
    							    
								    
    x=0;
    
    menu();
    system("cls");
    
    for(i = 0; i<3; i++)
    {
    	for( j = 0 ;j<2; j++)
    	{
    		tabela[i][j]=char(177);
            espelho[i][j]=char(177);
    		cout<<numeracao[i][j]<<"|"<<tabela[i][j]<<"|";
		}
		cout<<"\n\n";
	}
	
    //jogada 1
   
   do
   {
       jogadal();
   }
   while(jogada<6);
  
}




