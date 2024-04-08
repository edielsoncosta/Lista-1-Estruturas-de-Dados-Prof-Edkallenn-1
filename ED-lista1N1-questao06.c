/*
**    Função : verificacao de numeros de carmichael

**    Autor : Edielson Costa

**    Data  : 07/04/2024

**    Observações: verificar se um número é de carmichael
*/

#include <stdbool.h>
#include <stdio.h>

bool eh_primo(int num) {
  if (num <= 1)
    return false;
  if (num <= 3)
    return true;
  if (num % 2 == 0 || num % 3 == 0)
    return false;
  for (int i = 5; i * i <= num; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0)
      return false;
  }
  return true;
}

int potencia(int base, int expoente) {
  int resultado = 1;
  for (int i = 0; i < expoente; i++) {
    resultado *= base;
  }
  return resultado;
}

bool eh_numero_carmichael(int n) {
  if (eh_primo(n))
    return false;
  for (int a = 2; a < n; a++) {
    if (eh_primo(a) && potencia(a, n - 1) % n != 1)
      return false;
  }
  return true;
}
