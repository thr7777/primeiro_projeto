#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"fila.h"
#include"tratamentoDados.h"

#include"pilha.h"

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
void pegando_dados(int *idade, char *nome, char *cpf, int *preferencia, FILA_ENC n, FILA_ENC p, int *chamada){
printf("\n");
printf("+---------------------------------------+\n");
printf("|        CADASTRO DE PACIENTE           |\n");
printf("+---------------------------------------+\n");

printf("| Nome        : ");
scanf(" %49[^\n]", nome);

printf("| Idade       : ");
scanf("%d", idade);
limpar_buffer();

printf("| CPF         : ");
scanf(" %11[^\n]", cpf);
limpar_buffer();

printf("|---------------------------------------|\n");
printf("| Tipo de Atendimento                  |\n");
printf("|   [1] Normal                         |\n");
printf("|   [2] Preferencial                   |\n");
printf("|---------------------------------------|\n");
printf("| Opcao       : ");
scanf("%d", preferencia);
limpar_buffer();

printf("+---------------------------------------+\n");


    //logica para insersao de dados

    switch (*preferencia)
    {
    case 1:
        // caso nao tenha preferencia
        ins_fila(n, *idade, nome, cpf, *preferencia, chamada);
        break;
    case 2:
        // caso tenha preferencia
        ins_fila(p, *idade, nome, cpf, *preferencia, chamada);
        break;


    default:
        printf("erro ao definir prescedencia de usuario\n");
        break;
    }
}
void logica_da_retirada(FILA_ENC n, FILA_ENC p, PILHA_ENC *historico, int *global_de_verificacao){
	if(eh_vazio(n) && eh_vazio(p)){
		*global_de_verificacao = 0;
        printf("\n");
        printf("+---------------------------------------+\n");
        printf("|              AVISO                    |\n");
        printf("+---------------------------------------+\n");
        printf("| Nao ha ninguem na fila.               |\n");
        printf("+---------------------------------------+\n");
		return;
	}
	//se apenas a fila normal for vazia, retiramos da preferencial sempre
	else if(!eh_vazio(p) && eh_vazio(n)){
		cons_ret(p, historico);
	}
	//se apenas a fila preferencial for vazia, retiramos da normal sempre
	else if(eh_vazio(p) && !eh_vazio(n)){
		cons_ret(n, historico);
	}
	else{
		//se ambos estiverem com pacientes/usuarios nas filas, entao retiramos com proporção de 2:1
		if(*global_de_verificacao < 2){
			cons_ret(p, historico);
			*global_de_verificacao += 1;
		}else{
			cons_ret(n, historico);
			*global_de_verificacao = 0;
		}
	}
}