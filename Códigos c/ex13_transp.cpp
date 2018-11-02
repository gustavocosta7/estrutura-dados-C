#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	int a[4][2],b[2][4];
	int i,j,k,l;
		       
	
	
	cout<<"MATRIZ TRANSPOSTA";
	cout<<endl;
	cout<<" A matriz 4x2 é:"<<"\n";
	for( i = 0; i<4; i++)
	{
		
		for( j = 0; j<2; j++)
		{
			a[i][j] = rand()%10;
			cout<<" "<<a[i][j];			
		}
		cout<<"\n";
	}
	cout<<endl; 
	
	for(i = 0;  i<2 ; i++)
	{
		for( j=0 ; j<4; j++)
		{
			b[i][j]=a[i][j];
			cout<<" "<<b[i][j];
		}
		cout<<"\n";
	}
	
	cout<<endl; 
	j=0;
	k=0;
	l=0;
	for( i = 0; i<2 ; i++)
	{
		
		for(j = j+2; j<4; j++)
		{
			
			
			a[i][j]=b[k][l];
			l++;
			k++;
			cout<<" "<<a[i][j];
		}
		cout<<endl;
	}
	for(i = 0 ; i<2; i++)
	{
		for( j= 0 ; j<4; j++)
		{
			cout<<" "<<a[i][j];
		}
		
		cout<<"\n";
	}
	

}
