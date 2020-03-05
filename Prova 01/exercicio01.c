#include <stdio.h>
#include <stdlib.h>

/* 1. */



Lista * remover_no (int posicao, Lista * ponteiro){
	
		int contador = 1;
		Lista * atual;
		Lista * anterior;
		atual = ponteiro;
		if(aux->prox != NULL){
			while(atual != NULL && contador < posicao){
				
				anterior = aux->info;
				atual = aux->proximo;
			}
		}else{
			free(atual);
			ponteiro = NULL;
		}
		anterior->prox = atual->proximo;
		free(atual);
		
		return lista;
}

int main(int argc, char *argv[]) {
	return 0;
}
