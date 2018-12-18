/* Lab 08b - Pokemão
 * Nome: Lucas Fernandes Muniz
 * Neste laboratório será criado funções para a execução do jogo Pokemão
 */

#include <stdio.h>
#include <stdlib.h>

/* Lista de Cores e formatacao usados */
static const char color_reset[] = "\x1b[0m";
static const char color_bold[] = "\x1b[0;1m";
static const char color_sep[] = "\x1b[0;36m";
static const char color_black[] = "\x1b[0;30m";
static const char color_grass[] = "\x1b[0;32m";
static const char color_player[] = "\x1b[0;1m";
static const char *colors_list[] = {"\x1b[0;31m", "\x1b[0;33m", "\x1b[0;34m",
                                    "\x1b[0;35m", "\x1b[0;36m"};

/* Biliotecas em uso somente apenas para Linux e Mac OSX */
#if defined(__linux__) || defined(__APPLE__)
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <string.h>
#endif


int TTY = -1;
/* Verifica e habilita cores no terminal */
int enable_colors() {
    if (TTY < 0) {
#if defined(__linux__) || defined(__APPLE__)
        TTY = isatty(STDOUT_FILENO) && isatty(STDIN_FILENO);
#else
        TTY = 0;
#endif
    }
    return TTY;
}

/* Limpa a tela do terminal */
void clearScreen() {
#if defined(__linux__) || defined(__APPLE__)
    if (enable_colors()) {
        fputs("\x1b[2J\x1b[1;1H", stdout);
    }
#endif
}

/* Configura o terminal para enviar os caracteres sem enter e sem monstra-los na tela */
#if defined(__linux__) || defined(__APPLE__)
struct termios tty_settings;
#endif
void enable_getch() {
#if defined(__linux__) || defined(__APPLE__)
    if (enable_colors()) {
        struct termios newattr;
        tcgetattr(STDIN_FILENO, &tty_settings);
        tcgetattr(STDIN_FILENO, &newattr);
        newattr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    }
#endif
}
/* Desativa configuracao especial do terminal */
void disable_getch() {
#if defined(__linux__) || defined(__APPLE__)
    if (enable_colors()) {
        tcsetattr(STDIN_FILENO, TCSANOW, &tty_settings);
    }
#endif
}

/* Imprime cores e formatacao de texto */
void printc(const char *color) {
#if defined(__linux__) || defined(__APPLE__)
    if (enable_colors()) {
        fputs(color, stdout);
    }
#endif
}

#define MAX 20
#define MONSTROS 151

/* Funcoes implementadas pelo aluno */
void busca(int **tab, int tabSize, int pos[2]);
void visiveis(int **tab, int tabSize, int v[8]);
void proximos(int **tab, int tabSize,  int *p, int especies);
int movimenta(int **tab, int tabSize,  int desloca[2]);
int captura(int *capturados, int n_especies, int especie);

/* Imprime o numero de um mostro */
void print_monstro(int I) {
    if (I) {
        printc(
               colors_list[I / (MONSTROS /
                                (sizeof(colors_list) / sizeof(colors_list[0]) - 1))]);
    } else {
        printc(color_grass);
    }
    printf("%03d", I);
}

/* Imprime mapa de monstros visiveis */
void print_vis(int **tab, int tabSize) {
    int i, c;
    int vis[8];
    for (i = 0; i < 8; i++)
        vis[i] = 0;
    visiveis(tab, tabSize, vis);
    c = 0;
    for (i = 0; i < 8; i++) {
        print_monstro(vis[i]);
        c++;

        if (i == 3) {
            printc(color_player);
            printf(" .J. ");
            c++;
        } else if (c % 3) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    printc(color_reset);
}

/* Imprime lista de monstros proximos */
void print_prox(int **tab, int tabSize) {
    int prox[MONSTROS];
    int i;
    for (i = 0; i < MONSTROS; i++)
        prox[i] = 0;
    proximos(tab, tabSize, prox, MONSTROS);
    printc(color_reset);
    printf("Proximos: ");
    for (i = 0; i < MONSTROS; i++)
        if (prox[i]) {
            print_monstro(i + 1);
            printc(color_reset);
            printf(", ");
        }
    printf("\n");
}

/* Imprime valores de cada turno */
void print_turno(int **tab, int tabSize, int passos, int experiencia,
                 int restantes) {
    print_vis(tab, tabSize);
    printc(color_black);
    printf("-----------\n");
    print_prox(tab, tabSize);
    printf("Passos: %d\n", passos);
    printf("Experiencia: %d\n", experiencia);
    printf("Monstros Restantes: %d\n", restantes);
    fflush(stdout);
}

int main(int argc, char **argv) {
    int restantes = 0;
    int experiencia = 0;
    int passos = 0;
    int especie;
    int i, j;
    int *capturados = malloc(sizeof(int) * MONSTROS); /* Quantidade de capturados para cada especie */
    int **tab = malloc (sizeof(int*) * MAX);
    for (i = 0; i < MAX; ++i) {
        tab[i] = malloc(sizeof(int) * MAX);
    }

    for (i = 0; i < MONSTROS; i++) /* Limpa vetor de capturados */
        capturados[i] = 0;

#if defined(__linux__) || defined(__APPLE__)
    if (argc > 1 && !strcmp(argv[1],"play")) { /* Definir tabuleiro aleatoriamente */
        srand(time(NULL));

        restantes = 0;
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                tab[i][j] = rand() % (2 * MONSTROS);
                if (tab[i][j] >= (MONSTROS + 80)) {
                    tab[i][j] = 0;
                } else if (tab[i][j] >= MONSTROS) {
                    tab[i][j] = 1;
                    restantes++;
                } else if (tab[i][j] > 0) {
                    restantes++;
                }
            }
        }
        if (tab[MAX / 2][MAX / 2]) restantes--;
        tab[MAX / 2][MAX / 2] = -1;
    }
    else
#endif

        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                if (scanf("%d", &tab[i][j]) != 1) {
                    printf("Erro na leitura do tabuleiro\n");
                    return 1;
                }
                if (tab[i][j] > 0)
                    restantes++;
            }
        }

    enable_getch(); /* Configura terminal */

    clearScreen();
    printc(color_sep);
    printf("===========\n");
    print_turno(tab, MAX, passos, experiencia, restantes);
    while (1) {
        int op = fgetc(stdin);
        int desloca[2];
        switch (op) {
        case EOF:
        case 'X':
        case 'x':
            printc(color_sep);
            printf("===========\n");
            printc(color_bold);
            printf("Jogador acabou com %d de experiencia\n", experiencia);
            printc(color_reset);
            for (i = 0; i < MONSTROS; i++) {
                if (!capturados[i])
                    continue;
                printf("%d * ", capturados[i]);
                print_monstro(i + 1);
                printc(color_reset);
                printf(", ");
            }
            printf("\n");
            disable_getch(); /* Volta o terminal as configuracoes originais */
            /* Desaloca memória */
            free(capturados);
            for (i = 0; i < MAX; ++i)
                free(tab[i]);
            free(tab);
            return 0;
        case 'A': /* Seta para cima */
        case '^':
            desloca[0] = -1;
            desloca[1] = 0;
            break;
        case 'B': /* Seta para baixo */
        case 'V':
        case 'v':
            desloca[0] = 1;
            desloca[1] = 0;
            break;
        case 'C': /* Seta para direita */
        case '>':
            desloca[0] = 0;
            desloca[1] = 1;
            break;
        case 'D': /* Seta para esqueda */
        case '<':
            desloca[0] = 0;
            desloca[1] = -1;
            break;
        default:
            continue;
        }

        clearScreen();
        especie = movimenta(tab, MAX, desloca);
        passos++;
        printc(color_sep);
        printf("===========");
        if (especie != 0) {
            restantes--;
            printc(color_bold);
            fputc(' ', stdout);
            print_monstro(especie);
            if (captura(capturados, MONSTROS, especie)) {
                experiencia += especie;
                fputs(" capturado", stdout);
            } else {
                fputs(" fugiu", stdout);
            }
        }
        printf("\n");
        printc(color_reset);
        print_turno(tab, MAX, passos, experiencia, restantes);
    }

    /* Não deveria chegar aqui */
    return 1;
}

/* Funcao: busca
 * A funcao deve encontrar a posição (i,j) do jogador no tabuleiro.
 * O jogador é representado pelo valor -1.
 * O retorno da posicao se da pelo vetor parametro pos.
 *
 *
 * Parametros:
 *      tab: tabuleiro
 *  tabSize: largura e altura do tabuleiro (o tabuleiro é sempre quadrado)
 *      pos: posicao do jogador no tabuleiro
 *
 * Retorno:
 *   Em pos[0] deve ser setado a linha i onde esta o jogador.
 *   Em pos[1] deve ser setado a coluna j onde esta o jogador.
 */
void busca(int **tab, int tabSize, int pos[2]) {
  /* Implementar a funcao */
  int i, j;
  for(i=0; i<tabSize; i++){
    for(j=0; j<tabSize; j++){
      if(tab[i][j] == -1){
        pos[0] = i;
        pos[1] = j;
        break;
      }
    }
  }
}

/* Funcao: visiveis
 * Retorna os monstros visiveis nas 8 posições adjacentes em ordem.
 * A posição 0 representa o canto superior esquerdo e a posição 7 o canto
 * inferior direito.
 * 0 1 2
 * 3 J 4
 * 5 6 7
 * As posições devem ter o identificador da especie do monstro presente ou zero se a
 * posição não tiver um monstro.
 *
 * Parametros:
 *      tab: tabuleiro
 *  tabSize: largura e altura do tabuleiro (o tabuleiro é sempre quadrado)
 *        v: Identificadores das posições adjacentes
 *
 * Retorno:
 *    Para cada posicao v[i], onde i=0,1,..7, deve ser setado
 *    o identificador da especie do monstro naquela posição ou 0 se a posicao
 *    estiver vazia.
 */
void visiveis(int **tab, int tabSize, int v[8]) {
  /* Implementar a funcao */
  int pos[2];
  int i, j, monstro, posicao = 0;
  busca(tab, tabSize, pos);
  int lin = pos[0]-1, col = pos[1]-1;

  for(i=0; i<8; i++){
    v[i] = 0;
  }

  for(i=lin; i<=lin+2; i++){
    for(j=col; j<=col+2; j++){
      if(i == pos[0] && j == pos[1]){
        continue;
      }
      if((i==lin || j==col || i==lin + 2 || j == col+2) && (i>=0 && j>=0 && i<tabSize )){
        monstro = tab[i][j];
        v[posicao] = monstro;
      } else {
        v[posicao] = 0;
      }
      posicao++;
    }
  }
}

/* Funcao: proximos
 * Retorna quais tipos de monstros estão presentes nas 16 posições proximas ao
 * jogador mas não adjacentes a ele.
 * O valor de p[i] deve ser setado para 1 se existir ao menos uma ocorrência do monstro de
 * identificador i+1 em alguma das 16 posições proximas, ou 0 caso contrário.
 *
 * Parametros:
 *       tab: tabuleiro
 *   tabsize: tamanho do tabuleiro (sempre quadrado)
 *         p: Monstros proximos
 *  monstros: tamanho de p
 *
 * Retorno:
 *    Note que o parametro p eh um vetor de tamanho igual ao numero de especies de monstros (especies).
 *    Para cada posição i, p[i] deve ser setado com 1 se um monstro de especie (i+1) esta proximo
 *    e 0 caso contrario.
 */
void proximos(int **tab, int tabSize, int *p, int especies) {
  /* Implementar a funcao */
  int pos[2];
  busca(tab, tabSize, pos);
  int lin = pos[0]-2, col = pos[1]-2;
  int i, j, monstro, posicao = 0;

  for(i=0; i<especies; i++){
    p[i] = 0;
  }
  
  for(i=lin; i<=lin+4; i++){
    for(j=col; j<=col+4; j++){
      if((i==lin || j==col || i==lin + 4 || j == col+4) && (i>=0 && j>=0 && i<tabSize && j<tabSize)){
        monstro = tab[i][j];
        if(monstro <= especies && monstro != 0){
          p[monstro-1] = 1;
        } 
      }
    }
  }
}

/* Funcao: movimenta
 * Movimenta o jogador, que é representado no tabuleiro pelo valor -1.
 * O jogador deve sempre permanecer dentro do tabuleiro.
 *
 * Parametros:
 *      tab: tabuleiro
 *  tabsize: tamanho do tabuleiro (sempre quadrado)
 *      desloca: contem o deslocamento que deve ser aplicado ao jogador.
 *               desloca[1] contem o deslocamento em colunas (-1, 0, ou 1)
 *               desloca[0] contem o deslocamento em linhas (-1, 0, ou 1)
 *
 * Retorno:
 *   Especie do monstro encontrado na nova posicao do jogador
 *   ou 0 se nao houver monstro nesta posicao.
 */
int movimenta(int **tab, int tabSize, int desloca[2]) {
  /* Implementar a funcao e trocar o valor de retorno */
  int pos[2];
  int especie;
  busca(tab, tabSize, pos);
  int i_Jogador = pos[0], j_Jogador = pos[1];

  tab[i_Jogador][j_Jogador] = 0;

  if(i_Jogador+desloca[0]<tabSize && i_Jogador+desloca[0]>=0){
    i_Jogador += desloca[0];
  }
  if(j_Jogador+desloca[1]<tabSize && j_Jogador+desloca[1]>=0){
    j_Jogador += desloca[1];
  }

  especie = tab[i_Jogador][j_Jogador];
  tab[i_Jogador][j_Jogador] = -1;
  if(especie != 0){
    return especie;
  }
  return 0;
}

/* Funcao: captura
 * Verifica se o jogador pode capturar o monstro de uma especie que esta na posicao do jogador.
 * Armazena o monstro capturado no vetor capturados e retorna 1 se conseguiu
 * capturar, ou 0 caso contrario.
 * Um monstro de especie 1 sempre eh capturado.
 *
 * Parametros:
 *   capturados: vetor de tamanho n_especies com a quantidade de monstros de cada especie
 *               que o jogador possui. Desta forma, capturados[i] possui a quantidade de monstros
 *               da especie (i+1) que o jogador possui.
 *   n_especies: tamanho do vetor capturados
 *   especie: numero da especie que pretende-se capturar.
 *
 * Retorno:
 *   1 se o monstro foi capturado, e 0 caso contrario.
 *   Note que o vetor capturados deve ser atualizado caso o monstro tenha sido capturado.
 */
int captura(int *capturados, int n_especies,  int especie) {
  /* Implementar a funcao e trocar o valor de retorno */
  int i, experiencia = 0;
  for(i=0; i<n_especies; i++){
    experiencia += (i+1)*capturados[i];
  }

  if(especie <= experiencia || especie == 1){
    capturados[especie-1] += 1;
    return 1; 
  }
  return 0;
}
