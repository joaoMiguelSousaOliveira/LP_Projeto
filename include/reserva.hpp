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
    int diasEstadia;
    double valorTotal = 0.0;
public:
    Reserva(Cliente *cliente, Quarto *quarto, int diasEstadia);
    void set_dados();
    int get_dias_estadia() const;
    int calcular_dias();
    double calcular_valor_total();
    virtual ~Reserva() = default;
};