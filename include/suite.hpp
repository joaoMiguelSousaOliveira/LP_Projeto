#pragma once
#include <string>
#include "quarto.hpp"

using namespace std;

class Suite : public Quarto {
public:
    Suite(int numero, int tipo);
    void set_dados() override;
    double get_valor() override;
    virtual ~Suite() = default;
};