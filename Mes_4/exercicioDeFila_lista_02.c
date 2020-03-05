#include <stdio.h>
#include <stdlib.h>

/*3 – Crie uma fila usando uma lista encadeada e depois teste-a inserindo e
		removendo alguns elementos. 
		
4 – Implemente uma função que imprime os valores armazenados numa fila
		implementada com lista encadeada. Protótipo da função: void fila_imprime(Fila* f) 
		
	5 – Imagine uma situação onde você tem duas filas para entrar num evento que
			precisam ser unificadas. Crie uma função que recebe duas filas e retorna uma
			terceira fila com os elementos das duas filas originais. Os elementos das filas devem
			ser mesclados de forma alternada. Ou seja, o primeiro elemento da terceira fila será
			o primeiro elemento da primeira fila, seguido pelo primeiro elemento da segunda
			fila, seguido pelo segundo elemento da primeira fila, seguido pelo segundo elemento
			da segunda fila e assim por diante.		*/

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
	
	if(ponteiro -> fim != NULL)
		ponteiro -> fim -> proximo = novo;

	else
		ponteiro ->inicio = novo;
		ponteiro ->fim = novo;
	
}


int fila_vazia(Fila * test){
	return (test->inicio == NULL);
}


float pop_fila(Fila * fila){
	Lista * temp;
	float valor;
	if(fila_vazia(fila)){
		printf("Fila Vazia. \n");
		exit(1);
	}
	temp = fila->inicio;
	valor = temp->info;
	fila->inicio = temp->proximo;
	
	if(fila->inicio == NULL)
		fila->fim = NULL;
	
	free(temp);
	
	return valor;	
}
Fila * concatenar_filas(Fila * fila01, Fila* fila02,Fila * fila03){
	float valor;
	while(!fila_vazia(fila01) || !fila_vazia(fila02)){

		if(!fila_vazia(fila01)){
			valor = fila01->inicio->info;
			inserir_fila(fila03, valor);
			fila01->inicio = fila01->inicio->proximo;
		}
		if(!fila_vazia(fila02)){
			valor = fila02->inicio->info;
			inserir_fila(fila03, valor);
			fila02->inicio = fila02->inicio->proximo;
		}
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
	Fila * fila02;
	Fila * fila03;
	
	fila02 = criar_fila();
	fila03 = criar_fila();// NULL
	fila = criar_fila();

	float valor;
	
	inserir_fila(fila,20);
	inserir_fila(fila,30);
	inserir_fila(fila,40);
	inserir_fila(fila,50);
	
	// inserindo na fila 2 
	
	inserir_fila(fila02,25);
	inserir_fila(fila02,35);
	inserir_fila(fila02,45);
	inserir_fila(fila02,55);
	
	printf("\timprimindo a fila 1\n");
	imprimir(fila);
	
	printf("\t imprimindo a fila 2\n");
	imprimir(fila02);
	
	valor = pop_fila(fila);
	
	printf("valor removido da fila 1: %.2f \n",valor);
	
	imprimir(fila);
	printf("\n");
	
	concatenar_filas(fila,fila02,fila03);
	//imprimir a lista 3
	printf("\t imprimindo a lista 3\n");
	imprimir(fila03);
	return 0;
}











