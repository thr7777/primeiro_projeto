    #include"fila.h"
    #include"pilha.h"

    int c;
    char nome[50];
    int idade;
    char cpf[12];
    int prioridade;
    int global_de_verificacao = 0;
    int chamada = 0; //global


    FILA_ENC normal;
    FILA_ENC preferencial;

    //PILHA_ENC historico;
    PILHA_ENC historico;