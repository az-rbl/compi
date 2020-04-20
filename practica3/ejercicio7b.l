%{
#include <stdio.h>

int noPalabras;
int noLineas;
int noCaracteres;
%}


digito [0-9]
letra [a-zA-Z]
espacio [ \t]
nuevaLin [\n]
esps {espacio}


%%


{digito} {printf("Encontre un número %s \n", yytext); noCaracteres++;}
{letra} {printf("Encontré una palabra %s \n", yytext);noCaracteres++;}
{espacio} {printf("Encontré un espacio %s \n", yytext); noPalabras++; noLineas++;}
{nuevaLin} {printf("Encontré una nueva línea %s \n", yytext); noLineas++;}
%%

int main(){
    noPalabras =0;
    noLineas =0;
    noCaracteres=0;
    
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
    printf("Número de lineas: %d \n", noLineas);
    printf("Número de palabras: %d \n", noPalabras);
    printf("Número de caracters: %d \n", noCaracteres);
}


