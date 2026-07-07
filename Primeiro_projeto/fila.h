#ifndef FILA_H
#define FILA_H
//para nao ser criado duas vezes o mesmo .h

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"pilha.h"

//ESTRUTURA DA FILA
typedef struct nodo{
    int idade;
    char nome[50];
    char cpf[12]; //11 digitos + o \0
    int prioridade; // trataremos prioridade como 1 = verdadeiro, 0 = falso
    int chamada;
    struct nodo *prox;
}NODO;
typedef struct{
    NODO *inicio;
    NODO *fim;
    int tamanho;
}DESCRITOR;
typedef DESCRITOR * FILA_ENC;

//funções basicas
int eh_vazio(FILA_ENC);
int cpf_existe(FILA_ENC, char *);
int cpf_valido(char *);
void criar_fila(FILA_ENC *);
void ins_fila(FILA_ENC, int, char *, char *, int, int*);
void cons_ret(FILA_ENC, PILHA_ENC*);
void mostrar_fila_normal(FILA_ENC);
void mostrar_fila_preferencial(FILA_ENC);
void destruir_fila(FILA_ENC);
//para nao ser criado duas vezes o mesmo .h
#endif