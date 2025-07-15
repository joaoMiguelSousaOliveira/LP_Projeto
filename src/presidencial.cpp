#include "../include/presidencial.hpp"
#include <iostream>
using namespace std;

Presidencial::Presidencial(int numero, int tipo) : Quarto(numero, tipo) {}

void Presidencial::set_dados() {
    arCondicionado = true;
    hidromassagem = true;
    cafeIncluso = true;
    almocoIncluso = true;
    jantaIncluso = true;
    estacionamento = true;
    servicoQuarto = true; 
}

double Presidencial::get_valor() {
    return valor_diaria();
}
