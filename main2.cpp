#include <iostream>
#include "include/hotel.hpp"

#include "include/pessoa.hpp"
#include "include/cliente.hpp"
#include "include/funcionario.hpp"

#include "include/quarto.hpp"
#include "include/suite.hpp"
#include "include/quarto_casal.hpp"
#include "include/presidencial.hpp"

#include "include/reserva.hpp"
#include "include/pagamento.hpp"

using namespace std;

int main() {

    cout << "==============================================" << endl;
    cout << "   Bem-vindo ao Sistema de Gerenciamento de Hotel" << endl;
    cout << "==============================================" << endl;
    cout << "Este sistema permite cadastrar pessoas, quartos, reservas e pagamentos." << endl;
    cout << "Você poderá visualizar e gerenciar todos os dados do hotel de forma simples." << endl;
    cout << endl;
    cout << "Opções disponíveis:" << endl;
    cout << "  1 - Iniciar cadastro de pessoas" << endl;
    cout << "  2 - Iniciar cadastro de quartos" << endl;
    cout << "  3 - Efetuar reserva" << endl;
    cout << "  4 - Alterar o último dado cadastrado" << endl;
    cout << "  5 - Excluir o último dado cadastrado" << endl;
    cout << "  0 - Encerrar o programa" << endl;
    cout << "----------------------------------------------" << endl;

    Hotel *hotel;

    int resposta;
    cout << "Digite a opção desejada: ";
    cin >> resposta;

    while (resposta !=0) {

        // Cadastrar pessoas
        if (resposta == 1) {

            Pessoa *pessoa = new Pessoa(pessoa->get_nome(), pessoa->get_tipo());
            pessoa -> set_dados();

            // Cadastra Cliente
            if (pessoa->get_tipo() == 1) {

                Cliente *cliente = new Cliente(pessoa->get_nome(), pessoa->get_tipo(), cliente->get_cpf(), cliente->get_telefone(), cliente->get_email());
                cliente->set_dados();
                hotel->lista_pessoas.adicionar(cliente);
            
            // Cadastra Funcionário
            } else if (pessoa->get_tipo() == 2) {

                Funcionario *funcionario = new Funcionario(pessoa->get_nome(), pessoa->get_tipo(), funcionario->get_cargo(), funcionario->get_numQuartos());
                funcionario->set_dados();
                funcionario->calcular_salario();
                hotel->lista_pessoas.adicionar(funcionario);

            }

        // Cadastrar quartos
        } else if (resposta == 2) {

            Quarto *quarto = new Quarto(quarto->get_numero(), quarto->get_tipo());
            quarto->set_dados();

            // Cadastra Suite
            if (quarto->get_tipo() == 1) {

                Suite *suite = new Suite(quarto->get_numero(), quarto->get_tipo());
                suite->set_dados();
                suite->get_valor();
                hotel->lista_quartos.adicionar(suite);

            }

            // Cadastra Casal
            else if (quarto->get_tipo() == 2) {

                Casal *casal = new Casal(quarto->get_numero(), quarto->get_tipo());
                casal->set_dados();
                casal->get_valor();
                hotel->lista_quartos.adicionar(casal);

            } 
            
            // Cadastra Presidencial
            else if (quarto->get_tipo() == 3) {

                Presidencial *presidencial = new Presidencial(quarto->get_numero(), quarto->get_tipo());
                presidencial->set_dados();
                presidencial->get_valor();
                hotel->lista_quartos.adicionar(presidencial);

            }

        // Efetuar reserva
        } else if (resposta == 3) {

            // Verifica se há clientes e quartos cadastrados
            if (hotel->lista_pessoas.vazia() || hotel->lista_quartos.vazia()) {
                cout << "Cadastre pelo menos um cliente e um quarto antes de fazer uma reserva!" << endl;
                continue;
            }

            // Seleciona cliente
            cout << "Clientes cadastrados:" << endl;
            for (size_t i = 0; i < hotel->lista_pessoas.tamanho(); i++) {

                Cliente *cliente = dynamic_cast<Cliente *>(hotel->lista_pessoas[i]);

                if (cliente) {
                    cout << i << " - " << cliente->get_nome() << " (CPF: " << cliente->get_cpf() << ")" << endl;
                }
            }

            int idxCliente;
            cout << "Escolha o índice do cliente: ";
            cin >> idxCliente;
            /*TODO: Trycache*/
            if (idxCliente < 0 || idxCliente >= hotel->lista_pessoas.tamanho()) {
                cout << "Índice de cliente inválido!" << endl;
                continue;
            }
            /*TODO: Trycache*/
            Cliente *cliente = dynamic_cast<Cliente *>(hotel->lista_pessoas[idxCliente]);
            if (!cliente) {
                cout << "Selecione um cliente válido!" << endl;
                continue;
            }

            // Seleciona quarto
            cout << "Quartos cadastrados:" << endl;
            for (int i = 0; i < hotel->lista_quartos.tamanho(); ++i) {
                Quarto *q = hotel->lista_quartos[i];
                cout << i << " - Quarto " << q->get_numero() << " (Tipo: " << q->get_tipo() << ")" << endl;
            }
            int idxQuarto;
            cout << "Escolha o índice do quarto: ";
            cin >> idxQuarto;
            if (idxQuarto < 0 || idxQuarto >= hotel->lista_quartos.tamanho()) {
                cout << "Índice de quarto inválido!" << endl;
                continue;
            }
            Quarto *quarto = hotel->lista_quartos[idxQuarto];

            // Seleciona datas
            time_t dataEntrada, dataSaida;
            cout << "Informe a data de entrada (timestamp): ";
            cin >> dataEntrada;
            cout << "Informe a data de saída (timestamp): ";
            cin >> dataSaida;
            if (dataSaida <= dataEntrada) {
                cout << "Data de saída deve ser posterior à data de entrada!" << endl;
                continue;
            }

            // Cria reserva
            Reserva *reserva = new Reserva(cliente, quarto, dataEntrada, dataSaida);
            reserva->set_dados(); // Se quiser permitir alteração das datas
            hotel->lista_reservas.adicionar(reserva);

            cout << "Reserva cadastrada com sucesso!" << endl;
            cout << "Valor total da reserva: R$ " << reserva->calcular_valor_total() << endl;
    
        } else if (resposta == 4) {

            // Alterar o último dado cadastrado
            cout << "Funcionalidade de alteração ainda não implementada." << endl;

        } else if (resposta == 5) {

            // Excluir o último dado cadastrado
            cout << "Funcionalidade de exclusão ainda não implementada." << endl;

        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }
    

    
    
    std::cout << "\nPrograma finalizado.\n";

    return 0;
}

