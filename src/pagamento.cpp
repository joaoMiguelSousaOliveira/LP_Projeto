#include "../include/pagamento.hpp"
#include "../include/cliente.hpp"
#include "../include/quarto.hpp"
#include "../include/suite.hpp"
#include "../include/quarto_casal.hpp"
#include "../include/presidencial.hpp"

#include <iostream>


Pagamento::Pagamento(int formaPagamento, double valorTotal) : formaPagamento(formaPagamento), valorTotal(valorTotal){}

void Pagamento::set_dados() {
    cout << "Ecolha a forma de Pagamento [1 - Pix] [2 - Débito] [3 - Crédito]:  ";
    cin >> formaPagamento;    
    cout << endl;
} 

int Pagamento::get_forma_pagamento() const{
    return formaPagamento;
}

double Pagamento::get_valor_total() const {
    return valorTotal;
}

double Pagamento::calcular_pagamento_total() const{
    if (formaPagamento == 1) return valorTotal - (valorTotal * 0.05); 
    else if (formaPagamento == 2) return valorTotal;
    else if (formaPagamento == 3) return valorTotal + (valorTotal * 0.1);
    else return valorTotal; 
}
