#include <stdio.h>
#include <stdlib.h>
#define N 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct lista{
	int tamanho;
	int Vetor[N];
};  
typedef struct lista Lista;

Lista * Criar_lista(){
	Lista * novo = (Lista*) malloc (sizeof (Lista));
	novo->tamanho = 0;
	return novo;
}
void inserir(Lista * novo, int valor){
	if(novo->tamanho == N){
		printf("Pilha estourou!!");
		exit(1);
	}
	novo->Vetor[novo->tamanho] = valor;
	novo->tamanho++;
}

void imprimir(Lista * aux){
	int contador =0;
	while(contador < aux->tamanho){
		printf("\n valor: %d", aux->Vetor[contador]);
		contador++;
	}
}

int main(int argc, char *argv[]) {
	Lista * no = Criar_lista();
	
	inserir(no,10);
	inserir(no,20);
	inserir(no,30);
	inserir(no,40);
	inserir(no,50);
	
	imprimir(no);
	
	printf("\n");
	
	imprimir(no);
	return 0;
}
