#pragma once
#include <vector>
#include <iostream>  
#include <stdexcept>  


using namespace std; 

template <typename T>
class Lista {
private:
    std::vector<T> elementos; 

public:

    void adicionar(T elemento) {
        elementos.push_back(elemento);
    }

    void remover(int indice) {
        if (indice >= 0 && static_cast<typename std::vector<T>::size_type>(indice) < elementos.size()) {
            elementos.erase(elementos.begin() + static_cast<typename std::vector<T>::size_type>(indice));
        }
    }

    void atualizar(int indice, T elemento) {
        if (indice >= 0 && static_cast<typename std::vector<T>::size_type>(indice) < elementos.size()) {
            elementos[static_cast<typename std::vector<T>::size_type>(indice)] = elemento;
        } 
    }


    bool vazia() const {
        return elementos.empty();
    }

    int tamanho() const {
        return elementos.size();
    }

    T& operator[](int indice) {
        return elementos[static_cast<typename std::vector<T>::size_type>(indice)];
    } 


    const T& get_elementos(int indice) const {
        if (indice < 0 || static_cast<typename std::vector<T>::size_type>(indice) >= elementos.size()) {
            throw std::out_of_range("Índice fora do intervalo da lista");
        }
        return elementos[static_cast<typename std::vector<T>::size_type>(indice)];
    }
    
    virtual ~Lista() = default; 
};