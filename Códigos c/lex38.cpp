#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

int main ()
{

	system ("cls");
	setlocale (LC_ALL,"Portuguese");
	
	int t,a,b,total;
	system ("cls");
	setlocale (LC_ALL,"Portuguese");
	cout<<"Série de FIBONACI";
	cout<<"número de termos:";
	cin>>t;
	
	a=1;
	b=2;
	total=3;
	
	
	do
	{
		total=a+b;
		a=b;
		b=total;
		cout<<total;
		t=t-1;
		
		if(t>=1)
		cout<<",";
		
	}
	while(t!=0);
	return 0;
	
	}
