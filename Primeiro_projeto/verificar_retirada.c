

//==========================================================================
//ARQUIVO APENAS PARA MONTAR A LOGICA, OS CODIGOS FORAM PARA tratamentoDados
//==========================================================================

#include<stdio.h>
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

//logica do proximo da fila

//quando apertar em prox, o programa vai buscar na logica, se a precedencia for 1, pega da normal, se a precedencia for 2, pega da preferencial, em ambos os casos apresenta na tela e remove da lista

//ao apertar pop(), vai lancar um comando primeiro na logica de onde tirar o dado, e depois remover
//na logica de pegar o dado eu primeiro preciso ver se em qual caixa pegar, apos isso, verificar se nessa caixa 
//tem algo, se nao tiver, preciso ir na outra caixa, se nao tiver, preciso dar um sinal de que nao ha dado em nanhuma das duas caixas
int eh_vazio(FILA_ENC);
void cons_ret(FILA_ENC);
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
}
int main(){
	return 0;
}
