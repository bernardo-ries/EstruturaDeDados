//Exercicio Bernardo Segabinazzi Ries e João Vitor Guterres

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lista.h"

int main(){
    srand(time(NULL));
    Lista *lista1 = NULL;
    Lista *lista2 = NULL;
    Lista *lista3 = NULL;
    for(int i=0; i<30; i++){
        lista1 = inserir(rand()%100,lista1);
    }
    for(int i=0; i<30; i++){
        lista2 = inserir(rand()%100,lista2);
    }
    cout << "exibindo com pares"<< endl;
    exibir(lista1);
    cout << "Exibindo a lista 2 \n\n\n" <<endl;
    exibir(lista2);

    lista1 = excluir_pares(lista1);

    cout << "exibindo sem pares" << endl;
    exibir(lista1);
    cout<<"Exibindo a lista 3\n\n\n" <<endl;
    lista3=unir_listas(lista1,lista2);
    exibir(lista3);
    cout<<"Exibindo lista 3 ordenada\n\n\n"<< endl;
    exibir(lista3);

    cout<< "Excluindo lista 3..." << endl;

    lista3= excluir_lista(lista3);

    cout << lista3 <<endl;

    cout<< "Lista exluida" <<endl;


}
// dir
//g++ .\main.cpp -o roda
//.\roda.exe