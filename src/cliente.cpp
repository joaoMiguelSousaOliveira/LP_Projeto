#include "../include/cliente.hpp"
#include <iostream>

using namespace std;

Cliente::Cliente(string nome, string tipo, string cpf, string telefone, string email) : Pessoa(nome, tipo), cpf(cpf), telefone(telefone), email(email){}

void Cliente::set_dados() {
    cout << "Digite o cpf: ";
    getline(cin, cpf);
    
    cout << endl << "Digite o telefone: ";
    getline(cin, telefone);

    cout << endl;
} 

string Cliente::get_cpf() const {
    return cpf;
}

string Cliente::get_telefone() const {
    return telefone;
}