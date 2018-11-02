#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
using namespace std;
main() {
int col=40, lin=12;
system("cls");
while( 1 ) {
gotoxy(col,lin);
putch(219);
switch( toupper(getch()) ) {
case 'n': if( lin>1 ) lin=lin-1; break;
case 's': if( lin<24 ) lin=lin+1; break;
case 'l': if( col<80 ) col=col+1; break;
case 'o': if( col>1 ) col=col-1; break;
case 'f': exit(1);
}
}
}
