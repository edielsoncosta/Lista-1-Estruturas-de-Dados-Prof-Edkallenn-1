/*
**    Função : Este código em C calcula e exibe os fatoriais normais e duplos de
*números em um                     intervalo especificado, salvando os
*resultados em um arquivo de texto.
**    Autor : Edielson Costa
**    Data  : 08/04/2024
**    Observações: fiz no replit mas tentei fazer algo que se fosse pra rodar em
*outro local,                          poderia salvar o txt.
*/

#include <stdio.h>
#include <stdlib.h>

unsigned long long calcularFatorial(int n);
unsigned long long calcularFatorialDuplo(int n);
void exibirResultados(int inicio, int fim, const char *nomeArquivo);

unsigned long long calcularFatorial(int n) {
  unsigned long long resultado = 1;
  for (int i = 2; i <= n; i++) {
    resultado *= i;
  }
  return resultado;
}

unsigned long long calcularFatorialDuplo(int n) {
  unsigned long long resultado = 1;
  if (n % 2 == 0) {
    for (int i = n; i >= 2; i -= 2) {
      resultado *= i;
    }
  } else {
    for (int i = n; i >= 1; i -= 2) {
      resultado *= i;
    }
  }
  return resultado;
}

void exibirResultados(int inicio, int fim, const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "w");
  if (arquivo == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo %s para escrita.\n", nomeArquivo);
    exit(EXIT_FAILURE);
  }

  fprintf(arquivo, "n\tFatorial Normal\tFatorial Duplo\tDiferença\n");

  for (int n = inicio; n <= fim; n++) {
    unsigned long long fatorialNormal = calcularFatorial(n);
    unsigned long long fatorialDuplo = calcularFatorialDuplo(n);
    unsigned long long diferenca = fatorialNormal - fatorialDuplo;
    fprintf(arquivo, "%d\t%llu\t%llu\t%llu\n", n, fatorialNormal, fatorialDuplo,
            diferenca);
    printf("%d\t%llu\t%llu\t%llu\n", n, fatorialNormal, fatorialDuplo,
           diferenca);
  }

  fclose(arquivo);
  printf("Resultados salvos em %s.\n", nomeArquivo);
}

int master() {

  int inicio = 2;
  int fim = 20;

  exibirResultados(inicio, fim, "resultados_fatoriais.txt");
  return 0;
}
