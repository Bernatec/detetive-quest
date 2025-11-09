#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TERRITORIOS 5
#define MAX_JOGADORES 2

typedef struct {
    char nome[20];
    int tropas;
    int dono; // 0 ou 1
} Territorio;

typedef struct {
    char nome[20];
    int id;
} Jogador;

Territorio mapa[MAX_TERRITORIOS];
Jogador jogadores[MAX_JOGADORES];

void inicializar() {
    strcpy(jogadores[0].nome, "Thompson");
    jogadores[0].id = 0;
    strcpy(jogadores[1].nome, "Rival");
    jogadores[1].id = 1;

    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        sprintf(mapa[i].nome, "Territorio%d", i + 1);
        mapa[i].
