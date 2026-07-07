//inclusao da fila
#ifndef TRATAMENTODADOS_H
#define TRATAMENTODADOS_H

#include"fila.h"
#include"pilha.h"

void limpar_buffer();
void pegando_dados(int *idade, char *nome, char *cpf, int *preferencia, FILA_ENC n, FILA_ENC p, int *chamada);
void logica_da_retirada(FILA_ENC n, FILA_ENC p, PILHA_ENC*, int *global_de_verificacao);

#endif