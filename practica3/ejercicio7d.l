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
reservadas (if|else)
op_arit [+*/%]-
op_rel [¿!=]
simbolo_especial [(){};]
inicio_comen2 (<*)

%x COMILLAS
%x COMEN1
%x COMEN2
%%
{reservadas} {printf("Encontré una palabra reservada %s \n", yytext);}

{esps} { /* Ignorar los espacios en blanco */}


{hex}+ {printf("Encontré un hexadecimal %s \n", yytext);}

{identificador} {printf("Encontré un identificador %s \n", yytext);}
{blanco}+ {printf("Encontré un espacio en blanco %s \n", yytext);}

{real} {printf("Encontré un real %s \n", yytext);}
{entero} {printf("Encontre un entero %s \n", yytext);}

{op_arit} {printf("Encontré un operador aritmético %s \n", yytext);}
{op_rel} {printf("Encontré un operador relacional %s \n", yytext);}
{simbolo_especial} {printf("Encontré un símbolo especial %s \n", yytext);}
:= {printf("Encontré el operador de asignación %s \n", yytext);}


<COMILLAS>\" { BEGIN(INITIAL); printf("salgo de comillas %s \n", yytext);}
\" { BEGIN(COMILLAS); printf("Encontré comillas %s \n", yytext);}
<COMILLAS>. {printf("soy un comillado %s \n", yytext);}

-- { BEGIN (COMEN1); printf("Encontré comentario %s \n", yytext);}
<COMEN1>. {}
<COMEN1>\n { BEGIN(INITIAL); printf("salgo de comentario %s \n", yytext);}

{inicio_comen2} { BEGIN (COMEN2); printf("Encontré comentario %s \n", yytext);}
<COMEN2>>* { BEGIN(INITIAL); printf("salgo de comentario %s \n", yytext);}
<COMEN2>. {}



%%

int main(){
    yylex();
}

