/* Lab 05b - Liber8
 * Nome: Lucas Fernandes Muniz
 * Neste laborat�rio ser� criado um programa que ir� imprimir o estado de um mapa
 * ap�s o acionamento das bombas. 
 */

#include <stdio.h>

/*
Fun��o que recebe uma matriz e seu numero de linhas e colunas, e armazenada a
entrada digitada nas respectivas pos��es da matriz.
*/
void recebeMatriz (char m[][51], int lin, int col){
  int i=0, j=0;
  char c;
  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
        scanf("%c", &c);
        if(c == '\n'){
            j--;
            continue;
        }
        m[i][j] = c;
    }
  }
}

/*
Fun��o que recebe uma matriz e seu numero de linhas e colunas, e imprime a mesma
na tela.
*/
void imprimeMatriz (char m[][51], int lin, int col){
  int i, j;
  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
      printf("%c", m[i][j]);
    }
    printf("\n");
  }
}

/*
Essa fun��o recebe um n�mero e retorna o seu valor absoluto.
*/
int absoluto (int n1){
  if(n1 < 0){
    return -n1;
  } else {
    return n1;
  }
}

/*Fun��o que recebe a localiza��o da bomba (i1, j1) e um determinado ponto (i2, j2)
e a distancia d que a bomba alcan�a, retornando 1 se o ponto for atingido pela bomba,
ou 0 caso contr�rio.
*/
int distancia (int i1, int j1, int i2, int j2, int d){
  int vertical = absoluto(i2-i1);
  int horizontal = absoluto(j2 - j1);
  if (vertical > d || horizontal > d){
    return 0;
  } else {
    return 1;
  }
}

/*
Fun��o recursiva que recebe a localiza��o da bomba (iBomba, jBomba), a 
for�a(alcance) da bomba, uma matriz, e seu n�mero de linhas e colunas. A fun��o
preenche com 'x' os lugares que s�o atingidos pela bomba e preenche com 'B' 
no local onde se encontra a bomba.
*/
void preencheMatriz(int iBomba, int jBomba, int forca, char m[][51],
int linhas, int colunas){
  int i , j;

  int num;
  m[iBomba][jBomba] = 'B';
 
  for(i=0; i<linhas; i++){
      for(j=0; j<colunas; j++){
          if (m[i][j] != '.' && m[i][j] != 'x' && m[i][j] != 'B' && 
          distancia(iBomba, jBomba, i, j, forca)){
              char dist = m[i][j];
              int d = dist - '0';
              preencheMatriz(i, j, d, m, linhas, colunas);
          }
          if (distancia(iBomba, jBomba, i, j, forca) && m[i][j] != 'B'){
              m[i][j] = 'x';
          }
      }
  }
}

int main(){
  int linhas, colunas, x, y, forca;
  scanf("%d %d %d %d", &linhas, &colunas, &x, &y);
  char mapa[51][51];

  recebeMatriz(mapa, linhas, colunas);

  /*Convertendo um caracter num�rico em um n�mero inteiro.*/
  forca = mapa[x-1][y-1] - '0';
  preencheMatriz(x-1, y-1, forca, mapa, linhas, colunas);

  imprimeMatriz(mapa, linhas, colunas);

  return 0;
}vvv