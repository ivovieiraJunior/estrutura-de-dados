#include <stdio.h>
#include <stdlib.h>
# define N 10
/* 1 – Crie uma fila usando um vetor e depois teste-a inserindo e removendo alguns
elementos.

2 – Implemente uma função que imprime os valores armazenados numa fila
		implementada com vetor. Protótipo da função: void fila_imprime(Fila* f). */

struct fila {
	int n;
	int ini;
	float vet[N];
};
typedef struct fila Fila;

Fila * criar_fila(){
	Fila * novo = (Fila*) malloc (sizeof(Fila));
	novo ->n = 0;
	novo ->ini = 0;
	return novo;
}
void inserir_fila(Fila * ponteiro, float valor){
	int fim;
	if(ponteiro->n ==N){
		printf("Capcidade da fila esgotou!!");
		exit(1);
	}
	fim = (ponteiro ->ini + ponteiro ->n) % N;
	ponteiro ->vet[fim] = valor;
	ponteiro ->n ++;
	
}
int fila_vazia(Fila * fila){
	return (fila->n == 0);
}

float pop_fila(Fila * ponteiro){
	float valor;
	if(fila_vazia(ponteiro)){
		printf("Fila Vazia.\n");
		exit(1);
	}
	
	valor = ponteiro ->vet[ponteiro->ini];
	ponteiro ->ini = (ponteiro->ini + 1) % N;
	ponteiro-> n--;
	return valor;
}


void imprimir(Fila * ponteiro){
	int qtd;
	qtd = (ponteiro->ini + ponteiro->n) %N;
	int c = ponteiro->ini;
	while(c != qtd){
		
		if(c == N)
			c = 0;
			
		printf("valor: %.2f \n", ponteiro->vet[c]);
		
		c++;
	}
}

int main(int argc, char *argv[]) {
	
	Fila * fila;
	fila = criar_fila();
	
	inserir_fila(fila,10);
	inserir_fila(fila,11);
	inserir_fila(fila,12);
	inserir_fila(fila,13);
	inserir_fila(fila,14);
	inserir_fila(fila,15);
	
	
	imprimir(fila);
	
	float valor = pop_fila(fila);
	printf("valor removido: %f\n",valor);
	
	imprimir(fila);
	return 0;
}
