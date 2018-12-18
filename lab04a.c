/* Lab 04a - Series de Taylor
 * Nome: Lucas Fernandes Muniz
 * Neste laborat�rio ser� criado um programa que calcula a fun��o ln (logaritmo natural)
 * por s�rie de Taylor e pela s�rie da fun��o tangente hiperb�lico.
 */

#include <stdio.h>
#include <math.h>

/*Fun��o recursiva que calcula o ln por s�rie de Taylor*/
double logTaylor (double Z, int I){
    double soma = 0;
    if (I == 0){
        return 0;
    } else {
        soma += pow(-1, I+1)*(pow((Z-1), I))/I;
        I--;
        soma += logTaylor(Z, I);
        return soma;
    }
}

/*Fun��o recursiva que calcula o ln pela fun��o tangente hiperb�lica*/
double logTangente (double Z, int I, double n){
    double soma = 0;
    if (I == 0){
        return 0;
    } else {
        soma += (pow((Z-1)/(Z+1), n))*(2/n);
        I--;
        n += 2;
        soma += logTangente(Z, I, n);
        return soma;
    }
}


int main (){
    double Z, I, J;
    double valorReal, sta = 0.0, sth = 0.0;
    scanf("%lf %lf %lf", &Z, &I, &J);
    /*Calculo dos valores de ln*/
    valorReal = log(Z);
    sta = logTaylor(Z,I);
    sth = logTangente(Z,J, 1);
    /*Impress��o dos resulatados*/
    printf("%.6lf %.6lf %.6lf\n", valorReal, sta, sth);

    return 0;
}
