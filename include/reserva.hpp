#pragma once
#include "quarto.hpp"
#include "cliente.hpp"
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;
class Reserva {
private:
    Cliente *cliente;
    Quarto *quarto;
    time_t dataEntrada;
    time_t dataSaida;
    double valorTotal = 0.0;
public:
    Reserva(Cliente *cliente, Quarto *quarto, time_t dataEntrada, time_t dataSaida);
    void set_dados();
    time_t get_data_entrada() const;
    time_t get_data_saida() const;
    int calcular_dias();
    double calcular_valor_total();
    virtual ~Reserva() = default;
};