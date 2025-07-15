#pragma once
#include "hotel.hpp"

using namespace std;

class Quarto : public Hotel {
private:
    int numero;
    string tipo;
public:
    Quarto(Lista<Pessoa*> lista_pessoas, Lista<Quarto*> lista_quartos, int numero, string tipo);
    void set_dados();
    string get_numero() const;
    string get_tipo() const;
    virtual ~Quarto() = default;
};