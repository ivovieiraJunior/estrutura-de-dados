#include <stdio.h>
#include <stdlib.h>
# define N 10;
/* 1 – Crie um deque (fila dupla) usando um vetor, e:
		a) Construa uma função para inserir um novo nó em qualquer uma das duas
			extremidades da fila dupla implementada com vetor. A extremidade onde
			deve ser realizada a inserção deve ser passada como parâmetro (considere
			os parâmetros 0 para início e 1 para fim). O algoritmo deve retornar 0 ou 1
			indicando se a inclusão foi realizada com sucesso. */
			

struct deque{
	int quantidade;
	int inicio;
	float vetor[N];
};
typedef struct deque Deque;


static int decrementa (int ini){
	return (ini -1 + N ) % N;
}


Deque * cria_deque()

int main(int argc, char *argv[]) {
	return 0;
}
