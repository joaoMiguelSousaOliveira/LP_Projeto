#pragma once
#include <string>

using namespace std;

class Pessoa {
private:
    string nome;
    string tipo;
public:
    Pessoa(string nome, string tipo);
    virtual void set_dados();
    string get_nome() const;
    string get_tipo() const;
    virtual ~Pessoa() = default;
};