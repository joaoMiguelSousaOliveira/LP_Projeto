#pragma once
#include "reserva.hpp"

using namespace std;
class Pagamento {
private:
    int formaPagamento; 
    double valorTotal;
public:
    Pagamento(int formaPagamento, double valorTotal);
    void set_dados();
    int get_forma_pagamento() const;
    double get_valor_total() const;
    double calcular_pagamento_total() const;
    virtual ~Pagamento() = default;
};