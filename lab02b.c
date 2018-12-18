/*
 Lab 02b - Abastecimento
 * Nome: Lucas Fernandes Muniz
 * Objetivos: Com os dados de entrada, calcular o volume do tanque do 
 * caminhão, e em cada posto averiguar se o caminhão tem gasolina 
 * suficiente para abastecer o posto.
 * Imprimir quais postos foram abastecidos.
 */

#include <stdio.h>


int main(void) {

  float d, h, a, b, c, tanque;
  scanf("%f %f %f %f %f", &d, &h, &a, &b, &c);


  tanque = 3.14*d*d*h*1000/4;

  
  /*Verificar se o tanque tem gasolina para cada posto*/

  if (tanque >= a){

    tanque -= a;

    printf("posto A foi reabastecido\n");

  }else{

    printf("posto A nao foi reabastecido\n");

  }
  if(tanque >= b){

    tanque -= b;

    printf("posto B foi reabastecido\n");

  }else{
    printf("posto B nao foi reabastecido\n");
  }
  if(tanque >= c){
    tanque -= c;
    printf("posto C foi reabastecido\n");
  }
  else{
    printf("posto C nao foi reabastecido\n");
  }

  return 0;
}
