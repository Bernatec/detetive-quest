#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int id;
    struct No* esquerda;
    struct No* direita;
} No;

// Função para criar um novo nó
No* novoNo(int id) {
    No* no = (No*)malloc(sizeof(No));
    no->id = id;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

// Inserção na árvore binária de busca
No* inserir(No* raiz, int id) {
    if (raiz == NULL) return novoNo(id);
    if (id < raiz->id)
        raiz->esquerda = inserir(raiz->esquerda, id);
    else
        raiz->direita = inserir(raiz->direita, id);
    return raiz;
}

// Percurso pós-ordem e soma dos pares
void posOrdem(No* raiz, int* soma) {
    if (raiz == NULL) return;
    posOrdem(raiz->esquerda, soma);
    posOrdem(raiz->direita, soma);
    printf("%d ", raiz->id);
    if (raiz->id % 2 == 0)
        *soma += raiz->id;
}

// Verifica se soma é divisível por 7
void desbloquearCofre(int soma) {
    printf("\nSoma dos livros com pistas: %d\n", soma);
    if (soma % 7 == 0)
        printf("✅ Cofre desbloqueado!\n");
    else
        printf("❌ Cofre permanece trancado.\n");
}

int main() {
    int livros[] = {42, 15, 8, 23, 4, 16, 50};
    int n = sizeof(livros) / sizeof(livros[0]);
    No* raiz = NULL;

    for (int i = 0; i < n; i++)
        raiz = inserir(raiz, livros[i]);

    int soma = 0;
    printf("Percurso pós-ordem: ");
    posOrdem(raiz, &soma);
    desbloquearCofre(soma);

    return 0;
}