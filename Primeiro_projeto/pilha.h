#ifndef PILHA_H
#define PILHA_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodo_pilha{
    char nome[50];
    char cpf[12];
    int idade;
    int prioridade;
    int chamada;

    struct nodo_pilha *prox;
}PILHA;
typedef PILHA * PILHA_ENC;

void criar_pilha(PILHA_ENC*);
int vazio(PILHA_ENC);
void push(PILHA_ENC*, char*, char*, int, int, int);
void mostrar_historico(PILHA_ENC);
void destruir_pilha(PILHA_ENC *);

#endif