#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 1) (4,5Pontos)A loja “ADS MegaStore”cadastra seus clientes com as seguintes informações: nome, endereço e telefone. 
		Armazene todos os clientes numa estrutura de dados apropriada e mantenha os cadastros
		ordenados para permitir a busca binária dos clientespelo nome.
		Mantenhasempre a ordenaçãoda estrutura, mesmo depois que um novo cliente sejaadicionado.
		O sistema deve oferecer asopçõesde adicionar e remover clientes, além de buscar clientes pelo nome.
		Explique:
		
		 porque você escolheu determinada estrutura de dados e determinada estratégia de ordenação. 
		
			Resposta: Pois arvore binaria sendo recursiva ela tende a ser mais rapida na busca e
					também a ser mais dinamica na hora da busca em comparação a outras formas aproveitando melhor
					o recurso dispoivel 
					utilizei a ordenação pelo numero de telefone para assim fazer a comparação mais rapida do que 
					comparar strings.
					 */

struct arvore{
	char nome[40];
	char endereco[100];
	int telefone;
	struct arvore * esquerda;
	struct arvore * direita;
};
typedef struct arvore Arvore;

Arvore * criar_arvore(){
	return NULL;
}

Arvore * enserir_arvore(Arvore * arvore, char nome[],char endere[],int fone ){
	if(arvore == NULL){
		arvore  = (Arvore*) malloc(sizeof(Arvore));
			strcpy(arvore->nome, nome);
			strcpy(arvore->endereco, endere);
			arvore->telefone = fone;
			arvore->esquerda = NULL;
			arvore->direita = NULL;
	}
	else if(arvore->telefone > fone)
		arvore->esquerda = enserir_arvore(arvore->esquerda, nome , endere , fone);
	else 
		arvore->direita = enserir_arvore(arvore->direita, nome , endere , fone);

	return arvore;
}

int arvore_vazia(Arvore * arvore){
	return arvore == NULL;
}



void imprimir(Arvore * arvore){
	if(!arvore_vazia(arvore)){
	imprimir(arvore->esquerda);
	printf("Nome: %s \n", arvore->nome);
	printf("Endereco: %s \n", arvore->endereco);
	printf("telefom: %d \n", arvore->telefone);
	imprimir(arvore->direita);
	}
}

int buscar(Arvore * arvo, char nome[]){
	if(!arvore_vazia (arvo)  ){
		if( (strcmp(nome , arvo->nome)) == 0){
			printf("\n Pessoa Emcontrada: %s ", arvo->nome);
			printf("\n Seu Endereco: %s ", arvo->endereco);
			printf("\n Seu Telefone: %d ", arvo->telefone);
		}
			
			return 1;	
	}
	buscar(arvo->esquerda, nome);
	buscar(arvo->direita, nome);
	
}

Arvore * enserir(Arvore * arvo, char nome[], char end[], int fone){

	arvo = enserir_arvore(arvo , nome, end , fone );
	
	return arvo;
}

void Menu(){
	printf("\n==== Menu ====\n");
	printf("\tOpcoes\n");
	printf("[1] Inserir Pessoa\n");
	printf("[2] Buscar (Pelo Nome)\n");
	printf("[3] Retirar (Pelo Nome, endereco e telefone)\n");
	printf("[4] Mostrar Dados\n");
	printf("[5] sair\n");
}

Arvore * remover(Arvore * arvo,char nome [], char ende[], int fone){
	if(arvo == NULL)
		return NULL;
	else if(arvo->telefone > fone )
		arvo->esquerda = remover(arvo->esquerda,nome, ende , fone);
	else if(arvo->telefone < fone )
		arvo->direita = remover(arvo->direita,nome, ende , fone);
	else{
		if(arvo->esquerda ==NULL && arvo->direita ==NULL){
			free(arvo);
			arvo = NULL;
		}
		else if (arvo->esquerda == NULL){
			Arvore * aux = arvo;
			arvo = arvo->direita;
			free(aux);
		}
		else if (arvo->direita == NULL){
			Arvore * aux = arvo;
			arvo = arvo->esquerda;
			free(aux); 
		}
		else{
			Arvore * aux = arvo->esquerda;
			while(aux->direita !=NULL){
				aux = aux->direita;
			}
			strcpy(arvo->nome,aux->nome);
			strcpy(arvo->endereco,aux->endereco);
			arvo->telefone = aux->telefone;
			strcpy(aux->nome,nome);
			strcpy(aux->endereco, ende);
			arvo->telefone = fone;
			arvo->esquerda = remover(arvo->esquerda, nome, ende , fone );
		}
	}
	return arvo;
}

int main(int argc, char *argv[]) {
	
	Arvore * arvore = criar_arvore();
	int opcao = 6;
	char nome[40];
	char endereco[100];
	char busca[40];
	int telefone;
	
	
	while(opcao != 5){
	
		Menu();
		printf("\nOpcao:");
		scanf("%d", &opcao);
		switch (opcao){
		
			case 1:
				printf("\nNome:");
				scanf("%s", nome);
				fflush(stdin);
				printf("\nEndereco:");
				scanf("%s", endereco);
				fflush(stdin);
				printf("\nTelefone:");
				scanf("%d", &telefone);
			
				arvore = enserir(arvore, nome, endereco, telefone);
			
			break;
			
			case 2:
				printf("\nNome (Buscar)");
				scanf("%s", nome);
				fflush(stdin);
				int erro = 0;
				erro = buscar(arvore, nome);
			break;
			
			case 3:
				printf("\nNome:");
				scanf("%s", nome);
				fflush(stdin);
				printf("\nEndereco:");
				scanf("%s", endereco);
				fflush(stdin);
				printf("\nTelefone:");
				scanf("%d", &telefone);
				
				arvore = remover(arvore, nome , endereco, telefone);
				
			break;
			
			case 4:
			 imprimir(arvore);
			break;
				
			case 5:
				printf("\n\tBye.!!\n");
				opcao = 5;
			break;
		}
	}
	
	return 0;
}

