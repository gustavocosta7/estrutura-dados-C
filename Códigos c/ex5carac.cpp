#include <iostream>
#include <locale.h>

using namespace std;

int main ()
{   

    setlocale(LC_ALL,"Portuguese");
    
	char a[5],b[5],c[10];
	int i,j;
	
	cout<<"CONCATENA��O DE CARACTERES";
	cout<<"\nDigite at� 5 caracteres: ";
	
	for(i=0; i<5; i++)
	{
		cout<<"\nCaractere n�["<<(i+1)<<"]";
		cin>>a[i];
		
	}
	
	cout<<endl;
	cout<<"\n\nDigite mais 5 caracteres: ";
	
	
	for(i=0; i<5; i++)
	{
		cout<<"\nCaractere n�["<<(i+1)<<"]";
		cin>>b[i];
	}
	
	cout<<endl;
	cout<<"A concatena��o dos vetores A e B �: ";
	
	 j=0;
     while(j<10)
	 {	
         for(i=0; i<5; i++)
		 {
         
		     c[j]=a[i];
             j++;
         }
    
         for(i=0; i<5; i++)
		 {
         	c[j]=b[i];
         	j++;
         	
         	
		 }
     }
	
	cout<<"\nA n B=<";
	for(i=0; i<10; i++ )
	{
		cout<<c[i];
		
		if(i<9)
		   cout<<",";
		
		
	}
	cout<<">"<<endl;
	system("PAUSE");
	return 0;
}
