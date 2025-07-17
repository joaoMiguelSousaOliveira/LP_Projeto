#include "../include/cliente.hpp"
#include "../include/pessoa.hpp"
#include <limits>
#include <iostream>

using namespace std;

Cliente::Cliente(string nome, int tipo, string cpf, string telefone, string email) : Pessoa(nome, tipo), cpf(cpf), telefone(telefone), email(email){}

void Cliente::set_dados() {
    cout << "Digite o cpf: ";
    cin >> cpf;
    
    cout << endl << "Digite o Telefone: ";
    cin >> telefone;

    cout << endl << "Digite o Email: ";
    cin >> email;

    cout << endl;
} 

string Cliente::get_cpf() const {
    return cpf;
}

string Cliente::get_telefone() const {
    return telefone;
}

string Cliente::get_email() const {
    return email;
}