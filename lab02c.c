#include <stdio.h>
 /* Lab 02c - Cálculo do dia da semana
  * Nome: Lucas Fernandes Muniz
  * Objetivos: Com a data fornecida na entrada, temos que verificar se ela é verdadeira, e caso seja, aplicar * a fórmula de Gauss para se obter o dia da semana correspondente a data fornecida.  
  */
 
int main(void) {
  int dia, mes, ano, x, y, w;
  scanf("%d %d %d",&dia, &mes, &ano);

  /*Verificar se a data éé uma entrada invá:lida*/
  if (dia<0 || mes<0 || ano<0 || dia > 30 || mes > 12){
    printf("invalida\n");
  }else if(mes == 2 && dia > 28){
    printf("invalida\n");
  }else{
    
    /*Definir o valor de x de acordo com a tabela:*/
    switch (mes){
    case 1:
      x = 28;
      break;
    case 2:
      x = 31;
      break;
    case 3:
      x = 2;
      break;
    case 4:
      x = 5;
      break;
    case 5:
      x = 7;
      break;
    case 6:
      x = 10;
      break;
    case 7:
      x = 12;
      break;
    case 8:
      x = 15;
      break;
    case 9:
      x = 18;
      break;
    case 10:
      x = 20;
      break;
    case 11:
      x = 23;
      break;
    case 12:
      x = 25;
      break;
    }

    /*Definindo y:*/
    if (mes == 1 || mes == 2){
      y = 5*((ano-1) % 4) + 4*((ano-1) % 100) + 6*((ano-1) % 400);
    } else {
      y = 5*(ano % 4) + 4*(ano % 100) + 6*(ano % 400);  
    }

    w = (dia + x + y) % 7;

    /*Obtendo qual dia da semana corresponde ao w encontrado:*/
    switch (w){
      case 0:
        printf("domingo\n");
        break;
      case 1:
        printf("segunda\n");
        break;
      case 2:
        printf("terca\n");
        break;
      case 3:
        printf("quarta\n");
        break;
      case 4:
        printf("quinta\n");
        break;
      case 5:
        printf("sexta\n");
        break;
      case 6:
        printf("sabado\n");
        break;
    }

  }
  
}