#ifndef LISTA1_H
#define LISTA1_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ponto Ponto;

typedef struct celula Celula;

Celula* criaCelula(Ponto *q);

Celula* insereInicio(Celula *inicio, Ponto *q);

Celula* insereFinal(Celula *inicio, Ponto *q);

void imprimePonto(Ponto *q);

void imprimeLista(Celula *inicio);

Ponto* criaPonto(int x, int y);

int pontosIguais(Ponto *p, Ponto *q);

Celula* removeInicio(Celula *inicio);

Celula* removeFinal(Celula *inicio);

void destroiLista(Celula *inicio);

Celula* pesquisaCelula(Celula *inicio, Ponto *p);


#endif