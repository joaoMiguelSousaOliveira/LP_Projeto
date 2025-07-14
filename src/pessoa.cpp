#include "../include/pessoa.hpp"

using namespace std;

void Pessoa::set_nome() {
    cout << "Digite o nome: ";
    cin >> nome;
} 

string Pessoa::get_nome() {
    return nome;
}

void Pessoa::set_tipo() {
    cout << "Digite o tipo: ";
    cin >> tipo;
} 

string Pessoa::get_tipo() {
    return tipo;
}