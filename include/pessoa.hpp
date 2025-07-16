#pragma once
#include <string>

using namespace std;

class Pessoa {
private:
    string nome;
    int tipo;
public:
    Pessoa(string nome, int tipo);
    virtual void set_dados();
    string get_nome() const;
    int get_tipo() const;
    virtual ~Pessoa() = default;
};