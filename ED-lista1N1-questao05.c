/*
**    Função : somar fatoriais inversos

**    Autor : Edielson Costa

**    Data  : 07/04/2024

**    Observações: sem entrada de dados
*/

#include <stdio.h>

double soma_fatoriais_inversos(int n) {
  double soma = 0.0;
  double fatorial = 1.0;
  for (int i = 1; i <= n; i++) {
    fatorial *= i;
    soma += 1.0 / fatorial;
  }
  return soma;
}
