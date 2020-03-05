#include <stdio.h>
#include <stdlib.h>
#define N 10
/* qual o nome dessa estrutura de dados e a Fila statica e com vetor */

struct Fila{
	int n;
	int vetor[N];
};


void push(Fila* fila, int valor){
	
	if(fila->n == N){
		printf("Fila está cheia!!");
		exit(1);
	}
	fila->vetor[fila->n] = valor;
	Fila->n++;	
}

int pop (Fila *fila){
	int valor;
	if(fila->n == 0){
		printf("fila Vazia!!");
		exit(1);
	}
	valor = fila->vetor[fila->n];
	fila->n--;
	
	return valor; 
}


int main(int argc, char *argv[]) {
	return 0;
}
