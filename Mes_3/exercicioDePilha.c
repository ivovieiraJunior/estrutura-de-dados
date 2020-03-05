#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* 1- Implemente um programa que inverte palavras usando uma pilha. */

struct lista{
	char letra;
	struct lista * proximo;
};
typedef struct lista Lista;

struct pilha{
	struct Lista * topo;
};
typedef struct pilha Pilha;

Pilha * criar_pilha(){
	Pilha * ponteiro = (Pilha*) malloc (sizeof(Pilha));
	ponteiro->topo = NULL;
	return ponteiro;
}
Pilha * pilha_push(Pilha * ponteiro, char Caracter){
	Lista * novo = (Lista*) malloc (sizeof(Lista));
	novo->letra = Caracter;
	novo->proximo = ponteiro->topo;
	ponteiro->topo = novo;
}
int pilha_vazia(Pilha * p){
	return (p->topo == NULL);
}
char pilha_pop(Pilha * ponteiro){
	char letr;
	Lista * aux;
	if(pilha_vazia(ponteiro)){
		Printf("pilha vazia .\n");
		exit(1);
	}
	aux = ponteiro->topo;
	letr = aux->letra;
	ponteiro->topo = aux->proximo;
	free(aux);
	
	return letr;
}

int main(int argc, char *argv[]) {
	Pilha * no;
	no = criar_pilha();
	Lista * NO;
	char palavra[20];
	int contador=0;
	int tamanho = strlen(palavra);
	printf("digite uma palavra:");
	scanf("%s", palavra);
	//printf("%s ",palavra);
	
	while(contador < tamanho ){
		pilha_push(no,palavra[contador]);
		contador++;
	}
	while(NO != NULL){
		printf("%c",pilha_pop(no));
	NO = NO->proximo;
	}
	return 0;
}









