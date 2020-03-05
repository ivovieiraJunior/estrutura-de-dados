#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 1) (4,5Pontos)A loja “ADS MegaStore”cadastra seus clientes com as seguintes informações:
		nome, endereço e telefone. */

struct arvore{
	char Nome[50];
	char Endereço[100];
	int Telefone;
	struct arvore * filho;
	struct arvore * irmao;
};
typedef struct arvore Arvore;

Arvore * criar_arvore(){
	return NULL;
}

Arvore * criar_no(char nome[], char endereço[], int telefone){
	Arvore * no;
	no = (Arvore*) malloc(sizeof(Arvore));
	strcpy(no->Nome, nome);
	strcpy(no->Endereço, endereço);
	no->Telfone = telefone; 
	return no;
}

Arvore * inserir_filho(Arvore* arvore, char Nome[] ){
	Arvore * novo = (Arvore*) malloc (sizeof(Arvore));
	strcpy(novo->Nome, Nome);
	novo->irmao = NULL;
	novo->filho = arvore;
	return novo;
}

Arvore * inserir_irmao(Arvore* arvore, char Nome[] ){
	Arvore * novo = (Arvore*) malloc (sizeof(Arvore));
	strcpy(novo->Nome, Nome);
	novo->irmao = arvore->irmao;
	novo->filho = NULL;
	arvore->irmao = novo;
	return arvore;
}

Arvore * inserir_no(Arvore * arvore, char no[], char NomeNovo[]){// Arvore * no;
	if(strcmp(arvore->Nome,no) == 0){
	Arvore * novo = (Arvore*) malloc (sizeof(Arvore));
	strcpy(novo->Nome, NomeNovo);
	novo->irmao = NULL; //no->irmao =NULL;
	novo->filho = arvore->filho; //no->filho = arvore->filho; 
	arvore->filho = novo; //arvore->filho = no;
	}
	if(arvore->filho != NULL)
		inserir_no(arvore->filho,no);	
	if(arvore->irmao != NULL)
		inserir_no(arvore->irmao,no);
}

Arvore *remover(Arvore * arvore) {
	/*
	if( (strcmp(arvore->filho->Nome, RemoverNome)==0){
		Arvore * aux =arvore->filho->Nome;
		arvore->filho = arvore->filho->filho;
		arvore->filho =
	}
		*/
	if(arvore->filho != NULL)
		arvore->filho = remover(arvore->filho);	
		
	if(arvore->irmao != NULL)
		arvore->irmao = remover(arvore->irmao);
	arvore = NULL;
	free(arvore);
	
	return NULL;	
}

Arvore* buscaRemover (Arvore *arvore, char noHaRemover[]){
	Arvore * aux = arvore;
	if(strcmp(arvore->palavra, noHaRemover) == 0){
		aux = remover(aux);
		printf("NO: %s foi removido \n",arvore->palavra);	
	}

	if(arvore->filho != NULL)
		aux->filho = buscaRemover(arvore->filho, noHaRemover);	
		
	if(arvore->irmao != NULL)
		aux->irmao = buscaRemover(arvore->irmao, noHaRemover);
		
	return aux;
}

void imprimir(Arvore * arvore, int cont){
	int i =0;
	for(i; i< cont;i++){
		printf("---");
	}
	printf("N:%d %s\n",i,arvore->palavra);
	cont++;
	if(arvore->filho != NULL)
		imprimir(arvore->filho,cont);	
	if(arvore->irmao != NULL)
		imprimir(arvore->irmao,cont);
}

void buscaElemeto(Arvore * arvore, char buscar[]){
	
	if(strcmp(arvore->palavra, buscar ) == 0 ){
		printf("Conteudo: %s Emcontrado \n ", buscar);
	}
	if(arvore->filho != NULL)
		buscaElemeto(arvore->filho, buscar);	
	if(arvore->irmao != NULL)
		buscaElemeto(arvore->irmao, buscar);
}


int main(int argc, char *argv[]) {
	
	Arvore * arvo = criar_arvore();
	
	arvo = inserir_filho(arvo, "filho3");
	arvo = inserir_filho(arvo, "filho2");
	arvo = inserir_filho(arvo, "filho1");
	arvo = inserir_filho(arvo, "pai");
	arvo = inserir_irmao(arvo, "irmao1");
	arvo = inserir_irmao(arvo, "irmao2");
	arvo = inserir_irmao(arvo, "irmao3");

	
	printf("inserindo um filho em um no \n");

	// inserir no NO tal? um filho que se passa e se chamar filhoPasado em um determinado NO filho ou irmao
	inserir_no(arvo, "filho3");
	inserir_no(arvo, "irmao2");
	
	imprimir(arvo,0);
	
	// pesquisa elemento
	buscaElemeto(arvo, "irmao3");
	
	printf("\n\n");
	// Remover no apartir do no tal?
	arvo = buscaRemover(arvo, "irmao1");
	// buscar um elemento na arvore
	printf("\n\n");
	imprimir(arvo,0);
	
	return 0;
}
