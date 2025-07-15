#pragma once
#include <string>
#include "quarto.hpp"

using namespace std;

class Presidencial : public Quarto {
public:
    Presidencial(int numero, int tipo);
    void set_dados() override;
    double get_valor() override;
    virtual ~Presidencial() = default;
};