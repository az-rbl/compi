%{
#include <stdio.h>
%}


digito [0-9]
letra [a-zA-Z]
espacio [\t \n]
esps {espacio}
hex (0x{digito}+)
decimal  ({digito}*"."{digito}+)
/*identificador (letra({digito}|{letra})*)*/
identificador ({letra}({digito}|{letra}){0,31})
blanco " "
%%

{esps} { /* Ignorar los espacios en blanco */}
{digito}+ {printf("Encontre un número %s \n", yytext);}

{hex}+ {printf("Encontré un hexadecimal %s \n", yytext);}
{decimal}+ {printf("Encontré un decimal %s \n", yytext);}
{identificador} {printf("Encontré un identificador %s \n", yytext);}
{blanco}+ {printf("Encontré un espacio en blanco %s \n", yytext);}

%%

int main(){
    yyin = fopen("programa.c", "r");
    yylex();
}
