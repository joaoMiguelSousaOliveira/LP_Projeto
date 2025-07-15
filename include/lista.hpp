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
    vector<T> get_elementos();
};