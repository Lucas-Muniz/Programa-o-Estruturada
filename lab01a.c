/* Nome: Lucas Fernandes Muniz
 * Neste laboratório foi criado um programa que calcula o valor que deve ser pago pelo transporte.
 */

#include <stdio.h>


int main(){

    int xi, xf, yi, yf, dm, valor;

    int vi, taxa;

    scanf("%d", &vi);

    scanf("%d", &xi);

    scanf("%d", &yi);

    scanf("%d", &xf);

    scanf("%d", &yf);

    scanf("%d", &taxa);

    /* distância de Manhattan */

    dm = (xf - xi)+(yf - yi);

    /* valor a ser pago */

    valor = vi + taxa*dm;

    printf("%d\n", valor);

    return 0;

}