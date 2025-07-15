#pragma once

using namespace std;

class Quarto {
private:
    int numero;
    int tipo;
protected:
    double valor_base_diaria = 100.0;
    bool arCondicionado = false;
    bool hidromassagem = false;
    bool cafeIncluso = false;
    bool almocoIncluso = false;
    bool jantaIncluso = false;
    bool estacionamento = false;
    bool servicoQuarto = false; 

public:
    Quarto(int numero, int tipo);
    virtual void set_dados();
    virtual double get_valor();     
    int get_numero() const;
    int get_tipo() const;
    
    double valor_diaria();
    virtual ~Quarto() = default;
};