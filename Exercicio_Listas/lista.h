typedef struct no{
    int dado;
    struct no *prox;
}Lista;

//estamos usando recursão para aprender;
Lista *inserir(int dado, Lista *lista){
    if(lista && dado > lista->dado){
        if (dado!= lista->dado){
            lista->prox = inserir(dado,lista->prox);
        }
        return lista;
    }else{
        Lista *novo = (Lista*)malloc(sizeof(Lista));
        novo->dado = dado;
        if(lista){
            novo->prox = lista;
        }else{
            novo->prox = NULL;
        }
        return novo;
    }
}


//Função para exibir uma lista
void exibir(Lista *lista) {
    for (Lista *p = lista; p; p = p->prox) {
        cout << p->dado << endl;
    }
}



//Função para exibir duas listas
void exibirduas(Lista *lista1, Lista *lista2) {
    while (lista1 != NULL) {
        cout << lista1->dado << endl;
        lista1 = lista1->prox;
    }

    if (lista2 != NULL) {
        cout << "//////////Lista 2///////////" << endl;
    }

    while (lista2 != NULL) {
        cout << lista2->dado << endl;
        lista2 = lista2->prox;
    }
}




//Função para remover numeros da lista
Lista *remover(int dado, Lista * lista){
    Lista *p, *pR;
    for(p=lista, pR =NULL; p; pR=p, p=p->prox){
        if(dado==p->dado){
            if(p==lista){
                lista=lista->prox;
                free(p);
                return lista;
            }
            if(!p->prox){
                pR->prox=NULL;
                free(p);
                return lista;
            }
            pR->prox = p->prox;
            free(p);
            return lista;            
        }
    }
    return lista;
}



//Função para excluir os numeros pares de uma lista
Lista *excluir_pares(Lista *lista) {
    for (Lista *p = lista; p;) {
        if (p->dado % 2 == 0) {
            lista = remover(p->dado, lista);
            p = lista;
        } else {
            p = p->prox;
        }
    }
    return lista;
}


//Função para unir duas listas
Lista *unir_listas(Lista *lista1, Lista *lista2) {
    Lista *lista3 = NULL;

    for (Lista *p = lista1; p != NULL; p = p->prox) {
        lista3 = inserir(p->dado, lista3);
    }

    for (Lista *p = lista2; p != NULL; p = p->prox) {
        lista3 = inserir(p->dado, lista3);
    }

    return lista3;
}


//Função para ordenar uma lista
void ordenar_lista(Lista *lista) {
    if (lista == NULL || lista->prox == NULL) return;

    Lista *i;
    Lista *j;
    int aux;

    for (i = lista; i != NULL; i = i->prox) {
        for (j = i->prox; j != NULL; j = j->prox) {
            if (i->dado > j->dado) {
                aux = i->dado;
                i->dado = j->dado;
                j->dado = aux;
            }
        }
    }
}


//Função para excluir uma lista(Liberando a memória)
Lista *excluir_lista(Lista *lista) {
    for (Lista *p = lista; p;) {
        lista = remover(p->dado, lista);
        p = lista;
    }
    return lista;
}