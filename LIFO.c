#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_FILA 3

int fila[TAM_FILA], ultimaPosicao = 0;

int main(void)
{

    empilhar(1);
    empilhar(2);
    empilhar(3);
    desempilhar();
    exibir();

    return 0;
}
void empilhar(int valor)
{
    if (cheia() == 0) {
        fila[ultimaPosicao] = valor;
        ultimaPosicao++;
    } else {
        printf("Nao foi possivel empilhar item. Lista cheia!");
    }
}

int desempilhar()
{
    int valor;
    if (vazia() == 0) {
        for (int i = 0; i < TAM_FILA; i++) {
            fila[i] = 0;
            if (i + 1 < TAM_FILA && fila[i + 1]) {
                fila[i] = fila[i + 1];
            }
        }
        ultimaPosicao--;
    } else {
        printf("Não foi possivel desenfileirar item. Lista vazia!");
    }
}

int vazia()
{
    int resultado = 1;
    //Se resultado=1 significa que todos estão vazios e se for = 0 ele tem algum espaço cheio.
    for (int i = 0; i < TAM_FILA; i++) {
        //Checa cada item para ver se não estão vazios
        if (fila[i] != 0) {
            resultado = 0;
        }
    }
    return resultado;
}

int cheia()
{
    int resultado = 1;
    //Se resultado=1 significa que está cheio e se for = 0 ele tem algum espaço vazio.
    for (int i = 0; i < TAM_FILA; i++) {
        //Se algum item estiver vazio resultado recebe 0
        if (fila[i] == 0) {
            resultado = 0;
        }
    }
    //Aqui retorna o valor
    return resultado;
}

void exibir()
{

    for (int i = 0; i < TAM_FILA; i++) {
        printf("%i\n", fila[i]);
    }
}
void limpar()
{
    for (int i = 0; i < TAM_FILA; i++) {
        desempilhar();
    }
}
