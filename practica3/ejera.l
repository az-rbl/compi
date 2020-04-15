%{
#include <stdio.h>
%}


%%


A {printf("a");}
B {printf("b");}
C {printf("c");}
D {printf("d");}
E {printf("e");}
F {printf("f");}
G {printf("g");}
H {printf("h");}
I {printf("i");}
J {printf("j");}
K {printf("k");}
L {printf("l");}
M {printf("m");}
N {printf("n");}
Ñ {printf("ñ");}
O {printf("o");}
P {printf("p");}
Q {printf("q");}
R {printf("r");}
S {printf("s");}
T {printf("t");}
U {printf("u");}
V {printf("v");}
W {printf("w");}
X {printf("x");}
Y {printf("y");}
Z {printf("z");}

Á {printf("á");}
É {printf("é");}
Í {printf("í");}
Ó {printf("ó");}
Ú {printf("ú");}

. {printf("%s", yytext);}


%%

int main(){
    yylex();
}
