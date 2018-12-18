/* Lab 10a - Sistema da Prograd
 * Nome: Lucas Fernandes Muniz
 * Neste laboratório será implementado um sisteminha de controle de aluno da Prograd.
 */

#include <stdio.h>

typedef enum ENUM_ORDEM {CRESCENTE, DECRESCENTE, DESORDENADA} ordem_t;

/* Função que busca um aluno na lista pelo algoritmo de busca binária. */
void busca_binaria(int vet[], int ini, int fim, int ra, ordem_t ordem) {
    /* Implementando a busca binária. */
  int meio = (ini+fim)/2;

  if(fim<ini){
    printf("\n%d nao esta na lista!", ra);
    return;
  }

  printf("%d ", meio);
  if(vet[meio] == ra){
    printf("\n%d esta na posicao: %d", ra, meio);
    return;
  }
  
  /* verificando se a lista esta na ordem crescente ou decrescente. */
  if(ordem == CRESCENTE){
    if(ra < vet[meio]){
      busca_binaria(vet, ini, meio - 1, ra,  ordem);
    } else {
      busca_binaria(vet, meio + 1, fim, ra,  ordem);
    }
  } else {
    if(ra < vet[meio]){
      busca_binaria(vet, meio + 1, fim, ra, ordem);
    } else {
      busca_binaria (vet, ini, meio - 1, ra, ordem);
    }
  }

}

/* Função que busca um aluno na lista por um algoritmo de busca sequencial. */
int encontra_pos(int vet[], int ini, int fim, int ra, ordem_t ordem) {
   /* Fazendo a busca sequencial. */
    int i;
    for(i=ini; i<=fim; i++){
      if(vet[i] == ra){
        return i;
      }
    }
    return -1;
}

/* Função que recebe um vetor e seu tamanho, e coloca o vetor em ordem
 * crescente por Selection Sort. 
 */
void ordenacaoCrescente(int vet[], int tam){
  int i, j, pos, aux; 
  for(i=0; i<tam-1; i++){
    /* Busca do menor elemento.*/
    pos = i;
    for(j=i+1; j<tam; j++){
      if(vet[j] < vet[pos]){
        pos = j;
      }
    }
    /* Trocando a posição.*/
    aux = vet[i];
    vet[i] = vet[pos];
    vet[pos] = aux;
  }
}

/* Função que recebe um vetor e seu tamanho, e coloca o vetor em ordem
 * decrescente por Selection Sort. 
 */
void ordenacaoDescrescente(int vet[], int tam){
  int i, j, pos, aux; 
  for(i=0; i<tam-1; i++){
    /* Busca do maior elemento.*/
    pos = i;
    for(j=i+1; j<tam; j++){
      if(vet[j] > vet[pos]){
        pos = j;
      }
    }
    /* Trocando a posição.*/
    aux = vet[i];
    vet[i] = vet[pos];
    vet[pos] = aux;
  }
}

int main() {
    int i, j, pos, n;
    int aux;
    int lista[150];
    char op;
    ordem_t ordenacao = DESORDENADA;

    /* lendo quantidade de alunos e RA de cada um: */
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }

    do {
        scanf("%c", &op);
        switch(op) {
            case 'p':
                /* Operação de impressão da lista atual */
                if (n > 0) {
                    for (i = 0; i < n; i++)
                        printf("%d ", lista[i]);
                    printf("\n");
                }
                break;

            case 'c':
                /* Ordenar de forma crescente a lista
                 * Vamos usar Selection Sort */
                
                ordenacaoCrescente(lista, n);
                ordenacao = CRESCENTE;
                break;

            case 'd':
                /* Ordenar de forma decrescente a lista
                 * Vamos usar Selection Sort */

                ordenacaoDescrescente(lista, n);
                ordenacao = DECRESCENTE;
                break;

            case 'b':
                /* Fazer busca na lista apenas se ela estiver ordenada de alguma forma */
                scanf("%d", &aux);
                if (ordenacao == DESORDENADA)
                    printf("Vetor nao ordenado!");
                else
                    busca_binaria(lista, 0, n-1, aux, ordenacao);
                printf("\n");
                break;

            case 'i':
                /* Inserir aluno novo apenas se houver espaço na turma */
                scanf("%d", &aux);

                if (n == 150) {
                    printf("Limite de vagas excedido!\n");
                    break;
                } else {
                  pos = encontra_pos(lista, 0, n-1, aux, ordenacao);
                  if(pos == -1){
                    /* Adicionando o aluno ao final da lista.*/
                    n++;
                    lista[n-1] = aux;
                    if(ordenacao == CRESCENTE){
                      /* Ordenando a lista de forma crescente*/
                      ordenacaoCrescente(lista, n);
                    } else if (ordenacao == DECRESCENTE){
                      /* Ordenando a lista de forma decrescente*/
                      ordenacaoDescrescente(lista, n);
                    }
                  } else {
                    printf("Aluno ja matriculado na turma!\n");
                  }
                }

                break;

            case 'r':
                /* Remover aluno da lista apenas se ele existir */
                scanf("%d", &aux);

                /* Não remover caso a turma esteja cheia. */
                if (n == 0) {
                    printf("Nao ha alunos cadastrados na turma!\n");
                    break;
                } else {
                  /* Procurando o aluno na lista. */
                  pos = encontra_pos(lista, 0, n-1, aux, ordenacao);
                  /* Caso ele não esteja na lista. */
                  if(pos == -1){
                    printf("Aluno nao matriculado na turma!\n");
                  } else {
                    /* Caso o aluno esteja na lista. */
                    while((pos+1)<n){
                      lista[pos] = lista[pos+1];
                      pos++; 
                    }
                    n--;
                  }
                }

                break;

            case 's':
                break;
        }
    } while(op != 's');

    return 0;
}
