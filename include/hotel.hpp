#pragma once
#include "lista.hpp"
#include "pessoa.hpp"
#include "quarto.hpp"
#include "reserva.hpp"

using namespace std;

class Hotel {
public:
    Lista<Pessoa*> lista_pessoas;
    Lista<Quarto*> lista_quartos;
    Lista<Reserva*> lista_reservas;
    Hotel(Lista<Pessoa*> lista_pessoas, Lista<Quarto*> lista_quartos);
    void adicionar_pessoa(Pessoa* pessoa);
    void adicionar_quarto(Quarto* quarto);
    void adicionar_reserva(Reserva* reserva);
    virtual ~Hotel() = default;
};