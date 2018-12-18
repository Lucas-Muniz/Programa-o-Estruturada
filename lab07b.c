/* Lab 07b - Strpock
 * Aluno: Lucas Fernandes Muniz
 * Este lab tem como objetivo criar um programa que separa uma string em tokens 
 * de acordo dos delimitadores digitados pelo usuário.
 */
#include <stdio.h>

/* Variáveis globais utilizadas no código.*/
int pos = 0, numOrdem = 0;
char ordem[90];

/* Essa função recebe uma string e retorna o tamanho dessa string.*/
int tamanhoString(char *string){
  int cont = 0;
  while(string[cont] != '\0' && string[cont] != '\n'){
    cont++;
  }
  return cont;
}

/* Função que recebe uma string, um vetor de delimitadores e o tamanho do vetor 
 * de delimitadores e identifica se a string contem algum delimitador e retorna 1,
 * caso contrário, retorna 0.
 */
int ehIgualDelimitador(char str, char *delimiters, int tamDelim){
  int pos, i;
  
  for(i = 0; i<tamDelim; i++){
    if (str == delimiters[i]){
      ordem[numOrdem] = delimiters[i];
      numOrdem++;
      return 1;
    }
  }
  
  return 0;
}

/* Função que recebe uma string e um vetor de delimitadores, e retorna o endereço
 * da primeira posição de um token na string.
 */
char *strpock(char *str, char *delimiters){
  int posDiferente = 0, posParada = 0, token = 0;
  int tamDelimit = tamanhoString(delimiters);
  char *inicio = &str[pos];

  for(; str[pos] != '\0' && token != 1; pos++){
    if(ehIgualDelimitador(str[pos], delimiters, tamDelimit)){
      str[pos] = '\0';
      token = 1;
    }
  }

  return inicio;
}

/* Função que recebe a string e o vetor de delimitadores e imprime a string inicial
 * junto com os delimitadores do vetor.
 */
void imprimeOriginal(char *string, int tam){
  int i, p = 0;
  for(i=0; i<tam; i++){
    if(string[i] != '\0'){
      printf("%c", string[i]);
    } else {
      printf("%c", ordem[p]);
      p++;
    }
  }
  printf("\n");
}


int main(void) {
  char frase[180], delimitadores[10];
  char *inicio;
  
  /* Receebimento das entradas.*/
  fgets(frase, 181, stdin);
  fgets(delimitadores, 11, stdin);
  
  int tamFrase = tamanhoString(frase);
  frase[tamFrase] = '\0';
  
  /* Repetição que separa cada token e os imprime*/
  while(pos < tamFrase){
    inicio = strpock(frase, delimitadores);
    if(*inicio != '\0') printf("%s\n", inicio);
  }

  imprimeOriginal(frase, tamFrase);
  
  return 0;
}