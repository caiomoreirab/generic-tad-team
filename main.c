#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"

#define TRUE 1
#define FALSE 0

typedef struct {
    char nome[30];
    int anoFundacao;
    float numTorcedores;
} timeInfo; 

int cmp(void *a, void *b) {
    timeInfo *timeA = (timeInfo *)a;
    timeInfo *timeB = (timeInfo *)b;

    if (timeA != NULL && timeB != NULL) {
        if (strcmp(timeA->nome, timeB->nome) == 0 &&
            timeA->anoFundacao == timeB->anoFundacao &&
            timeA->numTorcedores == timeB->numTorcedores) {
            return 1; // Iguais
        }
        return 0; // Diferentes
    }
    return -1; // Caso algum ponteiro seja NULL
}


int main() {
    Time *colecao = NULL; 
    int opcao;

    while (1) {
        printf("\n=============================");
        printf("\n1 - Criar uma nova coleção");
        printf("\n2 - Inserir elementos");
        printf("\n3 - Listar elementos");
        printf("\n4 - Consultar elemento");
        printf("\n5 - Remover elemento");
        printf("\n6 - Limpar coleção");
        printf("\n7 - Sair");
        printf("\n=============================");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 7) {
            printf("Saindo...\n");
            break;
        }

        switch (opcao) {
            case 1: {
                int maxItens;
                printf("Digite o tamanho máximo da coleção: ");
                scanf("%d", &maxItens);

                colecao = timeCreate(maxItens);
                if (colecao != NULL) {
                    printf("Coleção criada com capacidade de %d itens.\n", maxItens);
                } else {
                    printf("Erro ao criar coleção.\n");
                }
                break;
            }

            case 2: {
                if (colecao == NULL) {
                    printf("Erro: Crie a coleção primeiro.\n");
                    break;
                }
                timeInfo *novoTime = (timeInfo *)malloc(sizeof(timeInfo));
                if (novoTime == NULL) {
                    printf("Erro ao alocar memória para o novo time.\n");
                    break;
                }

                printf("Digite o nome do time: ");
                scanf(" %[^\n]s", novoTime->nome);
                printf("Digite o ano de fundação: ");
                scanf("%d", &novoTime->anoFundacao);
                printf("Digite o número de torcedores: ");
                scanf("%f", &novoTime->numTorcedores);

                if (tadInsert(colecao, novoTime)) {
                    printf("Time adicionado com sucesso!\n");
                } else {
                    printf("Erro: Não foi possível adicionar o time.\n");
                    free(novoTime); 
                }
                break;
            }

            case 3: {
                if (colecao == NULL || colecao->numItens == 0) {
                    printf("Erro: Coleção vazia ou inexistente.\n");
                } else {
                    int size = 0;
                    void **times = tadList(colecao, &size);
                    if (times == NULL) {
                        printf("Erro ao listar os times.\n");
                        break;
                    }

                    for (int i = 0; i < size; i++) {
                        timeInfo *time = (timeInfo *)times[i];
                        printf("[%d] Nome: %s, Ano: %d, Torcedores: %.2f milhões\n",
                            i + 1, time->nome, time->anoFundacao, time->numTorcedores);
                    }
                    free(times);
                }
                break;
            }

            case 4: {
                if (colecao == NULL || colecao->numItens == 0) {
                    printf("Erro: Coleção vazia ou inexistente.\n");
                } else {
                    timeInfo busca;
                    printf("Digite o nome do time: ");
                    scanf(" %[^\n]s", busca.nome);
                    printf("Digite o ano de fundação: ");
                    scanf("%d", &busca.anoFundacao);
                    printf("Digite o número de torcedores (em milhões): ");
                    scanf("%f", &busca.numTorcedores);

                    timeInfo *resultado = (timeInfo *)tadQuery(colecao, &busca, cmp);
                    if (resultado != NULL) {
                        printf("Time encontrado: Nome: %s, Ano: %d, Torcedores: %.2f milhões\n",
                               resultado->nome, resultado->anoFundacao, resultado->numTorcedores);
                    } else {
                        printf("Time não encontrado.\n");
                    }
                }
                break;
            }

            case 5: {
                if (colecao == NULL || colecao->numItens == 0) {
                    printf("Erro: Coleção vazia ou inexistente.\n");
                } else {
                    timeInfo remove;
                    printf("Digite o nome do time: ");
                    scanf(" %[^\n]", remove.nome);

                    printf("Digite o ano de fundação: ");
                    scanf("%d", &remove.anoFundacao);

                    printf("Digite o número de torcedores (em milhões): ");
                    scanf("%f", &remove.numTorcedores);
                    
                    if (tadRemove(colecao, &remove, cmp)) {
                        printf("Time removido com sucesso.\n");
                    } else {
                        printf("Time não encontrado.\n");
                    }
                }
                break;
            }

            case 6:
                if (colecao != NULL) {
                    esvaziaTad(colecao);
                    printf("Coleção esvaziada.\n");
                } else {
                    printf("Erro: Coleção não existe.\n");
                }
                break;

            default:
                printf("Opção inválida!\n");
        }
    }

    if (colecao != NULL) {
        tadDestroy(colecao);
    }

    return 0;
}