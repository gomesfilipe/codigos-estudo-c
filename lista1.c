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
    inicio->p = q; // Não precisa dar malloc em inicio->p pois a referência dele vem do parâmetro
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
    printf("(%d, %d) ", q->x, q->y);
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

int pontosIguais(Ponto *p, Ponto *q){
    if(p->x == q->x && p->y == q->y){
        return 1;
    }

    return 0;
}

Celula* removeInicio(Celula *inicio){
    Celula *aux = inicio;
    inicio = inicio->prox;
    free(aux->p);
    free(aux);
    return  inicio;
}

Celula* removeFinal(Celula *inicio){
    Celula *aux = inicio;
    Celula *anterior;
    
    for(aux; aux->prox != NULL; aux = aux->prox){
        anterior = aux; 
    }
    
    free(aux->p);
    free(aux);
    anterior->prox = NULL;
    
    return inicio;
}

void destroiLista(Celula *inicio){
    Celula *aux = inicio;
    Celula *anterior;
    
    while(aux != NULL){
        anterior = aux;
        aux = aux->prox;
        free(anterior->p);
        free(anterior);
    }

    // Outras formas equivalentes de implementação
    // do{  
    //     anterior = aux;
    //     aux = aux->prox;
    //     free(anterior->p);
    //     free(anterior);
    // } while(aux != NULL);
    
    // for(aux; aux != NULL; aux = aux->prox){
    //     anterior = aux;
    //     free(anterior->p);
    //     free(anterior);
    // }
}

Celula* pesquisaCelula(Celula *inicio, Ponto *p){
    Celula *aux = inicio;
    while(aux != NULL){
        if(pontosIguais(p, aux->p)){
            return aux;
        }
        
        aux = aux->prox;
    }

    return NULL; // Retorna ponteiro nulo caso não encontre um ponto igual na lista
}

int main(){
    int x, y;
    Ponto *p = criaPonto(0, 0);
    Ponto *q, *r;
    Celula *inicio = criaCelula(p);

    printf("Lista no inicio com apenas 1 elemento:\n");
    imprimeLista(inicio);

    //  Insere elementos ao mesmo tempo no início e no final
    for(int i = 0; i < 10; i++){
        scanf("%d %d", &x, &y);
        q = criaPonto(x, y);
        r = criaPonto(x, y); // Criei dois pontos com mesmas coordenadas para eles terem referências diferentes para não ocorrer double free.
        
        inicio = insereInicio(inicio, q);
        inicio = insereFinal(inicio, r);
    }

    printf("\nLista apos adicionar elementos:\n");
    imprimeLista(inicio);

    Ponto *z = criaPonto(4, 4);
    Celula *pesquisa = pesquisaCelula(inicio, z);
    if(pesquisa == NULL){
        printf("Ponto nao encontrado\n");
    } else{
        printf("Ponto encontrado: ");
        imprimePonto(pesquisa->p);
    }
    

    // Remove elementos ao mesmo tempo no início e no final
    for(int i = 0; i < 10; i++){
        inicio = removeInicio(inicio);
        inicio = removeFinal(inicio);
    }

    printf("\nLista apos remover elementos:\n");
    imprimeLista(inicio);

    destroiLista(inicio);
    free(z);
    return 0;
}