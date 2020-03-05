#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct cel {

char conteudo;
struct cel *prox;
} celula;

void empilha(char c, celula *topo) { /* Atenção Aqui*/

celula *nova;
nova = malloc( sizeof (celula)); /* Principal erro do programa!! */
nova->conteudo = c;
nova->prox = topo->prox;
topo->prox = nova;

}

char desempilha(celula *topo) {

char c;
celula *pt;
pt = topo->prox;
c = pt->conteudo;
topo->prox = pt->prox;
free(pt);
return c;

}

int main() {

char frase[50];
int i;
celula cabeca;
celula *topo;
topo = &cabeca; 
topo->prox = NULL;
printf("Informe a frase: ");
gets(frase); /* Possível erro aqui  ()*/
for (i=0; frase != '\0'; i++)
empilha(frase, topo); /* Talvez erro aqui ()*/
printf("\nInvertida: ");
while (topo->prox != NULL)
putchar(desempilha(topo));
putchar('\n');
return 0;

}
