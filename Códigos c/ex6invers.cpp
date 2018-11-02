#include <iostream>
#include <locale.h>

using namespace std;

int main ()
{   

    setlocale(LC_ALL,"Portuguese");
    
    char a[12],b[12];
    int i,j;
    char x;
    
    
    cout<<"PROGRAMA: inversão de caracteres";
    cout<<"\n      Digite os Caracteres: ";
    
    cout<<endl;
    for(i=0; i<12; i++)
    {
    	
    	cout<<"    ["<<(i+1)<<"]"<<"=";
    	cin>>a[i];
    	
	}
	
	cout<<"\n\n  A inversão é:<";
	
	j=0;
	for(i=12-1; i>=0; i--)
	{
		b[j]=a[i];
		j++;
		
	    
	}
	b[j]='\0';
	
	for(i=0; i<12; i++)
	{
		cout<<b[i];
	}
	cout<<">";
	cout<<endl;
	
	system("PAUSE");
	return 0;
	
}
	
	
	
