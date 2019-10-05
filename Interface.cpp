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
#include <algorithm>
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
	this->banco.readFile();
	while (1){

		std::cout<< "\n--------- MENU ----------" << endl;
		std::cout << "1. Cadastrar cliente" << endl;
		std::cout << "2. Criar nova conta" << endl;
		std::cout << "3. Excluir cliente" << endl;
		std::cout << "4. Excluir conta"  << endl;
		std::cout << "5. Efetuar depósito" << endl;
		std::cout << "6. Efetuar saque"  << endl;
		std::cout << "7. Efetuar transferência" << endl;
		std::cout << "8. Cobrar tarifa"  << endl;
		std::cout << "9. Cobrar CPMF"  << endl;
		std::cout << "10. Obter saldo" << endl;
		std::cout << "11. Obter extrato" << endl;
		std::cout << "12. Listar clientes" << endl;
		std::cout << "13. Listar contas" << endl;
		std::cout << "14. Sair" << endl;

		std::string stropcao = "0";
		int opcao = 0;

		while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6 && opcao != 7
				&& opcao != 8 && opcao != 9 && opcao != 10 && opcao != 11 && opcao != 12 && opcao != 13 && opcao != 14){
			std::cout << "Escolha uma opção válida: ";

			getline(cin, stropcao);
			try {
				opcao = stoi(stropcao);
			} catch (...) {
				opcao = 0;
			}

		}

		switch (opcao){
			case 1:
				this->cadastrarCliente();
				break;
			case 2:
				this->criarConta();
				break;
			case 3:
				this->excluirCliente();
				break;
			case 4:
				this->excluirConta();
				break;
			case 5:
				this->depositar();
				break;
			case 6:
				this->sacar();
				break;
			case 7:
				this->transferir();
				break;
			case 8:
				this->cobrarTarifa();
				break;
			case 9:
				this->cobrarCPMF();
				break;
			case 10:
				this->obterSaldo();
				break;
			case 11:
				this->obterExtrato();
				break;
			case 12:
				this->printarClientes();
				break;
			case 13:
				this->printarContas();
				break;
			case 14:
				this->banco.writeFile();
				return;

		}
	}


}

void Interface::printarContas() {
	std:: cout << "\nLista de Contas" << endl;
	for (long unsigned int i = 0; i < banco.contasLista().size(); i++) {
		std::cout <<"Numero da conta: " << banco.contasLista()[i].getNumConta() << ", Saldo: " << banco.contasLista()[i].getSaldo() << ", CPF do titular: " << banco.contasLista()[i].getCliente().getCpfCnpj()
				<< ", Nome do titular: " << banco.contasLista()[i].getCliente().getNomeCliente() << std::endl;
	}
}

void Interface::printarClientes() {
	std:: cout << "\nLista de Clientes" << endl;
	for (auto i : this->banco.clientesLista()) {
		std::cout << "CPF: " << i.getCpfCnpj() << ", Nome: " << i.getNomeCliente() << ", Endereco: " << i.getEndereco() <<
			", Numero de telefone: " << i.getFone() << std::endl;
	}
	std::cout << std::endl;
}

void Interface::cadastrarCliente(){

    std::cout<< "\n--------- CADASTRO DE CLIENTE ----------" << endl;
	std::string nomeCliente;
	std::string cpf_cnpj;
	std::string endereco;
	std::string fone;
	std::cout<<"Nome: ";
	getline(cin, nomeCliente);
	std::cout<<"CPF/CNPJ: ";
	getline(cin, cpf_cnpj);
	std::cout<<"Endereço: ";
	getline(cin, endereco);
    std::cout<<"Telefone: ";
    getline(cin, fone);

    //cria o objeto
    Cliente *cliente = new Cliente(nomeCliente, cpf_cnpj, endereco, fone);
    //chama a funcao pra adicionar no vetor de clientes de banco
    this->banco.adicionaCliente(*cliente);
    std::cout << "\nCadastro realizado com sucesso." << endl;

}

void Interface::criarConta(){
    std::cout<< "\n--------- CRIAR CONTA ----------" << endl;
	this->printarClientes();

	//pega o cpf/cnpj para associar o cliente a conta
	std::string cpf_cnpj;
	std::cout<<"Insira o CPF/CNPJ do Cliente para criar uma conta: ";
	getline(cin, cpf_cnpj);
	bool found = false;

	//for para percorrer o list de cliente e saber se o cpf/cnpj digitado e valido
	for (auto i : this->banco.clientesLista()) {
		if (cpf_cnpj.compare(i.getCpfCnpj()) == 0) {
			found = true;
			//chama a funcao pra criar a conta
			this->banco.criarConta(cpf_cnpj);
		}
	}

	//if para disparar a mensagem pro usuário da execucao da funcao
	if (found == false) {
		std::cout<<"\nCPF/CNPJ nao encontrado. Não foi possível criar a conta."<< endl;
	} else {
	    std::cout << "\nConta criada com sucesso." << endl;
	}


}

void Interface::excluirCliente(){
    std::cout<< "\n--------- EXCLUIR CLIENTE ----------" << endl;

	this->printarClientes();

	//pega o cpf/cnpj para excluir
	std::string cpf_cnpj;
	std::cout<<"Insira o CPF/CNPJ do Cliente para excluir: ";
	getline(cin, cpf_cnpj);
	bool found = false;

	//for para percorrer o list de cliente e saber se o cpf/cnpj digitado e valido
	for (auto i : this->banco.clientesLista()) {
		if (cpf_cnpj.compare(i.getCpfCnpj()) == 0) {
			found = true;

			//chama a funcao pra deletar o cliente (so sera deletado caso nao tenha conta associada)
			if (this->banco.deletaCliente(cpf_cnpj) == false) {
				cout << "\nO cliente possui uma conta associada, portanto não é possível deletá-lo." << endl;
				return;
			}
		}
	}

	//if para disparar a mensagem pro usuário da execucao da funcao
	if (found == false) {
		std::cout<<"\nCPF/CNPJ nao encontrado. Não foi possível deletar o cliente."<< endl;
	} else {
	    std::cout << "\nCliente deletado com sucesso." << endl;
	}



}

void Interface::excluirConta(){
    std::cout<< "\n--------- EXCLUIR CONTA ----------" << endl;

	this->printarContas();

	//pega o numero da conta e faz tratamento de erro caso o usuario nao digite um numero valido
	std::string numContaStr;
	int numConta;
	std::cout<<"\nInsira o número da conta para excluir: ";
	getline(cin, numContaStr);
	try {
		numConta = stoi(numContaStr);
	} catch (...) {
		std::cout<<"Número da conta inválido." << endl;
		return;
	}

	bool found = false;

	//for para percorrer o vector de conta e saber se o num da conta digitado e valido
	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {
		if (numConta == this->banco.contasLista()[i].getNumConta()) {
			found = true;
			this->banco.deleteConta(numConta);
		}
	}

	//if para disparar a mensagem pro usuário da execucao da funcao
	if (found == false) {
		std::cout<<"\nNumero da conta nao encontrado. Não foi possível deletar a conta."<< endl;
	} else {
	    std::cout << "\nConta deletada com sucesso." << endl;
	}


}

void Interface::depositar() {
    std::cout<< "\n--------- DEPÓSITO ----------" << endl;
	this->printarContas();

	//pega o numero da conta e faz tratamento de erro caso o usuario nao digite um numero valido
	std::string numContaStr;
	int numConta;
	std::cout<<"\nInsira o número da conta para depositar: ";
	getline(cin, numContaStr);
	try {
		numConta = stoi(numContaStr);
	} catch (...) {
		std::cout<<"Número da conta inválido." << endl;
		return;
	}

	//pega o valor e faz tratamento de erro caso o usuario nao digite um numero valido
	std::string valorStr;
	double valor;
	std::cout<<"Insira valor do deposito: ";
	getline(cin, valorStr);
	//substitui virgula por ponto quando necessário
	std::replace(valorStr.begin(), valorStr.end(), ',', '.' );
	try {
		valor = stod(valorStr);
		if (valor<=0) {
			std::cout<<"Valor inválido." << endl;
			return;
		}
	} catch (...) {
		std::cout<<"Valor inválido." << endl;
		return;
	}

	bool found = false;

	//for para percorrer o vector de conta e saber se o num da conta digitado e valido
	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {
		if (numConta == this->banco.contasLista()[i].getNumConta()) {
			found = true;
			//chama a funcao pra depositar na conta
			this->banco.depositoConta(numConta, valor);

			std::cout<<"\nDepósito realizado com sucesso." << endl;
			break;
		}
	}

	//if para disparar a mensagem pro usuário da execucao da funcao
	if (!found) {
		std::cout<<"Numero da conta nao encontrado. "<< endl;
	}
}

void Interface::sacar() {
    std::cout<< "\n--------- SAQUE ----------" << endl;

	this->printarContas();

	//pega o numero da conta e faz tratamento de erro caso o usuario nao digite um numero valido
	std::string numContaStr;
	int numConta;
	std::cout<<"\nInsira o número da conta para sacar: ";
	getline(cin, numContaStr);
	try {
		numConta = stoi(numContaStr);
	} catch (...) {
		std::cout<<"Número da conta inválido." << endl;
		return;
	}

	//pega o valor e faz tratamento de erro caso o usuario nao digite um numero valido
	std::string valorStr;
	double valor;
	std::cout<<"Insira valor do saque: ";
	getline(cin, valorStr);
	//substitui virgula por ponto quando necessário
	std::replace(valorStr.begin(), valorStr.end(), ',', '.' );
	try {
		valor = stod(valorStr);
		if (valor<=0) {
			std::cout<<"Valor inválido." << endl;
			return;
		}
	} catch (...) {
		std::cout<<"Valor inválido." << endl;
		return;
	}

	bool found = false;

	//for para percorrer o vector de conta e saber se o num da conta digitado e valido
	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {
		if (numConta == this->banco.contasLista()[i].getNumConta()) {
			found = true;
			//verifica se o saldo e suficiente para fazer o saque
			if (!this->banco.saqueConta(numConta, valor)) {
				cout << "\nSaldo insuficiente." << endl;
			} else {

				cout << "\nSaque realizado com sucesso." << endl;
			}
			break;
		}
	}

	//if para disparar a mensagem pro usuário da execucao da funcao
	if (!found) {
		std::cout<<"Numero da conta nao encontrado. "<< endl;
	}
}

void Interface::transferir() {
    std::cout<< "\n--------- TRANSFERENCIA ----------" << endl;

	this->printarContas();

	//pega o numero da conta e faz tratamento de erro caso o usuario nao digite um numero valido
	std::string numContaOrigemStr;
	int numContaOrigem;
	std::cout<<"\nInsira o número da conta de origem para transferir: ";
	getline(cin, numContaOrigemStr);
	try {
		numContaOrigem = stoi(numContaOrigemStr);
	} catch (...) {
		std::cout<<"Número da conta inválido." << endl;
		return;
	}

	//pega o numero da conta e faz tratamento de erro caso o usuario nao digite um numero valido
	std::string numContaDestinoStr;
	int numContaDestino;
	std::cout<<"Insira o número da conta de destino para transferir: ";
	getline(cin, numContaDestinoStr);
	try {
		numContaDestino = stoi(numContaDestinoStr);
	} catch (...) {
		std::cout<<"Número da conta inválido." << endl;
		return;
	}

	//pega o valor e faz tratamento de erro caso o usuario nao digite um numero valido
	std::string valorStr;
	double valor;
	std::cout<<"Insira valor da transferencia: ";
	getline(cin, valorStr);
	//substitui virgula por ponto quando necessário
	std::replace(valorStr.begin(), valorStr.end(), ',', '.' );
	try {
		valor = stod(valorStr);
		if (valor<=0) {
			std::cout<<"Valor inválido." << endl;
			return;
		}
	} catch (...) {
		std::cout<<"Valor inválido." << endl;
		return;
	}

	//for para percorrer o vector de conta e saber se o num da conta digitado e valido
	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {
		//verifica se o saldo e suficiente para fazer o saque
		if (!this->banco.transferencia(numContaOrigem, numContaDestino, valor)) {
			std::cout << "\nNão foi possivel realizar a transferencia." << endl;
		} else {
			std::cout<<"\nTransferência realizada com sucesso. " << endl;
		}

		break;
	}

}

void Interface::cobrarTarifa() {
	this->banco.cobrarTarifa();
	std::cout<<"\nTarifa cobrada com sucesso." << endl;
}

void Interface::cobrarCPMF() {
	this->banco.cobrarCPMF();
	std::cout<<"\nCPMF cobrada com sucesso." << endl;
}

void Interface::obterSaldo() {
    std::cout<< "\n--------- OBTER SALDO ----------" << endl;
	this->printarContas();

	//pega o numero da conta e faz tratamento de erro caso o usuario nao digite um numero valido
	std::string numContaStr;
	int numConta;
	std::cout<<"\nInsira o número da conta para obter saldo: ";
	getline(cin, numContaStr);
	try {
		numConta = stoi(numContaStr);
	} catch (...) {
		std::cout<<"Número da conta inválido." << endl;
		return;
	}

	bool found = false;

	//for para percorrer o vector de conta e saber se o num da conta digitado e valido
	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {
		if (numConta == this->banco.contasLista()[i].getNumConta()) {
			found = true;
			std::cout << "\nSaldo: ";
			//chama funcao para obter saldo
			std:: cout << this->banco.obterSaldo(numConta) << endl;
		}
	}

	//if para disparar a mensagem pro usuário da execucao da funcao
	if (!found) {
		std::cout<<"Numero da conta nao encontrado. "<< endl;
	}


}

void Interface::obterExtrato() {

	std::cout<<"\n------ Tipo de extrato ------" << endl;
	std::cout<<"1. Mes atual" << endl;
	std::cout<<"2. A partir de uma data" << endl;
	std::cout<<"3. Entre duas datas" << endl;
	std::cout<<"4. Sair" << endl;

	std::string stropcao = "0";
	int opcao = 0;

	//so sai do while quando digitar uma opcao dentre as citadas acima
	while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4){
		std::cout << "Escolha uma opção válida: ";

		getline(cin, stropcao);
		try {
			opcao = stoi(stropcao);
		} catch (...) {
			opcao = 0;
		}

	}

	//exibe as contas
	this->printarContas();

	//pega o numero da conta e faz tratamento de erro caso o usuario nao digite um numero valido
	std::string numContaStr;
	int numConta;
	std::cout<<"\nInsira o número da conta para obter o extrato: ";
	getline(cin, numContaStr);
	try {
		numConta = stoi(numContaStr);
	} catch (...) {
		std::cout<<"Número da conta inválido." << endl;
		return;
	}

	bool found = false;

	//for para percorrer o vector de conta e saber se o num da conta digitado e valido
	for(std::size_t i=0; i< this->banco.contasLista().size(); i++) {
		if (numConta == this->banco.contasLista()[i].getNumConta()) {
			found = true;
			vector<Movimentacao> extrato;
			std::string dataIniStr;
			std::string dataFimStr;
			struct tm result;

			switch(opcao) {
			case 1:
			    std::cout<< "\n--------- EXTRATO MES ATUAL ---------" << endl;

				extrato = this->banco.obterExtratoMesAtual(numConta);

				this->printarExtrato(extrato);
				break;
			case 2:
				std::cout<<"Insira a data inicial (formato dd/mm/yyyy): ";
				cin >> dataIniStr;
				cin.ignore();

				if (strptime(dataIniStr.c_str(), "%d/%m/%Y", &result) == NULL) {
					std::cout << "\nData inválida. " << endl;
					return;
				}

				extrato = this->banco.obterExtrato(dataIniStr, numConta);

			    std::cout<< "\n--------- EXTRATO PERÍODO ATUAL ---------" << endl;

				this->printarExtrato(extrato);
				break;
			case 3:
				std::cout<<"Insira a data inicial (formato dd/mm/yyyy): ";
				cin >> dataIniStr;
				cin.ignore();

				if (strptime(dataIniStr.c_str(), "%d/%m/%Y", &result) == NULL) {
					std::cout << "\nData inválida. " << endl;
					return;
				}

				std::cout<<"Insira a data final (formato dd/mm/yyyy): ";
				cin >> dataFimStr;
				cin.ignore();

				if (strptime(dataIniStr.c_str(), "%d/%m/%Y", &result) == NULL) {
					std::cout << "\nData inválida. " << endl;
					return;
				}

			    std::cout<< "\n--------- EXTRATO PERÍODO PASSADO ---------" << endl;

				extrato = this->banco.obterExtrato(dataIniStr, dataFimStr, numConta);

				this->printarExtrato(extrato);
				break;
			case 4:
				return;

			}
			break;
		}

	}

	//if para disparar a mensagem pro usuário da execucao da funcao
	if (!found) {
		std::cout<<"Numero da conta nao encontrado. "<< endl;
	}


}


void Interface::printarExtrato(vector<Movimentacao> extrato) {
	//variaveis para converter time_t para string
	time_t seconds;
	tm * curr_tm;
	char date_string[100];
	//percorre o vector de extrato para printar na tela
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


