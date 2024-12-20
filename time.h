/*******************************************************
* Arquivo: time.h (Header)
* Descrição: Declaração das funções do TAD Colection Genérico (time.h)
* 
* Autor: Caio Bandeira Moreira
* Curso: Estrutura de Dados 1
* Professor: Anselmo Cardoso de Paiva
* Data: Dezembro/2024
*******************************************************/


#ifndef TIME_H
#define TIME_H

#include <stdlib.h>

// Constantes para representar valores lógicos
#define TRUE 1
#define FALSE 0

// Estrutura para o TAD Time
typedef struct {
    int **item;      // Ponteiro para os itens armazenados
    int numItens;    // Número atual de itens na coleção
    int maxItens;    // Número máximo de itens permitido
} Time;

// Função para criar o TAD Genérico
Time *timeCreate(int maxItems);

// Função para destruir o TAD
int tadDestroy(Time *c);

// Função para inserir um item no TAD
int tadInsert(Time *c, void *elem);

// Função para consultar se o item está no TAD
int *tadQuery(Time *C, void *elem, int (*cmp)(void *, void *));

// Função para remover um item do TAD
int *tadRemove(Time *c, void *elem, int (*cmp)(void *, void *));

// Função para listar os elementos na coleção
void **tadList(Time *c, int *size);

// Função para esvaziar a coleção
int esvaziaTad(Time *c);

#endif // TIME_H
