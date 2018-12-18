/* Lab 9c - CPU Wars
 * Nome: Lucas Fernandes Muniz
 * Neste laboratório iremos criar um programa que guarda o estado de um Super Trunfo
 * (CPU Wars), após um número n de rodadas. 
 */
 
#include <stdio.h>

/* estrutura que define as cartas. */
struct Carta {
    char nome[31];
    int caracteristicas[8];
};
typedef struct Carta Carta;

/* Lendo os valores da carta no arquivo. */
void lerCartas (FILE *arqin, Carta *baralho, int numCartas){
  int i, j;
  char aux;
  for(i=0; i<numCartas; i++){
    aux = fgetc(arqin);
    fgets(baralho[i].nome, 30, arqin);
    for(j=0; j<8; j++){
      fscanf(arqin, "%d", &baralho[i].caracteristicas[j]);
    }
  }
}

/* Verificando qual jogador tem a carta com a maior característica, retornando -1 
 * se for o primeiro jogador, 1 se for o segundo e 0 caso ambas as cartas tenham
 * o mesmo valor. */
int verificarMaior(Carta *meuBaralho, Carta *luqueBaralho, int caracteristica){
  if(meuBaralho[0].caracteristicas[caracteristica-1] > luqueBaralho[0].caracteristicas[caracteristica-1]){
    return -1;
  } else if (meuBaralho[0].caracteristicas[caracteristica-1] < luqueBaralho[0].caracteristicas[caracteristica-1]){
    return 1;
  } else {
    return 0;
  }
}

/* Verificando qual jogador tem a carta com a menor característica, retornando -1 
 * se for o primeiro jogador, 1 se for o segundo e 0 caso ambas as cartas tenham
 * o mesmo valor. */
int verificarMenor(Carta *meuBaralho, Carta *luqueBaralho, int caracteristica){
  if(meuBaralho[0].caracteristicas[caracteristica-1] < luqueBaralho[0].caracteristicas[caracteristica-1]){
    return -1;
  } else if (meuBaralho[0].caracteristicas[caracteristica-1] > luqueBaralho[0].caracteristicas[caracteristica-1]){
    return 1;
  } else {
    return 0;
  }
}

/* Movendo a primeira carta de cada deck para o fundo da pilha do vencedor. */
void moverParaFundo(Carta *meuBaralho, int *Q1, Carta *luqueBaralho, int *Q2, int vencedor){
  Carta baralho1, baralho2;
  int i;

  baralho1 = meuBaralho[0];
  baralho2 = luqueBaralho[0];

  for(i=0; i < *Q1-1; i++){
    meuBaralho[i] = meuBaralho[i+1];
  }

  for(i=0; i < *Q2-1; i++){
    luqueBaralho[i] = luqueBaralho[i+1];
  }

  switch(vencedor){
    case -1:
      meuBaralho[*Q1-1] = baralho1;
      meuBaralho[*Q1] = baralho2;
      (*Q1)++;
      (*Q2)--;
      break;
    case 1:
      luqueBaralho[*Q2-1] = baralho2;
      luqueBaralho[*Q2] = baralho1;
      (*Q2)++;
      (*Q1)--;
  }

}

/* Função que executa cada rodada do jogo, definindo quem é o vencedor e quem tem a 'vez da partida' no jogo. */
void rodada(Carta *meuBaralho, int *Q1, Carta *luqueBaralho, int *Q2, int *jogadorVez, int caracteristica){
  int vencedor;

  switch(caracteristica){
    case 1:
    case 2:
    case 4:
    case 5:
      vencedor = verificarMaior(meuBaralho, luqueBaralho, caracteristica);
      break;
    case 3:
    case 6:
    case 7:
    case 8:
      vencedor = verificarMenor(meuBaralho, luqueBaralho, caracteristica);
      break;
  }

  if(vencedor == 0){
    if(*jogadorVez == 1){
      vencedor = -1;
    } 
    if(*jogadorVez == 2){
      vencedor = 1;
    } 
  }

  if(vencedor == -1) *jogadorVez = 1;
  if(vencedor == 1) *jogadorVez = 2;

  moverParaFundo(meuBaralho, Q1, luqueBaralho, Q2, vencedor);
}


int main(int argc, char *argv[]) {
  char aux;
  
  /* Lendo o número de rodadas da entrada padrão. */
  int numRodadas, i, j;
  scanf("%d", &numRodadas);
  /* Guardando as características escolhidas para casa rodada. */
  int escolhidas[numRodadas];
  for(i=0; i<numRodadas; i++){
    scanf("%d", &escolhidas[i]); 
  }

  /* Abrindo os arquivos.*/
  FILE *arqin = fopen(argv[1],"r");
  FILE *arqout = fopen(argv[2],"w");

  if(arqin == NULL){
    printf("Erro na leitura do arquivo.\n");
  }
  
  /* Quantidade de cartas de cada jogador. */
  int Q1, Q2, jogador;
  fscanf(arqin,"%d", &Q1);
  fscanf(arqin,"%d", &Q2);
  fscanf(arqin,"%d", &jogador);

  /* Declaração do baralho máximo de cada jogador. */
  Carta minhasCartas[Q1+Q2+1], LuqueCartas[Q2+Q1+1];
  
  /* Lendo as cartas a partir do arquivo texto. */
  lerCartas(arqin, minhasCartas, Q1);
  lerCartas(arqin, LuqueCartas, Q2);

  /* Execução de cada rodada do jogo. */
  for(i=0; i<numRodadas; i++){
    rodada(minhasCartas, &Q1, LuqueCartas, &Q2, &jogador, escolhidas[i]);
  }


  /* Escrevendo o arquivo de saída em arqout. */
  fprintf(arqout, "%d", Q1);
  fprintf(arqout, "%c", ' ');
  fprintf(arqout, "%d", Q2);
  fprintf(arqout, "%c", ' ');
  fprintf(arqout, "%d", jogador);
  fprintf(arqout, "%c", '\n');

  for(i=0; i<Q1; i++){
    fprintf(arqout, "%s", minhasCartas[i].nome);
    for(j=0; j<8; j++){
      fprintf(arqout, "%d", minhasCartas[i].caracteristicas[j]);
      if(j == 7) fprintf(arqout, "%c", '\n');
      else fprintf(arqout, "%c", ' ');
    }
  }
  
  for(i=0; i<Q2; i++){
    fprintf(arqout, "%s", LuqueCartas[i].nome);
    for(j=0; j<8; j++){
      fprintf(arqout, "%d", LuqueCartas[i].caracteristicas[j]);
      if(j == 7) fprintf(arqout, "%c", '\n');
      else fprintf(arqout, "%c", ' ');
    }
  }
  

  fclose(arqin);
  fclose(arqout);
  
  return 0;
}