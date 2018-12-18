/**********************************************************
 * Created: Tue 30 Oct 2018 02:53:58 PM -03
 *
 * Author: Carla N. Lintzmayer, carla.negri@ufabc.edu.br
 *
 **********************************************************/

/**************************************************
 *  constantes para definir o tipo da unidade lida:
 **************************************************/

/* para medidas de peso: */
#define P_KG 0
#define P_LB 1
#define P_OZ 2
/* para medidas de comprimento: */
#define C_KM  0
#define C_MI  1
#define C_FT  2
#define C_LEA 3
/* para medidas de temperatura: */
#define T_C 0
#define T_F 1
#define T_K 2
/* para medidas de volume: */
#define V_M3   0
#define V_L    1
#define V_GAL  2
#define V_BL   3
#define V_FLOZ 4
/* para medidas de velocidade: */
#define S_KMH 0
#define S_MS  1
#define S_MPH 2
/*****************************************/
 

/* Essa função recebe a unidade de peso lida na variável <tipo> e um recebe um
 * valor na variável correspondente a tal unidade.
 * Ela converte esse valor para as outras duas unidades, escrevendo nas duas variáveis
 * correspondentes. */
void converte_peso(int tipo, double *kg, double *lb, double *oz);

/* Essa função recebe a unidade de comprimento lida na variável <tipo> e um recebe um
 * valor na variável correspondente a tal unidade.
 * Ela converte esse valor para as outras quatro unidades, escrevendo nas quatro variáveis
 * correspondentes. */
void converte_comprimento(int tipo, double *km, double *mi, double *ft, double *lea);

/* Essa função recebe a unidade de temperatura lida na variável <tipo> e um recebe um
 * valor na variável correspondente a tal unidade.
 * Ela converte esse valor para as outras duas unidades, escrevendo nas duas variáveis
 * correspondentes. */
void converte_temperatura(int tipo, double *c, double *f, double *k);

/* Essa função recebe a unidade de volume lida na variável <tipo> e um recebe um
 * valor na variável correspondente a tal unidade.
 * Ela converte esse valor para as outras quatro unidades, escrevendo nas quatro variáveis
 * correspondentes. */
void converte_volume(int tipo, double *m3, double *l, double *gal, double *bl, double *floz);

/* Essa função recebe a unidade de velocidade lida na variável <tipo> e um recebe um
 * valor na variável correspondente a tal unidade.
 * Ela converte esse valor para as outras duas unidades, escrevendo nas duas variáveis
 * correspondentes. */
void converte_velocidade(int tipo, double *kmh, double *ms, double *mph);
 

