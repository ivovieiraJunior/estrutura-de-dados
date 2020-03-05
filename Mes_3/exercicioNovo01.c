#include <stdio.h>
#include <stdlib.h>

/* 1 - Considere listas encadeadas de valores inteiros e implemente uma função para 
retornar o número de nós da lista que possuem o campo info
com valores maiores do que n . 

Protótipo da função: int maiores(Lista* l, int n);. */

struct lista{
	int info;
	struct lista * proximo;
};
typedef struct lista Lista;

Lista * criar_lista(){
	return NULL;
}
Lista * inserir_inicio(Lista * ponteiro , int valor ){
	Lista * novo = (Lista*) malloc (sizeof(Lista));
	novo->info = valor; // add o valor 
	novo->proximo = ponteiro; // aponta para a possição anterio que era a 1 posição
	return novo; //returna o ponteiro como 1 passição
}

int maiores(Lista* l, int n){
	int contaMaior=0;
	while(l!=NULL){// ou Lista * p = l um ponteiro aux para o while
		if (l->info > n){
			contaMaior++;
			// printf("\n if valor: %d",l->info);			
		}
	l = l->proximo;	
	}
	return contaMaior;
}
int main(int argc, char *argv[]) {
	Lista * no;
	no = criar_lista();
	int N=0;
	int valor=3;
	
	no = inserir_inicio(no,2);
	no = inserir_inicio(no,10);
	no = inserir_inicio(no,1);
	no = inserir_inicio(no,13);
	no = inserir_inicio(no,11);	
 
	N = maiores(no,valor);
	printf("\n Quantidade de numeros maiores que %d eh :%d",valor,N);

	return 0;
}

