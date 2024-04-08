/*
**    Função :Este código em C verifica e exibe todos os números automórficos
entre 2 e um valor inserido pelo usuário, armazenando-os em um array alocado
dinamicamente.

**    Autor : Edielson Costa
**    Data  : 08/04/2024
**    Observações: coloquei um exit com erro de alocacao de memoria
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int eh_numero_automorfico(int n) {
  int quadrado = n * n;
  while (n > 0) {
    if (n % 10 != quadrado % 10) {
      return 0;
    }
    n /= 10;
    quadrado /= 10;
  }
  return 1;
}

void verificar_numero_automorfico(int n) {
  int *automorficos = (int *)malloc(n * sizeof(int));
  if (automorficos == NULL) {
    fprintf(stderr, "Erro de alocação de memória.\n");
    exit(EXIT_FAILURE);
  }

  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (eh_numero_automorfico(i)) {
      automorficos[count++] = i;
    }
  }

  printf("Números automórficos entre 2 e %d:\n", n);
  for (int i = 0; i < count; i++) {
    printf("%d ", automorficos[i]);
  }
  printf("\n");

  free(automorficos);
}

int main_limite() {
  int limite;
  printf("Digite um número limite para encontrar os números automórficos: ");
  scanf("%d", &limite);
  verificar_numero_automorfico(limite);
  return 0;
}
