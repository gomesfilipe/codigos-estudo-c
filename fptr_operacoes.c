#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QTDFUNCIONALIDADES 5

typedef int (*fptr) (int, int); // bons modos

int soma(int x, int y);
int subtracao(int x, int y);
int mult(int x, int y);
int resto(int x, int y);
int potencia(int x, int y);

// Função que apenas efetua a operação que lhe foi passada como parâmetro
int efetuaOperacao(fptr ponteiroOperacao, int x, int y);

// Função que retorna o ponteiro para a operação que corresponde a um determinado caractere
fptr codOperacao(char op);

// Função que realiza a operação com base no caractere passado, de modo que deixa os ponteiros de função opacos para os desenvolvedores
int realizaOperacao(char op, int x, int y);

int main(){
    int result;
    int x = 17;
    int y = 5;

    // Efetuando operações utilizando o ponteiro da função como argumento
    fptr pointer[QTDFUNCIONALIDADES] = {soma, subtracao, mult, resto, potencia};
    char op[QTDFUNCIONALIDADES] = "+-*%^";
    for(int i = 0; i < QTDFUNCIONALIDADES; i++){
        printf("%d %c %d = %d\n", x, op[i], y, efetuaOperacao(pointer[i], x, y));
    }

    printf("-----------------\n");

    // Efetuando operações utilizando os caracteres que correspondem as operações
    for(int i = 0; i < QTDFUNCIONALIDADES; i++){
        printf("%d %c %d = %d\n", x, op[i], y, realizaOperacao(op[i], x, y));
    }

    return 0;
}

int soma(int x, int y){
    return x + y;
}

int subtracao(int x, int y){
    return x - y;
}

int mult(int x, int y){
    return x * y;
}

int resto(int x, int y){
    return x % y;
}

int potencia(int x, int y){
    return pow(x, y);
}

int efetuaOperacao(fptr ponteiroOperacao, int x, int y){
    return ponteiroOperacao(x, y);
}

fptr codOperacao(char op){
    switch(op){
        case '+': return soma;
        case '-': return subtracao;
        case '*': return mult;
        case '^': return potencia;
        case '%': return resto;
    }
}

int realizaOperacao(char op, int x, int y){
    fptr operacao = codOperacao(op);
    return operacao(x, y);
}