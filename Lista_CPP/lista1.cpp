#include <iostream>
#include "lista.h"

using namespace std;

Celula* inserir(int numero, Celula* lista) {
    Celula* nova = new Celula;
    nova->dado = numero;
    nova->prox = lista;
    return nova;
}

void exibir(Celula* lista) {
    for (Celula* p = lista; p != nullptr; p = p->prox) {
        cout << p->dado << "\t";
    }
    cout << endl;
}

int contarLista(Celula* lista) {
    int total = 0;
    for (Celula* p = lista; p != nullptr; p = p->prox) {
        total++;
    }
    return total;
}

bool estaNaLista(int numero, Celula* lista) {
    for (Celula* p = lista; p != nullptr; p = p->prox) {
        if (numero == p->dado) {
            return true;
        }
    }
    return false;
}

int contaOcorrencia(int numero, Celula* lista) {
    int conta = 0;
    for (Celula* p = lista; p != nullptr; p = p->prox) {
        if (numero == p->dado) {
            conta++;
        }
    }
    return conta;
}

bool verificaOrdem(Celula* lista) {
    if (lista == nullptr || lista->prox == nullptr) {
        return true;
    }

    for (Celula* p = lista; p->prox != nullptr; p = p->prox) {
        if (p->dado > p->prox->dado) {
            return false;
        }
    }
    return true;
}

float fazMedia(Celula* lista) {
    float total = 0;
    int num = 0;
    for (Celula* p = lista; p != nullptr; p = p->prox) {
        total++;
        num += p->dado;
    }
    return num / total;
}

int main() {
    Celula* lista = nullptr;

    lista = inserir(7, lista);
    lista = inserir(10, lista);
    lista = inserir(5, lista);

    cout << "Lista contem " << contarLista(lista) << " elementos\n";
    exibir(lista);

    int numero;
    cout << "Digite numero para pesquisa: ";
    cin >> numero;

    if (estaNaLista(numero, lista)) {
        cout << numero << " esta na lista.\n";
    } else {
        cout << numero << " nao está na lista.\n";
    }

    cout << "O numero " << numero << " aparece " << contaOcorrencia(numero, lista) << " vez(es) na lista.\n";

    if (verificaOrdem(lista)) {
        cout << "A lista esta ordenada.\n";
    } else {
        cout << "A lista nao esta ordenada.\n";
    }

    cout << "A media dos elementos da lista e: " << fazMedia(lista) << endl;

    return 0;
}