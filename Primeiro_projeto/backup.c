#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//ESTRUTURA DA FILA
typedef struct nodo{
    int idade;
    char nome[50];
    char cpf[12]; //11 digitos + o \0
    int prioridade; // trataremos prioridade como 1 = verdadeiro, 0 = falso

    struct nodo *prox;
}NODO;
typedef struct{
    NODO *inicio;
    NODO *fim;
    int tamanho;
}DESCRITOR;
typedef DESCRITOR * FILA_ENC;
//ESTRUTURA DA FILA

//CRIAR FILA_ENC
void criar_fila(FILA_ENC *f){
    *f = (DESCRITOR*)malloc(sizeof(DESCRITOR));
    if(!(*f)){
        printf("Falha na alocacao\n");
        exit(1);
    }
    (*f)->inicio = (*f)->fim = NULL;
}

//VERIFICACAO DE FILA VAZIA
int eh_vazio(FILA_ENC f){
    if(f->inicio == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//precisa adicionar a lista aqui para poder salvar no historico
void ins_fila(FILA_ENC f, int idade, char *nome, char *cpf, int prioridade){
    NODO *novo;
    novo = (NODO*)malloc(sizeof(NODO)); //alocacao
    if(!novo){
        printf("Falha na alocacao\n");
        exit(1);
    }

    //insersao dos valores
    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    novo->idade = idade;
    novo->prioridade = prioridade;
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
}
//limpador de buffer
void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
void pegando_dados(int *idade, char *nome, char *cpf, int *preferencia, FILA_ENC n, FILA_ENC p){
    printf("digite o nome\n");
    scanf(" %49[^\n]", nome);

    printf("digite idade\n");
    scanf("%d", idade);
    limpar_buffer();

    printf("digite cpf\n");
    scanf(" %11[^\n]", cpf);
    limpar_buffer();

    printf("digite preferencia\n");
    scanf("%d", preferencia);
   limpar_buffer();


    //logica para insersao de dados

    switch (*preferencia)
    {
    case 1:
        // caso nao tenha preferencia
        ins_fila(n, *idade, nome, cpf, *preferencia);
        break;
    case 2:
        // caso tenha preferencia
        ins_fila(p, *idade, nome, cpf, *preferencia);
        break;


    default:
        printf("erro ao definir prescedencia de usuario\n");
        break;
    }
}

/*void verificacao_de_cpf(char *cpf);*/
int main(){
    FILA_ENC fila_teste;
    FILA_ENC fila_normal;
    FILA_ENC fila_preferencial;

    int idade, preferencia;
    char nome[50], cpf[12];
    //criando filas
    criar_fila(&fila_normal);
    criar_fila(&fila_preferencial);

    //testes
    pegando_dados(&idade, nome, cpf, &preferencia, fila_normal, fila_preferencial);
    
    /*criar_fila(&fila_teste);
    ins_fila(fila_teste, 26, "henrique", "77777777777", 1);
    ins_fila(fila_teste, 20, "ana", "77777777777", 0);*/

    /*printf("%s\n", fila_normal->inicio->nome);
    printf("%d\n", fila_normal->inicio->idade);
    printf("%s\n", fila_normal->inicio->cpf);*/
    return 0;
}

















/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"fila.h"

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
void pegando_dados(int *idade, char *nome, char *cpf, int *preferencia, FILA_ENC n, FILA_ENC p){
    printf("digite o nome\n");
    scanf(" %49[^\n]", nome);

    printf("digite idade\n");
    scanf("%d", idade);
    limpar_buffer();

    printf("digite cpf\n");
    scanf(" %11[^\n]", cpf);
    limpar_buffer();

    printf("digite preferencia\n");
    scanf("%d", preferencia);
   limpar_buffer();


    //logica para insersao de dados

    switch (*preferencia)
    {
    case 1:
        // caso nao tenha preferencia
        ins_fila(n, *idade, nome, cpf, *preferencia);
        break;
    case 2:
        // caso tenha preferencia
        ins_fila(p, *idade, nome, cpf, *preferencia);
        break;


    default:
        printf("erro ao definir prescedencia de usuario\n");
        break;
    }
}
void logica_da_retirada(FILA_ENC n, FILA_ENC p, int *global_de_verificacao){
	if(eh_vazio(n) && eh_vazio(p)){
		*global_de_verificacao = 0;
		return;
	}
	//se apenas a fila normal for vazia, retiramos da preferencial sempre
	else if(!eh_vazio(p) && eh_vazio(n)){
		cons_ret(p);
	}
	//se apenas a fila preferencial for vazia, retiramos da normal sempre
	else if(eh_vazio(p) && !eh_vazio(n)){
		cons_ret(n);
	}
	else{
		//se ambos estiverem com pacientes/usuarios nas filas, entao retiramos com proporção de 2:1
		if(*global_de_verificacao < 2){
			cons_ret(p);
			*global_de_verificacao += 1;
		}else{
			cons_ret(n);
			*global_de_verificacao = 0;
		}
	}
}*/