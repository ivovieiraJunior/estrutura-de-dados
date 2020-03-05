#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct arvore{
	int info;
	struct arvore * esquerda;
	struct arvore * direita;
};
typedef struct arvore Arvore;

Arvore * criar_arvore(){
	return NULL;
}

Arvore * enserir_arvore(Arvore * esquerda, Arvore *direita, int valor ){
	Arvore * novo = (Arvore*) malloc(sizeof(Arvore));
	novo->info = valor;
	novo->esquerda = esquerda;
	novo->direita = direita;

	return novo;
}

int arvore_vazia(Arvore * arvore){
	return arvore == NULL;
}

void imprimir(Arvore * arvore){
	if(!arvore_vazia(arvore)){
	printf("valor: %d \n", arvore->info);
	imprimir(arvore->esquerda);
	imprimir(arvore->direita);

	/*imprimir(arvore->esquerda);
	printf("valor: %d\n", arvore->info);
	imprimir(arvore->direita);*/
	

	/*imprimir(arvore->esquerda);
	imprimir(arvore->direita);
	printf("valor: %d\n", arvore->info);
	*/	
	}
}

int busca(Arvore * arvo, int valor){
	if(!arvore_vazia (arvo)  ){
		if( valor == arvo->info)
			return valor;	
	}
	busca(arvo->esquerda, valor);
	busca(arvo->direita, valor);
	
}

int main(int argc, char *argv[]) {
	Arvore * arvore_A = criar_arvore();
	Arvore * arvore_b = criar_arvore();
	Arvore * arvore_c = criar_arvore();
	Arvore * arvore_d = criar_arvore();
	Arvore * arvore_e = criar_arvore();
	Arvore * arvore_f = criar_arvore();
	
	int i;
	
	arvore_f = enserir_arvore(criar_arvore() , criar_arvore(), 6 );
	arvore_e = enserir_arvore(criar_arvore() , criar_arvore(), 5 );
	arvore_d = enserir_arvore(criar_arvore() , criar_arvore(), 4 );
	arvore_c = enserir_arvore(arvore_e, arvore_f, 3 );
	arvore_b = enserir_arvore(criar_arvore() , arvore_d, 2 );
	arvore_A = enserir_arvore(arvore_b , arvore_c, 1 );
	
	imprimir(arvore_A);
	
	i = busca(arvore_A , 9);
	
	printf("valor encontrado %d: ", i);
	return 0;
}

