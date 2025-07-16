#include "../include/funcionario.hpp"
#include "../include/pessoa.hpp"
#include <iostream>
using namespace std;

Funcionario::Funcionario(string nome, int tipo,string cargo, int numQuartos) : Pessoa(nome, tipo), cargo(cargo), numQuartos(numQuartos) {
    numQuartos = 0;
}

void Funcionario::set_dados() {
    cout << "Cargo [C - Camareira, R - Recepcionista, G - Gerente, CO - Cozinheiro]: ";
    cin >> cargo;
    cin.ignore();
    
    // Validação do cargo
    while (cargo != "C" && cargo != "R" && cargo != "G" && cargo != "CO") {
        cout << "Cargo inválido! Digite novamente: ";
        cin >> cargo;
        cin.ignore(); 
    }

    cout << "Número de quartos sob sua responsabilidade: ";
    cin >> numQuartos;
    
    cin.ignore();

} 

string Funcionario::get_cargo() const {
    return cargo;
}

int Funcionario::get_numQuartos() const {
    return numQuartos;
}

double Funcionario::calcular_salario() {
    if (cargo == "C") {
        bonusPorCargo = 250.0; 
    } else if (cargo == "R") {
        bonusPorCargo = 100.0; 
    } else if (cargo == "G") {
        bonusPorCargo = 500.0; 
    } else {
        bonusPorCargo = 350.0;
    }
    
    return salarioBase + (numQuartos * bonusPorQuarto) + bonusPorCargo;
}