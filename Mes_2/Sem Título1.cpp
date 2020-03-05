#include <stdio.h>
#include <stdlib.h>

//1–Crie uma função que insere um elemento no final de uma lista encadeada.

typedef struct no No;
struct no{
	int num;
	struct no * prox;
}; 

No * criar_no(){
	No * no = (No*)malloc(sizeof(No));
	return no;
}

No * inserir_elemento_fim(No * Lista, int dado){
	No * no = criar_no();
	no->num=dado;
	
	if(Lista==NULL){
		no->prox=NULL;
		Lista=no;
	}else{
		No * aux = Lista;
		while(aux->prox!=NULL){
			aux = aux->prox;
		}
		no->prox = NULL;
		aux->prox = no;
	}
	return Lista;
}

void imprimir(No * Lista){
	No * aux = Lista;
	while(aux!=NULL){
		printf(" %d \n",aux->num);
		aux = aux->prox;
	}
}

int main(){
	
	No * lista = NULL;
		
	lista = inserir_elemento_fim(lista,5);
	lista = inserir_elemento_fim(lista,10);
	lista = inserir_elemento_fim(lista,15);
	lista = inserir_elemento_fim(lista,25);
	imprimir(lista);
	
	return 0;
}

