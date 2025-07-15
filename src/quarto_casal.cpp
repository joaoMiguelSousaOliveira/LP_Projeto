#include "../include/quarto_casal.hpp"
#include <iostream>
using namespace std;

Casal::Casal(int numero, int tipo) : Quarto(numero, tipo) {}

void Casal::set_dados() {
    arCondicionado = true;
    hidromassagem = true;
    cafeIncluso = true;
    estacionamento = true;
    servicoQuarto = true; 
}

double Casal::get_valor() {
    return valor_diaria();
}

