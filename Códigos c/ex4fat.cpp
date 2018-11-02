#include<iostream>
#include<locale.h>

using namespace std;

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	int i,n,f,resul,j;
	int a[15], b[15];
	
	cout <<"PROGRAMA FATORIAL";
	cout <<"\nDigite os Termos: ";
	
	for(i=0 ; i<15 ; i++)
	{
		cout<<"\nTermo["<<(i+1)<<"]";
		cin>>a[i];
	}
	
   
   f=n;
   for(i=0 ; i<15 ; i++)
   {
       
       cout<<a[i]<<"!";
       n=15;
       resul=1;
       j=0;
       
       for(f=a[i];f>0;f--)
       {
          
                 
          resul=resul*f;
          
	   }
	   b[j]=resul;
       cout  <<"="<<b[j];
	   j++;
	   cout<<endl;
   }
       
       
	    
   }
       
       
   
   
    
   
