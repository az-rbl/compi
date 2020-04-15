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
    yyin = fopen("programa.c", "r");
    yylex();
}


