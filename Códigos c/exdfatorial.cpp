#include <iostream>
using namespace std;

int main ()
{
	int n,fatorial,resul,mult;
	
	cout<<"Digite o número de termos: ";
	cin>>n;
	resul=1;
	fatorial=n;
	cout<<fatorial;
	
	while(fatorial!=0)
	{
	if(n!=1 )
		{
		mult=fatorial*(fatorial-1);
		resul=mult*resul;
		fatorial=fatorial-1;
		cout<<"x"<<fatorial;
		n=n-1;
	}
	
	else
	cout<<"não permitido";
		
		
	}
	
	cout<<"="<<resul;
	return 0;
}

