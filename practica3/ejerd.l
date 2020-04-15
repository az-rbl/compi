%{
#include <stdio.h>
%}


digito [0-9]
letra [a-zA-Z]
espacio [\t \n]
esps {espacio}
hex (0x{digito}+)
real  ({digito}*"."{digito}+)
/*identificador (letra({digito}|{letra})*)*/
identificador ({letra}({digito}|{letra}){0,31})
blanco " "
entero ({digito}+)
comillas [\"]
reservadas (if)

%x COMILLAS
%%
{reservadas} {printf("Encontré una palabra reservada %s \n", yytext);}

{esps} { /* Ignorar los espacios en blanco */}


{hex}+ {printf("Encontré un hexadecimal %s \n", yytext);}

{identificador} {printf("Encontré un identificador %s \n", yytext);}
{blanco}+ {printf("Encontré un espacio en blanco %s \n", yytext);}

{real} {printf("Encontré un real %s \n", yytext);}
{entero} {printf("Encontre un entero %s \n", yytext);}
<COMILLAS>\" { BEGIN(INITIAL); printf("salgo de comillas %s \n", yytext);}
\" { BEGIN(COMILLAS); printf("Encontré comillas %s \n", yytext);}

<COMILLAS>. {printf("soy un comillado %s \n", yytext);}

%%

int main(){
    yylex();
}

