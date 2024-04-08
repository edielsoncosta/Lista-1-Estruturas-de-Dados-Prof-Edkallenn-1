/*
**    Função : Este código em C calcula e exibe tabelas de potências fatoriais
               crescentes e decrescentes para valores de x e n variando de 2
a 10.

**    Autor : Edielson Costa

**    Data  : 07/04/2024

**    Observações:  As potências fatoriais são úteis em cálculos de permutações
                    e combinações.
*/

#include <math.h>
#include <stdio.h>

int potencia_fatorial_crescente(int x, int n) {
  int resultado = 1;
  for (int i = 1; i <= n; i++) {
    resultado *= (x + i - 1);
  }
  return resultado;
}

int potencia_fatorial_decrescente(int x, int n) {
  int resultado = 1;
  for (int i = 0; i < n; i++) {
    resultado *= (x - i);
  }
  return resultado;
}

int main() {
  int x;
  int n;
  int i, j;

  printf("Tabela com x variando de 2 a 10:\n");
  printf("n\tCrescente\tDecrescente\n");
  for (n = 2; n <= 10; n++) {
    printf("%d\t", n);
    for (x = 2; x <= 10; x++) {
      printf("%d\t\t%d\t\t", potencia_fatorial_crescente(x, n),
             potencia_fatorial_decrescente(x, n));
    }
    printf("\n");
  }

  printf("\nTabela com n variando de 2 a 10:\n");
  printf("x\tCrescente\tDecrescente\n");
  for (x = 2; x <= 10; x++) {
    printf("%d\t", x);
    for (n = 2; n <= 10; n++) {
      printf("%d\t\t%d\t\t", potencia_fatorial_crescente(x, n),
             potencia_fatorial_decrescente(x, n));
    }
    printf("\n");
  }

  return 0;
}
