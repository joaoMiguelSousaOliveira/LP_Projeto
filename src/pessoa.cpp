#include "../include/pessoa.hpp"
#include <iostream>

using namespace std;

Pessoa::Pessoa(string nome, int tipo) : nome(nome), tipo(tipo) {
}

void Pessoa::set_dados() {
    cout << "Digite o nome da pessoa: ";
    getline(cin, nome);
    cin.ignore();

    cout << endl <<"Cadastro [1 - Cliente] [2 - Funcionário]: ";
    cin >> tipo;
    cout << endl;
} 

string Pessoa::get_nome() const{
    return nome;
}

int Pessoa::get_tipo() const {
    return tipo;
}