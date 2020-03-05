#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct arvore{
	int info;
	arvore * filho;
	arvore * irmao;
};
typedef struct arvore * Arvore;

Arvore * criar_arvore(){
	return NULL;
}

Arvore * inserir_filho(Arvore* arvore, int valor ){
	Arvore * novo = (Arvore*) malloc (sizeof(Arvore));
	novo->info = valor;
	novo->irmao = NULL;
	novo->filho = Arvore;
	return novo;
}

Arvore * inserir_irmao(Arvore * arvore, int valor){
	Arvore * aux;
	if(!arvore->irmao)// enserir no inicio os irmaos e arquarda a referencias pro proximo irmao 
		aux = arvore->irmao;
	
	Arvore * novo = (Arvore*) malloc (sizeof(Arvore));
	novo->info = valor;
	arvore->irmao = novo;
	novo->irmao = NULL;
	novo->filho = aux;
	
	return arvore;
}

/*
imprimir(Arvore * arvo){
	printf("\nvalor: %d", arvo->info);
	imprimir(!arvo->filho);
	imprimir(!arvo->filho);
	return false;
}*/

imprimir(Arvore * arvore){
	printf("%d\n",arvore->info);
	if(arvore->filho != NULL)
		imprimir(arvore->filho);
	if(arvore->irmao != NULL)
		imprimir(arvore->irmao);
}
int main(int argc, char *argv[]) {
	return 0;
}
