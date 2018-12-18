/* Lab 07a - DON'T PANIC
 * Aluno: Lucas Fernandes Muniz
 * Lab 07a: DON'T PANIC
 * Programa para conversão de uma medida para várias outras unidades de massa, 
 * comprimento, temperatura, volume e velocidade.
 */

#include<stdio.h>

/* Função que recebe um inteiro 'tipo' que corresponde ao valor de uma determinada
 * medida, e os ponteiros de quilograma, libra e onça. A função coverte o valor 
 * de uma medida para as outras unidades de massa.
 */
void converte_peso(int tipo, double *kg, double *lb, double *oz){
  switch(tipo){
    case 0:
      *lb = (*kg)/(0.3732417216);
      *oz = (*kg)/0.028;
      break;
    case 1:
      *kg = (*lb)*(0.3732417216);
      *oz = (*lb)*(0.3732417216/0.028);
      break;
    case 2:
      *kg = (*oz)*0.028;
      *lb = (*oz)*(0.028/0.3732417216);
      break;
  }
}

/* Função que recebe um inteiro 'tipo' que corresponde ao valor de uma determinada
 * medida, e os ponteiros de quilometro, milhas, pé e léguas. A função coverte o valor 
 * de uma medida para as outras unidades de comprimento.
 */
void converte_comprimento(int tipo, double *km, double *mi, double *ft, double *lea){
  switch(tipo){
    case 0:
      *mi = ((*km)*1000)/1609.344;
      *ft = ((*km)*1000)/0.3048;
      *lea = ((*km)*1000)/4828;
      break;
    case 1:
      *km = ((*mi)*1609.344)/1000;
      *ft = (*mi)*(1609.344/0.3048);
      *lea = (*mi)*(1609.344/4828);
      break;
    case 2:
      *km = ((*ft)*0.3048)/1000;
      *mi = (*ft)*(0.3048/1609.344);
      *lea = (*ft)*(0.3048/4828);
      break;
    case 3:
      *km = ((*lea)*4828)/1000;
      *mi = (*lea)*(4828/1609.344);
      *ft = (*lea)*(4828/0.3048);
      break;
  }
}

/* Função que recebe um inteiro 'tipo' que corresponde ao valor de uma determinada
 * medida, e os ponteiros de graus Celsius, Fahrenheit e Kelvin. A função coverte o valor 
 * de uma medida para as outras unidades de temperatura.
 */
void converte_temperatura(int tipo, double *c, double *f, double *k){
  switch(tipo){
    case 0:
      *f = (*c)*(9/5.0) + 32;
      *k = (*c) + 273.15;
      break;
    case 1:
      *c = (5/9.0)*(*f - 32);
      *k = (5/9.0)*(*f - 32) + 273.15;
      break;
    case 2:
      *c = *k - 273.15;
      *f = (*k - 273.15)*(9/5.0) + 32.0;
      break;
  }
}

/* Função que recebe um inteiro 'tipo' que corresponde ao valor de uma determinada
 * medida, e os ponteiros de metros cúbicos, litros, galão, barril e onça fluída.
 * A função coverte o valor de uma medida para as outras unidades de volume.
 */
void converte_volume(int tipo, double *m3, double *l, double *gal, double *bl, double *floz){
  switch(tipo){
    case 0:
      *l = (*m3)/ 0.001;
      *gal = (*m3)*1000/(4.54609);
      *bl = (*m3)/0.16365924;
      *floz = (*m3)*100000/(3.0);
      break;
    case 1:
      *m3 = (*l)*0.001;
      *gal = (*l)/(4.54609);
      *bl = ((*l)*0.001)/0.16365924;
      *floz = ((*l)*100)/(3.0);
      break;
    case 2:
      *m3 = (*gal)*(4.54609/1000);
      *l = ((*gal)*(4.54609/1000))/ 0.001;
      *bl = ((*gal)*(4.54609/1000))/0.16365924;
      *floz = ((*gal)*(4.54609*100))/(3.0);
      break;
    case 3:
      *m3 = (*bl)*0.16365924;
      *l = ((*bl)*0.16365924)/ 0.001;
      *gal = ((*bl)*0.16365924*1000)/(4.54609);
      *floz = ((*bl)*0.16365924)*100000/(3.0);
      break;
    case 4:
      *m3 = (*floz)*3/(100000.0);
      *l = ((*floz)*(3/100.0));
      *gal = ((*floz)*3)/(100*4.54609);
      *bl = (*floz)*(3/(100000*0.16365924));
      break;
    
  }
}

/* Função que recebe um inteiro 'tipo' que corresponde ao valor de uma determinada
 * medida, e os ponteiros de quilômetros por hora, metros por segundo e milhas por hora.
 * A função coverte o valor de uma medida para as outras unidades de velocidade.
 */
void converte_velocidade(int tipo, double *kmh, double *ms, double *mph){
  switch(tipo){
    case 0:
      *ms = (*kmh)*(2.7/10);
      *mph = ((*kmh)*(2.7/10))/0.44704;
      break;
    case 1:
      *kmh = (*ms)/(2.7/10);
      *mph = ((*ms)/0.44704);
      break;
    case 2:
      *ms = (*mph)*0.44704;
      *kmh = ((*mph)*0.44704)/(2.7/10);
      break;
  }
}