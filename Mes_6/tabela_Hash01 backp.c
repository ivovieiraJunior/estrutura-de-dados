#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5000

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct aluno{
	int matricula;
	char nome[20];
	char email[20];
};
typedef struct aluno Aluno;

typedef Aluno * Hash[N];

int hash1(int matricula){
	return(matricula % N);
}

int hash2(int matricula){
	return N - 2 - matricula % (N - 2);
}

Aluno * hsh_busca2(Hash tabela, int matricula){
	int h1 = hash1(matricula);
	int h2 = hash2(matricula);
	while(tabela[h1] != NULL){
		if(tabela[h1]->matricula == matricula)
			return tabela[h1];	
		h1 = (h1 + h2 ) % N;
	}
	return NULL;
}
void insere_altera(Hash tabela, int matricula, char * nome, char * email){
	int h1 = hash1(matricula);
	int h2 = hash2(matricula);
	while(tabela[h1] != NULL){
		if(tabela[h1]->matricula == matricula)
			break;	
		h1 = (h1 + h2) % N;	
	}
	if(tabela[h1] == NULL){
		tabela[h1] = (Aluno*) malloc(sizeof(Aluno));
		tabela[h1]->matricula = matricula;
	}
	strcpy(tabela[h1]->nome, nome);
	strcpy(tabela[h1]->email, email);
}
int main(int argc, char *argv[]) {
	
	Hash tabela;
	char Nome[] = "Aluno ADS";
	char email[] = "aluno@ads.com";
	insere_altera(tabela, 1111, Nome, email);
	insere_altera(tabela, 1122, Nome, email);
	Aluno * res = hsh_busca2(tabela, 1122);
	if(res)
		printf(res->nome);
	else
		printf("Aluno Nao encontrado");
		
	printf("\n");
	
	return 0;
}
