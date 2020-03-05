#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* 1– Crie uma função que insere um elemento no final de uma lista encadeada.*/

struct lista{
	int varialvel;
	struct lista* proximo;
};
typedef struct lista Lista;
Lista *primeiro = NULL;
Lista * criar_lista(void){	
	return NULL; 
}
Lista * inserir_inicio(Lista * ponteiro,int i){
	Lista * novo_espaco = (Lista*) malloc(sizeof(lista));
	novo_espaco->varialvel= i;
	novo_espaco->proximo= ponteiro;
	
	
	return novo_espaco;
}
void inserir_fim(int valor)//Insere um nó na ultima posição
{
   // if (primeiro == NULL)
   // {
       // inserir_inicio(valor);
    //    return;
   // }
    Lista *no = primeiro, *novo;
    while (no->proximo != NULL)
    {
        no = no->proximo;
    }
    novo = (Lista*) malloc (sizeof(Lista));
    novo->varialvel = valor;
    novo->proximo = NULL;
    no->proximo = novo;
}

void emprimir(Lista * ponteiro_i){
	Lista * ponteiro_l;
	int contador=0;
	for(ponteiro_l=ponteiro_i;ponteiro_l !=NULL;ponteiro_l =ponteiro_l->proximo){
		printf("info = %d \n",ponteiro_l->varialvel);
		contador++;
	}		
	printf("comprimento da lista encadeada %d", contador);
}
int comprimento(Lista * ponteiro_L){
	int conta_comprimento=0;
	Lista * ponteiro_conta;
		for(ponteiro_conta=ponteiro_L;ponteiro_conta !=NULL;ponteiro_conta=ponteiro_conta->proximo)
		conta_comprimento++;
	
	
	return conta_comprimento;
}
int main(int argc, char** argv) {
	Lista* armazenar;
	int info=1;
	int fim=1;
	armazenar =criar_lista();
	while(info!=0){
		printf("digite o numero inteiro a armazenar:");
		scanf("%d",&info);
		if(info!=0)
		armazenar = inserir_inicio(armazenar,info);

	}
	emprimir(armazenar);
	info=comprimento(armazenar);
	printf("comprimento da Lista encadeada %d",info);
	return 0;
}






























