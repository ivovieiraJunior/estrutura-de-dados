#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void encriptar(char frase[]){	
	int i = 0;	
	for( ; i < strlen(frase); i ++ ){	
		int j =  frase[i];
		//printf("j e : %d\n", j);
		j+=3;
		if(j >= 122){
			j -= 26;
		}		
		frase[i] =  j;
	}
	printf("frase encripitada: %s", frase);
}


int main(int argc, char *argv[]) {
	char palavra [30];
	
	
	
	printf("digite sua palavra:");
	scanf("%s", &palavra);

	encriptar(palavra);
	
	return 0;
}
