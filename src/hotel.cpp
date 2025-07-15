#include "../include/hotel.hpp"


Hotel::Hotel (Lista<Pessoa*> lista_pessoas, Lista<Quarto*> lista_quartos) :   lista_pessoas(lista_pessoas), lista_quartos(lista_quartos) {}

void Hotel::adicionar_pessoa(Pessoa* pessoa) {
    lista_pessoas.adicionar(pessoa);
}
void Hotel::adicionar_quarto(Quarto* quarto) {
    lista_quartos.adicionar(quarto);
}

