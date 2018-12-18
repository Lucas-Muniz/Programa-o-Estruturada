/* Lab 03a - Street Fighter
 * Nome: Lucas Fernandes Muniz
 * Neste laboratório será criado um programa que calcula o resultado geral
 * da luta entre Ken e Ryu.
 */

#include <stdio.h>

int main(void) {
  int pontosRyu = 0, pontosKen = 0, roundRyu = 0,
  roundKen = 0, golpe = 1, round = 1;

  while (golpe != 0){
    scanf("%d", &golpe);
    
    /*Verificação de término de round*/
    if (golpe >= 0 && round == 0){
      round = 1;

      if (pontosRyu > pontosKen){
        roundRyu++;
      } else if (pontosKen > pontosRyu){
        roundKen++;
      }

      pontosRyu = 0;
      pontosKen = 0;
    }
    
    /*Contagem dos pontos dos lutadores*/
    if(golpe > 0){
      pontosRyu += golpe;
    } else if (golpe < 0){
      pontosKen += golpe*(-1);
      round = 0;
    }
  }

  /*Imprimindo os resultados das lutas*/
  if(roundRyu == roundKen){
    printf("empatou\n");
  } else if (roundRyu > roundKen){
    printf("Ryu venceu\n");
  } else {
    printf("Ken venceu\n");
  }

  return 0;
}
