# Classes

```mermaid
classDiagram
    class Lista~T~ {
        -elementos: vector~T~
        +adicionar(elem: T) : void
        +remover(index: int) : void
        +exibir_todos() : void
    }

    class Hotel {
        +pessoas: Lista~Pessoa*~
        +quartos: Lista~Quarto*~
        +adicionar_pessoa(p: Pessoa) : void
        +adicionar_quarto(q: Quarto) : void
    }

    class Pessoa {
        +nome : string
        +tipo : string
        +set_dados() : void
        +get_nome() : string
        +get_tipo() : string
    }

    class Cliente {
        -cpf : string
        -telefone : string
        +set_dados() : void
        +get_cpf() : string
        +get_telefone() : string
    }

    class Funcionario {
        -cargo : string
        -numQuartos : int
        -salarioBase : double
        -bonusPorQuarto : double
        -bonusPorCargo : double
        +set_dados() : void
        +get_cargo() : string
        +get_numQuartos() : int
        +calcular_salario() : double
    }

    class Quarto {
        -numero : int
        -tipo: int
        #arCondicionado : bool
        #hidromassagem : bool
        #cafeIncluso : bool
        #almocoIncluso : bool
        #jantaIncluso : bool
        #estacionamento : bool
        #servicoQuarto : bool
        +*set_dados()* : void
        +*get_valor()* : double
        +get_numero() : int
        +get_tipo() : int
        +valor_diaria() : double
        *+~Quarto()*
    }

    class Suite {
        #arCondicionado : bool
        #cafeIncluso : bool
        #estacionamento : bool
        +set_dados() : void
        +get_valor() : double
        *+~Suite()*
    }

    class Quarto_Casal {
        #arCondicionado : bool
        #hidromassagem : bool
        #cafeIncluso : bool
        #estacionamento : bool
        #servicoQuarto : bool
        +set_dados() : void
        +get_valor() : double
        *+~Casal()*
    }

    class Presidencial {
        #arCondicionado : bool
        #hidromassagem : bool
        #cafeIncluso : bool
        #almocoIncluso : bool
        #jantaIncluso : bool
        #estacionamento : bool
        #servicoQuarto : bool
        +set_dados() : void
        +get_valor() : double
        *+~Presidencial()*
    }

    class Reserva {
        -cliente : Cliente
        -quarto : Quarto
        -data_entrada : time_t
        -data_saida : time_t
        +set_dados() : void
        +get_data_entrada() : time_t
        +get_data_saida() : time_t
        +calcular_valor_total() : double 
    }

    class Pagamento {
        -valor : double
        -metodo : string
        +set_dados() : void
        +exibir_dados() : void
    }

    %% Herança
    Pessoa --|> Cliente
    Pessoa --|> Funcionario

    Quarto --|> Suite
    Quarto --|> Quarto_Casal
    Quarto --|> Presidencial

    %% Composição
    Hotel --> Pessoa
    Hotel --> Quarto

    Cliente "1" -- "*" Reserva
    Quarto "1" -- "*" Reserva
    
    Reserva "1" --o "1" Pagamento
```
