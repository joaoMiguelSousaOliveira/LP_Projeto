# Sistema para gerenciamento de Hotel

Este projeto implementa um sistema básico de gerenciamento de hotel em C++. Ele inclui funcionalidades CRUD (Create, Read, Update, Delete) para Clientes, Quartos, Reservas, Funcionários e Pagamentos.

## Estrutura do Projeto

- `include/`: Contém os arquivos de cabeçalho (`.hpp`) para as classes do projeto (e.g., `hotel.hpp`, `pessoa.hpp`, `quarto.hpp`, `cliente.hpp`, `funcionario.hpp`, `reserva.hpp`, `pagamento.hpp`, `lista.hpp`).

- `main.cpp`: Contém a lógica principal do programa, incluindo as funções CRUD e o menu de interação com o usuário.

## Relacionamento das classes
- A classe principal, que engloba o projeto, é "Hotel". A partir dessa classe principal o projeto se ramifica, complementando suas funcionalidades a partir de um sistema de classes filhas.



## Funcionalidades CRUD
Para algumas das classes, foram implementados CRUDs com algumas funcionalidades que auxiliam no sistema:

### Cliente

- **Adicionar Cliente**: Permite adicionar um novo cliente ao sistema.

- **Listar Clientes**: Exibe uma lista de todos os clientes cadastrados.

- **Atualizar Cliente**: Funcionalidade de exemplo para atualização de clientes.

- **Remover Cliente**: Permite remover um cliente existente pelo CPF.

### Funcionário

- **Adicionar Funcionário**: Permite adicionar um novo funcionário ao sistema.

- **Listar Funcionários**: Exibe uma lista de todos os funcionários cadastrados.

- **Atualizar Funcionário**: Funcionalidade de exemplo para atualização de funcionários.

- **Remover Funcionário**: Permite remover um funcionário existente pelo CPF.

### Quarto

- **Adicionar Funcionário**: Permite adicionar um novo funcionário ao sistema.

- **Listar Funcionários**: Exibe uma lista de todos os funcionários cadastrados.

- **Atualizar Funcionário**: Funcionalidade de exemplo para atualização de funcionários.

- **Remover Funcionário**: Permite remover um funcionário existente pelo CPF.

## Makefile

- **make** ou **make all**  
  Compila todos os arquivos-fonte e gera o executável `hotel`.  
  ```
  make
  ```
  - **make clean**  
  Remove o diretório `obj/` e o executável `hotel`, limpando todos os arquivos gerados.  
  ```
  make clean
  ```

  - **./hotel**  
  Executa o programa compilado.  
  ```
  ./hotel
  ```
