#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ra, telefone;
    char nome[100];
} Aluno;

typedef struct {
    int armazenados;
    int capacidade;
    Aluno *alunos;
} Base;

void criar_base(Base *base, int n);
void liberar_base(Base *);
int buscar(Base *base, int ra);
void adicionar(Base *base, int ra, int telefone, char *nome);
void imprimir(Base *base, int ra);
void remover(Base *base, int ra);

int main() {

    Base base;
    int capacidade;
    char op;
    int ra, telefone;
    char nome[100];

    if (scanf("%d\n", &capacidade) != 1) {
        printf("Erro de Leitura da Capacidade\n");
        return 1;
    }
    criar_base(&base, capacidade);

    if (base.capacidade != capacidade) {
        printf("Capacidade inicial errada: %d\n", base.capacidade);
    }
    if (base.armazenados != 0) {
        printf("Quantidade armazenada inicial errada: %d\n", base.armazenados);
    }
    if (base.alunos == NULL) {
        printf("Vetor de registros nao alocado.\n");
    }

    scanf("%c", &op);
    while (op != 'q') {

        scanf("%d", &ra);

        if (op == '>') {
            imprimir(&base, ra);
        } else if (op == '-') {
            remover(&base, ra);
        } else if (op == '+') {
            scanf(" %d %[^\n]", &telefone, nome);
            adicionar(&base, ra, telefone, nome);
        }
        scanf("\n%c", &op);
    }

    liberar_base(&base);

    if (base.capacidade != 0) {
        printf("A base ainda tem capacidade %d.\n", base.capacidade);
    }
    if (base.armazenados != 0) {
        printf("A base ainda tem %d registros armazenados.\n", base.armazenados);
    }
    if (base.alunos != NULL) {
        printf("A base ainda tem um ponteiro de registros.\n");
    }

    return 0;
}
