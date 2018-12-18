/* lab06a: Mortos de fome
 * Autor: Lucas Fernandes Muniz
 * Neste laboratório será implementado um código que calcula a trajetória de zumbis em um determinado mapa
 */
#include <stdio.h>
#define MAX_SIZE 100

/* Função que recebe uma matriz, o número de linhas, o número de coluna e uma variável
 * espacos. A função preenche a matriz com os caracteres do mapa e conta o número
 * de espaços vazios e armazena na variável espacos.
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

/* Função que recebe uma matriz de caracter, uma matriz de inteiros, o número de 
 * linhas e colunas de ambas, e preenche as matrizes com os valores de lateralidade,
 * direção, e cordenadas x e y de cada zumbi no mapa.
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

/* Função que recebe uma matriz de caracteres, número de linhas e de colunas
 * e imprime a matriz na tela. Essa função é utilizada para imprimir o mapa.*/
void imprimeMatriz (char m[][MAX_SIZE], int lin, int col){
  int i, j;
  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
      printf("%c", m[i][j]);
    }
    printf("\n");
  }
}

/* Função que recebe um vetor de caracter de um dado zumbi, e altera o eixo de 
 * direção do zumbi de acordo com a lateralidade do mesmo.*/
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

/* Função que recebe um caracter e um vetor com as informações de um dado zumbi
 * e verifica se o caracter é um obstáculo 'X', se for um obstaculo, o eixo
 *  de direção do zumbi é mudado e a função retorna 0, caso contrário, retorna 1.
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

/* Função que recebe uma matriz de caracteres (o mapa), uma posição x, outra posição
 * y e o número de espaços preenchidos com '#'. A função preenche o local passado 
 * como parâmetro no mapa com o caracter '#', e adiciona 1 ao númeero de espaços
 * preenchidos.
 */
void preencheBranco (char mapa[][MAX_SIZE], int x, int y, int *espacoPreenchido){
  if (mapa[x][y] != '#'){
    *espacoPreenchido = *espacoPreenchido + 1;
    mapa[x][y] = '#';
  }
}


/* Função que recebe um vetor de caracteres(informações dos zumbis), umvetor de
 * inteiros (coordenadas dos zumbis), uma matriz de caracteres (o mapa), o número 
 * de tempo e o número de espaços preenchidos. A função simula o movimento de cada
 * zumbi verificando onde há obstaculos e mudando a ddireção do zumbi e preenchendo
 * os locais onde o zumbi já passou.
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

/* Função qur recebe uma matriz de caracter, uma matriz de inteiros e o número de
 * zumbis e imprime a coordenada e a direção de cada zumbi.
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
 
 /* A função movimento é chamada para calcular o moiimento de cada zumbi.*/
  for(i=0; i<numZumbis; i++){
    movimento(zumbisInfo[i], zumbisCoord[i], mapaMercado, tempo, &espacoPreenchidos);
  }
 
 /* O número de espaços que nenhum zumbi passou e calculado pelo número de espaços
  * brancos iniciais menos os espaços que foram preenchidos.
  */
  espacosBrancos -= espacoPreenchidos; 
  
  /*Impressão dos resultados.*/
  imprimeZumbi(zumbisInfo, zumbisCoord, numZumbis);
  printf("\n");
  imprimeMatriz(mapaMercado, n, m);
  printf("\n");
  printf("%d", espacosBrancos);
  printf("\n");

  return 0;
}