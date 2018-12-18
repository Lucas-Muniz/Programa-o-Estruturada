/* Lab 03b - Wall-E
 * Nome: Lucas Fernandes Muniz
 * Neste laborat�rio ser� criado um c�digo que calcula a posi��o do rob� Wall-e ap�s uma
 * s�rie de coordenandas passadas para o rob�, considerando que o mesmo n�o sai da �rea de
 * alcance da base. 
 */

#include <stdio.h>

/*Fun��o que recebe o raio de alcance e as coordenadas, e retorna se 
  WALL-E passou ou n�o da �rea de alcance da base*/
int verificaDistancia (int raio, int x, int y){
  int h = x*x + y*y;
  if (h > raio*raio){
    return 1;
  } else {
    return 0;
  } 
}

/*Fun��o que recebe em qual eixo (X ou Y) o WALL-E est� se movimentando 
  e tem como retorno o eixo trocado*/
char mudaEixo (char eixo){
  if (eixo == 'H'){
    return 'V';
  } else if (eixo == 'V'){
    return 'H';
  }
}

int main(void) {
  /*A vari�vel p define se o movimento do rob� ser� para frente ou para 
    para tr�s no seu eixo de dire��o (eixo x ou y), sendo -1 quando o movimento
    � para tr�s ou 1 se for para frente.*/
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
     
    /*Defini��o do valor da vari�vel p.*/
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
  
    /*Verificando se o rob� passou da �rea de alcance da base.*/
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
