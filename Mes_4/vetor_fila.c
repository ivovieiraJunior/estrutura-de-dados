#include <stdio.h>
#include <stdlib.h>
#define N 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct fila {
	int elementos;
	int inicio;
	int vetor[N];
};
typedef struct fila Fila;

Fila * criar_fila(){
	Fila * novo = (Fila*) malloc (sizeof(Fila));
	novo->elementos = 0;
	novo->inicio = 0;
}
void inserir (Fila * novo, int valor){
	if(novo->elementos == N){
		printf("Fila esta cheia !!");
		exit(1);
	}
	int fim;
	fim = (novo->elementos + novo->inicio)%N;
	novo->vetor[fim] = valor;
	novo->elementos++;
}

int remover(Fila *novo){
	int valor;
	
	if(novo->elementos == 0){
		printf("\n Fila vazia!!");
		exit(1);
	}
	
	valor = novo->vetor[novo->inicio];
	novo->inicio = (novo->inicio + 1 )%N;
	novo->elementos--;
	return valor;
}

void imprimir(Fila * ponteiro){
	int contador = ponteiro->inicio;
	int qtd = (ponteiro->elementos + ponteiro->inicio) %N;
	while(contador != qtd){
		
		if(contador == N)
			contador = 0;
			
		printf("\n valor: %d", ponteiro->vetor[contador]);
		
		contador ++;		
	} 
}
int main(int argc, char *argv[]) {
	
	Fila * fila;
	fila = criar_fila();
	
	inserir(fila,10);
	inserir(fila,11);
	inserir(fila,12);
	inserir(fila,13);
	inserir(fila,14);
	inserir(fila,15);
	
	
	imprimir(fila);
	printf("\n");
	int valor;
	valor = remover(fila);
	printf("valor removido foi: %d \n", valor);
	imprimir(fila);
	
	return 0;
}
