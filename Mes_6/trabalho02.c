#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
			parâmetros 0 para início e 1 para fim).
			
		1) (4,5Pontos)A loja “ADS MegaStore”cadastra seus clientes com as seguintes informações:
		nome, endereço e telefone.  */
		
	// Deque C/ lista emcadeada 
	
struct no{
	char nome[40];
	char endereco[100];
	int telefone;
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


void deque_inserir_inicio(Deque * deque, int telefone, char nome[],char endere[]){
	NO * novo =(NO*) malloc (sizeof(NO));
	novo->telefone = telefone;
	strcpy(novo->nome, nome);
	strcpy(novo->endereco, endere);
	novo->proximo =  deque->inicio;
	novo->anterior = NULL;
	if(deque->inicio != NULL)
		deque->inicio->anterior = novo;
	else
		deque->fim = novo;
	deque->inicio = novo;
}


void deque_inserir_fim(Deque * deque, int telefone, char nome[],char endere[]){
	NO * novo =(NO*) malloc (sizeof(NO));
	novo->telefone = telefone;
	strcpy(novo->nome, nome);
	strcpy(novo->endereco, endere);
	novo->proximo = NULL;
	novo->anterior = deque->fim;
	if(deque->fim != NULL)
		deque->fim->proximo = novo;
	else
		deque->inicio = novo;
	deque->fim = novo;
}


void inserir(Deque * deque,char nome[], char endere[] , int telefone){
	if(deque == NULL){
		deque_inserir_inicio(deque, telefone,  nome, endere);
	}
}


void  deque_retira_inicio(Deque * deque){
	if(deque_vazio(deque)){
		printf("Deque vazio.\n");
		exit(1);
	}
	char nome[40];
	strcpy(nome,deque->inicio->nome);
	NO *novo_ini = deque->inicio->proximo;
	if(novo_ini != NULL)
		novo_ini->anterior = NULL;
	else
		deque->fim = NULL;
		free(deque->inicio);
		deque->inicio = novo_ini;
	printf("Nome Retirado: %s", nome);
	//return nome;
}


void deque_retira_fim(Deque * deque){
	if(deque_vazio(deque)){
		printf("Deque vazio.\n");
		exit(1);
	}
	char nome[40];
	strcpy(nome,deque->inicio->nome);
	NO *novo_fim = deque->fim->anterior;
	if(novo_fim != NULL)
		novo_fim->proximo = NULL;
	else
		deque->inicio = NULL;
		free(deque->fim);
		deque->fim = novo_fim;
	printf("\nNome Retirado: %s", nome);
	//	return nome;
}


void deque_retira_no(Deque * deque , char retirar[]){
	if(deque_vazio(deque)){
		printf("Deque Vazio. \n");
		exit(1);
	}	
	
	if((strcmp(deque->inicio->nome, retirar) == 0)){
		deque_retira_inicio(deque);
	}
	if((strcmp(deque->fim->nome, retirar) == 0)){
		deque_retira_fim(deque);
	}
	char retirado[40];
	NO * no = deque->inicio;
	NO * aux;
	char nomeRe[40];
	strcpy(nomeRe,no->nome);
	while(deque!= NULL){
		if((strcmp(nomeRe , retirar )) == 0){
			aux = no;
			no->proximo->anterior = no->anterior;
			no->anterior->proximo = no->proximo;
			strcpy(retirado , aux->nome);
			free(aux);
		}
		
		no = no->proximo;
	}
	printf("\nNome Retirado: %s", retirado);
}


void imprimir(Deque *deque){

	NO * lista;
	lista = deque->inicio;
	while(lista !=NULL){
		printf("\n Nome: %s", lista->nome);
		lista = lista->proximo;
	}
}


void buscar(Deque *deque , char buscar[]){

	NO * lista;
	lista = deque->inicio;
	while(lista !=NULL){
		if((strcmp(lista->nome, buscar))==0){
			printf("\n Nome: %s", lista->nome);
		}
		lista = lista->proximo;
	}
}

void Menu(){
	printf("\n==== Menu ====\n");
	printf("\tOpçoes\n");
	printf("[1] Inserir Pessoa\n");
	printf("[2] Buscar (Pelo Nome)\n");
	printf("[3] Retirar (Pelo Nome)\n");
	printf("[4] sair\n");
}


int main(int argc, char *argv[]) {
	Deque *deque;
	deque = cria_Deque_Lista();
	
	int opcao = 5;
	char nome[40];
	char endereco[100];
	int telefone;
	
	while(opcao != 4){
	
		Menu();
		scanf("%d", &opcao);
		switch (opcao){
		
			case 1:
				printf("\nNome:");
				scanf("%s", nome);
				fflush(stdin);
				printf("\nEndereço");
				scanf("%s", endereco);
				fflush(stdin);
				printf("\nTelefone");
				scanf("%d", &telefone);
			
				inserir(deque, nome, endereco, telefone);
			
			break;
			case 2:
				printf("Nome (Buscar)");
				scanf("%s", nome);
				fflush(stdin);
				buscar(deque, nome);
				break;
			case 3:
				break;
			case 4:
				printf("\n\tBye.!!");
				opcao = 4;
				break;
		}
	}

	/*
 	// Deque C/ Lista
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
	return 0;
}

