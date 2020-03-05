#include <stdio.h>
#include <stdlib.h>

void shellsort(int arr[], int num){

    int gap, pos, posAtual, tmp;
    for (gap = num / 2; gap > 0; gap = gap / 2)// cria o gap: gap e a metade do tamanho do vetor
    {
        for (pos = gap; pos < num; pos++)// inseri a posiçao do mesmo tamnho do gap e percore ate o utima posiçao da vetor
        {
            for(posAtual = pos - gap; posAtual >= 0; posAtual = posAtual - gap)// posAtual = pos - gap fazendo
																				// que a primeira vez a posiçao seja  a inicial 0 na 1 vez															
            {
                if (arr[posAtual+gap] >= arr[posAtual])// compara que os valores das posiçao se menor braek
                    break;
                else
                {
                    tmp = arr[posAtual];      // troca de posiçao com o maior valor
                    arr[posAtual] = arr[posAtual+gap];
                    arr[posAtual+gap] = tmp;
                }
            }
        }
    }
}

int main()
{
    int arr[30];
    int k,  num;
    printf("Enter total no. of elements : ");
    scanf("%d", &num);
    printf("\nEnter %d numbers: ", num);
 
    for (k =  0 ; k < num; k++)
    {
        scanf("%d", &arr[k]);
    }
    shellsort(arr, num);
    printf("\n Sorted array is: ");
    for (k = 0; k < num; k++)
        printf("%d ", arr[k]);
    return 0;
}
