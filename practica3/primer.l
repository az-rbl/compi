%{
#include <stdio.h>
%}


digito [0-9]
letra [a-zA-Z]
espacio [\t \n]
esps {espacio}


%%

{esps} { /* Ignorar los espacios en blanco */}
{digito}+ {printf("Encontre un número %s \n", yytext);}

{letra}+ {printf("Encontré una palabra %s \n", yytext);}

%%

int main(){
    
    yylex();
}
