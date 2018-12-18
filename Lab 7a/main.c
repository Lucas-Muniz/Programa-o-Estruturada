/***********************************************************
 * Created: Tue 30 Oct 2018 02:01:27 PM -03
 *
 * Author: Carla N. Lintzmayer, carla.negri@ufabc.edu.br
 *
 ***********************************************************/
 
#include <stdio.h>
#include "lab07a.h"

void imprime_peso(double kg, double lb, double oz);
void imprime_comprimento(double km, double mi, double ft, double lea);
void imprime_temperatura(double c, double f, double k);
void imprime_volume(double m3, double l, double gal, double bl, double floz);
void imprime_velocidade(double kmh, double ms, double mph);

int main() {
    
    char operacao;
    char unidade[20];

    /* são no máximo 5 unidades possíveis para cada medida: */
    double valor, convert1, convert2, convert3, convert4;

    scanf("%c", &operacao);
    while (operacao != 'Q') {
        scanf("%lf %s\n", &valor, unidade);

        switch (operacao) {
            /* operação requerida é de conversão de peso: */
            case 'P':
                /* dependendo da unidade que veio, o valor lido é passado em uma ordem diferente na lista de parâmetros */
                if (unidade[0] == 'q') { /* outro teste possível: !strcmp(unidade, "quilogramas") */
                    converte_peso(P_KG, &valor, &convert1, &convert2);
                    imprime_peso(valor, convert1, convert2);
                } else if (unidade[0] == 'l') { /* !strcmp(unidade, "libras") */
                    converte_peso(P_LB, &convert1, &valor, &convert2);
                    imprime_peso(convert1, valor, convert2);
                } else {
                    converte_peso(P_OZ, &convert1, &convert2, &valor);
                    imprime_peso(convert1, convert2, valor);
                }
                break;

            /* operação requerida é de conversão de comprimento: */
            case 'C':
                if (unidade[0] == 'q') { /* outro teste possível: !strcmp(unidade, "quilometros")*/
                    converte_comprimento(C_KM, &valor, &convert1, &convert2, &convert3);
                    imprime_comprimento(valor, convert1, convert2, convert3);
                } else if (unidade[0] == 'm') {
                    converte_comprimento(C_MI, &convert1, &valor, &convert2, &convert3);
                    imprime_comprimento(convert1, valor, convert2, convert3);
                } else if (unidade[0] == 'p') {
                    converte_comprimento(C_FT, &convert1, &convert2, &valor, &convert3);
                    imprime_comprimento(convert1, convert2, valor, convert3);
                } else {
                    converte_comprimento(C_LEA, &convert1, &convert2, &convert3, &valor);
                    imprime_comprimento(convert1, convert2, convert3, valor);
                }
                break;

            /* operação requerida é de conversão de temperatura: */
            case 'T':
                if (unidade[0] == 'c') {
                    converte_temperatura(T_C, &valor, &convert1, &convert2);
                    imprime_temperatura(valor, convert1, convert2);
                } else if (unidade[0] == 'f') {
                    converte_temperatura(T_F, &convert1, &valor, &convert2);
                    imprime_temperatura(convert1, valor, convert2);
                } else {
                    converte_temperatura(T_K, &convert1, &convert2, &valor);
                    imprime_temperatura(convert1, convert2, valor);
                }
                break;

            /* operação requerida é de conversão de volume: */
            case 'V':
                if (unidade[0] == 'm') { /* metros cúbicos */
                    converte_volume(V_M3, &valor, &convert1, &convert2, &convert3, &convert4);
                    imprime_volume(valor, convert1, convert2, convert3, convert4);
                } else if (unidade[0] == 'l') { /* litros */
                    converte_volume(V_L, &convert1, &valor, &convert2, &convert3, &convert4);
                    imprime_volume(convert1, valor, convert2, convert3, convert4);
                } else if (unidade[0] == 'g') { /* galões */
                    converte_volume(V_GAL, &convert1, &convert2, &valor, &convert3, &convert4);
                    imprime_volume(convert1, convert2, valor, convert3, convert4);
                } else if (unidade[0] == 'b') { /* barris */
                    converte_volume(V_BL, &convert1, &convert2, &convert3, &valor, &convert4);
                    imprime_volume(convert1, convert2, convert3, valor, convert4);
                } else { /* onça fluída */
                    converte_volume(V_FLOZ, &convert1, &convert2, &convert3, &convert4, &valor);
                    imprime_volume(convert1, convert2, convert3, convert4, valor);
                }
                break;

            /* operação requerida é de conversão de velocidade: */
            case 'S':
                if (unidade[0] == 'k') { /* km/h */
                    converte_velocidade(S_KMH, &valor, &convert1, &convert2);
                    imprime_velocidade(valor, convert1, convert2);
                } else if (unidade[2] == 's') { /* m/s */
                    converte_velocidade(S_MS, &convert1, &valor, &convert2);
                    imprime_velocidade(convert1, valor, convert2);
                } else { /* mph */
                    converte_velocidade(S_MPH, &convert1, &convert2, &valor);
                    imprime_velocidade(convert1, convert2, valor);
                }
                break;
        }

        /* próxima operação: */
        scanf("%c", &operacao);

    }

    return 0;
}

void imprime_peso(double kg, double lb, double oz) {
    printf("%.4f quilos equivalem a %.4f libras,", kg, lb);
    printf(" que equivalem a %.4f oncas.\n", oz);
}

void imprime_comprimento(double km, double mi, double ft, double lea) {
    printf("%.4f quilometros equivalem a %.4f milhas,", km, mi);
    printf(" que equivalem a %.4f pes, que equivalem a %.4f leguas.\n", ft, lea);
}

void imprime_temperatura(double c, double f, double k) {
    printf("%.4f graus Celsius equivalem a %.4f graus Fahrenheit,", c, f);
    printf(" que equivalem a %.4f kelvin.\n", k);
}

void imprime_volume(double m3, double l, double gal, double bl, double floz) {
    printf("%.4f metros cubicos equivalem a %.4f litros,", m3, l);
    printf(" que equivalem a %.4f galoes, que equivalem a %.4f barris,", gal, bl);
    printf(" que equivalem a %.4f oncas fluidas.\n", floz);
}

void imprime_velocidade(double kmh, double ms, double mph) {
    printf("%.4f km/h equivalem a %.4f m/s, que equivalem a %.4f mph.\n", kmh, ms, mph);
}
