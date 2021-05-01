#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int conteudo;
    struct celula *prox;
} Celula;

Celula* inicializaCelula(int conteudo) {
    Celula* c = (Celula*) malloc(sizeof(Celula));
    c->conteudo = conteudo;
    c->prox = NULL;
    return c;
}

Celula* insere(Celula* inicio, int conteudo) {
    Celula* aux = inicio;

    while(aux->prox != NULL) {
        aux = aux->prox;
    }

    Celula* novoElemento = inicializaCelula(conteudo);
    aux->prox = novoElemento;
    return aux; // Retornando referência do último elemento
}

void imprimeLista(Celula* inicio){
    Celula *aux = inicio;
    
    while(aux != NULL){
    printf("%d ", aux->conteudo);
        aux = aux->prox;
    }
}

Celula* removePrimeiroElemento(Celula *inicio){
    Celula *aux = inicio;
    inicio = inicio->prox;
    free(aux);
    return inicio;
}

int main(){
    Celula *inicio = inicializaCelula(0);

    for(int i = 1; i < 10; i++) {
        insere(inicio, i);
    }

    imprimeLista(inicio);

    inicio = removePrimeiroElemento(inicio);
    imprimeLista(inicio);
    return 0;
}
