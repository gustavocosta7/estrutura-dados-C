#include <iostream>
#include <cstdio>
using namespace std;

struct HistoricoEscolar{
   	char disciplina[30], aluno[50], situacao;
	float notabim1,notabim2	,notabim3,notabim4,mediafinal;
	int faltas,ano;
   };


int main()
{
   HistoricoEscolar ficha2005008;
   
   
   cout<<"Informe os dados da ficha";
   cout<<"\n\nDisciplina: ";
   gets(ficha2005008.disciplina);
   cout<<"\nAluno: ";
   gets(ficha2005008.aluno);
   cout<<"\n\nNotas bimestrais";
   cout<<"\nNota1: ";
   cin>>ficha2005008.notabim1;
   cout<<"\nNota2: ";
   cin>>ficha2005008.notabim2;
   cout<<"\nNota3: ";
   cin>>ficha2005008.notabim3;
   cout<<"\nNota4: ";
   cin>>ficha2005008.notabim4;
   cout << "\nAno: ";
   cin >> ficha2005008.ano;
//Processamento da média e da situação do aluno na disciplina
ficha2005008.mediafinal=(ficha2005008.notabim1 +ficha2005008.notabim2 +
ficha2005008.notabim3 + ficha2005008.notabim4)/4;

if(ficha2005008.mediafinal>=5)
ficha2005008.situacao ='A';
else
ficha2005008.situacao ='R';
//Saída dos dados da ficha
cout << "\n************* HISTORICO ESCOLAR *************\n";
cout << "\nDisciplina: " << ficha2005008.disciplina;
cout << "\nAluno: " << ficha2005008.aluno;
cout << "\n ----- Notas Bimestrais -----";
printf("\nPrimeira: \t %2.1f", ficha2005008.notabim1);
printf("\nSegunda: \t %2.1f", ficha2005008.notabim2);
printf("\nTerceira: \t %2.1f", ficha2005008.notabim3);
printf("\nQuarta: \t %2.1f", ficha2005008.notabim4);
printf("\nMédia Final: \t %2.1f", ficha2005008.mediafinal);
if(ficha2005008.situacao=='A')
cout << "\nSituação: Aprovado";
else
cout << "\nSituação: Reprovado";
cout << "\nNúmero de Faltas: " << ficha2005008.faltas;
cout << "\nAno: " << ficha2005008.ano;

return 0;
}
   


