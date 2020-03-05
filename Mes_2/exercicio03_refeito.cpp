#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* 3 - Crie uma função que insere um elemento na posição n de uma lista encadeada. */

struct lista{
	int info;
	struct lista * proximo;
};
typedef struct lista Lista;

Lista * criar_lista(){
	Lista * novo=(Lista*)malloc (sizeof(Lista));
	return novo;
}
Lista * inserir_fim(Lista * ponteiro, int val){
	Lista *novo = criar_lista();
	novo->info=val;
	
	if(ponteiro==NULL){
		novo->proximo=NULL;
		ponteiro=novo;
	}else{
		Lista * auxiliar= ponteiro;
		while(auxiliar->proximo!=NULL){
			auxiliar =auxiliar->proximo;	
		}
		novo->proximo=NULL;
		auxiliar->proximo=novo;
	}
	return ponteiro;
}

void emprimir(Lista * No){
	Lista *emprimir=No;
	while(emprimir->proximo!=NULL){
		printf("\nvalor: %d \n",emprimir->info);
		emprimir= emprimir->proximo;
	}
}
int main(int argc, char** argv) {
	Lista *no= NULL;
	int valor=1;
	int valor2;
	int posicaoN;
	while(valor!=0){
		printf("digite um valor:(zero pra sair)");
		scanf("%d",&valor);
		if(valor!=0)
		no = inserir_fim(no,valor);
	}
	printf("ditite a posicao na lista:");
	scanf("%d",&posicaoN);
	printf("digite um valor a inserir:(maior que zero)");
	scanf("%d",&valor2);
	int contador =1;
	while(contador<=posicaoN){
		if(contador!=posicaoN){
			no = inserir_fim(no,0);	
			printf("valor:%d  ,", valor2);
		}
		if(contador==posicaoN) {
			printf("valor02:%d  ,", valor2);
			no = inserir_fim(no,valor2);
		}	
	contador++;
	}
	emprimir(no);
	return 0;
}
