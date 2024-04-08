#include <stdio.h>

int calcular_anos(int PA, int PB, float G1, float G2) {
  int anos = 0;
  while (PA <= PB) {
    PA += PA * G1 / 100;
    PB += PB * G2 / 100;
    anos++;
    if (anos > 100) {
      return -1; // Indica que passou de 100 anos
    }
  }
  return anos;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; i++) {
    int PA, PB;
    float G1, G2;
    printf("diga valores professor: ");
    scanf("%d %d %f %f", &PA, &PB, &G1, &G2);

    int anos = calcular_anos(PA, PB, G1, G2);
    if (anos == -1) {
      printf("Mais de 1 seculo.\n");
    } else {
      printf("%d anos.\n", anos);
    }
  }

  return 0;
}
