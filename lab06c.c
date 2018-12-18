/* Lab 06c - Alterações em Textos
 * Nome: Lucas Fernandes Muniz
 * Neste laboratório será implemetado um programa que retira o que estiver escrito em parenteses
 * em uma string. 
 */

#include <stdio.h>

/*Função que recebe uma string e retirna o seu tamanho*/
int tamanhoString (char str[]){
  int i;
  for(i = 0; (str[i] != '\0' && str[i] != '\n');  i++){
  }
  return i;
}

/*Função que recebe uma String e seu tamanho tam, e imprime a string sem os parênteses*/
void ignoraParentese (char str[], int tam){
  int i;
  for(i = 0; i < tam; i++){
    if (str[i] == '*' || str[i] == '(' || str[i] == ')'){
      continue;
    }
    printf("%c", str[i]);
  }
}

/*Função que recebe uma String e seu tamanho tam, e imprime a string sem o texto
que está contido nos parênteses e retorna o tamanho do novo texto que foi impresso*/
int tiraParenteses (char str[], int tam){
 int i, intervalo = 0, novoTam = 0;

  for(i = 0; i < tam; i++){
    if (str[i] == '('){intervalo++; }
    if (!intervalo){
      printf("%c", str[i]);
      novoTam++;
    }
    if (str[i] == ')') {intervalo = 0; }
  }
  return novoTam;
}


int main (){
  char frase[81];
  int tam;

  fgets(frase, 81, stdin);
  tam = tamanhoString(frase);

  ignoraParentese(frase, tam);
  printf("\n");
  tam = tiraParenteses(frase, tam);
  printf("\n");
  printf("%d\n", tam);

  return 0;
}