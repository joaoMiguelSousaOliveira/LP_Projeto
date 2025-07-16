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
void Lista<T>::atualizar(int indice, T elemento) {
    if (indice >= 0 && indice < elementos.size()) {
        elementos[indice] = elemento;
    } 
}

template <typename T>
bool Lista<T>::vazia() const {
    return elementos.empty();
}

template <typename T>
int Lista<T>::tamanho() const {
    return elementos.size();
}

template <typename T>
T& Lista<T>::operator[](int indice) {
    return elementos[indice];
} 


template <typename T>
const T& Lista<T>::get_elementos(int indice) const {
    if (indice < 0 || indice >= elementos.size()) {
        throw std::out_of_range("Índice fora do intervalo da lista");
    }
    return elementos[indice];
}