#include "../include/lista.hpp"
#include <iostream>
using namespace std;

template <typename T>
void Lista<T>::adicionar(T elemento) {
    elementos.push_back(elemento);
}

template <typename T>
void Lista<T>::remover(int indice) {
    if (indice >= 0 && indice < elementos.size()) {
        elementos.erase(elementos.begin() + indice);
    }
}

template <typename T>
vector<T> Lista<T>::get_elementos() {
    return elementos;
} 