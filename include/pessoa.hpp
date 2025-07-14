#pragma once
#include <iostream>

using namespace std;

class Pessoa {
private:
    string nome;
    string tipo;
public:
    void set_nome();
    void set_tipo();
    string get_nome();
    string get_tipo();
};