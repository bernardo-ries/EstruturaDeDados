#ifndef LISTA_H
#define LISTA_H

struct Celula {
    int dado;
    Celula* prox;
};

Celula* inserir(int numero, Celula* lista);
void exibir(Celula* lista);
int contarLista(Celula* lista);
bool estaNaLista(int numero, Celula* lista);
int contaOcorrencia(int numero, Celula* lista);
bool verificaOrdem(Celula* lista);
float fazMedia(Celula* lista);

#endif
