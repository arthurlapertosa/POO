/*
 * Interface.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: thayanlima
 */

#include "Interface.h"
#include "Banco.h"
#include "Movimentacao.h"
#include "Cliente.h"
#include "Conta.h"
#include <iostream>
#include <string>

using namespace std;

Interface::Interface(Banco banco) {

}

Interface::~Interface() {
	// TODO Auto-generated destructor stub
}

void Interface::menu(){
  while(1){
    std::cout<< "------------- " <<"MENU"<< " -------------" <<"\n\t\t\t";
    std::cout << "Escolha qual opção deseja realizar" << "\n\t\t\t";
    std::cout << "(1) - Cadastrar cliente" << "\n\t\t\t";
    std::cout << "(2) - Criar nova conta" << "\n\t\t\t";
    std::cout << "(3) - Excluir cliente" << "\n\t\t\t";
    std::cout << "(4) - Excluir conta" << "\n\t\t\t";
    std::cout << "(5) - Efetuar depósito" << "\n\t\t\t";
    std::cout << "(6) - Efetuar saque" << "\n\t\t\t";
    std::cout << "(7) - Efetuar transferência" << "\n\t\t\t";
    std::cout << "(8) - Cobrar tarifa" << "\n\t\t\t";
    std::cout << "(9) - Cobrar CPMF" << "\n\t\t\t";
    std::cout << "(10) - Obter saldo" << "\n\t\t\t";
    std::cout << "(11) - Obter extrato" << "\n\t\t\t";
    std::cout << "(12) - Listar clientes" << "\n\t\t\t";
    std::cout << "(13) - Listar contas" << "\n\t\t\t";
    std::cout << "(14) - Sair" << "\n\t\t\t";

    int entrada = 0;
    std::cin >> entrada;

    switch (entrada){
        case 0:
        	this->cadastrarCliente();
          break;
        case 1:
          break;
    }
 }
}


void Interface::cadastrarCliente(){
	std::string nomeCliente;
	std::string cpf_cnpj;
	std::string endereco;
	std::string fone;
	std::cout<<"Insira o nome do Cliente: ";
	getline(cin, nomeCliente);
	std::cout<<"Insira o CPF do Cliente: ";
	getline(cin, cpf_cnpj);
	std::cout<<"Insira o endereço do Cliente: ";
	getline(cin, endereco);
    std::cout<<"Insira o telefone do Cliente: ";
    getline(cin, fone);

    Cliente *cliente = new Cliente(nomeCliente, cpf_cnpj, endereco, fone);
    this->banco.adicionaCliente(*cliente);
}


void Interface::criarConta(){

}


