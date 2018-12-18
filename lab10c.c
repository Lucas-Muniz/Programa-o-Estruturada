/* Lab 10c - Copa do mundo
 * Nome: Lucas Fernandes Muniz
 * Neste laboratório será criado um código para calcular quais serão as partidas das 
 * oitavas de final, de acordo com os resultados das partidas de cada grupo da copa do mundo.  */

#include <stdio.h> 
#include <string.h>

/* Tamanho maximo de um nome de time */
#define MAX_NOME 30

/* Struct com as informações de cada time. */
struct Time {
  char nome[MAX_NOME];
  int pontos;
  int gols_feitos;
  int saldo_gols;
  int num_vitorias;
  int gols_sofridos;
};
typedef struct Time Time;

/* Atualiza os atributos de um time na tabela de classificacao */
void atualiza_tabela(Time tabela[], int * num_times, char * nome, int gols_feitos, int gols_sofridos) {
  int i, pos;

  /* busca o time na tabela */
  pos = -1;
  for (i = 0; i < * num_times && pos == -1; i++) {
    if (strcmp(nome, tabela[i].nome) == 0)
      pos = i;
  }

  /*Se o time não está na tabela... */
  if (pos == -1) {
    pos = * num_times;
    strcpy(tabela[pos].nome, nome);
    tabela[pos].gols_feitos = gols_feitos;
    tabela[pos].pontos = 0;
    tabela[pos].num_vitorias = 0;
    tabela[pos].gols_sofridos = gols_sofridos;
    (* num_times) ++;
    if (gols_feitos > gols_sofridos) {
      tabela[pos].pontos = 3;
      tabela[pos].num_vitorias = 1;
    } else if (gols_feitos == gols_sofridos) {
      tabela[pos].pontos = 1;
    }
    tabela[pos].saldo_gols = gols_feitos - gols_sofridos;
    return;
  }

  /* se acho o time na tabela */
  tabela[pos].gols_feitos += gols_feitos;
  tabela[pos].gols_sofridos += gols_sofridos;
  if (gols_feitos > gols_sofridos) {
    tabela[pos].pontos += 3;
    tabela[pos].num_vitorias += 1;
  } else if (gols_feitos == gols_sofridos) {
    tabela[pos].pontos += 1;
  }
  tabela[pos].saldo_gols += (gols_feitos - gols_sofridos);

}

/* Determina qual dos dois times eh o mais bem classificado.
 * Retorna 1 se t1 é o melhor e 0 caso contrário */
int eh_maior(Time time1, Time time2) {
  int ordem;

  /* Confere qual time tem maior classificaçãão de acordo com os critérios
   * de desempate.*/
  if (time1.pontos > time2.pontos) {
    return 1;
  } else {
    if (time1.pontos == time2.pontos) {
      if (time1.num_vitorias > time2.num_vitorias) {
        return 1;
      } else {
        if (time1.num_vitorias == time2.num_vitorias) {
          if (time1.saldo_gols > time2.saldo_gols) {
            return 1;
          } else {
            if (time1.saldo_gols == time2.saldo_gols) {
              if (time1.gols_feitos > time2.gols_feitos) {
                return 1;
              } else {
                if (time1.gols_feitos == time2.gols_feitos) {
                  ordem = strcmp(time1.nome, time2.nome);
                  if (ordem < 0) return 1;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

/* Ordena a tabela de times por selection sort */
void ordena_times(Time tabela[], int n) {
  int i, j, melhor, pos;
  Time aux;

  /* Ordenando de forma decrescente. */
  for (i = 0; i < n - 1; i++) {

    /* Buscando o time com melhor classificação. */
    pos = i;
    for (j = i + 1; j < n; j++) {
      melhor = eh_maior(tabela[j], tabela[pos]);
      if (melhor) {
        pos = j;
      }
    }

    /* Trocando os times. */
    aux = tabela[pos];
    tabela[pos] = tabela[i];
    tabela[i] = aux;

  }

  return;

}

int main() {

  int num_jogos, i, j;
  int num_times [8];
  int gols1, gols2;
  char nome_time1[MAX_NOME], nome_time2[MAX_NOME];
  /* Matriz que contém os 8 grupos e os times de cada grupo.*/
  Time tabela[8][4];

  /* Estrutura de repetição que lê as partidas de cada grupo. */
  for(i=0; i<8; i++){
    num_times[i] = 0;
    for (j=0; j<6; j++) {
    scanf("%s %d x %d %s", nome_time1, & gols1, & gols2, nome_time2);
    atualiza_tabela(tabela[i], & num_times[i], nome_time1, gols1, gols2);
    atualiza_tabela(tabela[i], & num_times[i], nome_time2, gols2, gols1);
    }
  }

  /* Ordenando a tabela de times */
  for(i=0; i<8; i++){
    ordena_times(tabela[i], num_times[i]);
  }

  /* Impressão do resultado de cada grupo. */
  for(i=0; i<8; i++){
    printf("Grupo %c:\n", (65+i));
    for(j=0; j<4; j++){
      printf("%-15s %3d %3d %3d %3d\n", tabela[i][j].nome, tabela[i][j].pontos,
      tabela[i][j].gols_feitos, tabela[i][j].gols_sofridos,tabela[i][j].saldo_gols);
    }
    printf("\n");
  }
  
  /* Impressão dos resultados para as partidas das oitavas de final. */
  printf("Oitavas de final:\n");
  for(i=0; i<8; i+=2){
      printf("%15s x %s\n", tabela[i][0].nome, tabela[i+1][1].nome);
      printf("%15s x %s\n", tabela[i+1][0].nome, tabela[i][1].nome);
  }

  return 0;
}