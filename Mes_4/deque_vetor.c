#include <stdio.h>
#include <stdlib.h>
# define N 10;
/* 1 � Crie um deque (fila dupla) usando um vetor, e:
		a) Construa uma fun��o para inserir um novo n� em qualquer uma das duas
			extremidades da fila dupla implementada com vetor. A extremidade onde
			deve ser realizada a inser��o deve ser passada como par�metro (considere
			os par�metros 0 para in�cio e 1 para fim). O algoritmo deve retornar 0 ou 1
			indicando se a inclus�o foi realizada com sucesso. */
			

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
