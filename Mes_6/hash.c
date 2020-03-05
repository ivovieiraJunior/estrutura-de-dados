#include <stdio.h>
#include <stdlib.h>
#define N 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int hash(int mat){
	return N - 2 - mat % (N-2);
}
int main(int argc, char *argv[]) {
	
	int a = hash(105);
	
	printf("valor: %d", a);
	return 0;
}
