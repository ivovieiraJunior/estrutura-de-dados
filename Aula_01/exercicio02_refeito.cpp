#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/* 2 Crie uma fun��o que tenha como valor de retorno o comprimento de uma lista 
encadeada, isto �, que calcule o n�mero de n�s de uma lista. Essa fun��o deve 
obedecer ao prot�tipo � int comprimento (Lista* l); � */

struct lista{
	int val;
	struct lista * proximo;
};
typedef struct lista Lista;

Lista * criar_lista(void){
	return NULL;
}
Lista * inserir_inicio(Lista * ponteiro_inicio, int info){
	Lista * novo_espaco = (Lista*) malloc (sizeof(Lista)); 
	novo_espaco->val=info;
	novo_espaco->proximo=ponteiro_inicio;
	
	return novo_espaco;
}
int comprimento (Lista * Nos){
	Lista * ponteiro;
	int conta_comprimento=0;
	for(ponteiro=Nos;ponteiro!=NULL;ponteiro=ponteiro->proximo){
		conta_comprimento++;
	}
	return conta_comprimento;
}
int main(int argc, char** argv) {
	Lista * no;
	no =criar_lista();
	int valor=1;
	while(valor != 0){
		printf("digite um valor:(zero pra sair)");
		scanf("%d",&valor);
		if(valor!=0)
		no= inserir_inicio(no,valor);
	} 
	int contador = comprimento(no);
	
	printf("comprimento da lista eh %d", contador);
	
	return 0;
}






