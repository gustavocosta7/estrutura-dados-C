#include<iostream>
#include<iomanip>
#include<locale.h>

using namespace std;

int main(){
	
	setlocale(LC_ALL,"Portuguese");
    int a,b,i,j,c;
    int x=0;
    int igual=0;
    
    cout<<"++PROGRAMA: CONJUNTO";
    cout<<"\n\nQuantos termos cont�m o conjunto A?: ";
	cin>>a;
    cout<<"\n\nQuantos termos cont�m o conjunto B?: ";
	cin>>b;
    c=a+b;
    int ca[a],cb[b],un[c];
    
    cout<<"\n\nDigite os termos de A:";
    
    for(i=0;i<a;i++){
    	cout<<"\nDigite o "<<(i+1)<<"� termo: ";
        cin>>ca[i];
        
     }
     
     cout<<"\n\nDigite os termos de B: ";
     for(i=0;i<b;i++){
    	cout<<"\nDigite o "<<(i+1)<<"� termo: ";
        cin>>cb[i];
        
     }
   //Uni�o
    
     j=0;
     while(j<c){	
         for(i=0;i<a;i++){
         
		     un[j]=ca[i];
             j++;
         }
    
         for(i=0; i<b; i++){
         	un[j]=cb[i];
         	j++;
         	
         	
		 }//Concatenar conjunto
     }
     cout<<"\n\n";
     
     //Ordem crescente     
     cout<<" a Uni�o � A n B={";
     
     for(i=0; i<c; i++){
     	for(j=i+1;j<c;j++){
     		if(un[i]>un[j]){
     	   
     	      x=un[i];
     	      un[i]=un[j];
     	      un[j]=x;
     	  }
     	  
		 }
     	 
	 }
	 
	 for(int i=0; i<c; i++){
	 	cout<<un[i];
	 	
	 	if(un[i]<c)
	 	  cout<< ",";
	 	
	 }

	 cout<<"}";
 

    cout<<endl;
    cout<< " a Intersec��o �: A u B={";
    
    
         for(i=0;i<a;i++)
		 {  
			
	         for(j=0;j<b;j++)
			 {
			 	
			 	
			     if(ca[i] == cb[j])
				       cout<<ca[i];   //formula para intersec��o*/
			          
					         
             }
             
             if(i<a-2)
			    cout<< ",";
         }
    
	cout<< "}";      

    
    cout<<endl;
    cout<< "A diferen�a de A e B �: A-B={";
    
     
    //diferen�a de a-b;
     for (i=0; i<a; i++) {
          igual = 0;
          
          for (j=0; j<b; j++) {
          	
               if (ca[i] == cb[j]) {
                    igual = 1;
                    break;
               }
    }
       if(igual == 0) 
           cout << ca[i];
    }
    
    cout<<"}";
     
     //diferen�a de b-a
     cout<<endl;
     cout << "A diferen�a de B-A �: B-A={";
     for (i=0 ; i<b ; i++)
     {
     	igual=0;
     	for( j=0; j<a; j++)
     	{
     		if( cb[i] == ca[j])
     		{
     			igual=1;
     			break;
			 }
		 }
		 
		 if(igual == 0)
		 
		 	cout<<cb[i];
		
     }
	
		
	cout<< "}";	
	
	system("PAUSE");
	return 0;
}

