#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct lista{
	int info;
	struct lista * proximo;
};
typedef lista Lista;

Lista * criar_lista(){
	Lista *novo =(Lista*)malloc (sizeof(Lista));
	return novo;
}

Lista *inserir_fim(Lista *ponteiro, int val){
	Lista * novo=criar_lista();
	novo->info=val;
	
	if(ponteiro==NULL){
		novo->proximo=NULL;
		ponteiro =novo; //inserir no ponteiro a proxima posição vazia;
	} else{
		Lista *auxiliar= ponteiro; //auxiliar pega a nova posiçao da lista que e NULL;
		while(auxiliar->proximo!=NULL){
			auxiliar = auxiliar->proximo;//percorrer o fim da lista para adicionar o novo No;
		}
		novo->proximo=NULL;
		auxiliar->proximo=novo;
	}
	
	return ponteiro;
}

void emprimir(Lista * No){
	Lista *emprimir =No;
	while(emprimir!=NULL){
		printf("valor: %d \n",emprimir->info);
		emprimir=emprimir->proximo;
	}
}
int main(int argc, char** argv) {
	Lista * no=NULL;
	int valor=1;
	while(valor!=0){
		printf("digite um valor:(zero pra sair)");
		scanf("%d", &valor);
		if(valor!=0)
		no = inserir_fim(no,valor);	
	}
	emprimir(no);
	return 0;
}
