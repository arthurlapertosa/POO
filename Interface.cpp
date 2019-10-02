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

Interface::Interface(Banco &banco) {
	this->banco = banco;
}

Interface::~Interface() {
	// TODO Auto-generated destructor stub
}

Banco Interface::getBanco() {
	return this->banco;
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
	for(std::size_t i=0; i< this->banco.clientesLista().size(); i++) {
		std::cout<<"Nome: "  + this->banco.clientesLista()[i].getNomeCliente();
		std::cout<<"  CPF/CNPJ: "  + this->banco.clientesLista()[i].getCpfCnpj() << endl;
	}

	std::string cpf_cnpj;
	std::cout<<"Insira o CPF/CNPJ do Cliente para criar uma conta: ";
	getline(cin, cpf_cnpj);
	bool found = false;

	for(std::size_t i=0; i< this->banco.clientesLista().size(); i++) {
		if (cpf_cnpj.compare(this->banco.clientesLista()[i].getCpfCnpj())) {

			std::string nomeCliente = banco.clientesLista()[i-1].getNomeCliente();
			std::string endereco = banco.clientesLista()[i-1].getEndereco();
			std::string fone = banco.clientesLista()[i-1].getFone();

			found = true;
			this->banco.criarConta(*new Cliente(nomeCliente, cpf_cnpj, endereco, fone));
		}
	}

	if (!found) {

		std::cout<<"CPF/CNPJ nao encontrado. "<< endl;
	}


}

void Interface::excluirCliente(){
	for(std::size_t i=0; i< this->banco.clientesLista().size(); i++) {
		std::cout<<"Nome: "  + this->banco.clientesLista()[i].getNomeCliente();
		std::cout<<"  CPF/CNPJ: "  + this->banco.clientesLista()[i].getCpfCnpj() << endl;
	}

	std::string cpf_cnpj;
	std::cout<<"Insira o CPF/CNPJ do Cliente para excluir: ";
	getline(cin, cpf_cnpj);
	bool found = false;

	for(std::size_t i=0; i< this->banco.clientesLista().size(); i++) {
		if (cpf_cnpj.compare(this->banco.clientesLista()[i].getCpfCnpj())) {
			found = true;
			this->banco.deletaCliente(cpf_cnpj);
		}
	}

	if (!found) {

		std::cout<<"CPF/CNPJ nao encontrado. "<< endl;
	}


}

void Interface::excluirConta(){

	for (int i = 0; i < banco.contasLista().size(); i++) {
		std::cout <<"Numero da conta: " << banco.contasLista()[i].getNumConta() << ", Saldo: " << banco.contasLista()[i].getSaldo() << ", CPF do titular: " << banco.contasLista()[i].getCliente().getCpfCnpj()
				<< ", Nome do titular: " << banco.contasLista()[i].getCliente().getNomeCliente() << std::endl;
	}

	int numConta;
	std::cout<<"Insira o número da conta para excluir: ";
	cin >> numConta;
	bool found = false;

	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {
		if (numConta == this->banco.contasLista()[i].getNumConta()) {
			found = true;
			this->banco.deleteConta(numConta);
		}
	}

	if (!found) {

		std::cout<<"Numero da conta nao encontrado. "<< endl;
	}


}


void Interface::depositar() {
	for (int i = 0; i < banco.contasLista().size(); i++) {
		std::cout <<"Numero da conta: " << banco.contasLista()[i].getNumConta() << ", Saldo: " << banco.contasLista()[i].getSaldo() << ", CPF do titular: " << banco.contasLista()[i].getCliente().getCpfCnpj()
				<< ", Nome do titular: " << banco.contasLista()[i].getCliente().getNomeCliente() << std::endl;
	}

	int numConta;
	std::cout<<"Insira o número da conta para depositar: ";
	cin >> numConta;

	double valor;
	std::cout<<"Insira valor do deposito: ";
	cin >> valor;

	std::string descricao;
	std::cout<<"Insira a descricao do deposito: ";
	cin.ignore();
	getline(cin, descricao);

	bool found = false;

	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {
		if (numConta == this->banco.contasLista()[i].getNumConta()) {
			found = true;

			std::cout<<&banco.contasLista()[i];
			this->banco.contasLista()[i].creditar(valor, descricao);
			this->banco.printContas();
		}
	}


	if (!found) {

		std::cout<<"Numero da conta nao encontrado. "<< endl;
	}
}


