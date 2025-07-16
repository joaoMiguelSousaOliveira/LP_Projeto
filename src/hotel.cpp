#include "../include/hotel.hpp"
#include "../include/lista.hpp"
#include "../include/pessoa.hpp"
#include "../include/quarto.hpp"
#include "../include/reserva.hpp"


Hotel::Hotel (Lista<Pessoa*> lista_pessoas, Lista<Quarto*> lista_quartos) :   lista_pessoas(lista_pessoas), lista_quartos(lista_quartos) {}

void Hotel::adicionar_pessoa(Pessoa* pessoa) {
    lista_pessoas.adicionar(pessoa);
}
void Hotel::adicionar_quarto(Quarto* quarto) {
    lista_quartos.adicionar(quarto);
}

void Hotel::adicionar_reserva(Reserva* reserva) {
    lista_reservas.adicionar(reserva);
}