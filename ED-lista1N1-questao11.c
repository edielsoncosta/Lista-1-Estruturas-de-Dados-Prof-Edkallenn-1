/*
**    Função : permutacao circular. Uma permutação circular de uma sequência de números é obtida movendo cada número para a posição seguinte, e movendo o último número para a primeira posição. Por exemplo, a permutação circular de (1, 2, 3, 4) é (4, 1, 2, 3).
**    Autor : Edielson Costa

**    Data  : 07/04/2024

**    Observações:
*/

#include <stdio.h>
#include <stdlib.h>

int permutacao_circular(int *array1, int *array2, int tamanho) {
  
    int igual = 1;
    for (int i = 0; i < tamanho; i++) {
        if (array1[i] != array2[i]) {
            igual = 0;
            break;
        }
    }

    if (igual) {
      
        for (int i = 0; i < tamanho; i++) {
            int igual_todos = 1;
            for (int j = 0; j < tamanho; j++) {
                if (array1[j] != array2[(j + i) % tamanho]) {
                    igual_todos = 0;
                    break;
                }
            }
            if (igual_todos) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
  
    int tamanho = 4;
    int *array1 = (int *)malloc(sizeof(int) * tamanho);
    int *array2 = (int *)malloc(sizeof(int) * tamanho);

    for (int i = 0; i < tamanho; i++) {
        array1[i] = i + 1;
        array2[i] = (i == 0) ? tamanho : i;
    }

    if (permutacao_circular(array1, array2, tamanho)) {
        printf("Os arrays são permutações circulares um do outro.\n");
    } else {
        printf("Os arrays não são permutações circulares um do outro.\n");
    }

    free(array1);
    free(array2);

    return 0;
}
