#pragma once
#include <string>
#include "quarto.hpp"

using namespace std;

class Casal : public Quarto {
public:
    Casal(int numero, int tipo);
    void set_dados() override;
    double get_valor() override;
    virtual ~Casal() = default;
};