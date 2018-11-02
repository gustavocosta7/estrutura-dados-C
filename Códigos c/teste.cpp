#include <iostream>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <conio.c>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <time.h>
#include <cstdlib>

#define ap fflush(stdin)

struct paciente{
	char nome[50], logradouro[50], email[50], estado[10], cidade[10], bairro[20],n_casa[10],cep[10];
	int idade, telefone, celular,dia,mes,ano;
};
paciente Paciente;
using namespace std;

void cadastrar_paciente()
{ 
            FILE* arq;
   
            
            int i;
            
            
            if((arq = fopen("teste.txt", "r")) == NULL)
            {
            	cout<<"arquivo criado!";
            	arq = fopen("teste.txt", "w");
            	fclose(arq);
			}
			
			
			
			arq = fopen ("teste.txt", "a"); 
   
         	textbackground(BLACK);textcolor(WHITE);
	        system("cls");
            cout<<"******CADASTRO DE PACIENTE******"<<(i+1);
        	textbackground(WHITE);textcolor(BLACK);
		
        	cout<<"\nNome:                                      ";
        	cout<<"\nLogradouro:                                ";
        	cout<<"\nNÃºmero da Casa(Com ou sem Sigla):         ";
         	cout<<"\nBairro:                                    ";
         	cout<<"\nEstado:                                    ";
	        cout<<"\nCidade:                                    ";
	        cout<<"\nEmail:                                     ";
	        cout<<"\nCEP:                                       ";
	        cout<<"\nData de nascimento:  /  /                  ";
   
        	cout<<"\n******Contato******                        ";
	        cout<<"\nTelefone:                                  ";
	        cout<<"\nCelular:                                   ";
	        
        	cout<<endl;
        	
            
          	Paciente.idade = 2016-Paciente.ano;
	        
            
            
         	textcolor(LIGHTBLUE);
        	gotoxy(6,2); gets(Paciente.nome);
        	gotoxy(12,3); gets(Paciente.logradouro);
	        gotoxy(34,4); gets(Paciente.n_casa);
         	gotoxy(8,5);  gets(Paciente.bairro);
        	gotoxy(8,6); cin>>Paciente.estado;
        	gotoxy(8,7); cin>>Paciente.cidade;
        	gotoxy(8,8); cin>>Paciente.email;
            ap;
        	gotoxy(5,9);   gets(Paciente.cep);
         	gotoxy(20,10); cin>>Paciente.dia;
        	gotoxy(23,10); cin>>Paciente.mes;
        	gotoxy(26,10); cin>>Paciente.ano;
         	gotoxy(10,12); cin>>Paciente.telefone;
        	gotoxy(10,13); cin>>Paciente.celular;
        
        	fprintf(arq,"\n%s",Paciente.nome);
            fprintf(arq,"\n%s",Paciente.logradouro);
            fprintf(arq,"\n%s",Paciente.n_casa);
            fprintf(arq,"\n%s",Paciente.bairro);
            fprintf(arq,"\n%s",Paciente.estado);
            fprintf(arq,"\n%s",Paciente.cidade);
            fprintf(arq,"\n%s",Paciente.email);
            fprintf(arq,"\n%s",Paciente.cep);
            fprintf(arq,"\n%d",Paciente.dia);
            fprintf(arq,"\n%d",Paciente.mes);
            fprintf(arq,"\n%d",Paciente.ano);
            fprintf(arq,"\n%d",Paciente.telefone);
            fprintf(arq,"\n%d",Paciente.celular);
        	fprintf(arq,"\n%d", Paciente.idade);
        	//fwrite(Paciente,sizeof(paciente),1,arq);
        	
        	if(ferror(arq))
        	   cout<<"erro na gravação";
        	else
        	   cout<<"gravado com sucesso";
        	   
        	fclose(arq);
        	
        	
        	getchar();
        	
        	
        	
        	
   
   
}

void get_cadastro()
{
	FILE *arq;
	
    arq = fopen("teste.txt", "r");
    
    fgets(Paciente.nome,50,arq);
    fgets(Paciente.logradouro,50,arq);
    fgets(Paciente.n_casa,10,arq);
    fgets(Paciente.bairro,20,arq);
    fgets(Paciente.estado,10,arq);
    fgets(Paciente.cidade,10,arq);
    ap;
    fgets(Paciente.email,50,arq);
    fgets(Paciente.cep,10,arq);
	fscanf(arq,"%d",Paciente.dia);
	fscanf(arq,"%d",Paciente.mes);
	fscanf(arq,"%d",Paciente.ano);
	fscanf(arq,"%d",Paciente.telefone);
	fscanf(arq,"%d",Paciente.celular);
	fscanf(arq,"%d",Paciente.idade);
	
	
	cout<<"\n"<<Paciente.nome;
	cout<<"\n"<<Paciente.logradouro;
	cout<<"\n"<<Paciente.n_casa;
	cout<<"\n"<<Paciente.bairro;
	cout<<"\n"<<Paciente.estado;
	cout<<"\n"<<Paciente.cidade;
	cout<<"\n"<<Paciente.email;
	cout<<"\n"<<Paciente.cep;
	cout<<"\n"<<Paciente.dia;
	cout<<"\n"<<Paciente.mes;
	cout<<"\n"<<Paciente.ano;
	cout<<"\n"<<Paciente.telefone;
	cout<<"\n"<<Paciente.celular;
	cout<<"\n"<<Paciente.idade;
	
	
	getch();
	
	
	
	
	
}

int main()
{
	
	cout<<"Escolha um opção";
	cout<<"\n1\tCadastro de paciente";
	cout<<"\n2\tExibir paciente no sistema";
	char opc;
    cout<<"\nOpção: ";
    opc = getchar();
    
    switch(opc)
    {
    	case '1':cadastrar_paciente();break;
    	case '2':get_cadastro();break;
    	default:break;
	}
	
	system("PAUSE");
	return 0;
	
}

