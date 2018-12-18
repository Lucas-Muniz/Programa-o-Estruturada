/*
 Lab 02a - Aula Prática - Jogo da Velha
 * Nome: Lucas Fernandes Muniz
 * Objetivos: Avaliar as posições do jogo e encontrar algum padrão em que jogo da velha foi vencido.
 */
#include <stdio.h>


int main(void) {


  char v1, v2, v3, v4, v5, v6, v7, v8, v9;

  scanf("%c %c %c %c %c %c %c %c %c", &v1, &v2, &v3, &v4, &v5, &v6, &v7, &v8, &v9);


  /*Casos possíveis do jogo da velha:*/
  if((v1 == v2)&&(v2 == v3)&&(v1 != '-')){
    printf("%c venceu\n", v1);
  }else if((v4 == v5)&&(v5 == v6)&&(v4 != '-')){
    printf("%c venceu\n", v4);
  }else if((v7 == v8)&&(v8 == v9)&&(v7 != '-')){
    printf("%c venceu\n", v7);
  }else if((v1 == v4)&&(v4 == v7)&&(v1 != '-')){
    printf("%c venceu\n", v1);
  }else if((v2 == v5)&&(v5 == v8)&&(v2 != '-')){
    printf("%c venceu\n", v2);
  }else if((v3 == v6)&&(v6 == v9)&&(v3 != '-')){
    printf("%c venceu\n", v3);
  }else if((v1 == v5)&&(v5 == v9)&&(v1 != '-')){
    printf("%c venceu\n", v1);
  }else if((v3 == v5)&&(v5 == v7)&&(v3 != '-')){
    printf("%c venceu\n", v3);
  }else{
    printf("empatou\n");
  }


  return 0;
}
