#include <stdio.h>
#include <stdlib.h>

/* 4 – Implemente uma função que imprime os valores armazenados numa fila
		implementada com lista encadeada. Protótipo da função: void fila_imprime(Fila* f) */

struct lista{
	float info;
	struct lista * proximo;
};
typedef struct lista Lista;

struct fila{
	struct lista * inicio;
	struct lista * fim;
};
typedef struct fila Fila;

Fila * criar_fila(){
	Fila * novo = (Fila*) malloc (sizeof(Fila));
	novo -> fim = NULL;
	novo -> inicio = NULL;
	
	return novo;
}


void inserir_fila(Fila * ponteiro, float valor){
	
	Lista * novo = (Lista*)malloc (sizeof(Lista));
	
	novo-> info = valor;
	novo-> proximo = NULL;
	
	if(ponteiro -> fim != NULL){
		ponteiro -> fim -> proximo = novo;
		ponteiro->fim = novo;
	}
	else{
		ponteiro ->inicio = novo;
		ponteiro ->fim = novo;
	}
	
}


void imprimir(Fila * ponteiro){
	Lista * aux;
	aux = ponteiro -> inicio;
	while (aux != NULL){
		printf("valor: %.2f \n", aux->info);
		
		aux = aux -> proximo; 
	}
}
int main(int argc, char *argv[]) {
	
	Fila * fila;
	fila = criar_fila();
	
	
	inserir_fila(fila,20);
	inserir_fila(fila,25);
	inserir_fila(fila,30);
	inserir_fila(fila,40);
	
	
	imprimir(fila);
	printf("\n");
	imprimir(fila);
	return 0;
}











