#include "../include/funcionario.hpp"
#include <iostream>
using namespace std;

Funcionario::Funcionario(string nome, int tipo,string cargo, int numQuartos) : Pessoa(nome, tipo), cargo(cargo), numQuartos(numQuartos) {
    numQuartos = 0;
}

void Funcionario::set_dados() {
    cout << "Cargo: ";
    getline(cin, cargo);
    
    cout << endl << "Número de quartos: ";
    cin >> numQuartos;

    cout << endl;

} 

string Funcionario::get_cargo() const {
    return cargo;
}

int Funcionario::get_numQuartos() const {
    return numQuartos;
}

double Funcionario::calcular_salario() {
    if (cargo == "camareira") {
        bonusPorCargo = 250.0; 
    } else if (cargo == "recepcionista") {
        bonusPorCargo = 100.0; 
    } else if (cargo == "gerente") {
        bonusPorCargo = 500.0; 
    } else if (cargo == "cozinheiro") {
        bonusPorCargo = 350.0;
    } else {
        bonusPorCargo = 0.0;
    }
    return salarioBase + (numQuartos * bonusPorQuarto) + bonusPorCargo;
}