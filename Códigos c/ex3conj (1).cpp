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
    cout<<"\n\nQuantos termos contém o conjunto A?: ";
	cin>>a;
    cout<<"\n\nQuantos termos contém o conjunto B?: ";
	cin>>b;
    c=a+b;
    int ca[a],cb[b],un[c];
    
    cout<<"\n\nDigite os termos de A:";
    
    for(i=0;i<a;i++){
    	cout<<"\nDigite o "<<(i+1)<<"º termo: ";
        cin>>ca[i];
        
     }
     
     cout<<"\n\nDigite os termos de B: ";
     for(i=0;i<b;i++){
    	cout<<"\nDigite o "<<(i+1)<<"º termo: ";
        cin>>cb[i];
        
     }
   //União
    
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
     cout<<" a União é A n B={";
     
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
    cout<< " a Intersecção é: A u B={";
    
    
         for(i=0;i<a;i++)
		 {  
			
	         for(j=0;j<b;j++)
			 {
			 	
			 	
			     if(ca[i] == cb[j])
				       cout<<ca[i];   //formula para intersecção*/
			          
					         
             }
             
             if(i<a-2)
			    cout<< ",";
         }
    
	cout<< "}";      

    
    cout<<endl;
    cout<< "A diferença de A e B é: A-B={";
    
     
    //diferença de a-b;
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
     
     //diferença de b-a
     cout<<endl;
     cout << "A diferença de B-A é: B-A={";
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

