/* Lab 04b - Convers�o de Base
 * Nome: Lucas Fernandes Muniz
 * Neste laborat�rio ser� desenvolvido um programa que converte um n�mero de base decimal
 * para qualquer base informada, imprimindo o n�mero na ordem inversa.
 */

#include <stdio.h>

/*Fun��o que calcula a convers�o e imprime na ordem inversa*/
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