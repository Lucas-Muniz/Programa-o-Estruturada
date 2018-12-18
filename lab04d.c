/* Lab 04d - JMob
 * Nome: Lucas Fernandes Muniz
 * Neste laborat�rio ser� criado um c�digo que calcula se o m�bile est� equilibrado
 * e mede a massa total do m�bile.
 */

#include <stdio.h>

/*Vari�vel global que indica se a barra est� em equil�brio.
O valor 0 significa barra equilibrada, e
o valor 1 indica barra desequilibrada*/
int equilibrio = 0;

/*Fun��o que verifica se a barra est� em equil�brio*/
void mobileEquilibrado (int Pe, int De, int Pd, int Dd){
    if (Pe*De != Pd*Dd){
          equilibrio = 1;
    }
}

/*Fun��o recursiva que mede a massa do mobile*/
int massaMobile (int Pe, int De, int Pd, int Dd){
  int m;
  scanf("%d %d %d %d", &Pe, &De, &Pd, &Dd);
  /*As vari�veis auxiliares Pe1 e Pd1 s�o utilizadas posteriormente para a veri-
  fica��o posterior do equil�brio da barra*/ 
  int  Pe1, Pd1;
  Pe1 = Pe;
  Pd1 = Pd;
  int massa = 0;
  
  if (Pe != 0 && Pd != 0){
      mobileEquilibrado(Pe, De, Pd, Dd);
      return Pe+Pd;
  } else {
      
    if (Pe == 0){
      massa += Pd;
      m = massaMobile(Pe, De, Pd, Dd);
      massa += m;
      Pe1 = m;
    } 
    m = 0;
    if (Pd == 0) {
      massa += Pe;
      m = massaMobile(Pe, De, Pd, Dd);
      massa += m;
      Pd1 = m;
    }
    mobileEquilibrado(Pe1, De, Pd1, Dd);
    
    return massa;
  }
}


int main (){
  int massaTot = 0;
  
  massaTot = massaMobile(0, 0, 0, 0);
      
  if (equilibrio == 1){
      printf("Mobile desequilibrado\n");
  } else {
      printf("Mobile equilibrado\n");
  }
  printf("Peso total: %d\n", massaTot);
  
  return 0;
}
