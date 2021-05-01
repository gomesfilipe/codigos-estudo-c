#include "lista1.h"

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

    // Testando função pesquisa
    Ponto *z = criaPonto(4, 4);
    Celula *pesquisa = pesquisaCelula(inicio, z);
    if(pesquisa == NULL){
        printf("Ponto nao encontrado\n");
    } else{
        printf("Ponto esta na lista");
    }
    

    // Remove elementos ao mesmo tempo no início e no final
    for(int i = 0; i < 10; i++){
        inicio = removeInicio(inicio);
        inicio = removeFinal(inicio);
    }

    printf("\nLista apos remover elementos:\n");
    imprimeLista(inicio);

    destroiLista(inicio);
    //free(z);
    return 0;
}
