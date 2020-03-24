#include <stdio.h>
//#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include <regex.h>

int afd[6][4];
char c;
bool acep[]={false, true, true,false, true, true};

int yylex(){
int q;
char yytext[20];
q=0;
strcpy(yytext, "");
while(true){
    if(afd[q][c]=!-1)
    {
        q =afd[q][c];
        strcat( yytext, c);//añadir el caractyer a la cadena
        c =sig_caracter();
    }
    else{
        if (acep[q]==true)
        {
            if (q ==5){q = 0;
            strcpy(yytext, "");
            }
            else return gentoken(q, yytext);
        }
        else return 5;
    }
}

int error(){
printf("error");
return 5;
}

}

struct token{
int clase;
char valor[20];
}token;

int gentoken(int q, char lex[]){
switch(q){
    case 1:
        token.clase = 1;
        strcpy(token.valor, lex);
        return 1;
    case 2:
        token.clase = 2;
        strcpy(token.valor, lex);
        return 2;
    case 4:
        token.clase = 4;
        strcpy(token.valor, lex);
        return 4;

}

}

char sig_caracter()
{

}


int main(void)
{
    return 0;
}





