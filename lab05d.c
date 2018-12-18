/* lab05d: Processamento de imagens
 * Autor: Lucas Fernandes Muniz
 * Neste laboratório vamos implementar 4 filtros em imagens.
 */

#include <stdio.h>
#include <string.h>

/* Definindo tamanho maximo das imagens */
#define MAX_TAM 400

int ler_pgm(int img[][MAX_TAM], int *W, int *H, int *MaxV,
            int *F, double *Px, double *Py);
void escrever_pgm(int img[][MAX_TAM], int W, int H, int MaxV);

/*Função que recebe um número e retorna o seu valor absoluto*/
int absoluto(int n){
	if(n<0){
		return -n;
	}
	return n;
}

/*Função que recebe uma matriz m1, seu comprimento, altura e também
 * uma outra matriz m2, e copia os lementos da matriz m1 para a m2.
 */
void copiaMatriz(int m1[][MAX_TAM],int W, int H, int m2[][MAX_TAM]){
  int i, j;
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      m2[i][j] = m1[i][j];
    }
  }
}

/*Função que recebe uma matriz, seu comprimento e altura e retorna 
 * a matriz recebidad com todos os elemntos com o valor 0.
 */
void zeraMatriz(int m[][MAX_TAM],int W, int H){
  int i, j;
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      m[i][j] = 0;
    }
  }
}

/* Negativo */
/*Função que recebe a matriz imagem, seu comprimento, altura e valor
 * máximo da divisão de cores da imagem. A função retorna a imagem
 * com as intensidades das cores invertidas.
 */
void negativo(int img[][MAX_TAM], int W, int H, int MaxV) {
    
     int i, j;
     for(i=0; i<H; i++){
     	for(j=0; j<W; j++){
     		img[i][j] = absoluto(img[i][j] - MaxV);
     	}
     }
}

/* Rotacao de 180 graus */
/* Função que uma matriz, seu comprimento e altura e retorna a 
 * matriz recebida invertida.
 */
void rotacao180(int img[][MAX_TAM], int W, int H) {
    
     int i, j;
     int img2[H][MAX_TAM];
     copiaMatriz(img,  W,  H, img2);
     for(i=H-1; i>=0; i--){
       for(j=W-1; j>=0; j--){
         img[H-i-1][W-j-1] = img2[i][j];
       }
     }
     
}

/* Deteccao de bordas */
/* Função que recebe uma matriz, seu comprimento, altura e número
 * máximo de tonalidades e retorna a matriz da imagem destacndo
 * as bordas.
 */
void detectaBorda(int img[][MAX_TAM], int W, int H, int MaxV) {
   
     int i, j;
     int img2[H][MAX_TAM];
     copiaMatriz(img, W, H, img2);

     for(i=0; i<=H; i++){
       for(j=0; j<W; j++){
         if (i==0 || i==(H-1) || j==0 || j==(W-1)){
           continue;
         }
         img[i][j] = 0;
         img[i][j] += -1*(img2[i-1][j-1]+img2[i-1][j+1]+img2[i+1][j-1]+img2[i+1][j+1]);
         img[i][j] += -4*(img2[i][j-1]+img2[i][j+1]+img2[i+1][j]+img2[i-1][j]);
         img[i][j] += 20*img2[i][j];

         if(img[i][j] < 0) img[i][j] = 0;
         if(img[i][j] > MaxV) img[i][j] = MaxV;
      }
     }

}

/* Cisalhamento */
/* Função que recebe uma matriz, seu comprimento, altura, e as 
 * intensidades de cisalhamento Px e Py, retornando a matriz da
 * distorcida de acordo com as inteensidades do cisalhemnto.
 */
void cisalhamento(int img[][MAX_TAM], int W, int H, double Px, double Py) {  

     int i, j, x, y;
     int img2[H][MAX_TAM];
     copiaMatriz(img, W, H, img2);  
     zeraMatriz(img, W, H);   

     for(i=0; i<H; i++){
       for(j=0; j<W; j++){
         x = i + Py*j;
         y = j + Px*i;
         if (x > H || x < 0 || y < 0 || y > W){
           continue;
         }
         img[x][y] = img2[i][j];
       }
     }
}


/* VOCE NAO DEVE ALTERAR A FUNCAO PRINCIPAL */
int main() {
    /* Matriz que armazena os pixels da imagem */
    int img[MAX_TAM][MAX_TAM]; 
    /* Atributos da imagem */
    int W, H, MaxV;
    /* Identificador do filtro a ser utilizado */
    int F;
    /* Parâmetro a ser passado para o cisalhamento */
    double Px, Py;

    /* Le a imagem */
    if (ler_pgm(img, &W, &H, &MaxV, &F, &Px, &Py) != 1) {
        printf("Error: nao foi possivel ler a imagem\n");
        return 0;
    }
 
    /* Seleciona o filtro */
    switch (F) {
        case 1:
            negativo(img, W, H, MaxV);
            break;
        case 2:
            rotacao180(img, W, H);
            break;
        case 3:
            detectaBorda(img, W, H, MaxV);
            break;
        case 4:
            cisalhamento(img, W, H, Px, Py);
            break;
    }

    /* Escreve a imagem */
    escrever_pgm(img, W, H, MaxV);

    return 0;
}


/* Le uma imagem em formato PGM a partir da entrada padrao.
 * Retorna 1 se a leitura for realmente de um arquivo PGM
 * e 0 caso contrario.
 * VOCE NAO DEVE ALTERAR ESTA FUNCAO                       */
int ler_pgm(int img[][MAX_TAM], int *W, int *H, int *MaxV,
            int *F, double *Px, double *Py) {
    char nome_formato[3];
    char c;
    int i,j;

    /* Le o formato da imagem. P2 indica o formato PGM */
    scanf("%s ", nome_formato);
    if (strcmp(nome_formato, "P2") != 0)
        return 0;

    /* Le o '#', que indica um comentario, e os numeros indicando
    * o filtro e o parametro, se houver */
    scanf("%[#]c", &c);
    scanf("%d", F);
    if (*F == 4) {
        scanf("%lf %lf", Px, Py);
    } 
 
    /* Le dimensoes e intensidade maxima da imagem */
    scanf("%d", W);
    scanf("%d", H);
    scanf("%d", MaxV);
 
    /* Le o valor de cada pixel da imagem */
    for (i = 0; i < (*H); i++) {
        for (j = 0; j < (*W); j++) {
            scanf("%d", &img[i][j]);
        }
    }

    return 1;
}

/* Escreve a imagem em formato pgm na saida padrao 
 * VOCE NAO DEVE ALTERAR ESTA FUNCAO               */
void escrever_pgm(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j;

    /* Escreve os atributos da imagem */
    /* Tipo da imagem: P2 significa pgm*/
    printf("P2\n");
    /* Dimensoes e intensidade maxima da imagem */
    printf("%d %d %d\n", W, H, MaxV);

    /* Escreve os pixels da imagem */
    for (i = 0; i < H; i++) {
        printf("%d", img[i][0]);
        for (j = 1; j < W; j++) {
            printf(" %d", img[i][j]);
        }
        printf("\n");
    }
}