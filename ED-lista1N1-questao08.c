/*
**    Função : numero de armstrong

**    Autor : Edielson Costa

**    Data  : 07/04/2024

**    Observações:
*/

#include <stdio.h>
#include <stdbool.h>

int numero_digitos(int n) {
    int contador = 0;
    while (n != 0) {
        n /= 10;
        contador++;
    }
    return contador;
}

bool eh_numero_armstrong(int n) {
    int numero = n;
    int soma = 0;
    int num_digitos = numero_digitos(n);

    while (n != 0) {
        int digito = n % 10;
        soma += pow(digito, num_digitos);
        n /= 10;
    }

    return soma == numero;
}

int main() {
    printf("Números de Armstrong entre 1 e 100:\n");
    for (int i = 1; i <= 100; i++) {
        if (eh_numero_armstrong(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
