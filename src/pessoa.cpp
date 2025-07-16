#include "../include/pessoa.hpp"
#include <iostream>

using namespace std;

Pessoa::Pessoa(string nome, int tipo) : nome(nome), tipo(tipo) {
}

void Pessoa::set_dados() {
	cout << "Digite o nome da pessoa: ";
	getline(cin, nome);

	cout <<"Cadastro [1 - Cliente] [2 - Funcionário]: ";
	cin >> tipo;
	cout << endl;

	while (tipo != 1 && tipo != 2) {
		cout << "Tipo inválido! Digite novamente: ";
		cin >> tipo;
		cout << endl;
		
	} 
	cin.ignore();
	
} 

string Pessoa::get_nome() const{
	return nome;
}

int Pessoa::get_tipo() const {
	return tipo;
}