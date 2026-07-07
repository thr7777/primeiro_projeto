#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>



//inclusao da fila
#include"fila.h"
//#include"pilha.h"
#include"pilha.h"

int eh_vazio(FILA_ENC f){
    if(f->inicio == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int cpf_existe(FILA_ENC f, char *cpf){
    NODO *aux = f->inicio;

    while(aux != NULL){
        if(strcmp(aux->cpf, cpf) == 0){
            return 1; // CPF encontrado
        }
        aux = aux->prox;
    }

    return 0; // CPF não encontrado
}

int cpf_valido(char *cpf){
    int i;

    for(i = 0; cpf[i] != '\0'; i++){
        if(!isdigit(cpf[i])){
            return 0; // encontrou algo que não é número
        }
    }

    return 1;
}

void criar_fila(FILA_ENC *f){
    *f = (DESCRITOR*)malloc(sizeof(DESCRITOR));
    
    if(!(*f)){
        printf("\n");
        printf("+---------------------------------------+\n");
        printf("|      CPF JA CADASTRADO NO SISTEMA!    |\n");
        printf("+---------------------------------------+\n");
        exit(1);
    }
    (*f)->tamanho = 0;
    (*f)->inicio = (*f)->fim = NULL;
}
void ins_fila(FILA_ENC f, int idade, char *nome, char *cpf, int prioridade, int *chamada){

    if(!cpf_valido(cpf)){
    printf("\n");
    printf("+---------------------------------------+\n");
    printf("|     CPF DEVE CONTER APENAS NUMEROS!   |\n");
    printf("+---------------------------------------+\n");
    return;
    }

    if(cpf_existe(f, cpf)){
        printf("\nCPF ja cadastrado!\n");
        return;
    }

    NODO *novo;
    novo = (NODO*)malloc(sizeof(NODO)); //alocacao
    if(!novo){
        printf("Falha na alocacao\n");
        exit(1);
    }

    (*chamada)++;
    //insersao dos valores
    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    novo->idade = idade;
    novo->prioridade = prioridade;
    novo->chamada = *chamada;
    novo->prox = NULL;
    //encadeando o nodo criado

    if(eh_vazio(f)){
        //caso seja vazia o inicio agora é o novo nodo criado
        f->inicio = novo;
    }
    else{
        //se nao for vazia, entao precisamos fazer o elemento anterior que era apontador por fim, apontar agora para o novo nodo
        f->fim->prox = novo;
    }

    //apontando o fim para o novo nodo criado e encadeado
    f->fim = novo;
    f->tamanho++;
    printf("\n");
    printf("+---------------------------------------+\n");
    printf("|  PACIENTE INSERIDO COM SUCESSO!       |\n");
    printf("+---------------------------------------+\n");

}
void cons_ret(FILA_ENC f, PILHA_ENC *historico){
    if(eh_vazio(f)){
        printf("\n\n Nao ha ninguem na fila \n\n");
        return;
    }

    NODO *aux = f->inicio;

    printf("\n\n");
    printf("+---------------------------------------+\n");

if(aux->prioridade == 1){
    printf("|          ATENDIMENTO NORMAL           |\n");
}
else{
    printf("|       ATENDIMENTO PREFERENCIAL        |\n");
}

    printf("+---------------------------------------+\n");
    
    printf("| Nome  : %-28s |\n", aux->nome);
    printf("| CPF   : %-28s |\n", aux->cpf);
    printf("+---------------------------------------+\n\n");

    //incluindo na fila
    push(historico, aux->nome,aux->cpf, aux->idade, aux->prioridade, aux->chamada);

    //apagando
    f->inicio = aux->prox;

    //caso o novo inicio seja nulo
    if(f->inicio == NULL){
        f->fim =NULL;
    }
    
    free(aux);
    f->tamanho--;

}

//mostrando filas
void mostrar_fila_normal(FILA_ENC f){

    if(eh_vazio(f)){
        printf("\n");
        printf("+---------------------------------------+\n");
        printf("|         FILA NORMAL VAZIA             |\n");
        printf("+---------------------------------------+\n");
        return;
    }

    NODO *aux = f->inicio;

    printf("\n");
    printf("+=======================================+\n");
    printf("|            FILA NORMAL                |\n");
    printf("+=======================================+\n");

    while(aux){

        
        printf("| Nome  : %-28s |\n", aux->nome);
        printf("| Idade : %-28d |\n", aux->idade);
        printf("| CPF   : %-28s |\n", aux->cpf);
        printf("+---------------------------------------+\n");

        aux = aux->prox;
    }

    printf("| Total : %-28d |\n", f->tamanho);
    printf("+=======================================+\n");
}

//fila preferencial

void mostrar_fila_preferencial(FILA_ENC f){

    if(eh_vazio(f)){
        printf("\n");
        printf("+---------------------------------------+\n");
        printf("|      FILA PREFERENCIAL VAZIA          |\n");
        printf("+---------------------------------------+\n");
        return;
    }

    NODO *aux = f->inicio;

    printf("\n");
    printf("+=======================================+\n");
    printf("|         FILA PREFERENCIAL             |\n");
    printf("+=======================================+\n");

    while(aux){

        printf("| Nome  : %-28s |\n", aux->nome);
        printf("| Idade : %-28d |\n", aux->idade);
        printf("| CPF   : %-28s |\n", aux->cpf);
        printf("+---------------------------------------+\n");

        aux = aux->prox;
    }

    printf("| Total : %-28d |\n", f->tamanho);
    printf("+=======================================+\n");
}

void destruir_fila(FILA_ENC f){

    NODO *aux;

    while(f->inicio != NULL){

        aux = f->inicio;

        f->inicio = f->inicio->prox;

        free(aux);
    }

    f->fim = NULL;
    f->tamanho = 0;
}