/* Lab 01b: Rogue 102: A Alian�a Contra-Ataca
 * Nome: Lucas Fernandes Muniz
 * Neste laborat�rio ser� feito um programa que calcula o tempo de acionamento da bomba.
 */

#include <stdio.h>


int main(){

    double h, vb, d, emp, t_vertical, t_horizontal, t;

    scanf("%lf", &h);

    scanf("%lf", &vb);

    scanf("%lf", &d);

    scanf("%lf", &emp);

    t_vertical = h/vb;

    t_horizontal = d/emp;

    /* tempo de acionamento */

    t = t_vertical - t_horizontal;

    printf("%.3f\n", t);

    return 0;

}