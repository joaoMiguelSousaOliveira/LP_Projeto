#include <iostream>
#include <limits>
#include "include/hotel.hpp"
#include "include/lista.hpp"

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

    cout << "=================================================" << endl;
    cout << "   Bem-vindo ao Sistema de Gerenciamento de Hotel" << endl;
    cout << "=================================================" << endl;
    cout << "Este sistema permite cadastrar pessoas, quartos, reservas e pagamentos." << endl;
    cout << "Você poderá visualizar e gerenciar todos os dados do hotel de forma simples." << endl;
    cout << endl;
    
    
    Lista<Pessoa*> lista_pessoas;
    Lista<Quarto*> lista_quartos;
    
    Hotel *hotel = new Hotel(lista_pessoas, lista_quartos);

    int resposta;
    

    while (true) {
        cout << "----------------------------------------------" << endl;
        cout << "Opções disponíveis:" << endl;
        cout << "  1 - Iniciar cadastro de pessoas" << endl;
        cout << "  2 - Iniciar cadastro de quartos" << endl;
        cout << "  3 - Efetuar reserva" << endl;
        cout << "  4 - Alterar dado Cadastrado [Cliente / Quarto]" << endl;
        cout << "  5 - Excluir dado cadastrado" << endl;
        cout << "  0 - Encerrar o programa" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Digite a opção desejada: ";
        cin >> resposta;
        cout << "----------------------------------------------"<< endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (resposta == 0) {
            cout << "Encerrando o programa..." << endl;
            cout << "----------------------------------------------" << endl;
            break;
        }
        // Cadastrar pessoas
        else if (resposta == 1) {

            Pessoa *pessoa = new Pessoa("", 0);

            pessoa->set_dados();

            // Cadastra Cliente
            if (pessoa->get_tipo() == 1) {

                Cliente *cliente = new Cliente(pessoa->get_nome(), pessoa->get_tipo(), "", "", "");

                cliente->set_dados();
                hotel->lista_pessoas.adicionar(cliente);
            
            // Cadastra Funcionário
            } else if (pessoa->get_tipo() == 2) {

                Funcionario *funcionario = new Funcionario(pessoa->get_nome(), pessoa->get_tipo(), "", 0);
                funcionario->set_dados();
                cout << "Salário do funcionário: R$ " << funcionario->calcular_salario() << endl;

                hotel->lista_pessoas.adicionar(funcionario);

            }

        // Cadastrar quartos
        } else if (resposta == 2) {

            Quarto *quarto = new Quarto(0, 0);
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
            for (size_t i = 0; i < static_cast<size_t>(hotel->lista_pessoas.tamanho()); i++) {

                Cliente *cliente = dynamic_cast<Cliente *>(hotel->lista_pessoas[i]);

                if (cliente) {
                    cout << i << " - " << cliente->get_nome() << " (CPF: " << cliente->get_cpf() << ")" << endl;
                }
            }
            cout << endl;

            int idxCliente;

            cout << "Escolha o índice do cliente: ";
            cin >> idxCliente;
            cout << endl;
            
            if (idxCliente < 0 || idxCliente >= hotel->lista_pessoas.tamanho()) {
                cout << "Índice de cliente inválido!" << endl;
                continue;
            }
            
            Cliente *cliente = dynamic_cast<Cliente *>(hotel->lista_pessoas[idxCliente]);
            if (!cliente) {
                cout << "Selecione um cliente válido!" << endl;
                continue;
            }

            // Seleciona quarto
            cout << endl;
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
            cout << endl;
            // Seleciona datas
            int diasEstadia;
            cout << "Informe o número de dias de estadia: ";
            cin >> diasEstadia;

            if (diasEstadia <= 0) {
                cout << "Insira um número de dias válidos!" << endl;
                continue;
            }

            // Cria reserva
            Reserva *reserva = new Reserva(cliente, quarto, diasEstadia);
            
            cout << "Reserva cadastrada com sucesso!" << endl;
            cout << "Valor total da reserva: R$ " << reserva->calcular_valor_total() << endl;

            hotel->lista_reservas.adicionar(reserva);

        // Altera dado selecionado (Cliente ou Quarto)
        } else if (resposta == 4) {

            // Verifica se há clientes e quartos cadastrados
            if (hotel->lista_pessoas.vazia()) {
                cout << "Cadastre pelo menos um cliente!" << endl;
                continue;
            } if (hotel->lista_quartos.vazia()) {
                cout << "Cadastre pelo menos um quarto!" << endl;
                continue;
            }
            int dadoEscolhido;
            cout << "Selecione o tipo de dado a ser alterado [1 - Cliente] [2 - Quarto]: ";
            cin >> dadoEscolhido;
            cout << "----------------------------------------------" << endl;

            if (dadoEscolhido != 1 && dadoEscolhido != 2) {
                cout << "Opção inválida! Tente novamente." << endl;
                continue;
            } else if (dadoEscolhido == 1) {
            // Seleciona cliente
                cout << "Clientes cadastrados:" << endl;
                for (size_t i = 0; i < static_cast<size_t>(hotel->lista_pessoas.tamanho()); i++) {

                    Cliente *cliente = dynamic_cast<Cliente *>(hotel->lista_pessoas[i]);

                    if (cliente) {
                        cout << i << " - " << cliente->get_nome() << " (CPF: " << cliente->get_cpf() << ")" << endl;
                    }
                }
                cout << endl;

                int idxCliente;

                cout << "Escolha o índice do cliente: ";
                cin >> idxCliente;
                cout << endl;
                
                if (idxCliente < 0 || idxCliente >= hotel->lista_pessoas.tamanho()) {
                    cout << "Índice de cliente inválido!" << endl;
                    continue;
                }
                
                Cliente *cliente = dynamic_cast<Cliente *>(hotel->lista_pessoas[idxCliente]);
                if (!cliente) {
                    cout << "Selecione um cliente válido!" << endl;
                    continue;
                }

                cliente->set_dados();
            } else {

            // Seleciona quarto
                cout << endl;
                cout << "Quartos cadastrados:" << endl;
                for (int i = 0; i < hotel->lista_quartos.tamanho(); ++i) {
                    Quarto *q = hotel->lista_quartos[i];
                    cout << i << " - Quarto " << q->get_numero() << " (Tipo: " << q->get_tipo() << ")" << endl;
                }
                int idxQuarto;
                cout << "Escolha o índice do quarto: ";
                cin >> idxQuarto;
                Quarto *quarto = hotel->lista_quartos[idxQuarto];
                if (!quarto) {
                    cout << "Índice de quarto inválido!" << endl;
                    continue;
                }
                
                quarto->set_dados();
            
            }
            

        } else if (resposta == 5) {

            // Verifica se há clientes e quartos cadastrados
            if (hotel->lista_pessoas.vazia()) {
                cout << "Cadastre pelo menos um cliente!" << endl;
                continue;
            } if (hotel->lista_quartos.vazia()) {
                cout << "Cadastre pelo menos um quarto!" << endl;
                continue;
            }
            int dadoEscolhido;
            cout << "Selecione o tipo de dado a ser alterado [1 - Cliente] [2 - Quarto]: ";
            cin >> dadoEscolhido;
            cout << "----------------------------------------------" << endl;

            if (dadoEscolhido != 1 && dadoEscolhido != 2) {
                cout << "Opção inválida! Tente novamente." << endl;
                continue;
            } else if (dadoEscolhido == 1) {
            // Seleciona cliente
                cout << "Clientes cadastrados:" << endl;
                for (size_t i = 0; i < static_cast<size_t>(hotel->lista_pessoas.tamanho()); i++) {

                    Cliente *cliente = dynamic_cast<Cliente *>(hotel->lista_pessoas[i]);

                    if (cliente) {
                        cout << i << " - " << cliente->get_nome() << " (CPF: " << cliente->get_cpf() << ")" << endl;
                    }
                }
                cout << endl;

                int idxCliente;

                cout << "Escolha o índice do cliente: ";
                cin >> idxCliente;
                cout << endl;
                
                if (idxCliente < 0 || idxCliente >= hotel->lista_pessoas.tamanho()) {
                    cout << "Índice de cliente inválido!" << endl;
                    continue;
                }
                
                Cliente *cliente = dynamic_cast<Cliente *>(hotel->lista_pessoas[idxCliente]);
                if (!cliente) {
                    cout << "Selecione um cliente válido!" << endl;
                    continue;
                }

                delete cliente;
                hotel->lista_pessoas.remover(idxCliente);
                cout << "Cliente removido com sucesso!" << endl;
            } else {

            // Seleciona quarto
                cout << endl;
                cout << "Quartos cadastrados:" << endl;
                for (int i = 0; i < hotel->lista_quartos.tamanho(); ++i) {
                    Quarto *q = hotel->lista_quartos[i];
                    cout << i << " - Quarto " << q->get_numero() << " (Tipo: " << q->get_tipo() << ")" << endl;
                }
                int idxQuarto;
                cout << "Escolha o índice do quarto: ";
                cin >> idxQuarto;
                Quarto *quarto = hotel->lista_quartos[idxQuarto];
                if (!quarto) {
                    cout << "Índice de quarto inválido!" << endl;
                    continue;
                }
                cout << endl;
                delete quarto;
                hotel->lista_quartos.remover(idxQuarto);
                cout << "Quarto removido com sucesso!" << endl;
            }
        
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }
    

    
    
    std::cout << "\nPrograma finalizado.\n";

    return 0;
}

