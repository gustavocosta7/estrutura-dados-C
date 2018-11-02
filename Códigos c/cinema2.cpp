#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int i,j,linha;
char lugares[5][5];
char alocacao[5]={'A','B','C','D','E'};
char caractere;

int transf(){
	
	
	switch (caractere)
	{
		case 'A':linha=0;break;
		case 'a':linha=0;break;
		case 'B':linha=1;break;
		case 'b':linha=1;break;
		case 'C':linha=2;break;
		case 'c':linha=2;break;
		case 'D':linha=3;break;
		case 'd':linha=3;break;
		case 'E':linha=4;break;
		case 'e':linha=4;break;
		default: linha=5;
		
	}
	return linha;
}

void televisor(){
	 cout<<"               "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	 cout<<"               "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	 cout<<"               "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<endl;
	 cout<<"               "<<char(220)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(220)<<endl;
	 cout<<"               "<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205);
}

void basecima(){
	cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
	     <<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
		 <<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
		 <<char(205)<<char(205)<<char(205)<<char(205)<<char(187);
}

void basebaixo(){
	cout<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
	     <<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
		 <<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
		 <<char(205)<<char(205)<<char(205)<<char(205)<<char(188);
}

void caracteres(){
	cout<<"    "<<char(254)<<char(254)<<char(254)<<char(254)<<char(254)<<char(254)<<char(254)<<char(254)<<char(254)<<char(254);
}

void exibir(){   
    caracteres();
	cout<<" CINEP"<<char(162)<<"LIS ";
	caracteres();
	cout<<"\n";
	basecima();
	cout<<"\n";
	int c=0;
	for( i = 0; i<5; i++)
	{
		
		for(j = 0; j<5; j++)
		{
		       
		    cout<<" | "<<""<<alocacao[i]<<"."<<(j+1)<<"["<<lugares[i][j]<<"]";
		        
		}
		cout<<"\n";
    }
    televisor();
    cout<<"\n";
	basebaixo();
}
	
void preencher(){
   int coluna;				     
   char op;
do {
	cout<<"\n\n\nDigite a linha:";
	cin>>caractere;
	transf();
	//função de transformar em número
	
	while(linha<0||linha>4)
	{
		cout<<"Inválido! Digite outra letra (A-E):"<<endl;
		cout<<" ";
		cin>>caractere;
		transf();
	}
	cout<<"\n\nDigite a coluna: ";
	cin>>coluna;
	while(coluna<1||coluna>5)
	{
		cout<<"Invalido! Digite outro valor(1-5):"<<endl;
		cout<<" ";
		cin>>coluna;
	}
       
    system("cls");
    
    coluna--;
    
   
    //2.1 verifica se cadeira está ocupada
    
    if(lugares[linha][coluna] == 'x')
    {
    	cout<<"\n\n          Invalido, procure outra cadeira\n";
	}
    lugares[linha][coluna]='x';
    
    exibir();
    
    //cout<<"         "<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187);
    //2.3 decisão
	cout<<"\n\nDeseja continuar? [S]sim ou outra tecla: ";
    cin>>op;  
  }while(op=='s'||op=='S');
}


int main()
{
	
	//digita caracteres especias
	
	for( i = 0; i<5; i++)
	{
		for(j = 0; j<5; j++)
		{
			lugares[i][j]=char(176);
			
		}
	}
	exibir();
	cout<<"\n\nEscolha a cadeira:(LINHA,COLUNA) "<<"\n\n";

	
	
	       
	preencher();

	

  
  cout<<endl;
  system("PAUSE");
  return 0;
}
