# 42 C++ Modules — From Basics to Advanced Object-Oriented Programming

![C++ Version](https://img.shields.io/badge/C%2B%2B-98-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS-lightgrey.svg)
![42 School](https://img.shields.io/badge/School-42%20Network-black.svg)

Este repositório centraliza todos os meus projetos da trilha de **C++ da 42 São Paulo**. O objetivo desta trilha é a transição da programação imperativa (em C) para a **Programação Orientada a Objetos (POO)**, utilizando estritamente o padrão **C++98**.

---

## 📌 Visão Geral dos Módulos

O repositório está organizado em 10 módulos (`cpp00` ao `cpp09`), cobrindo desde os conceitos mais básicos até estruturas de dados avançadas e algoritmos complexos.

| Módulo | Conceitos Chave | Projetos Destacados |
| :--- | :--- | :--- |
| **[CPP 00](./cpp00)** | Namespaces, Classes, Member functions, Streams | Megaphone, Lista telefônica (PhoneBook) |
| **[CPP 01](./cpp01)** | Alocação de memória (new/delete), Referências, Pointers to members | Sistema de zumbis, Harl (Simulador de logs) |
| **[CPP 02](./cpp02)** | Polimorfismo ad-hoc, Sobrecarga de operadores, Classe Canônica Fixed-point | Implementação de ponto fixo |
| **[CPP 03](./cpp03)** | Herança (Inheritance), encapsulamento | Robôs de batalha (ClapTrap, ScavTrap, FragTrap) |
| **[CPP 04](./cpp04)** | Polimorfismo de subtipo, Classes Abstratas, Interfaces | Sistema de Animais (Dog/Cat) e cérebros de memória |
| **[CPP 05](./cpp05)** | Tratamento de Exceções (Try/Catch), Formulários | Burocracia, Testes de formulários assinados |
| **[CPP 06](./cpp06)** | Conversão de tipos (Scalar casting, Serialization) | `static_cast`, `reinterpret_cast`, `dynamic_cast` |
| **[CPP 07](./cpp07)** | Templates de funções e classes | Funções genéricas de swap, min, max e arrays iteráveis |
| **[CPP 08](./cpp08)** | STL (Standard Template Library), Containers, Iteradores, Algoritmos | Buscas, gerenciamento de spans enormes |
| **[CPP 09](./cpp09)** | Algoritmos Avançados, Análise de Performance e Containers STL | Calculadora RPN, Algoritmo Ford-Johnson (`PmergeMe`) |

---

## 🛠️ Regras de Compilação Estritas (Padrão 42)

Todos os projetos foram desenvolvidos e testados seguindo as exigências rigorosas de C++ da 42:
* **Compilador:** `c++` ou `g++`
* **Flags de compilação obrigatórias:** `-Wall -Wextra -Werror -std=c++98`
* **Forma Canônica de Coplien:** Quase todas as classes implementam obrigatoriamente:
    1. Construtor padrão (Default constructor)
    2. Construtor de cópia (Copy constructor)
    3. Operador de atribuição de cópia (Copy assignment operator)
    4. Destrutor (Destructor)

---

## 🚀 Como Executar os Projetos

Cada exercício dentro dos módulos possui seu próprio `Makefile` independente.

1. Clone o repositório:
   ```bash
   git clone git@github.com:seu-usuario/cpp_master_repository.git
