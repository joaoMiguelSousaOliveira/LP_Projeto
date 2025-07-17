#include "../include/quarto.hpp"
#include <iostream>
using namespace std;

Quarto::Quarto(int numero, int tipo) : numero(numero), tipo(tipo) {}


void Quarto::set_dados() {
    
    cout << "Numero do quarto: ";
    cin >> numero;    
    
    cout << endl << "Selecione o quarto desejado [Suite - 1], [Quarto de Casal - 2], [Presidencial - 3]: ";
    cin >> tipo;
    cout << endl;
    while (tipo < 1 || tipo > 3) {
        cout << "Tipo inválido! Digite novamente: ";
        cin >> tipo;
    }
    cin.ignore();
    cout << "Número do quarto: " << numero << endl;
    cout << "Tipo do quarto: " << tipo << endl;
    cout << endl;

} 

int Quarto::get_numero() const{
    return numero;
}

int Quarto::get_tipo() const{
    return tipo;
}

double Quarto::valor_diaria() {
    double diaria = valor_base_diaria;
    if (arCondicionado) diaria += 20.0;
    if (hidromassagem) diaria += 30.0;
    if (cafeIncluso) diaria += 10.0;
    if (almocoIncluso) diaria += 15.0;
    if (jantaIncluso) diaria += 20.0;
    if (estacionamento) diaria += 5.0;
    if (servicoQuarto) diaria += 10.0;

    return diaria;
}

double Quarto::get_valor() {
    double valorTotal = valor_diaria();
    return valorTotal;
}
