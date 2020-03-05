#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* 3 - Crie uma função que insere um elemento na posição n de uma lista encadeada. */
 
 
struct lista{
 	int valor:
 	struct lista * proxima;
 }No;
  typedef struct lista Lista;
  No *primeiro = NULL;
lista* criar_lista(void){
 		return NULL;
	}
void inserir_inicio(int valor){
		No *no=(No*)malloc(sizeof(No));
		no->valor=valor;
		no->procima=primeiro;
		primeiro=no;
	}
	
Lista * inserir_valor(int lugar,int valor){
		if(lugar<0)
			return;
		if(lugar==valor){
			inserir_inicio(valor);
			return;
		}
		int conta_while=0;
		while(conta_while==lugar){
			no=no->proxima;
		conta_while++;
		}
		
	}
int main(int argc, char** argv) {
	No= criar_lista();
	int posicao, valor=1;
	
	inserir_inicio(60);
	inserir_inicio(50);
	inserir_inicio(40);
	inserir_inicio(30);
	inserir_inicio(20);
	inserir_inicio(10);
	
	while(valor!=0){
		printf("digite o valor: (zero pra sair)");
		scanf("%d",&valor);
		if (valor!=0){
			printf("digite a posicao de 1 a 6:");
			scanf("%d",&posicao);
			
		}	
	}
	return 0;
}
