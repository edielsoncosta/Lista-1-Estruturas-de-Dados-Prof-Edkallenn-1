/*
**    Função : s=numero feliz ou nao.

**    Autor : Edielson Costa

**    Data  : 07/04/2024

**    Observações: verificar se um número é feliz.
*/

#include <stdio.h>
#include <stdbool.h>

int soma_quadrados_digitos(int n) {
    int soma = 0;
    while (n > 0) {
        int digito = n % 10;
        soma += digito * digito;
        n /= 10;
    }
    return soma;
}

bool eh_numero_feliz(int n) {
    int visitados[1000] = {0};
    while (n != 1 && !visitados[n]) {
        visitados[n] = 1;
        n = soma_quadrados_digitos(n);
    }
    return n == 1;
}
