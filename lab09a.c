/* lab 9a - Sem Comentários
 * Nome: Lucas Fernandes Muniz
 * Neste laboratório será criado um programa que lê um código em C e retira todos
 * os comentários desse código.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

  /* Ponteiros que recem os arquivos. */
  FILE *arqin = fopen(argv[1],"r");
  FILE *arqout = fopen(argv[2],"w");

  char charAntigo, charAtual;
  
  fscanf(arqin, "%c", &charAntigo);
  /* Variáveis que indicam quando se está dentro de um comentário:
   * comentario1 é usado para indicar o comentário do tipo '//';
   * comentario2 é usado para indicar um comentário do tipo '/*'. */
  int comentario1;
  comentario1 = 0;
  int comentario2;
  comentario2 = 0;
  
  while(fscanf(arqin, "%c", &charAtual) != EOF){
    
    if(comentario1 == 0 && comentario2 == 0){
      /* Verificando se um comentário é iniciado.*/
      if(charAntigo == '/'){
          
        if(charAtual == '/' || charAtual == '*'){
          if(charAtual == '/'){
            comentario1 = 1;
          } else {
            comentario2 = 1;
          }
        } else {
          fprintf(arqout, "%c", charAntigo);
        }
        
      } else {
        fprintf(arqout, "%c", charAntigo);
      }

    } else {
      /* Verificando quando o comentário é terminado. */
      if(charAntigo == '\n' && comentario1){
        fprintf(arqout, "%c", '\n');
        comentario1 = 0;
      } else if (charAntigo == '*' && comentario2){
        if(charAtual == '/'){
          comentario2 = 0;
          /* Scanf para pular um caracter do arquivo.*/
          fscanf(arqin, "%c", &charAtual);
        } 
      } 
    }

    charAntigo = charAtual;

  }

  fprintf(arqout, "%c", '\n');

  /* Fechando arquivos recebidos. */
  fclose(arqin);
  fclose(arqout);

  return 0;
}