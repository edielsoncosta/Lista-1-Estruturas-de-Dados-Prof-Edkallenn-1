/*
**    Função : verifica se dois números são amigáveis, exibindo seus divisores e
*soma, e encontra todos os pares de números amigáveis até um
*valor limite especificado pelo usuário.
**    Autor : Edielson Costa
**    Data  : 08/04/2024
**    Observações: ele ta meio contrario mas to sem tempo para mudar, considere
*                  minha honesta tentativa.
*/

#include <stdio.h>

int somaDivisores(int num) {
  int soma = 0;
  for (int i = 1; i <= num / 2; i++) {
    if (num % i == 0) {
      soma += i;
    }
  }
  return soma;
}

void verificarAmigaveis(int a, int b) {
  int somaA = somaDivisores(a);
  int somaB = somaDivisores(b);

  printf("Divisores de %d: 1", a);
  for (int i = 2; i <= a / 2; i++) {
    if (a % i == 0) {
      printf(", %d", i);
    }
  }
  printf("\nSoma dos divisores de %d: %d\n", a, somaA);

  printf("Divisores de %d: 1", b);
  for (int i = 2; i <= b / 2; i++) {
    if (b % i == 0) {
      printf(", %d", i);
    }
  }
  printf("\nSoma dos divisores de %d: %d\n", b, somaB);

  if (somaA == b && somaB == a) {
    printf("%d e %d são números amigáveis.\n", a, b);
  } else {
    printf("%d e %d não são números amigáveis.\n", a, b);
  }
}

void encontrarAmigaveisAteN(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (somaDivisores(i) == j && somaDivisores(j) == i) {
        printf("%d e %d são números amigáveis.\n", i, j);
      }
    }
  }
}

int main_outra() {
  int num1, num2;
  printf("Digite dois números para verificar se são amigáveis: ");
  scanf("%d %d", &num1, &num2);
  verificarAmigaveis(num1, num2);

  int limite;
  printf(
      "\nDigite um valor limite para encontrar pares de números amigáveis: ");
  scanf("%d", &limite);
  encontrarAmigaveisAteN(limite);

  return 0;
}
