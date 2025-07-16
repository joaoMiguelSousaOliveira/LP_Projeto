#pragma once
#include <vector>

using namespace std;

template <typename T>
class Lista {
private:
    vector<T> elementos;
public:
    void adicionar(T elemento);
    void remover(int indice);
    void atualizar(int indice, T elemento);
    bool vazia() const;
    int tamanho() const;
    T& operator[](int indice);          
    const T& get_elementos(int indice) const; 
};