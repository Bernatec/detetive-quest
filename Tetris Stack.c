#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char formato[10];
    char cor[10];
} Peca;

typedef struct {
    Peca pilha[MAX];
    int topo;
} TetrisStack;

void inicializar(TetrisStack *stack) {
    stack->topo = -1;
}

int estaVazia(TetrisStack *stack) {
    return stack->topo == -1;
}

int estaCheia(TetrisStack *stack) {
    return stack->topo == MAX - 1;
}

void empilhar(TetrisStack *stack, Peca nova) {
    if (estaCheia(stack)) {
        printf("⚠️ Pilha cheia! Não é possível empilhar mais peças.\n");
        return;
    }
    stack->topo++;
    stack->pilha[stack->topo] = nova;
    printf("✅ Peça empilhada com sucesso!\n");
}

void desempilhar(TetrisStack *stack) {
    if (estaVazia(stack)) {
        printf("⚠️ Pilha vazia! Não há peças para remover.\n");
        return;
    }
    printf("🧱 Peça removida: %s (%s)\n", stack->pilha[stack->topo].formato, stack->pilha[stack->topo].cor);
    stack->topo--;
}

void visualizar(TetrisStack *stack) {
    if (estaVazia(stack)) {
        printf("📦 Pilha está vazia.\n");
        return;
    }
    printf("📦 Estado atual da pilha:\n");
    for (int i = stack->topo; i >= 0; i--) {
        printf("🔹 %s (%s)\n", stack->pilha[i].formato, stack->pilha[i].cor);
    }
}

int main() {
    TetrisStack stack;
    inicializar(&stack);

    int opcao;
    Peca nova;

    do {
        printf("\n=== TETRIS STACK – TEMA 3 ===\n");
        printf("1. Empilhar peça\n");
        printf("2. Desempilhar peça\n");
        printf("3. Visualizar pilha\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1:
                printf("Formato da peça (quadrado, linha, T, L, Z): ");
                fgets(nova.formato, sizeof(nova.formato), stdin);
                nova.formato[strcspn(nova.formato, "\n")] = '\0';

                printf("Cor da peça (vermelho, azul, verde, amarelo, roxo): ");
                fgets(nova.cor, sizeof(nova.cor), stdin);
                nova.cor[strcspn(nova.cor, "\n")] = '\0';

                empilhar(&stack, nova);
                break;
            case 2:
                desempilhar(&stack);
                break;
            case 3:
                visualizar(&stack);
                break;
            case 4:
                printf("👋 Encerrando o desafio Tetris Stack!\n");
                break;
            default:
                printf("❌ Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}
