/* lab06a: Mortos de fome
 * Autor: Lucas Fernandes Muniz
 * Neste laborat�rio ser� implementado um c�digo que calcula a trajet�ria de zumbis em um determinado mapa
 */
#include <stdio.h>
#define MAX_SIZE 100

/* Fun��o que recebe uma matriz, o n�mero de linhas, o n�mero de coluna e uma vari�vel
 * espacos. A fun��o preenche a matriz com os caracteres do mapa e conta o n�mero
 * de espa�os vazios e armazena na vari�vel espacos.
 */
void recebeMatriz (char m[][MAX_SIZE], int lin, int col, int *espacos){
  int i=0, j=0;
  char c;
  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
        scanf("%c", &c);
        if(c == '\n'){
            j--;
            continue;
        }
        if (c == ' ') {*espacos = *espacos + 1;}
        m[i][j] = c;
    }
  }
}

/* Fun��o que recebe uma matriz de caracter, uma matriz de inteiros, o n�mero de 
 * linhas e colunas de ambas, e preenche as matrizes com os valores de lateralidade,
 * dire��o, e cordenadas x e y de cada zumbi no mapa.
 */
void recebeZumbis (char zumbiInfo[][2], int zumbiCoord[][2] , int lin, int col){
  int i=0, j=0, num;
  char c;
  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
        
        if (j<2){
          scanf("%c", &c);
          if(c == '\n' || c == ' '){
            j--;
            continue;
          }
          zumbiInfo[i][j] = c;
        } else {
          scanf("%d", &num);
          zumbiCoord[i][j-2] = num;
        }
        
    }
  }
}

/* Fun��o que recebe uma matriz de caracteres, n�mero de linhas e de colunas
 * e imprime a matriz na tela. Essa fun��o � utilizada para imprimir o mapa.*/
void imprimeMatriz (char m[][MAX_SIZE], int lin, int col){
  int i, j;
  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
      printf("%c", m[i][j]);
    }
    printf("\n");
  }
}

/* Fun��o que recebe um vetor de caracter de um dado zumbi, e altera o eixo de 
 * dire��o do zumbi de acordo com a lateralidade do mesmo.*/
void mudaEixo(char zumbi[]){
  if (zumbi[0] == 'R'){
    switch(zumbi[1]){
      case 'N':
        zumbi[1] = 'E';
        break;
      case 'E':
        zumbi[1] = 'S';
        break;
      case 'S':
        zumbi[1] = 'W';
        break;
      case 'W':
        zumbi[1] = 'N';
        break;
    }
  } else if (zumbi[0] == 'L'){
    switch(zumbi[1]){
      case 'N':
        zumbi[1] = 'W';
        break;
      case 'W':
        zumbi[1] = 'S';
        break;
      case 'S':
        zumbi[1] = 'E';
        break;
      case 'E':
        zumbi[1] = 'N';
        break;
    }
  }

}

/* Fun��o que recebe um caracter e um vetor com as informa��es de um dado zumbi
 * e verifica se o caracter � um obst�culo 'X', se for um obstaculo, o eixo
 *  de dire��o do zumbi � mudado e a fun��o retorna 0, caso contr�rio, retorna 1.
 */
int obstaculo (char obstaculo, char zumbi[]){
  char c = obstaculo;
  if (obstaculo != 'X'){
    return 1;
  } else {
    mudaEixo(zumbi);
    return 0;
  }
}

/* Fun��o que recebe uma matriz de caracteres (o mapa), uma posi��o x, outra posi��o
 * y e o n�mero de espa�os preenchidos com '#'. A fun��o preenche o local passado 
 * como par�metro no mapa com o caracter '#', e adiciona 1 ao n�meero de espa�os
 * preenchidos.
 */
void preencheBranco (char mapa[][MAX_SIZE], int x, int y, int *espacoPreenchido){
  if (mapa[x][y] != '#'){
    *espacoPreenchido = *espacoPreenchido + 1;
    mapa[x][y] = '#';
  }
}


/* Fun��o que recebe um vetor de caracteres(informa��es dos zumbis), umvetor de
 * inteiros (coordenadas dos zumbis), uma matriz de caracteres (o mapa), o n�mero 
 * de tempo e o n�mero de espa�os preenchidos. A fun��o simula o movimento de cada
 * zumbi verificando onde h� obstaculos e mudando a ddire��o do zumbi e preenchendo
 * os locais onde o zumbi j� passou.
 */
void movimento (char zumbi[], int zumbiCoord[], char mapa[][MAX_SIZE], int tempo, int *espacoPreenchido){
  int x, y, i;
  x = zumbiCoord[0];
  y = zumbiCoord[1];

  preencheBranco(mapa, x, y, espacoPreenchido);

 for(i=0; i<tempo; i++){
   char obstac;
   switch(zumbi[1]){
    case 'N':
      x--;
      obstac = mapa[x][y];
      if (obstaculo(obstac, zumbi)){
        preencheBranco(mapa, x, y, espacoPreenchido);
        zumbiCoord[0] = x;
      } else {
          x++;
      }
      break;
    case 'S':
      x++;
      obstac = mapa[x][y];
      if (obstaculo(obstac, zumbi)){
        preencheBranco(mapa, x, y, espacoPreenchido);
        zumbiCoord[0] = x;
      } else {
          x--;
      }
      break;
    case 'W':
      y--;
      obstac = mapa[x][y];
      if (obstaculo(obstac, zumbi)){
        preencheBranco(mapa, x, y, espacoPreenchido);
        zumbiCoord[1] = y;
      } else {
          y++;
      }
      break;
    case 'E':
      y++;
      obstac = mapa[x][y];
      if (obstaculo(obstac, zumbi)){
        preencheBranco(mapa, x, y, espacoPreenchido);
        zumbiCoord[1] = y;
      } else {
          y--;
      }
      break;
  }
 }
  
}

/* Fun��o qur recebe uma matriz de caracter, uma matriz de inteiros e o n�mero de
 * zumbis e imprime a coordenada e a dire��o de cada zumbi.
 */
void imprimeZumbi(char zumbi[][2], int zumbiCoord[][2], int numZumbi){
  int i;
  for(i=1; i<=numZumbi; i++){
    printf("Zumbi %d: (%d, %d, %c)\n", i, zumbiCoord[i-1][0], zumbiCoord[i-1][1], zumbi[i-1][1]);
  }
}

int main (){
  int n, m, numZumbis, tempo, i;
  int espacosBrancos = 0, espacoPreenchidos = 0;

  scanf("%d %d", &n, &m);
  char mapaMercado[n][MAX_SIZE];
  recebeMatriz(mapaMercado, n, m, &espacosBrancos);

  scanf("%d", &numZumbis);
  char zumbisInfo[numZumbis][2];
  int zumbisCoord[numZumbis][2];
  recebeZumbis(zumbisInfo, zumbisCoord, numZumbis, 4);

  scanf("%d", &tempo);
 
 /* A fun��o movimento � chamada para calcular o moiimento de cada zumbi.*/
  for(i=0; i<numZumbis; i++){
    movimento(zumbisInfo[i], zumbisCoord[i], mapaMercado, tempo, &espacoPreenchidos);
  }
 
 /* O n�mero de espa�os que nenhum zumbi passou e calculado pelo n�mero de espa�os
  * brancos iniciais menos os espa�os que foram preenchidos.
  */
  espacosBrancos -= espacoPreenchidos; 
  
  /*Impress�o dos resultados.*/
  imprimeZumbi(zumbisInfo, zumbisCoord, numZumbis);
  printf("\n");
  imprimeMatriz(mapaMercado, n, m);
  printf("\n");
  printf("%d", espacosBrancos);
  printf("\n");

  return 0;
}