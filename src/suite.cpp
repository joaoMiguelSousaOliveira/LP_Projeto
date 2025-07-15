#include "../include/suite.hpp"
#include <iostream>
using namespace std;

Suite::Suite(int numero, int tipo) : Quarto(numero, tipo) {}

void Suite::set_dados() {
    arCondicionado = true;
    cafeIncluso = true;
    estacionamento = true;
}

double Suite::get_valor() {
    return valor_diaria();
}

