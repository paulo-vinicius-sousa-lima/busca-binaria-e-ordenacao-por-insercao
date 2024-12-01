#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int vetor[1000];
    int i, j, aux;

    srand(time(NULL));
    
    for (i = 0; i < 1000; i++) {
        vetor[i] = rand() % 1100 + 1;
    }



    for (i = 1; i < 1000; i++) {
        
        aux = vetor[i];
        j = i - 1;
        
        while (j >= 0 && vetor[j] > aux) {
            
            vetor[j + 1] = vetor[j];
            j--;
            
        }
        
        vetor[j + 1] = aux;
        
    }



    int escolha;
    printf("Escolha um numero (entre 1 e 1100): ");
    scanf("%i", &escolha);


    
    int inicio = 0;
    int fim = 999;
    int meio;
    int encontrado = 0;
    
    while (inicio <= fim) {
        
        meio = inicio + (fim - inicio) / 2;
        
        if (vetor[meio] == escolha) {
            
            printf("Numero %i encontrado na posicao %i.\n", escolha, meio);
            encontrado = 1;
            break;
            
        } else if (vetor[meio] < escolha) {
            
            inicio = meio + 1;
            
        } else {
            
            fim = meio - 1;
            
        }
    }



    if (!encontrado) {
        
        printf("O numero %i nao foi encontrado no vetor.\n", escolha);
        
    }

    return 0;
}
