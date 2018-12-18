/* Lab 10b - Paixão Nacional
 * Nome: Lucas Fernandes Muniz
 * Neste laboratório será criado um código para organizar a classificação de times
 * em um campeonato de futebol. */

#include <stdio.h> 
#include <string.h>

/* Tamanho maximo de um nome de time */
#define MAX_NOME 26
/* Numero maximo de partidas */
# define MAX_TIMES 400

struct Time {
  char nome[MAX_NOME];
  int pontos;
  int gols_feitos;
  int saldo_gols;
  int num_vitorias;
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

  int num_jogos, num_times, i;
  int gols1, gols2;
  char nome_time1[MAX_NOME], nome_time2[MAX_NOME];
  Time tabela[MAX_TIMES];

  /* Lendo a entrada */
  scanf("%d", & num_jogos);
  for (i = 0; i < num_jogos; i++) {
    scanf("%s %d x %d %s", nome_time1, & gols1, & gols2, nome_time2);
    atualiza_tabela(tabela, & num_times, nome_time1, gols1, gols2);
    atualiza_tabela(tabela, & num_times, nome_time2, gols2, gols1);
  }

  /* Ordenando a tabela de times */
  ordena_times(tabela, num_times);

  /* Escrevendo a saida */
  for (i = 0; i < num_times; i++) {
    printf("%-30s %5d %5d %5d %5d\n", tabela[i].nome, tabela[i].pontos,
      tabela[i].num_vitorias, tabela[i].saldo_gols, tabela[i].gols_feitos);
  }

  return 0;
}
