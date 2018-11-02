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

using namespace std;

char opc;
int i,j,k,o,ano1;
//ESTRUTURAS

struct data{
	short dia,ano,mes0;
	char mes[3],dia1[3],ano1[5];	
};




struct prof_sau{
	int matricula,numeroRP,fone,cel;
	data dnasc_prof;
	char email[80],sigla[6],tipo_prof[80],cpf[13],nome[80];
	bool teste[20];
	
};

prof_sau pessoa[20];

struct endereco{
	char logradouro[80],bairro[40],cidade[20],estado[20],numero_ca[10],CEP[12];
	
};

struct cliente{
	
    
	
	char nome[80];
    data dnas_cliente;
	endereco domicilio;
    char email_cl[80],fone[20],fone_cl[20];
	bool teste1[20];
    int codigo,idade,testearq;
    char codigo1,idade1,testearq1;
    
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
	cout<<"\n\n    Opcoes    ";
	cout<<"\n\n1 \tNovo Atendimento";
	cout<<"\n2 \tCadastrar Cliente";
	cout<<"\n3 \tCadastrar Profissional";
	//cout<<"\n4 \tMenu de Edições ( NECESSÁRIA SENHA DE ADM)";
	cout<<"\n5 \tExibir relatorios";
	cout<<"\n6 \tSair";
	cout<<"\nEscolha: ";
	
}

void menu_relatorio(){
	system("cls");
	cout<<"***Escolha o tipo de Relatório***";
	cout<<"\n1-\tExibir todo cadastro existente";
	cout<<"\n2-\tRelatório por pesquisa";
	cout<<"\n3-\tVoltar ao menu anterior";
	
	cout<<"\n\nEscolha: ";
	
}
void menu_relatorio2(){
	system("cls");
	cout<<"***Escolha o campo de pesquisa***";
	cout<<"\n1-\tAtendimentos";
	cout<<"\n2-\tPacientes";
	cout<<"\n3-\tProfissionais";
	cout<<"\n4-\tVoltar ao Menu anterior";
	
	cout<<"\n\nEscolha: ";
	
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

void ler_pacientes(){
    
    FILE *abrir;
    
    if( (abrir = fopen("paciente_lista.txt","r")) == NULL)
    {
        cout<<"Arquivo não encontrado";
        Sleep(1000);
        abrir = fopen ("paciente_lista.w","w");
        fclose(abrir);
        
        
    }
    
        
    
   
    
    /*i = 0;
     
    fgets(paciente[i].nome,80,abrir);
    fgets(paciente[i].domicilio.logradouro,80,abrir);
    fgets(paciente[i].domicilio.numero_ca,10,abrir);
    fgets(paciente[i].domicilio.bairro,40,abrir);
    fgets(paciente[i].domicilio.estado,20,abrir);
    fgets(paciente[i].domicilio.cidade,20,abrir);
    fgets(paciente[i].email_cl,80,abrir);
    fgets(paciente[i].domicilio.CEP,12,abrir);
    fgets(paciente[i].dnas_cliente.dia1,3,abrir);
    fgets(paciente[i].dnas_cliente.mes,3,abrir);
    fgets(paciente[i].dnas_cliente.ano1,5,abrir);
    fgets(paciente[i].fone,20,abrir);
    fgets(paciente[i].fone_cl,20,abrir);
    
    paciente[i].teste1[i] = true;
    
    */
    
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
      cout<<"\nSem profissionais registrados, registre um primeiro";
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
	      
	      printf("Data do Atendimento: %d/%02d/%d",ficha[i].daten.dia,ficha[i].daten.mes0,ficha[i].daten.ano);
	      
	      
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
          if(opc=='1')
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
 
  ap;
  do{
 	  
    if(pessoa[i].teste[i]!=true)
    {
    	
  	   FILE *profissionais;
       system("cls");
       
       if((profissionais = fopen("profissional.txt","r") )== NULL)
       {
           cout<<"\nArquivo ainda não criado: ";
           Sleep(1000);
          profissionais = fopen("profissional.txt","w");
          fclose(profissionais);
       }
       profissionais = fopen ( "profissional.txt","a");
       system("cls");
     	//strcpy(pessoa[i].tipo_prof,"mophobics"); para colocar uma string 
	  	cout<<"******CADASTRO DE PROFISSIONAL DA SAUDE****** :"<<(i+1);
	
		
    	textbackground(WHITE);textcolor(BLACK);
    	cout<<"\nNome:                                                              ";
    	cout<<"\nemail:                                                             ";
    	cout<<"\nTipo de Profissional:                                              ";
    	cout<<"\nSigla da profissao:                                                ";
    	cout<<"\nCPF:                                                               ";
    	cout<<"\nNúmero do registro profissional:                                  ";
    	cout<<"\nData de nascimento:  /  /                                          ";
     	cout<<endl;
    	
    	textcolor(LIGHTBLUE);
    	gotoxy(6,2); gets(pessoa[i].nome);
    	gotoxy(7,3); gets(pessoa[i].email);
    	gotoxy(22,4); cin>>pessoa[i].tipo_prof;
    	ap;
    	gotoxy(20,5); cin.getline(pessoa[i].sigla,4);
    	gotoxy(5,6);  cin.getline(pessoa[i].cpf,12);
     	gotoxy(34,7); cin>>pessoa[i].numeroRP;
     	ap;
     	gotoxy(20,8);cin>>pessoa[i].dnasc_prof.dia1;
		gotoxy(23,8);cin>>pessoa[i].dnasc_prof.mes;		             
		gotoxy(26,8);cin>>pessoa[i].dnasc_prof.ano1;
        
	        pessoa[i].matricula=20162000;
	        int aux=0,dia_ain;
	        char dia_a[2];
			aux=(i+1);
			strcpy(dia_a,"");
			strncat(dia_a , __DATE__ +4, 2);
			dia_ain=atoi(dia_a);
	        pessoa[i].matricula+=(dia_ain*10);
	        pessoa[i].matricula+=aux;
	        
	    fprintf(profissionais,"\n%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n%d",pessoa[i].nome,pessoa[i].email,pessoa[i].tipo_prof,pessoa[i].sigla,pessoa[i].cpf,pessoa[i].numeroRP,
		pessoa[i].dnasc_prof.dia1,pessoa[i].dnasc_prof.mes,pessoa[i].dnasc_prof.ano1,pessoa[i].matricula);
		
		
	    textbackground(BLACK);textcolor(WHITE);
     	cout<<"\n\n****************PROFISSIONAL**********************";
    	cout<<"\n\nNome:\t"<<pessoa[i].nome;
    	cout<<"\nEmail:\t"<<pessoa[i].email;
    	cout<<"\nTipo da profissão:\t"<<pessoa[i].tipo_prof;
    	cout<<"\nSigla da Profissão:\t"<<pessoa[i].sigla;
    	cout<<"\nCPF:\t"<<pessoa[i].cpf;
	    cout<<"\nNúmero de Registro profissional:\t"<<pessoa[i].numeroRP;
    	cout<<"\nData de Nascimento:\t"<<pessoa[i].dnasc_prof.dia1<<"/"<<pessoa[i].dnasc_prof.mes<<"/"<<pessoa[i].dnasc_prof.ano1;
	    pessoa[i].teste[i]=true;
	    cout<<"\nMatricula <"<<pessoa[i].matricula<<">";
	    cout<<"\n\n\bOBS! É de extrema importância manter anotada a matrícula!!!";
	    
    	cout<<"\n\nDeseja cadastrar outro profissional?[s]sim ou outra tecla para sair\n";
    	
	    opc=getch();
    	fflush(stdin);
        i++;
  	    fclose(profissionais);
    }
   
   }while(opc=='S'||opc=='s');
  
}

void c_paciente(){
	
	ap;
	do{
	    FILE *paciente_arq;
        if( (paciente_arq = fopen("paciente_lista.txt","r")) == NULL)
        {
            paciente_arq = fopen("paciente_lista.txt","w");
            cout<<"arquivo criado!";
            Sleep(1000);
            
        }
        
        system("cls");
        
        paciente_arq = fopen("paciente_lista.txt", "a");
        
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
        	
            
          	paciente[i].idade=0;
            paciente[i].idade=2016-paciente[i].dnas_cliente.ano;
	        
            
            
         	textcolor(LIGHTBLUE);
        	gotoxy(6,2); gets(paciente[i].nome);
        	gotoxy(12,3); gets(paciente[i].domicilio.logradouro);
	        gotoxy(34,4); gets(paciente[i].domicilio.numero_ca);
         	gotoxy(8,5);  gets(paciente[i].domicilio.bairro);
        	gotoxy(8,6); cin>>paciente[i].domicilio.estado;
        	gotoxy(8,7); cin>>paciente[i].domicilio.cidade;
        	gotoxy(8,8); cin>>paciente[i].email_cl;
            ap;
        	gotoxy(5,9); gets(paciente[i].domicilio.CEP);
         	gotoxy(20,10); cin>>paciente[i].dnas_cliente.dia1;
        	gotoxy(23,10); cin>>paciente[i].dnas_cliente.mes;
        	gotoxy(26,10); cin>>paciente[i].dnas_cliente.ano1;
         	gotoxy(10,12); cin>>paciente[i].fone;
        	gotoxy(10,13); cin>>paciente[i].fone_cl;
            
            paciente[i].testearq=1;
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
	      
            sprintf(paciente[i].idade1, "%f", paciente[i].idade);
            
             if(paciente_arq == NULL)
                 cout<<"\nErro ao abrir arquivo";
    
             else
            {
                fwrite(&paciente,sizeof(struct cliente),1,paciente_arq);
                if(ferror(paciente_arq))
                      cout<<"\nErro na gravação";
                else
                      cout<<"\nGravação realizada com sucesso";
            
        
               fclose(paciente_arq);
            
		    }
        	/*fprintf(paciente_arq,"\n%s",paciente[i].nome);
            fprintf(paciente_arq,"\n%s",paciente[i].domicilio.logradouro);
            fprintf(paciente_arq,"\n%s",paciente[i].domicilio.numero_ca);
            fprintf(paciente_arq,"\n%s",paciente[i].domicilio.bairro);
            fprintf(paciente_arq,"\n%s",paciente[i].domicilio.estado);
            fprintf(paciente_arq,"\n%s",paciente[i].domicilio.cidade);
            fprintf(paciente_arq,"\n%s",paciente[i].email_cl);
            fprintf(paciente_arq,"\n%s",paciente[i].domicilio.CEP);
            fprintf(paciente_arq,"\n%s",paciente[i].dnas_cliente.dia1);
            fprintf(paciente_arq,"\n%s",paciente[i].dnas_cliente.mes);
            fprintf(paciente_arq,"\n%s",paciente[i].dnas_cliente.ano1);
            fprintf(paciente_arq,"\n%s",paciente[i].fone);
            fprintf(paciente_arq,"\n%s",paciente[i].fone_cl);
            
        	*/
         	
	        //fprintf(Paciente,"%")
	        
	        textbackground(BLACK);textcolor(WHITE);
	        cout<<"\n*******PACIENTE*******";
	        cout<<"\n\nNome:\t"<<paciente[i].nome;
	        cout<<"\nEndereço:\t"<<paciente[i].domicilio.logradouro<<" "<<paciente[i].domicilio.numero_ca<<","<<paciente[i].domicilio.bairro
            <<","<<paciente[i].domicilio.cidade<<"-"<<paciente[i].domicilio.estado;
         	cout<<"\nCEP:\t"<<paciente[i].domicilio.CEP;
        	cout<<"\nEmail:\t"<<paciente[i].email_cl;
        	cout<<"\nData de Nascimento:\t"<<paciente[i].dnas_cliente.dia1<<"/"<<paciente[i].dnas_cliente.mes<<"/"<<paciente[i].dnas_cliente.ano1;
            
        	paciente[i].dnas_cliente.ano=atoi(paciente[i].dnas_cliente.ano1);
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
     textbackground(BLACK);textcolor(WHITE);
  }while(opc=='s'||opc=='S');
}
 
   

void exibir_relatorio_pacientes(){
	system("cls");
     
    FILE*abrir;
    
    if((abrir = fopen("paciente_lista.txt","r"))==NULL)
    {
        cout<<"\nArquivo não encontrado, cadastre clientes primeiro!";
        Sleep(10000);
    }
    /*else
    {
            
       pac_arq(paciente[i].nome,paciente[i].domicilio.logradouro,paciente[i].domicilio.numero_ca,paciente[i].domicilio.bairro,paciente[i].domicilio.cidade,
       paciente[i].domicilio.estado,paciente[i].domicilio.CEP,paciente[i].email_cl,paciente[i].dnas_cliente.dia1,
       paciente[i].dnas_cliente.mes,paciente[i].dnas_cliente.ano1);
	   cout<<"******RELATÓRIO CLIENTES******";
	*/
       for( i = 0; i<20; i++)
      {
 
       if(paciente[i].teste1[i] == true)
       {	
        	cout<<"\n\n*******PACIENTE "<<(i+1)<<"*******";
	        cout<<"\n\nNome:\t"<<paciente[i].nome;
	        cout<<"\nEndereço:\t"<<paciente[i].domicilio.logradouro<<" "<<paciente[i].domicilio.numero_ca<<","<<paciente[i].domicilio.bairro
	        <<","<<paciente[i].domicilio.cidade<<"-"<<paciente[i].domicilio.estado;
	        cout<<"\nCEP:\t"<<paciente[i].domicilio.CEP;
            cout<<"\nEmail:\t"<<paciente[i].email_cl;
	        cout<<"\nData de Nascimento:\t"<<paciente[i].dnas_cliente.dia1<<"/"<<paciente[i].dnas_cliente.mes<<"/"<<paciente[i].dnas_cliente.ano1;
	
            paciente[i].dnas_cliente.ano=atoi(paciente[i].dnas_cliente.ano1);
            paciente[i].idade=2016-paciente[i].dnas_cliente.ano;
	        cout<<"\nIdade:\t"<<paciente[i].idade;
	        cout<<"\n***Contatos***";
	        cout<<"\n\nTelefone:\t"<<paciente[i].fone;
	        cout<<"\nCelular:\t"<<paciente[i].fone_cl;
	        cout<<"\nEmail:\t"<<paciente[i].email_cl;
	
        }
       }
       Sleep(2000);
  
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
		        
            }
            system("cls");
           
            
		    
		    
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
	
  //ler_pacientes();
  
  
  do{
  	
  setlocale(LC_ALL,"Portuguese");	
  system("color 0f");
  system("cls");
  cout<<"*****HOSPITAL SALUTE-PRONTO ATENDIMENTO*****";
  menu();
  opc=getchar();
  
  
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
             opc=getch();	
             switch(opc){
                                case'1':menu_relatorio2();
                                        opc=getch();	
                                        switch(opc){
	                       	                                                          
                                           case'1':exibir_relatorio_atendimento();break;
                                           case'2':exibir_relatorio_pacientes();break;
                                           case'3':exibir_relatorio_profissionais();break;
                                           }
                                        } 
	
                                            
	default:break;
  }
  }while(opc!=6);
  
  cout<<endl;
  system("PAUSE");
}

