#include "../include/pessoa.hpp"
#include <iostream>

using namespace std;

Pessoa::Pessoa(string nome, string tipo) : nome(nome), tipo(tipo) {
}

void Pessoa::set_dados() {
    cout << "Digite o nome: ";
    getline(cin, nome);
    
    cout << endl <<"Cadastro [Cliente / Funcionário]: ";
    getline(cin, tipo);

    cout << endl;
} 

string Pessoa::get_nome() const{
    return nome;
}

string Pessoa::get_tipo() const {
    return tipo;
}