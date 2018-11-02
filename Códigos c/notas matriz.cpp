#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	
	const int TAMANHO=50;
	
	float notas[TAMANHO],media=0.0;
	cout<<setprecision(2);
	
	int i=0;
	
	do{
		cout<<"Digite uma nota a nota do aluno"<<(i+1)<<":";
		cin>>notas[i];
		
		
	}
	while(notas[i++] >=0);
	
	i--;
	
	for(int j=0;j<i;j++)
		media+=notas[j];
		
	cout<<"\n\nMédia das notas:"<< (media/i);	
}


