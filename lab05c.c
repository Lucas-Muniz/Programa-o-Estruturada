/* lab05c: Intercala��o
 * Autor: Lucas Fernandes Muniz
 * Neste laborat�rio ser� criado um c�digo que intercala dois vetores em ordem crescente.
 */
#include <stdio.h>

/* Fun��o que recebe um vetor e seu tamanho, e preenche o vetor
 * com os n�meros que est�o sendo digitados pelo usu�rio.
 */
void preencherVetor(int vetor[], int tam){
  int i;
  for(i=0; i<tam; i++){
    scanf("%d", &vetor[i]);
  }
}

/* Fun��o que recebe um vetor e seu tamanho, e imprime o vetor 
 * na tela.
 */
void imprimirVetor(int vetor[], int tam){
  int i;
  for(i=0; i<tam; i++){
    if(i == tam -1){
      printf("%d", vetor[i]);
    } else {
      printf("%d ", vetor[i]);
    }
  }
  printf("\n");
}

/* Essa fun��o recebe dois vetores v1 e v2 e seus temanhos, e tamb�m um terceiro
 * vetor v3. A fun���o intercala os vetores v1 e v2 em ordem crescente
 * armazenando o vetor intercalado em v3.
*/
void intercala(int v1[], int n1, int v2[], int n2, int v3[]){
  int i, pos1 = 0, pos2 = 0, n3 = n1 + n2;
  for(i=0; i<n3; i++){
    if(v1[pos1] <= v2[pos2] && pos1 < n1){
      v3[i] = v1[pos1];
      pos1++;
    } else {
      v3[i] = v2[pos2];
      pos2++;
    }
  }
}

int main(void) {
  int n1, n2;

  scanf("%d", &n1);
  int v1[n1];
  preencherVetor(v1, n1);

  scanf("%d", &n2);
  int v2[n2];
  preencherVetor(v2, n2);

  int n3 = n1 + n2; 
  int v3[n3];

  intercala(v1, n1, v2, n2, v3);

  imprimirVetor(v3, n3);

  return 0;
}