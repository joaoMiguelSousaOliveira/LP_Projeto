#include "../include/reserva.hpp"
#include "../include/cliente.hpp"
#include "../include/quarto.hpp"
#include "../include/suite.hpp"
#include "../include/quarto_casal.hpp"
#include "../include/presidencial.hpp"
#include "../include/funcionario.hpp"
#include <iostream>


Reserva::Reserva(Cliente *cliente, Quarto *quarto, int diasEstadia) : cliente(cliente), quarto(quarto), diasEstadia(diasEstadia) {}

void Reserva::set_dados() {
    cout << "Quantos dias ficará no hotel: ";
    cin >> diasEstadia;    
    cout << endl;
} 

int Reserva::get_dias_estadia() const{
    return diasEstadia;
}


double Reserva::calcular_valor_total() {
    valorTotal = quarto->get_valor() * diasEstadia;
    return valorTotal;
}
