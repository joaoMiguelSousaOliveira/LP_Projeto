#include "../include/quarto.hpp"
#include <iostream>
using namespace std;

Quarto::Quarto(int numero, string tipo) : Hotel(nome, tipo), cargo(cargo), numQuartos(numQuartos) {
    numQuartos = 0;
}

void Funcionario::set_dados() {
    cout << "Cargo: ";
    getline(cin, cargo);
    
    cout << endl << "Número de quartos: ";
    cin >> numQuartos;

    cout << endl;

} 
