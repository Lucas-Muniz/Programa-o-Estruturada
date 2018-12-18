/* lab 9a - Sem Coment�rios
 * Nome: Lucas Fernandes Muniz
 * Neste laborat�rio ser� criado um programa que l� um c�digo em C e retira todos
 * os coment�rios desse c�digo.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

  /* Ponteiros que recem os arquivos. */
  FILE *arqin = fopen(argv[1],"r");
  FILE *arqout = fopen(argv[2],"w");

  char charAntigo, charAtual;
  
  fscanf(arqin, "%c", &charAntigo);
  /* Vari�veis que indicam quando se est� dentro de um coment�rio:
   * comentario1 � usado para indicar o coment�rio do tipo '//';
   * comentario2 � usado para indicar um coment�rio do tipo '/*'. */
  int comentario1;
  comentario1 = 0;
  int comentario2;
  comentario2 = 0;
  
  while(fscanf(arqin, "%c", &charAtual) != EOF){
    
    if(comentario1 == 0 && comentario2 == 0){
      /* Verificando se um coment�rio � iniciado.*/
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
      /* Verificando quando o coment�rio � terminado. */
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