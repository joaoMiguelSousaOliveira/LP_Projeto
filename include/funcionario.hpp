#pragma once
#include "pessoa.hpp"

using namespace std;

class Funcionario : public Pessoa {
private:
    string cargo;
    int numQuartos;
    double salarioBase = 1500.0; 
    double bonusPorQuarto = 100.0; 
    double bonusPorCargo = 0.0;

public:
    
    Funcionario(string nome, string tipo, string cargo, int numQuartos);
    void set_dados() override;
    string get_cargo() const;
    int get_numQuartos() const;
    double calcular_salario();

    virtual ~Funcionario() = default;
};