/* Lab 09b - Sistema de notas
 * Nome: Lucas Fernandes Muniz
 * Neste laboratório será desenvolvido funções para gerenciar um banco de dados de notasm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ra, telefone;
    char nome[100];
} Aluno;

typedef struct {
    int armazenados;
    int capacidade;
    Aluno *alunos;
} Base;

/* Cria uma base nova que armazena 0 alunos mas tem capacidade para n, alocando
 * essa quantidade de alunos.
 * Imprime "Base criada.\n" no fim */
void criar_base(Base *base, int n) {
    /* Implemente essa função */
    (*base).alunos = malloc(n*sizeof(int));
    (*base).armazenados = 0;
    (*base).capacidade = n;
    printf("Base criada.\n");
}

/* Procura por aluno ra na base
 * Retorna a posição do aluno no vetor alunos caso ele exista
 * Retorna -1 caso contrário */
int buscar(Base *base, int ra) {
    /* Implemente essa função */
    int i, r;
    for(i=0; i<=(*base).capacidade; i++){
      r = (((base->alunos)[i]).ra);
      if( (((base->alunos)[i]).ra) == ra ){
        return i;
      }
    }
    return -1;
}

/* Imprime a informação de um aluno.
 * Se o aluno ra existe na base, imprime "RA - TELEFONE - NOME\n"
 * Caso contrário imprime "Aluno RA nao encontrado.\n" */
void imprimir(Base *base, int ra) {
    /* Implemente essa função */
    int busca = buscar(base, ra);
    if(busca != -1){
      printf("%d - %d - %s\n", ((base->alunos)[busca]).ra, ((base->alunos)[busca]).telefone, ((base->alunos)[busca]).nome);
    } else {
      printf("Aluno %d nao encontrado.\n", ra);
    }
}


void adicionar(Base *base, int ra, int telefone, char *nome) {
  int pos = -1, i;
    if(buscar(base, ra) != -1){
      pos = buscar(base, ra);
      ((base->alunos)[pos]).ra = ra;
      ((base->alunos)[pos]).telefone = telefone;
      strcpy(((base->alunos)[pos]).nome, nome);
      printf("Alterado: %d - %d - %s\n", ((base->alunos)[pos]).ra, ((base->alunos)[pos]).telefone, ((base->alunos)[pos]).nome);
      
    } else if((base->capacidade) == (base->armazenados)){
      printf("Erro: base cheia.\n");
      
    } else {
      for(i=0; i<=(base->capacidade); i++){
        if(((base->alunos)[i]).ra == 0){
          pos = i;
        }
      }
      if(pos == -1){
        pos = (base->armazenados);
      }
      (base->armazenados)++;
      
      ((base->alunos)[pos]).ra = ra;
      ((base->alunos)[pos]).telefone = telefone;
      strcpy(((base->alunos)[pos]).nome, nome);
      printf("Adicionado: %d - %d - %s\n", ((base->alunos)[pos]).ra, ((base->alunos)[pos]).telefone, ((base->alunos)[pos]).nome);
    }

}

/* Tenta remover um aluno da base.
 * Se o aluno existe na base, remove-o e imprime "Aluno RA removido.\n"
 * Se o aluno não existe, imprime "Aluno RA nao encontrado.\n" */


void remover(Base *base, int ra) {
  int pos = buscar(base, ra);
  if(pos != -1){
      ((base->alunos)[pos]).ra = 0;
      
      (base->armazenados)--;
      
      printf("Aluno %d removido.\n", ra);
  } else {
      printf("Aluno %d nao encontrado.\n", ra);
  }
}

/* Reseta os valores da base para 0 ou NULL, liberando a memória alocada */
void liberar_base(Base *base) {
    /* Implemente essa função */
    /*free(base);*/
    (base->armazenados) = 0;
    (base->capacidade) = 0;
    (base->alunos) = NULL;
    free(base);
}
