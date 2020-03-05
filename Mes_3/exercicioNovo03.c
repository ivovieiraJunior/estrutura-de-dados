#include <stdio.h>
#include <stdlib.h>

/* 3� Implemente uma fun��o que recebe duas listas encadeadas de valores reais e 
retorna a lista resultante de concatena��o das duas 
listas recebidas como par�metro, isto �, ap�s a concatena��o, o �ltimo elemento da primeira lista deve 
apontar para o primeiro elemento da segunda lista

.Prot�tipo da fun��o: Lista* concatena (Lista* l1, Lista*l2); 

4 � Considere listas de valores inteiros e implemente uma fun��o que receba como
par�metros uma lista encadeada e um valor inteiro n, retire da lista todas as
ocorr�ncias de n e retorne a lista resultante. Prot�tipo: Lista* retira_n(Lista* l, int
n);
.*/

struct lista{
	int info;
	struct lista * proximo;
};
typedef struct lista Lista;

Lista * criar_lista(){
	return NULL;
}

Lista * inserir_inicio(Lista * ponteiro, int valor){
	Lista * novo = (Lista*) malloc (sizeof(Lista));
	novo->info = valor;
	novo->proximo = ponteiro;
	return novo;
}
void imprimir (Lista * ponteiro){
	Lista * l;
	printf("\n imprimindo ...");
	while(l = ponteiro !=NULL){
		printf("\n valor: %d ",ponteiro->info);
	ponteiro = ponteiro->proximo;
	}
}
Lista* concatena (Lista* l1, Lista * l2){
	Lista *aux = l1;
	while(l1->proximo !=NULL){
		l1= l1->proximo;
	}
	l1->proximo = l2;
	
	return aux;
}
Lista* retira_n(Lista* l, int n){
	Lista * aux;
	Lista * anterior;
	Lista * atual = l;
	if(atual->info == n){
		printf("\n if");
		l = l->proximo;
		free(atual);
	}
	atual = l;
	while(atual->info != n){
	//	printf("\n while");
		anterior = atual;	
		atual=atual->proximo;
	}
	anterior->proximo = atual->proximo;
	aux = atual;
	free(atual);
	atual = aux;
	return l;
}
int main(int argc, char *argv[]) {
	Lista * no01;
	Lista * no02;
	no01 = criar_lista();
	no02 = criar_lista();
	
	no01 = inserir_inicio(no01, 30);
	no01 = inserir_inicio(no01, 25);
	no01 = inserir_inicio(no01, 20);
	no01 = inserir_inicio(no01, 15);
	no01 = inserir_inicio(no01, 10);
	no01 = inserir_inicio(no01, 5);
	
	no02 = inserir_inicio(no02, 5);
	no02 = inserir_inicio(no02, 10);
	no02 = inserir_inicio(no02, 15);
	no02 = inserir_inicio(no02, 20);
	no02 = inserir_inicio(no02, 25);
	no02 = inserir_inicio(no02, 30);
	
	printf("\n primeira lista: ");
	imprimir(no01);
	printf("\n segunda lista: ");
	imprimir(no02);
	
	printf("\n concatenado as 2 listas em uma");
	no01 = concatena(no01,no02);
	imprimir(no01);
	// removendo o valor da lista;
	no01 = retira_n(no01,5);
	imprimir(no01);
	
	return 0;
}










