#define RESET   "\033[0m"

#define VERMELHO "\033[1;31m"
#define VERDE    "\033[1;32m"
#define AMARELO  "\033[1;33m"
#define AZUL     "\033[1;34m"
#define MAGENTA  "\033[1;35m"
#define CIANO    "\033[1;36m"
#define BRANCO   "\033[1;37m"
#define ROSA "\033[38;5;213m"

#include<stdio.h>
#include<stdlib.h>
#include"fila.h"
#include"tratamentoDados.h"
#include"variaveis.h"
#include"pilha.h"


int main(){
    system("color 0F");
    
    criar_fila(&normal);
    criar_fila(&preferencial);
    criar_pilha(&historico);

    
    ins_fila(preferencial, 65, "preferencial1",  "11111111111", 2, &chamada);
    ins_fila(preferencial, 66, "preferencial2",  "11111111112", 2, &chamada);
    ins_fila(preferencial, 67, "preferencial3",  "11111111113", 2, &chamada);
    ins_fila(preferencial, 68, "preferencial4",  "11111111114", 2, &chamada);
    ins_fila(preferencial, 69, "preferencial5",  "11111111115", 2, &chamada);
    ins_fila(preferencial, 70, "preferencial6",  "11111111116", 2, &chamada);
    ins_fila(preferencial, 71, "preferencial7",  "11111111117", 2, &chamada);
    ins_fila(preferencial, 72, "preferencial8",  "11111111118", 2, &chamada);
    ins_fila(preferencial, 73, "preferencial9",  "11111111119", 2, &chamada);
    ins_fila(preferencial, 74, "preferencial10", "11111111120", 2, &chamada);

    // Normais
    ins_fila(normal, 20, "normal1",  "22222222221", 1, &chamada);
    ins_fila(normal, 21, "normal2",  "22222222222", 1, &chamada);
    ins_fila(normal, 22, "normal3",  "22222222223", 1, &chamada);
    ins_fila(normal, 23, "normal4",  "22222222224", 1, &chamada);
    ins_fila(normal, 24, "normal5",  "22222222225", 1, &chamada);
    ins_fila(normal, 25, "normal6",  "22222222226", 1, &chamada);
    ins_fila(normal, 26, "normal7",  "22222222227", 1, &chamada);
    ins_fila(normal, 27, "normal8",  "22222222228", 1, &chamada);
    ins_fila(normal, 28, "normal9",  "22222222229", 1, &chamada);
    ins_fila(normal, 29, "normal10", "22222222230", 1, &chamada);

    while (1)
    {
        system("cls");
        printf("\n");
        printf(ROSA "+=======================================+\n" RESET);
        printf(ROSA "|      SISTEMA DE ATENDIMENTO           |\n" RESET);
        printf(ROSA "+=======================================+\n" RESET);

        printf(ROSA   "| [1] Cadastrar paciente                |\n" RESET);
        printf(ROSA    "| [2] Verificar filas                   |\n" RESET);
        printf(ROSA "| [3] Chamar proximo                    |\n" RESET);
        printf(ROSA "| [4] Historico de atendimentos         |\n" RESET);
        printf(ROSA "|" VERMELHO " [5] Encerrar sistema" ROSA "                  |\n" RESET);
        printf(ROSA "+=======================================+\n" RESET);
        printf(BRANCO " Opcao: " RESET);
        scanf("%d", &c);
        system("cls");

        if(c == 5)
            exit(1);
        
        switch (c)
        {
        case 1:
            pegando_dados(&idade, nome, cpf, &prioridade, normal, preferencial, &chamada);
            system("pause");
            break;
        case 2:
            printf("\n");
            printf(ROSA "+=======================================+\n" RESET);
            printf(ROSA "|          CONSULTAR FILA               |\n" RESET);
            printf(ROSA "+=======================================+\n" RESET);

            printf(ROSA "| 1 - Normal                            |\n" RESET);
            printf(ROSA "| 2 - Preferencial                      |\n" RESET);

            printf(ROSA "+=======================================+\n" RESET);
            printf(BRANCO "Digite a opcao: " RESET);
            scanf("%d", &c);
            if(c == 1){
                system("cls");
                mostrar_fila_normal(normal);
                system("pause");
            }
            else if(c == 2){
                system("cls");
                mostrar_fila_preferencial(preferencial);
                system("pause");
            }
            else{
                printf(VERMELHO "Nao existe essa opcao!\n" RESET);
            }
            break;
        case 3:
            logica_da_retirada(normal, preferencial,&historico,&global_de_verificacao);
            system("pause");
            break;
        case 4:
            mostrar_historico(historico);
            system("pause");
            break;
        case 5:
            exit(1);
            destruir_fila(normal);
            destruir_fila(preferencial);
            destruir_pilha(&historico);
        default:
            break;
        }
    }
    return 0;
}