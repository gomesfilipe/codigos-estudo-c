#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
    int x, y;
} Ponto;

typedef struct celula{
    Ponto *p;
    struct celula *prox;
} Celula;

Celula* criaCelula(Ponto *q){
    Celula *inicio = (Celula*) malloc(sizeof(Celula));
    inicio->p = (Ponto*) malloc(sizeof(Ponto));
    inicio->p = q;
    inicio->prox = NULL;
    return inicio;
}

Celula* insereInicio(Celula *inicio, Ponto *q){
    Celula *aux = criaCelula(q);
    aux->prox = inicio;
    return aux;
}

Celula* insereFinal(Celula *inicio, Ponto *q){
    Celula *final = criaCelula(q);
    Celula *aux = inicio;
    for(aux; aux->prox != NULL; aux = aux->prox);

    aux->prox = final;
    return inicio;
}

void imprimePonto(Ponto *q){
    printf("(%d, %d)\n", q->x, q->y);
}

void imprimeLista(Celula *inicio){
    Celula *aux = inicio;
    for(aux; aux != NULL; aux = aux->prox){
        imprimePonto(aux->p);
    }
}

Ponto* criaPonto(int x, int y){
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    return p;
}

Celula* removeInicio(Celula *inicio){
    Celula *aux = inicio;
    inicio = inicio->prox;
    free(aux);
    return  inicio;
}

Celula* removeFinal(Celula *inicio){
    Celula *aux = inicio;
    Celula *anterior;
    
    for(aux; aux->prox != NULL; aux = aux->prox){
        anterior = aux; 
    }
    
    anterior->prox = NULL;
    free(aux);
    
    return inicio;
}

int main(){
    int x, y;
    Ponto *p = criaPonto(0, 0);
    Ponto *q;
    Celula *inicio = criaCelula(p);

    printf("Lista no inicio com apenas 1 elemento:\n");
    imprimeLista(inicio);

    //  Insere elementos ao mesmo tempo no início e no final
    for(int i = 0; i < 10; i++){
        scanf("%d %d", &x, &y);
        q = criaPonto(x, y);
        
        inicio = insereInicio(inicio, q);
        inicio = insereFinal(inicio, q);
    }

    printf("\nLista apos adicionar elementos:\n");
    imprimeLista(inicio);
    
    // Remove elementos ao mesmo tempo no início e no final
    for(int i = 0; i < 10; i++){
        inicio = removeInicio(inicio);
        inicio = removeFinal(inicio);
    }

    printf("\nLista apos remover elementos:\n");
    imprimeLista(inicio);

    return 0;
}