#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5000

/* 3) (1Ponto)Qual abordagem para armazenar os dados dos clientes te parece mais apropriada,
		 a da questão 1 ou 2, porquê
		 
		 Resposta: A questão 2 porque tende a ser melhor em questão de perfermançe. */
struct no{
	int cpf;
	char nome[40];
	char endereco[80];
	int telefone;
	struct no * proximo;
};
typedef struct no NO;

typedef NO * Hash[N];

int hash1(int cpf){
	return(cpf % N);
}

int hash2(int cpf){
	return N - 2 - cpf % (N - 2);
}

NO * hsh_busca2(Hash tabela, int cpf){
	int h1 = hash1(cpf);
	int h2 = hash2(cpf);
	while(tabela[h1] != NULL){
		if(tabela[h1]->cpf == cpf)
			return tabela[h1];	
		h1 = (h1 + h2 ) % N;
	}
	return NULL;
}

void remover_no(Hash tabela, int cpf){
    int h = hash1(cpf);
    NO * no = tabela[h];
    if(no->cpf == cpf){
        tabela[h] = no->proximo;
        free(no);
    }
    NO * aux;
    while(no != NULL){
        aux = no->proximo;
        if(aux && aux->cpf == cpf){
            no->proximo = aux->proximo;
            free(aux);
        }
        no = no->proximo;
    }
}
void insere_altera(Hash tabela, int cpf, char  nome[], char ende[], int fone){
	int h1 = hash1(cpf);
	int h2 = hash2(cpf);
	while(tabela[h1] != NULL){
		if(tabela[h1]->cpf == cpf)
			break;	
		h1 = (h1 + h2) % N;	
	}
	if(tabela[h1] == NULL){
		tabela[h1] = (NO*) malloc(sizeof(NO));
		tabela[h1]->cpf = cpf;
	}
	strcpy(tabela[h1]->nome, nome);
	strcpy(tabela[h1]->endereco, ende);
	tabela[h1]->telefone = fone;
}


void Menu(){
	printf("\n==== Menu ====\n");
	printf("\tOpcoes\n");
	printf("[1] Inserir Pessoa\n");
	printf("[2] Buscar (Pelo Cpf)\n");
	printf("[3] Retirar (Pelo Cpf)\n");
	printf("[4] Mostrar Dados\n");
	printf("[5] sair\n");
}

void imprimir(Hash tabela,int tam){
	int h1 = 0 ;
	while(h1 < 5000){
		
		if(tabela[h1] != NULL){
			//printf("VALOR H1: %d",h1);
			printf("\nNome: %s",tabela[h1]->nome);
			printf("\nCpf: %d",tabela[h1]->cpf);
			printf("\nEndereco: %s",tabela[h1]->endereco);
			printf("\ntelefone: %d",tabela[h1]->telefone);
		}
		h1 ++;
	}
}
int main(int argc, char *argv[]) {
	
	Hash tabela = {};

	//insere_altera(tabela, 1111, Nome, email);
	//insere_altera(tabela, 1122, Nome, email);
	
	int opcao = 6;
	char nome[40];
	char endereco[100];
	int telefone;
	int cpf;
	int tamanho = 0;
	
	
	while(opcao != 5){
	
		Menu();
		printf("\nOpcao:");
		scanf("%d", &opcao);
		switch (opcao){
		
			case 1:
				tamanho++;
				printf("\nNome:");
				scanf("%s", nome);
				fflush(stdin);
				printf("\nCpf:");
				scanf("%d", &cpf);
				printf("\nEndereco:");
				scanf("%s", endereco);
				fflush(stdin);
				printf("\nTelefone:");
				scanf("%d", &telefone);
				
				insere_altera(tabela, cpf, nome, endereco, telefone);
				//arvore = enserir(arvore, nome, endereco, telefone);
			
			break;
			
			case 2:
				printf("\nCpf:");
				scanf("%d", &cpf);
				NO * aux = hsh_busca2(tabela, cpf);
					if(aux)
						printf("Nome: %s", aux->nome);
					else
						printf("Aluno Nao encontrado");
		
						printf("\n");
			break;
			
			case 3:
				printf("\nCpf:");
				scanf("%d", &cpf);
				
				remover_no(tabela, cpf);
				
			break;
			
			case 4:
			 imprimir(tabela,tamanho);
			break;
				
			case 5:
				printf("\n\tBye.!!\n");
				opcao = 5;
			break;
		}
	}
	
	return 0;
}
