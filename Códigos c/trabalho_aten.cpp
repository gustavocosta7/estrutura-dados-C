#include <iostream>
#include <stdio.h>
#include <conio.c>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <time.h>


using namespace std;

char opc;
int i,j,k,o,ano1;
//ESTRUTURAS

struct data{
	int dia,ano,mes0;
	char mes[20];
};


struct prof_sau{
	int matricula,numeroRP,fone,cel;
	data dnasc_prof;
	char email[80],sigla[6],tipo_prof[80],cpf[10],nome[80];
	bool teste[20];
	
};

prof_sau pessoa[20];

struct endereco{
	char logradouro[80],bairro[40],cidade[20],estado[20],numero_ca[10];
	int CEP;
};

struct cliente{
	int codigo,idade;
	data dnas_cliente;
	endereco domicilio;
	char nome[80],email_cl[80],fone[20],fone_cl[20];
	bool teste1[20];
};

cliente paciente[20];

struct atendimento{
	int matricula_atend,matriculamed,matricupac;
	data daten;
	char descricao[250];
	bool teste2[20];	
};

atendimento ficha[20];


//=====FUNÇÕES=====
//tempo
void tempoatual(){
	    struct tm *local;
          time_t t;
          t=time(NULL);
          local=localtime(&t);

          ficha[i].daten.dia=local->tm_mday;
          ficha[i].daten.mes0=local->tm_mon+1;
          ficha[i].daten.ano=local->tm_year+1900;
}

void tempo(){
	 
      textcolor(MAGENTA);
      cout<<"\n\n Fechando em... ";
      
    
	  for(int i=5; i>0; i--)
       {	

		      cout<<" "<<(i);
    	      Sleep(1000);
    	
      }
           textcolor(WHITE);
}

//menus

void menu(){
	cout<<"\n\n    Opções    ";
	cout<<"\n\n1 \tNovo Atendimento";
	cout<<"\n2 \tCadastrar Cliente";
	cout<<"\n3 \tCadastrar Profissional";
	cout<<"\n4 \tMenu de Edições ( NECESSÁRIA SENHA DE ADM)";
	cout<<"\n5 \tExibir relatórios";
	cout<<"\n6 \tSair";
	
	
}

void menu_relatorio(){
	system("cls");
	cout<<"***Escolha o tipo de Relatório***";
	cout<<"\n1-\tExibir todo cadastro existente";
	cout<<"\n2-\tRelatório por pesquisa";
	cout<<"\n3-\tVoltar ao menu anterior";
	
	cout<<"\n\nEscolha: ";
	opc=getch();	
}
void menu_relatorio2(){
	system("cls");
	cout<<"***Escolha o campo de pesquisa***";
	cout<<"\n1-\tAtendimentos";
	cout<<"\n2-\tPacientes";
	cout<<"\n3-\tProfissionais";
	cout<<"\n4-\tVoltar ao Menu anterior";
	
	cout<<"\n\nEscolha: ";
	opc=getch();	
}

void swi_ex(){
   switch(opc){
   	case 'e':break;
   	case 'a':break;
   	case 's':
	   break;
   }
   
}
//funções diversas

void pesq_prof(int a)
{
	for(i = 0; i<20; i++)
	{
		if(a==pessoa[i].matricula)
		{
			textcolor(WHITE);
			cout<<"\nNome do profissional\t";
			textcolor(YELLOW);cout<<pessoa[i].nome;
			textcolor(WHITE);
			cout<<"\nTipo\t";
			textcolor(YELLOW);cout<<pessoa[i].tipo_prof;
		}
		
	}
}

void pesq_pac(int a)
{
	for(i = 0; i<20; i++)
	{
		if(a==paciente[i].codigo)
		{
			textcolor(YELLOW);
			cout<<"\nNome do paciente:\t";
			textcolor(BLUE);cout<<paciente[i].nome;
			textcolor(WHITE);
			cout<<"\nDomicilio:\t";
			textcolor(YELLOW);cout<<paciente[i].domicilio.logradouro<<"-"<<paciente[i].domicilio.bairro;
			textcolor(WHITE);
			cout<<"\nIdade:\t";
			textcolor(YELLOW);cout<<paciente[i].idade;
			textcolor(WHITE);
	    }
	}
}
//funções de cadastro e exibição
void novo_aten(){
	int j=0,k=0;
    for( k = 0; k<20; k++)
    {
    	if(pessoa[k].teste[k]==true)
    	{
    	j++;
        }
    }
    
	if(j==0)
	{
      cout<<"\nSem profissionais registrados, registre antes primeiro";
      Sleep(1000);
	  
    }
    else{
  	  do
      {
  	
	   if(ficha[i].teste2[i]!=true)
	   {
	     system("cls");	
	      cout<<"\n\nFicha: <"<<(i+1)<<">";
	      cout<<"\n\n";
	      tempoatual();
	      
	      printf("Data do Atendimento: %d/%02d/%d                                       ",ficha[i].daten.dia,ficha[i].daten.mes0,ficha[i].daten.ano);
	      
	      
          cout << "\nDigite a descrição do problema(MAX 250): " ;
          gets(ficha[i].descricao);
	      
          cout<<"\nMatrícula do Profissional que irá atender:";
          int pr=0;
          textcolor(YELLOW);
          cin>>pr;
          
          
          pesq_prof(pr);
          ficha[i].matriculamed=pessoa[i].matricula;
          textcolor(WHITE);
          
          cout<<"\n\nPACIENTE EM CASO DE \n1-\tUrgência\n2-\tEmergência";
          opc=getch();
          if(opc=='2')
          {
          	
          
             cout<<"\nMatrícula do Paciente: ";
		     textcolor(YELLOW);        
             cin>>pr;
             pesq_pac(pr);
             ficha[i].matricupac=paciente[i].codigo;
             textcolor(WHITE);
          }
          
	      ficha[i].teste2[i]=true;
	      cout<<"\nDeseja preencher outra ficha?[S]sim ou outra tecla para sair";
	      cout<<endl;
	      opc=getch();
          i++;
	      fflush(stdin);
    
       }
      
    }while(opc=='s'||opc=='S');
  }
}

void c_prof(){
 i=0;
 do{
 	  
    if(pessoa[i].teste[i]!=true)
    {
  	   
       system("cls");
     	//strcpy(pessoa[i].tipo_prof,"mophobics"); para colocar uma string 
	
    	cout<<"******CADASTRO DE PROFISSIONAL DA SAÚDE****** :"<<(i+1);
	
		
    	textbackground(WHITE);textcolor(BLACK);
    	cout<<"\nNome:                                                              ";
    	cout<<"\nemail:                                                             ";
    	cout<<"\nTipo de Profissional:                                              ";
    	cout<<"\nSigla da profissão:                                                ";
    	cout<<"\nCPF:                                                               ";
    	cout<<"\nNúmero do registro profissional:                                   ";
    	cout<<"\nData de nascimento:  /  /                                          ";
     	cout<<endl;
    	
    	textcolor(LIGHTBLUE);
    	gotoxy(6,2); cin.getline(pessoa[i].nome,80);
    	gotoxy(7,3); gets(pessoa[i].email);
    	gotoxy(22,4); cin>>pessoa[i].tipo_prof;
    	gotoxy(20,5); cin>>pessoa[i].sigla;
    	gotoxy(5,6); cin>>pessoa[i].cpf;
     	gotoxy(33,7); cin>>pessoa[i].numeroRP;
    	gotoxy(20,8); cin>>pessoa[i].dnasc_prof.dia;
    	gotoxy(23,8); cin>>pessoa[i].dnasc_prof.mes;
    	gotoxy(26,8); cin>>pessoa[i].dnasc_prof.ano;
	    
	        pessoa[i].matricula=20162000;
	        int aux=0,dia_ain;
	        char dia_a[2];
			aux=(i+1);
			strcpy(dia_a,"");
			strncat(dia_a , __DATE__ +4, 2);
			dia_ain=atoi(dia_a);
	        pessoa[i].matricula+=(dia_ain*10);
	        pessoa[i].matricula+=aux;
	        
	    textbackground(BLACK);textcolor(WHITE);
     	cout<<"\n\n****************PROFISSIONAL**********************";
    	cout<<"\n\nNome:\t"<<pessoa[i].nome;
    	cout<<"\nEmail:\t"<<pessoa[i].email;
    	cout<<"\nTipo da profissão:\t"<<pessoa[i].tipo_prof;
    	cout<<"\nSigla da Profissão:\t"<<pessoa[i].sigla;
    	cout<<"\nCPF:\t"<<pessoa[i].cpf;
	    cout<<"\nNúmero de Registro profissional:\t"<<pessoa[i].numeroRP;
    	cout<<"\nData de Nascimento:\t"<<pessoa[i].dnasc_prof.dia<<"/"<<pessoa[i].dnasc_prof.mes<<"/"<<pessoa[i].dnasc_prof.ano;
	    pessoa[i].teste[i]=true;
    	cout<<"\n\nDeseja cadastrar outro profissional?[s]sim ou outra tecla para sair\n";
    	cout<<"\nMatricula <"<<pessoa[i].matricula<<">";
	    cout<<"\n\n\bOBS! É de extrema importância manter anotada a matrícula!!!";
	    opc=getch();
    	fflush(stdin);
        i++;
  	  
    }
   
   }while(opc=='S'||opc=='s');
  
}

void c_paciente(){
	i=0;
	do{
	  
	    if(paciente[i].teste1[i]!=true)
	    {
	    	textbackground(BLACK);textcolor(WHITE);
	        system("cls");
            cout<<"******CADASTRO DE PACIENTE******"<<(i+1);
        	textbackground(WHITE);textcolor(BLACK);
		
        	cout<<"\nNome:                                      ";
        	cout<<"\nLogradouro:                                ";
        	cout<<"\nNúmero da Casa(Com ou sem Sigla):          ";
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
        	
          	paciente[i].idade=2016-paciente[i].dnas_cliente.ano;
	

         	textcolor(LIGHTBLUE);
        	gotoxy(6,2); gets(paciente[i].nome);
        	gotoxy(12,3); gets(paciente[i].domicilio.logradouro);
	        gotoxy(34,4); gets(paciente[i].domicilio.numero_ca);
         	gotoxy(8,5);  gets(paciente[i].domicilio.bairro);
        	gotoxy(8,6); cin>>paciente[i].domicilio.estado;
        	gotoxy(8,7); cin>>paciente[i].domicilio.cidade;
        	gotoxy(8,8); cin>>paciente[i].email_cl;
        	gotoxy(5,9); cin>>paciente[i].domicilio.CEP;
         	gotoxy(20,10); cin>>paciente[i].dnas_cliente.dia;
        	gotoxy(23,10); cin>>paciente[i].dnas_cliente.mes;
        	gotoxy(26,10); cin>>paciente[i].dnas_cliente.ano;
         	gotoxy(10,12); cin>>paciente[i].fone;
        	gotoxy(10,13); cin>>paciente[i].fone_cl;
        	
         	fflush(stdin);
	        paciente[i].teste1[i]=true;
	        paciente[i].codigo=20163000;
	        int aux=0,dia_ain;
	        char dia_a[2];
			aux=(i+1);
			strcpy(dia_a,"");
			strncat(dia_a , __DATE__ +4, 2);
			dia_ain=atoi(dia_a);
	        paciente[i].codigo+=(dia_ain*10);
	        paciente[i].codigo+=aux;
	        
	        
	        
	        cout<<"\n*******PACIENTE*******";
	        cout<<"\n\nNome:\t"<<paciente[i].nome;
	        cout<<"\nEndereço:\t"<<paciente[i].domicilio.logradouro<<" "<<paciente[i].domicilio.numero_ca<<","<<paciente[i].domicilio.bairro
            <<","<<paciente[i].domicilio.cidade<<"-"<<paciente[i].domicilio.estado;
         	cout<<"\nCEP:\t"<<paciente[i].domicilio.CEP;
        	cout<<"\nEmail:\t"<<paciente[i].email_cl;
        	cout<<"\nData de Nascimento:\t"<<paciente[i].dnas_cliente.dia<<"/"<<paciente[i].dnas_cliente.mes<<"/"<<paciente[i].dnas_cliente.ano;
        	paciente[i].idade=2016-paciente[i].dnas_cliente.ano;
        	cout<<"\nIdade:\t"<<paciente[i].idade;
        	cout<<"\n***Contatos***";
         	cout<<"\n\nTelefone:\t"<<paciente[i].fone;
          	cout<<"\nCelular:\t"<<paciente[i].fone_cl;
         	cout<<"\nEmail:\t"<<paciente[i].email_cl;
	        cout<<"\nMatricula <"<<paciente[i].codigo<<">";
	        cout<<"\n\n\bOBS! É de extrema importância manter anotada a matrícula!!!";
	
           	cout<<"\n\nDeseja Continuar?[s] Sim, ou outra tecla para voltar ao menu: ";
         	opc=getch();
        	i++;
	        fflush(stdin);
		}
   }while(opc=='s'||opc=='S');
   textbackground(BLACK);textcolor(WHITE);
}


void exibir_relatorio_pacientes(){
	system("cls");

	cout<<"******RELATÓRIO CLIENTES******";
	
 for( i = 0; i<20; i++){
 
 if(paciente[i].teste1[i] == true)
  {	
	cout<<"\n\n*******PACIENTE "<<(i+1)<<"*******";
	cout<<"\n\nNome:\t"<<paciente[i].nome;
	cout<<"\nEndereço:\t"<<paciente[i].domicilio.logradouro<<" "<<paciente[i].domicilio.numero_ca<<","<<paciente[i].domicilio.bairro
	<<","<<paciente[i].domicilio.cidade<<"-"<<paciente[i].domicilio.estado;
	cout<<"\nCEP:\t"<<paciente[i].domicilio.CEP;
	cout<<"\nEmail:\t"<<paciente[i].email_cl;
	cout<<"\nData de Nascimento:\t"<<paciente[i].dnas_cliente.dia<<"/"<<paciente[i].dnas_cliente.mes<<"/"<<paciente[i].dnas_cliente.ano;
	paciente[i].idade=2016-paciente[i].dnas_cliente.ano;
	cout<<"\nIdade:\t"<<paciente[i].idade;
	cout<<"\n***Contatos***";
	cout<<"\n\nTelefone:\t"<<paciente[i].fone;
	cout<<"\nCelular:\t"<<paciente[i].fone_cl;
	cout<<"\nEmail:\t"<<paciente[i].email_cl;
	Sleep(5000);
  }
  else
  break;
 }
}

void exibir_relatorio_profissionais(){
	system("cls");
	for(i = 0; i<20; i++)
	{
		
			if(pessoa[i].teste[i]!=false)
	     	{
		
	            cout<<"\n\n ****************PROFISSIONAL**********************";
	            cout<<"\n\n Nome:\t"<<pessoa[i].nome;
	            cout<<"\n Email:\t"<<pessoa[i].email;
	            cout<<"\n Tipo da profissão:\t";
				
	            cout<<"\n Sigla da Profissão:\t"<<pessoa[i].sigla;
	            cout<<"\n CPF:\t"<<pessoa[i].cpf;
	            cout<<"\n Número de Registro profissional:\t"<<pessoa[i].numeroRP;
	            cout<<"\n Data de Nascimento:\t"<<pessoa[i].dnasc_prof.dia<<"/"<<pessoa[i].dnasc_prof.mes<<"/"<<pessoa[i].dnasc_prof.ano;
	            cout<<"\n\n Exibir próximo? Editar[E] - APAGAR[A] - SAIR[S]  ";
	            opc=getch();
		        o=1;
            }
            system("cls");
            if(o!=1)
            {
            	cout<<"\n\n Sem cadastros no sistema!";
			}
            
		    
		    
    }
     tempo();
}


void exibir_relatorio_atendimento(){
	system("cls");
	
	cout<<"\n\n ******ATENDIMENTO******";
	for( i = 0; i<20; i++)
	{
		if(ficha[i].teste2[i]!=false)
		{
		   
	       cout<<"\n\n\n ***Descrição*** \n";
	       cout<<ficha[i].descricao;
	       cout<<"\n Data:\t"<<ficha[i].daten.dia<<"/"<<ficha[i].daten.mes<<"/"<<ficha[i].daten.ano;	
	       
	    }
	    
	    
    }
    tempo();
 }



int main()
{
  inicio:
  setlocale(LC_ALL,"Portuguese");
  i=0;
  
  
  do{
  system("cls");
  cout<<"*****HOSPITAL SALUTE-PRONTO ATENDIMENTO*****";
  menu();
  cout<<endl;
  opc=getch();
  switch(opc)
  {
  	case '1':
  	system("cls");
	  i=0;
	  novo_aten();
	  break;
	case '2':c_paciente();break;
	case '3':c_prof();break;
	case '5':menu_relatorio();
	         switch(opc){
	               case'1':menu_relatorio2();
	                       switch(opc){
	                       	     case'1':exibir_relatorio_atendimento();break;
						         case'2':exibir_relatorio_pacientes();break;
						         case'3':exibir_relatorio_profissionais();break;
	          }
	
        } 
	
	
	;break;
	
  }
  }while(opc!=6);
}

