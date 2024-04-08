/*
**    Função : numero de fibonacci na restricao maxima

**    Autor : Edielson Costa

**    Data  : 07/04/2024

**    Observações:
*/

#include <stdio.h>
#include <stdlib.h>

int *fibonacci_max(int max) {
  
    int *fibonacci = (int *)malloc(sizeof(int) * max);

    if (fibonacci == NULL) {
        printf("Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    int i = 2;
    while (1) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        if (fibonacci[i] > max) {
            fibonacci[i] = -1;
            break;
        }
        i++;
    }

    return fibonacci;
}

int main() {
    int max = 15;
    int *fib = fibonacci_max(max);

    printf("Série de Fibonacci até %d:\n", max);
    for (int i = 0; fib[i] != -1; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    free(fib);
    return 0;
}
