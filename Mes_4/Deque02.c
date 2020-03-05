#include <stdio.h>
#include <stdlib.h>
# define N 10

/*2 – Crie um deque (fila dupla) usando uma lista encadeada, e:
		a) Construa uma função para inserir um novo nó em qualquer uma das duas
			extremidades da fila dupla implementada com lista encadeada. A
			extremidade onde deve ser realizada a inserção deve ser passada como
			parâmetro (considere os parâmetros 0 para início e 1 para fim).
		
		b) Construa uma função para remover um novo nó de qualquer uma das duas
			extremidades da fila dupla implementada com lista encadeada. A
			extremidade onde deve ser realizada a remoção deve ser passada como
			parâmetro (considere os parâmetros 0 para início e 1 para fim). O algoritmo
			deve retornar o parâmetro removido.
			
		c) Construa uma função que retorna o valor contido em uma das
			extremidades da fila dupla implementada com lista encadeada. A
			extremidade considerada deve ser passada como parâmetro (considere os
			parâmetros 0 para início e 1 para fim). */
		
	// Deque C/ lista emcadeada 
struct no{
	int info;
	struct no * anterior;
	struct no * proximo;
};
typedef struct no NO;


struct deque{
	NO * inicio;
	NO * fim;
};
typedef struct deque Deque;


Deque * cria_Deque_Lista(){
	Deque * deque = (Deque*) malloc (sizeof(Deque));
	deque->inicio =NULL;
	deque->fim = NULL;
	return deque;
}


int deque_vazio(Deque * deque){
	return (deque->inicio == NULL);
}


void deque_inserir_inicio(Deque * deque, int valor){
	NO * novo =(Deque*) malloc (sizeof(Deque));
	novo->info = valor;
	novo->proximo =  deque->inicio;
	novo->anterior = NULL;
	if(deque->inicio != NULL)
		deque->inicio->anterior = novo;
	else
		deque->fim = novo;
	deque->inicio = novo;
}


void deque_inserir_fim(Deque * deque, int valor){
	NO * novo =(Deque*) malloc (sizeof(Deque));
	novo->info = valor;
	novo->proximo = NULL;
	novo->anterior = deque->fim;
	if(deque->fim != NULL)
		deque->fim->proximo = novo;
	else
		deque->inicio = novo;
	deque->fim = novo;
}


void imprimir(Deque *deque){

	NO * lista;
	lista = deque->inicio;
	while(lista !=NULL){
		printf("\n Valor: %d", lista->info);
		lista = lista->proximo;
	}
}


void inserir(int lugar ,Deque * deque, int valor){
	if(lugar == 0)
		deque_inserir_inicio(deque, valor);
	else
		deque_inserir_fim(deque, valor);
}


int deque_retira_inicio(Deque * deque){
	if(deque_vazio(deque)){
		printf("Deque vazio.\n");
		exit(1);
	}
	int valor = deque->inicio->info;
	NO *novo_ini = deque->inicio->proximo;
	if(novo_ini != NULL)
		novo_ini->anterior = NULL;
	else
		deque->fim = NULL;
		free(deque->inicio);
		deque->inicio = novo_ini;
		return valor;
}


int deque_retira_fim(Deque * deque){
	if(deque_vazio(deque)){
		printf("Deque vazio.\n");
		exit(1);
	}
	int valor = deque->fim->info;
	NO *novo_fim = deque->fim->anterior;
	if(novo_fim != NULL)
		novo_fim->proximo = NULL;
	else
		deque->inicio = NULL;
		free(deque->fim);
		deque->fim = novo_fim;
		return valor;
}


 // Deque c/ vetor

struct dequevet{
	int quant_Elemt;
	int inicio;
	float vetor[N];
};
typedef struct dequevet DequeVet;


static int decrementa (int ini){
	return (ini -1 + N ) % N;
}


DequeVet * criar_deque_Vetor(){
	DequeVet * novo = (DequeVet*) malloc (sizeof(DequeVet));
	novo->inicio = 0;
	novo->quant_Elemt = 0;
	return novo;
}
 
 
void deque_inserir_vetor(DequeVet * deque, float valor){
	
	if (deque->quant_Elemt == N){ // nao tem malloc porque e um vetor so aloca uma vez 
		printf("\n Deque estourou !!");
		exit(1);
	}
	int precedente;
	precedente = (deque->inicio -1 + N ) % N;
	deque->vetor[precedente] = valor;
	deque->inicio = precedente;  // atualiza a indice atual 
	deque->quant_Elemt ++;       // add mais um no numero de elementos
	
	// nao tem return porque e um vetor (ponteiro)
}


float retirar_vetor_fim(DequeVet * vet){
	int ultimo;
	float valor;
	if (Deque_vazio(vet)){
		printf("Deque vazio !!");
		exit(1);
	}
	/*retira  o ultimo elemento  */
	ultimo = (vet->inicio + vet->quant_Elemt -1)% N;
	valor = vet->vetor[ultimo];
	vet->quant_Elemt--;
	return valor;
}


float retirar_vetor_ini(DequeVet * vet){
	float valor;
	if (Deque_vazio(vet)){
		printf("Deque vazio !!");
		exit(1);
	}
	/*retira  o ultimo elemento  */
	valor = vet->vetor[vet->inicio];
	vet->inicio = (vet->inicio +1) % N;
	vet->quant_Elemt --;
	return valor;
}
  
int Deque_vazio(DequeVet * vet){
	return (vet->quant_Elemt == 0);
}
 
 
void imprimirVet (DequeVet * vet){
	
	int conta =  vet->inicio;
	int numeroElemt = 0;
	while(conta < N && numeroElemt < vet->quant_Elemt) {
		printf("\n valor: %.2f", vet->vetor[conta] );
		if(conta == N)
			conta = 0;
		numeroElemt++;
		conta++;
	}
}

int main(int argc, char *argv[]) {
	/* // Deque C/ Lista
	Deque *deque;
	deque = cria_Deque_Lista();
	
	// execicio a);
	deque_inserir_fim(deque,10);
	deque_inserir_fim(deque,20);
	deque_inserir_fim(deque,30);
	deque_inserir_fim(deque,40);
    inserir(1,deque,40);
	inserir(1,deque,30);
	inserir(1,deque,20);
	inserir(1,deque,10);
	inserir(0,deque,20);
	inserir(0,deque,30);
	inserir(0,deque,40);
	
	imprimir(deque);
	
	// exercicio b);
	
	int valor;
	valor =	deque_retira_inicio(deque);
	printf("\n\n valor retirado do inicio: %d", valor);
	
	valor =	deque_retira_fim(deque);
	printf("\n\n valor retirado do fim: %d", valor);

	imprimir(deque);
	
	// exercicio c);
	
	printf("\n\nvalor inicio: %d", deque->inicio->info);
	
	printf("\n\nvalor inicio: %d", deque->fim->info);
	*/
	
	
	
	// Deque c/ vetor
	
	DequeVet * vet;
	vet = criar_deque_Vetor();
	
	float valor;
	
	deque_inserir_vetor(vet, 2);
	deque_inserir_vetor(vet, 3);
	deque_inserir_vetor(vet, 4);
	deque_inserir_vetor(vet, 7);
	deque_inserir_vetor(vet, 5);
	
	printf(" \n tamanho: %d",vet->quant_Elemt);

	
	imprimirVet(vet);
	
	valor = retirar_vetor_fim(vet);
		
	printf("\n valor retirado do fim: %.2f", valor);

	imprimirVet(vet);
	
	valor = retirar_vetor_ini(vet);
	
	printf("\n valor retirado do inicio: %.2f", valor);

	imprimirVet(vet);
	
	return 0;
}

