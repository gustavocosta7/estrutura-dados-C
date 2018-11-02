#include <iostream>
#include <locale.h>
#include <cmath>
using namespace std;

	
int op;
void menu(){
	cout<<"\n1-Soma";
	cout<<"\n2-Multiplicação";
	cout<<"\n3-Subtração";
	cout<<"\n4-Divisão";
	cout<<"\n5-Fatorial";
	cout<<"\n6-Potência";
	cout<<"\n0-Sair";
	cout<<"\nOPÇÃO É:";
    cin>>op;
    
}
void titulo(){
	
	cout<<"\n***Calculadora***";
}
int exp(int a,int b){
	cout<<" "<<(pow(a,b));
}
double mult(double a,double b){
	cout<<" "<<(a*b);
}
int soma(int a,int b){
       cout<<" "<<(a+b);
}
double div(double a,double b){
	cout<<" "<<(a/b);
} 
double sub(double a,double b){
	cout<<" "<<(a-b);
}
int fat(int a){
	int f;
	f=1;
	cout<<a<<"!=";
	for(a;a>0;a--)
	{
		cout<<a;
		f=f*a;
		if(a>1)
		  cout<<"x";
	}
	cout<<"="<<f;
	}
int main ()
{
    int a,b;
	setlocale (LC_ALL,"Portuguese");
	system ("cls");
	
		titulo();
		
		  
do{
	    menu();
	    if(op!=0){
		   if(op==5){
		      cout<<" "<<"Digite um valor:";
		      cin>>a;
		      fat(a);
	       }
	       
		   else{
		   	
		   	if(op==6){
		   		cout<<"\nDigite a base:";
		   		cin>>a;
		   		cout<<"\nDigite o expoente:";
		   		cin>>b;
		   		exp(a,b);
			   }
			 else{
			   
		            cout<<"Digite um número:";
		            cin>>a;
		            cout<<"Digite o 2º numero:";
		            cin>>b; 
	      
	                switch(op)
		           {
	      	        case 1:soma(a,b);break;
	      	        case 2:mult(a,b);break;
	      	        case 3:sub(a,b);break;
	      	        case 4:div(a,b);break;
	      	
		           }
	              }
	            }
			}
	}while(op!=0);
	   
	   return 0;	
              
}
	
