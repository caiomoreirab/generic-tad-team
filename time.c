/*******************************************************
* Arquivo: time.c (Implementação)
* Descrição: Implementação das funções do TAD Colection Genérico (time.c)
* 
* Autor: Caio Bandeira Moreira
* Curso: Estrutura de Dados 1
* Professor: Anselmo Cardoso de Paiva
* Data: Dezembro/2024
*******************************************************/


#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int **item;
    int numItens;
    int maxItens;
} Time;


// Função para criar o Tad Genérico
Time *timeCreate(int maxItems) {
    if (maxItems <= 0) {
        return NULL;
    }

    Time *c = (Time *)malloc(sizeof(Time));
    if (c != NULL) {
        c->item = (int **)malloc(sizeof(int) * maxItems);
        if (c->item != NULL) {
            c->numItens = 0;
            c->maxItens = maxItems;
            return c;
        }
        free(c); 
    }
    return NULL;
}


// Função para destruir o TAD;
int tadDestroy(Time *c) {
    if (c != NULL) {
        if (c->numItens == 0) {
            free(c->item);
            free(c);
            return TRUE;
        }
    }
    return FALSE;
}


// Função para inserir um item no TAD
int tadInsert(Time *c, void *elem) {
    if (c != NULL && c->numItens < c->maxItens) {
        c->item[c->numItens] = elem;
        c->numItens++;
        return TRUE;
    }
    return FALSE;
}


// Função para consultar se o item está no TAD
int *tadQuery(Time *C, void *elem, int (*cmp)(void *, void *)) {
    if (C != NULL && C->item != NULL && elem != NULL && cmp != NULL && C->numItens > 0) {
        for (int i = 0; i < C->numItens; i++) {
            if (cmp(C->item[i], elem) == 1) { // Compara o item atual
                return C->item[i]; // Retorna o item encontrado
            }
        }
    }
    return NULL; 
}


// Função para remover um item do TAD
int tadRemove(Time *c, void *elem, int (*cmp)(void *, void *)) {
    if (c != NULL && cmp != NULL && elem != NULL && c->numItens > 0) {
        for (int i = 0; i < c->numItens; i++) {
            // Compara o elemento atual com o elemento a ser removido
            if (cmp(c->item[i], elem) == 1) { 
                // Remove o elemento deslocando os itens seguintes
                for (int j = i; j < c->numItens - 1; j++) {
                    c->item[j] = c->item[j + 1];
                }
                c->numItens--; // Decrementa o número de itens
                return 1;      // Retorna sucesso
            }
        }
    }
    return 0; // Retorna 0 se o elemento não foi encontrado
}


// Função para listar os elementos na coleção
void **tadList(Time *c, int *size) {
    if (c != NULL && c->item != NULL && c->numItens > 0) {
        *size = c->numItens;
        void **times = (void **)malloc(c->numItens * sizeof(void *));
        if (times == NULL) {
            return NULL; // Falha na alocação de memória
        }
        for (int i = 0; i < c->numItens; i++) {
            times[i] = c->item[i];
        }
        return times;
    }
    *size = 0; // Coleção vazia ou inválida
    return NULL;
}

//Função para esvaziar a colecão
int esvaziaTad(Time *c) {
    if (c!= NULL) {
        c-> numItens = 0;
        return 1;
    }
    return 0;
}