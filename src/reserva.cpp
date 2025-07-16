#include "../include/reserva.hpp"
#include "../include/cliente.hpp"
#include "../include/quarto.hpp"
#include "../include/suite.hpp"
#include "../include/quarto_casal.hpp"
#include "../include/presidencial.hpp"
#include "../include/funcionario.hpp"
#include <iostream>


Reserva::Reserva(Cliente *cliente, Quarto *quarto, time_t dataEntrada, time_t dataSaida) : cliente(cliente), quarto(quarto), dataEntrada(dataEntrada), dataSaida(dataSaida) {}

void Reserva::set_dados() {
    cout << "Data de Checkin [AAAA-MM-DD]: ";
    cin >> dataEntrada;    
    cout << endl;

    cout << "Data de Checkout [AAAA-MM-DD]: ";
    cin >> dataSaida;   
    cout << endl;
} 

time_t Reserva::get_data_entrada() const{
    return dataEntrada;
}

time_t Reserva::get_data_saida() const{
    return dataSaida;
}

int Reserva::calcular_dias() {
    double segundos = difftime(dataSaida, dataEntrada);
    int dias = static_cast<int>(segundos / (60 * 60 * 24));
    return dias;
}

double Reserva::calcular_valor_total() {
    valorTotal = quarto->get_valor() * calcular_dias();
    return valorTotal;
}
