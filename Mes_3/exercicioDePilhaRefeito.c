#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
/* 1- Implemente um programa que inverte palavras usando uma pilha. */

struct pilha{
	int n;
	char palavra[N];
};
typedef struct pilha Pilha;

Pilha * pilha_criar(){
	Pilha * p = (Pilha*)malloc(sizeof(Pilha));
	p->n=0;
	return p;
}

void push_pilha(Pilha * ponteiro, char letra[]){
	if(ponteiro->n==N){
		printf("pilha estourou:");
		exit(1);
	}
	ponteiro->palavra[ponteiro->n]=letra;
	ponteiro->n++;
}

void set_palavra(Pilha * no,char palavra[]){
	
	int contaFor;
	int contaTamanho;
	
	//contando tamanho da palavra;
	contaTamanho = strlen(palavra);
	
	for(contaFor=0;contaFor <=contaTamanho; contaFor++){
		push_pilha(no,palavra[contaFor]);
	}
}

int pilha_vazia(Pilha * p){
	return (p->n == 0);
}

char pop_pilha(Pilha * ponteiro){
	//printf("\n remover pilha");
	char aux;
	char letra;
	if(pilha_vazia(ponteiro)){
		printf("\n Pilha vazia!!");
		exit(1);
	}
	
	//aux  = ponteiro->palavra[ponteiro->n];
	letra = ponteiro->palavra[ponteiro->n-1];
	ponteiro->n--;
	
	return letra;
}

int tamanho (Pilha * no){	
	return no->n;
}

void emprimir (Pilha * no){
	
	int conta=no->n;
	while(conta >= 0){
		printf("%c",no->palavra[conta-1]);
		//printf("tamanho: %d",no->n);
	conta--;
	}
	
}
void tamanho_pilha(Pilha * no1,Pilha * no2){

	if(tamanho(no1)==0){
		printf("\n pilha 1 vazia");	
	}
	if(tamanho(no2)==0)
			printf("\n pilha 2 vazia!!\n");
	if(tamanho(no1)>tamanho(no2)){
		printf("\npilha 1 e maior");
	}if(tamanho(no1)<tamanho(no2)){
	printf("\npilha 2 e maior");		
	}else{
		printf("\npilha 1 tem o mesmo tamanho que a pilha 2 ");
	}
}
int main(int argc, char *argv[]) {
	
	Pilha * no;
	Pilha * NO;
	no = pilha_criar();
	NO = pilha_criar();
	
	char palavra[50];//= {"ronaldo"};
	char letra;
	int contaTamanho=0;
		
	printf("Digite a palavra:");
	scanf("%s",palavra);
	//contando tamanho da palavra;
	contaTamanho= strlen(palavra);
	printf("\npalavra eh: %s , tamanho: %d ",palavra,contaTamanho);
	set_palavra(no,palavra);
	// aki coloca a palavra enviando uma letra p
	// set = coloca
	// lendo a palavra da segunda pilha 
	printf("\n Digite a palavra:");
	scanf("%s",palavra);
	set_palavra(NO,palavra);
	
	printf("\nInvertendo a palavra:\n");
	printf("\n Pilha 1:");
	emprimir(no);
	printf("\n Pilha 2:");
	emprimir(NO);
	
	
	tamanho_pilha(no,NO);
	printf("\n");
	emprimir(no);
	return 0;
}

