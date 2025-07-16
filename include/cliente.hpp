#pragma once
#include "pessoa.hpp"

using namespace std;

class Cliente : public Pessoa {
private:
    string cpf;
    string telefone;
    string email;
public:
    Cliente(string nome, int tipo, string cpf, string telefone, string email);
    void set_dados() override;
    string get_cpf() const;
    string get_telefone() const;
    string get_email() const;
    virtual ~Cliente() = default;
};