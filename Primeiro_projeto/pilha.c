#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pilha.h"

void criar_pilha(PILHA_ENC *p){
    *p = NULL;
}
int vazio(PILHA_ENC p){
    return !p;
}
void push(PILHA_ENC *p, char *nome, char *cpf, int idade, int prioridade, int chamada){
    PILHA *novo;
    novo = (PILHA*) malloc(sizeof(PILHA));
    if(!novo){
        printf("falha na alocacao da pilha!");
        exit(1);
        }
    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    novo->idade = idade;
    novo->prioridade = prioridade;
    novo->chamada = chamada;

    novo->prox = *p;
    *p = novo;

}
void mostrar_historico(PILHA_ENC p){

    if(vazio(p)){
        printf("\n\nHistorico vazio!\n\n");
        return;
    }

    printf("\n");
    printf("+---------------------------------------+\n");
    printf("|      HISTORICO DE ATENDIMENTOS        |\n");
    printf("+---------------------------------------+\n");

    while(p){

        printf("| Nome  : %-28s |\n", p->nome);
        printf("| CPF   : %-28s |\n", p->cpf);

        if(p->prioridade == 1)
            printf("| Tipo  : %-28s |\n", "Normal");
        else
            printf("| Tipo  : %-28s |\n", "Preferencial");

        printf("+---------------------------------------+\n");

        p = p->prox;
    }
}

void destruir_pilha(PILHA_ENC *p){

    PILHA *aux;

    while(*p != NULL){

        aux = *p;

        *p = (*p)->prox;

        free(aux);
    }
}