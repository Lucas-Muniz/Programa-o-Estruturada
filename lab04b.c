/* Lab 04b - Conversão de Base
 * Nome: Lucas Fernandes Muniz
 * Neste laboratório será desenvolvido um programa que converte um número de base decimal
 * para qualquer base informada, imprimindo o número na ordem inversa.
 */

#include <stdio.h>

/*Função que calcula a conversão e imprime na ordem inversa*/
void conversao (int X, int Y){
  int r = X%Y;
  int q = X/Y;
  if (q == 0){
    printf("%d", r);
  } else {
    printf("%d", r);
    conversao(q, Y);
  }
}

int main(void) {
  int X, Y;
  scanf("%d %d", &X, &Y);
  conversao(X, Y);
  printf("\n");
  return 0;
}