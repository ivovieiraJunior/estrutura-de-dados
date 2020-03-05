#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct lista{
	int info;
	struct lista * proximo;
};
typedef struct lista Lista;

Lista* criar_lista(){     // Função do tipo apontador para lista, i.e., o tipo de função tem de ser igual ao tipo que retorna
    Lista * novo;
    novo = (Lista *) malloc( sizeof( lista ));  

    return novo; 
}
Lista * inserir_fim(Lista *ponteiro,int val){
	Lista * novo = criar_lista();
	novo->info=val;
	
	if(ponteiro==NULL) {
	novo->proximo=NULL;
	ponteiro=novo;
	} else{
		Lista * aux= ponteiro;
		while(aux->proximo !=NULL){
			aux = aux->proximo; 
		}
		novo->proximo = NULL;
		aux->proximo = novo;
	}
	return ponteiro;
}	
void emprimir(Lista *ponteiro){
	Lista *emprimir;
	//printf("entrou no emprimir::" );
	for(emprimir = ponteiro; emprimir!= NULL; emprimir =emprimir->proximo){
		printf("valor: %d \n",emprimir->info);
	}
}	

int main(int argc, char** argv) {
	Lista * no = NULL;
	int i=1;
	while(i!=0){
		printf("digite um valor:");
		scanf("%d",&i);
		if(i!=0)
		no = inserir_fim(no,i);
	}
	emprimir(no);
	return 0;
}
