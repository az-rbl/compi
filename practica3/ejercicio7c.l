%{
#include <stdio.h>
%}


digito [0-9]
letra [a-zA-Z]
espacio [ ]

%%

{espacio} { /* Ignorar los espacios en blanco */}
. {printf( "%s", yytext);}

%%

int main(){
    char archivoEntrada[200]="";
    printf("Por favor escribe el archivo: \n");
    scanf("%s", archivoEntrada);
    printf("%s", archivoEntrada);

    yyin = fopen(archivoEntrada, "r");
     if (yyin == NULL){
        perror("fopenff");
        exit(1);
    }


    yylex();
}


