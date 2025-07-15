#pragma once
#include "lista.hpp"
#include "pessoa.hpp"
#include "quarto.hpp"

using namespace std;

class Hotel {
public:
    Lista<Pessoa*> lista_pessoas;
    Lista<Quarto*> lista_quartos;

    Hotel(Lista<Pessoa*> lista_pessoas, Lista<Quarto*> lista_quartos);
    void adicionar_pessoa(Pessoa* pessoa);
    void adicionar_quarto(Quarto* quarto);
    virtual ~Hotel() = default;
};