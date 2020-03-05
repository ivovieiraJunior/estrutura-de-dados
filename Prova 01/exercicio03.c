#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct lista{
	int info;
	struct lista *proximo;
	struct lista *anterior;
};
typedef struct lista Lista;

struct deque{
	Lista * inicio;
	Lista * fim;
}; 
typedef struct deque Deque;

Lista* criar_lista(){
	return NULL;
}

Deque * criar_deque(){
	Deque * novo = (Deque*) malloc (sizeof(Deque));
	novo-> inicio = NULL;
	novo-> fim = NULL;
}

void inserir_inicio(Deque * deque , int valor){
	Lista * novo = (Lista*) malloc (sizeof(Lista));
	novo->info = valor;
	novo->proximo = deque->inicio;
	novo->anterior = NULL;
	if(deque->inicio !=NULL)
		deque->inicio->anterior= novo;
	else 
		deque->fim = novo;
	deque->inicio = novo;
} 

void inserir_fim(Deque * deque , int valor){
	Lista * novo = (Lista*) malloc (sizeof(Lista));
	novo->info = valor;
	novo->proximo = NULL;
	novo->anterior = deque->fim;
	if(deque->fim !=NULL)
		deque->fim->proximo = novo;
	else 
		deque->inicio = novo;
	deque->fim = novo;
} 

void imprimir(Deque * deque){
	Lista *aux;
	aux = deque->inicio;
	
		
	while(aux != NULL){
		printf("\n valor: %d",aux->info);
		aux = aux->proximo;
	
	}
}

int remover_inicio(Deque * deque){
	int valor;
	Lista * aux;
	aux = deque->inicio;
	deque->inicio = deque->inicio->proximo;
	valor = aux->info;
	free(aux);
	return valor;
}

int remover_fim(Deque * deque){
	//printf("\ valor do fim: %d \n\n", deque->fim->info);
	//printf("\ valor anterior do fim: %d \n\n", deque->fim->anterior->info);
	
	
	int valor;
	Lista * aux;
	aux = deque->fim;
	deque->fim = deque->fim->anterior;
	deque->fim->proximo = NULL;
	valor = aux->info;
	free(aux);
	
	return valor;
}
int main(int argc, char *argv[]) {
	
	Deque * deque = criar_deque();	
	Lista * lista = criar_lista();
	
	inserir_inicio(deque, 10);
	inserir_inicio(deque, 10);
	inserir_inicio(deque, 10);
	inserir_inicio(deque, 10);
	
	imprimir(deque);
	
	printf("\n ");
	
	inserir_fim(deque, 20);
	
	imprimir(deque);
	
	printf("\n ");	
	
	int valor;
	valor = remover_inicio(deque);
	
	printf("valor removido inicio: %d", valor);
	
	printf("\n");
	
	imprimir(deque);
	
	printf("\n");
	
	valor = remover_fim(deque);
	
	printf("valor removido do fim: %d", valor);
	
	printf("\n");
	
	imprimir(deque);
		
	return 0;
}











