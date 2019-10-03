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
#include <vector>

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

void Interface::printarContas() {
	for (int i = 0; i < banco.contasLista().size(); i++) {
		std::cout <<"Numero da conta: " << banco.contasLista()[i].getNumConta() << ", Saldo: " << banco.contasLista()[i].getSaldo() << ", CPF do titular: " << banco.contasLista()[i].getCliente().getCpfCnpj()
				<< ", Nome do titular: " << banco.contasLista()[i].getCliente().getNomeCliente() << std::endl;
	}
}

void Interface::printarClientes() {
	for (auto i : this->banco.clientesLista()) {
		std::cout << "CPF: " << i.getCpfCnpj() << ", Nome: " << i.getNomeCliente() << ", Endereco: " << i.getEndereco() <<
			", Numero de telefone: " << i.getFone() << std::endl;
	}
	std::cout << std::endl;
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
	this->printarClientes();

	std::string cpf_cnpj;
	std::cout<<"Insira o CPF/CNPJ do Cliente para criar uma conta: ";
	getline(cin, cpf_cnpj);
	bool found = false;


	for (auto i : this->banco.clientesLista()) {
		if (cpf_cnpj.compare(i.getCpfCnpj())) {
			found = true;
			this->banco.criarConta(cpf_cnpj);
		}
	}

	if (!found) {

		std::cout<<"CPF/CNPJ nao encontrado. "<< endl;
	}


}

void Interface::excluirCliente(){
	std::string cpf_cnpj;
	std::cout<<"Insira o CPF/CNPJ do Cliente para excluir: ";
	getline(cin, cpf_cnpj);
	bool found = false;


	for (auto i : this->banco.clientesLista()) {
		if (cpf_cnpj.compare(i.getCpfCnpj())) {
			found = true;
			this->banco.deletaCliente(cpf_cnpj);
		}
	}

	if (!found) {

		std::cout<<"CPF/CNPJ nao encontrado. "<< endl;
	}


}

void Interface::excluirConta(){

	this->printarContas();

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
	this->printarContas();

	int numConta;
	std::cout<<"Insira o número da conta para depositar: ";
	cin >> numConta;

	double valor;
	std::cout<<"Insira valor do deposito: ";
	cin >> valor;

	bool found = false;

	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {
		if (numConta == this->banco.contasLista()[i].getNumConta()) {
			found = true;
			this->banco.depositoConta(numConta, valor);
			break;
		}
	}


	if (!found) {

		std::cout<<"Numero da conta nao encontrado. "<< endl;
	}
}

void Interface::sacar() {

	this->printarContas();

	int numConta;
	std::cout<<"Insira o número da conta para sacar: ";
	cin >> numConta;

	double valor;
	std::cout<<"Insira valor do saque: ";
	cin >> valor;

	bool found = false;

	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {
		if (numConta == this->banco.contasLista()[i].getNumConta()) {
			found = true;
			if (!this->banco.saqueConta(numConta, valor)) {
				cout << "Saldo insuficiente." << endl;
			}
			break;
		}
	}


	if (!found) {

		std::cout<<"Numero da conta nao encontrado. "<< endl;
	}
}

void Interface::transferir() {

	this->printarContas();

	int numContaOrigem;
	std::cout<<"Insira o número da conta de origem: ";
	cin >> numContaOrigem;

	int numContaDestino;
	std::cout<<"Insira o número da conta de destino: ";
	cin >> numContaDestino;

	double valor;
	std::cout<<"Insira valor da transferencia: ";
	cin >> valor;


	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {

		if (!this->banco.transferencia(numContaOrigem, numContaDestino, valor)) {
			cout << "Não foi possivel realizar a transferencia." << endl;
		}

		break;
	}

}

void Interface::cobrarTarifa() {
	this->banco.cobrarTarifa();
	std::cout<<"Tarifa cobrada." << endl;
}

void Interface::cobrarCPMF() {
	this->banco.cobrarCPMF();
	std::cout<<"CPMF cobrada." << endl;
}

void Interface::obterSaldo() {

	this->printarContas();

	int numConta;
	std::cout<<"Insira o número da conta para obter saldo: ";
	cin >> numConta;
	bool found = false;

	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {
		if (numConta == this->banco.contasLista()[i].getNumConta()) {
			found = true;
			cout << "Saldo: ";
			cout << this->banco.contasLista()[i].getSaldo()<< endl;
		}
	}

	if (!found) {

		std::cout<<"Numero da conta nao encontrado. "<< endl;
	}


}

void Interface::obterExtrato() {

	this->printarContas();

	int numConta;
	std::cout<<"Insira o número da conta para obter extrato: ";
	cin >> numConta;

	int tipo = 0;
	std::cout<<"Tipo de extrato: " << endl;
	std::cout<<"1. Mes atual" << endl;
	std::cout<<"2. A partir de uma data" << endl;
	std::cout<<"3. Entre duas datas" << endl;
	std::cout<<"4. Sair" << endl;

	while (tipo != 1 && tipo != 2 && tipo != 3 && tipo != 4){
		std::cout<<"Selecione a opção do menu: ";
		cin >> tipo;
	}




	bool found = false;

	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {
		if (numConta == this->banco.contasLista()[i].getNumConta()) {
			found = true;
			vector<Movimentacao> extrato;
			std::string dataIniStr;
			std::string dataFimStr;

			switch(tipo) {
			case 1:
				extrato = this->banco.contasLista()[i].obterExtratoMesAtual();
				//variaveis para converter time_t to string
				time_t seconds;
				tm * curr_tm;
				char date_string[10];

				this->printarExtrato(extrato);
				break;
			case 2:
				std::cout<<"Insira a data inicial (formato dd/mm/yyyy): ";
				cin >> dataIniStr;
				extrato = this->banco.contasLista()[i].obterExtrato(dataIniStr);

				this->printarExtrato(extrato);
				break;
			case 3:

				std::cout<<"Insira a data inicial (formato dd/mm/yyyy): ";
				cin >> dataIniStr;
				std::cout<<"Insira a data final (formato dd/mm/yyyy): ";
				cin >> dataFimStr;
				extrato = this->banco.contasLista()[i].obterExtrato(dataIniStr, dataFimStr);

				this->printarExtrato(extrato);
				break;
//			case 4:
//				return;

			}
		}
	}

	if (!found) {

		std::cout<<"Numero da conta nao encontrado. "<< endl;
	}


}


void Interface::printarExtrato(vector<Movimentacao> extrato) {
	time_t seconds;
	tm * curr_tm;
	char date_string[10];
	for(std::size_t j=0; j< extrato.size(); j++) {

		std::cout << extrato[j].getDescricao();
		std::cout << " ";
		std::cout << extrato[j].getValor();
		std::cout << " ";

		//convert time_t to string
		seconds = extrato[j].getDataMov();
		time(&seconds);
		curr_tm = localtime(&seconds);
		strftime(date_string, 50, "%d/%m/%Y %H:%M", curr_tm);
		std::string s(date_string);

		std::cout << date_string;
		std::cout << " ";
		std::cout << extrato[j].getDebitoCredito() << endl;

	}
}


