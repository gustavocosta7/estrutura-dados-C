#include<stdio.h>
#include<conio.h>
int main(){
    float M[5][5], i,j,aux,linha2=1,linha4=3;
    printf("\nDigite os elementos da matriz");
    for(i=0;i<5,i++){
        for(j=0;j<5;j++){
            scanf("%f",&M[i][j]);

    }
    }


    for(j = 0; j < 5 ;j++){
        aux = M[linha2][j];
        M[linha2][j] = M[linha4][j];
        M[linha4][j] = aux;

    }

    for(i=0;i<5,i++){
        for(j=0;j<5;j++){
            printf("%f",M[i][j]);

        }
    }




}
