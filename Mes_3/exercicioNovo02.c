#include <stdio.h>
#include <stdlib.h>

/* 2 - Implemente uma função que tenha como valor de retorno o ponteiro
para o último nó de uma lista encadeada. Essa função deve obedecer ao protótipo: 

Lista* ultimo (Lista* l);. */
struct lista{
	int info;
	struct lista * proximo;
};
typedef struct lista * Lista;

Lista * criar_lista(){
	return NULL;
}
Lista * inserir_fim(Lista * ponteiro , int valor){
	Lista * novo = (Lista*) malloc (sizeof(Lista));
	novo->info = valor;
	novo->proximo = NULL;
	
	if(ponteiro == NULL){// se a lista for vazia
		return novo;
	} 
	Lista * aux;
	for(aux = ponteiro; aux != NULL; aux = aux->proximo);

	aux->proximo = novo;
	
	return ponteiro;
}
Lista * ultimo (Lista * l){
	for(l;l->proximo!=;l= l->proximo);
	return l;
}
int main(int argc, char *argv[]) {
	Lista * no;
	Lista * aux;
	no = criar_lista();
	
	no = inserir_fim(no,10);
	no = inserir_fim(no,20);
	no = inserir_fim(no,5);
	no = inserir_fim(no,21);
	no = inserir_fim(no,2);
	
	aux = (no); 
	
	return 0;
}
