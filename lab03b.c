/* Lab 03b - Wall-E
 * Nome: Lucas Fernandes Muniz
 * Neste laboratório será criado um código que calcula a posição do robô Wall-e após uma
 * série de coordenandas passadas para o robô, considerando que o mesmo não sai da área de
 * alcance da base. 
 */

#include <stdio.h>

/*Função que recebe o raio de alcance e as coordenadas, e retorna se 
  WALL-E passou ou não da área de alcance da base*/
int verificaDistancia (int raio, int x, int y){
  int h = x*x + y*y;
  if (h > raio*raio){
    return 1;
  } else {
    return 0;
  } 
}

/*Função que recebe em qual eixo (X ou Y) o WALL-E está se movimentando 
  e tem como retorno o eixo trocado*/
char mudaEixo (char eixo){
  if (eixo == 'H'){
    return 'V';
  } else if (eixo == 'V'){
    return 'H';
  }
}

int main(void) {
  /*A variável p define se o movimento do robô será para frente ou para 
    para trás no seu eixo de direção (eixo x ou y), sendo -1 quando o movimento
    é para trás ou 1 se for para frente.*/
  int raio, x = 0, y = 0, m, p = 1;
  char comando = 'W', eixo = 'V', coordX = 'E', coordY = 'N';
  scanf("%d", &raio);

  while (comando != 'X'){
    scanf("%c", &comando);

    /*Deslocamento de acordo com o eixo.*/
    if (comando == 'F'){
      scanf("%d", &m);
      if (eixo == 'H'){
        x += m*p;
      } else if (eixo == 'V'){
        y += m*p;
      }
     
    /*Definição do valor da variável p.*/
    } else if (comando == 'R'){
      if (eixo == 'V'){
        p *= 1;
      } else if (eixo == 'H'){
        p *= -1;
      }
      eixo = mudaEixo(eixo);
    } else if (comando == 'L'){
      if (eixo == 'V'){
        p *= -1;
      } else if (eixo == 'H'){
        p *= 1;
      }
      eixo = mudaEixo(eixo);
    }
  
    /*Verificando se o robô passou da área de alcance da base.*/
    if (verificaDistancia(raio, x, y)){
      break;
    }

  }
  
  /*Ajustando os sentidos dos eixos segundo a rosa dos ventos.*/
  if (x < 0){
    coordX = 'W';
    x *= -1;
  }
  if (y < 0){
    coordY = 'S';
    y *= -1;
  }

  printf("%d%c %d%c\n", x, coordX, y, coordY);

  return 0;
}
