/* Lab 04c - �rea de Pol�gonos Convexos
 * Nome: Lucas Fernandes Muniz
 * Neste laborat�rio ser� criado um programa que calcula a �rea de qualquer pol�gono convexo.
 */

#include <stdio.h>

/*Fun��o que calcula a �rea do tri�ngulo pelo determinante*/
double areaDeterminante (double x1, double y1, double x2, double y2, double x3,double y3){
  double area = x2 * y3 + y1 * x3 + x1 * y2 - (y1 * x2 + x1 * y3 + x3 * y2);
  if (area < 0){
      return (-area)/2.0;
  }
  return area/2.0;
}

int main (void){
  int n = 1, cont, i;
  double Xfixo, Yfixo, X1, X2, Y1, Y2, area = 0.0;

  while (n != 0){
      scanf ("%d", &n);
      if (n == 0) {break;}
      cont = n - 3;
      
      /*Leitura dos tr�s pontos iniciais*/
      scanf ("%lf %lf", &Xfixo, &Yfixo);
      scanf ("%lf %lf", &X1, &Y1);
      scanf ("%lf %lf", &X2, &Y2);
      area += areaDeterminante (Xfixo, Yfixo, X1, Y1, X2, Y2);
      
      /*Troca dos pontos para o c�lculo da �rea do pr�ximo tri�ngulo que forma
      o pol�gono*/
      for (i = 0; i < cont; i++){
        X1 = X2;
	      Y1 = Y2;
	      scanf ("%lf %lf", &X2, &Y2);
	      area += areaDeterminante (Xfixo, Yfixo, X1, Y1, X2, Y2);
      }

      printf ("%.6f\n", area);
      area = 0;
    }

  return 0;
}