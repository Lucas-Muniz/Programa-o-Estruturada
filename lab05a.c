/* Lab 05a - Killing the Messenger
 * Nome: Lucas Fernandes Muniz
 * Neste laboratório será feito um código que verifica se o gene foi silenciado.
*/

#include <stdio.h>

/*
Essa função recebe uma string e uma posição, faz a leitura da base nitrogenada e
retorna a base nitrogenada correspondente na transcrição.
*/
char baseNitrogenada (char primeira[], int i){
  char base = primeira[i]; 
  switch (base){
    case 'A':
      return 'U';
      break;
    case 'U':
      return 'A';
      break;
    case 'C':
      return 'G';
      break;
    case 'G':
      return 'C';
      break;
  }
}

/*
Função que recebe duas strings e o tamanho da primeira, verifica na ordem 
inversa a base nitrogenada da primeira string e troca pela base nitrogenada 
correspondente na transcrição, aramzenando-a na segunda string.
*/
void leituraFita (char primeira[], char segunda[], int tam){
  int i, pos = 0;
  for(i=tam; i>= 0; i--){
    segunda[pos]= baseNitrogenada(primeira, i);
    pos++;
  }
}

/*
Essa função recebe duas strings e seus respectivos tamanhos, e procura se a 
segunda string esta contida na primeira, retornando -1 para caso a segunda não 
seja encontrada, ou retornando a posição onde a string foi encontrada.
*/
int busca (char rna[], int tamRNA, char fita[], int tamFITA){
  int i, pos = 0;
  for(i=0; i<tamRNA; i++){
    while (fita[pos] == rna[i]){
      i++;
      pos++;
    }

    if(pos != 0){
      if (pos == tamFITA){
        return i - pos;
      }
      i -= pos;
      pos = 0;
    }

  }
  return -1;
}

/*
Essa função recebe uma string vazia e seu tamanho, e armazena os caracteres 
digitados dentro da string.
*/
void recebeString(char str[], int tam){
  int i;
  for(i=0; i<tam+1; i++){
    scanf("%c", &str[i]);
  }
}


int main(){
  int nRNA, nFita, pos;
  scanf("%d %d", &nRNA, &nFita);
  char RNA[nRNA+1], Fita1[nFita+1], Fita2[nFita];

  recebeString(RNA, nRNA);
  recebeString(Fita1, nFita);

  leituraFita(Fita1, Fita2, nFita);
  pos = busca(RNA, nRNA, Fita2, nFita);

  if (pos == -1){
    printf("Nao silenciado\n");
  } else {
    printf("Silenciado em %d\n", pos);
  }

  return 0;
}