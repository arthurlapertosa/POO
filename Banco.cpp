#include "Banco.h"

Banco::Banco(std::string nomeB) {
	nomeBanco = nomeB;
}

void Banco::adicionaCliente(Cliente& novo) {
	clientes.push_back(novo);
}

void Banco::criarConta(Cliente& novaConta) {
	Conta* conta = new Conta(novaConta);
	contas.push_back(*conta);
	delete conta;
}

bool Banco::possuiConta(std::string cpf) {
	//Passa por todas as contas no banco
	for (int i = 0; i < contas.size(); i++) {
		if (contas[i].getCliente().getCpfCnpj() == cpf) { //Achou o cliente
			return true;
		}
	}
	return false;
}

void Banco::deletaCliente(std::string cpf) {
	if (!possuiConta(cpf)) {
		for (int i = 0; i < clientes.size(); i++) {
			if (clientes[i].getCpfCnpj() == cpf) {
				clientes.erase(clientes.begin() + i);
			}
		}
	}
}

void Banco::printClientes() {
	for (int i = 0; i < clientes.size(); i++) {
		std::cout << "CPF: " << clientes[i].getCpfCnpj() << ", Nome: " << clientes[i].getNomeCliente() << ", Endereco: " << clientes[i].getEndereco() <<
			", Numero de telefone: " << clientes[i].getFone() << std::endl;
	}
	std::cout << std::endl;
}

void Banco::printContas() {
	for (int i = 0; i < contas.size(); i++) {
		std::cout <<"Numero da conta: " << contas[i].getNumConta() << ", Saldo: " << contas[i].getSaldo() << ", CPF do titular: " << contas[i].getCliente().getCpfCnpj()
			<< ", Nome do titular: " << contas[i].getCliente().getNomeCliente() << std::endl;
	}
	std::cout << std::endl;
}

void Banco::deleteConta(int numConta) {
	//Passa por todas as contas
	for (int i = 0; i < contas.size(); i++) {
		if (contas[i].getNumConta() == numConta) { //Achou a conta
			contas.erase(contas.begin() + i);
			break;
		}
	}
}

void Banco::depositoConta(int numConta, double valor) {
	//Passa por todas as contas
	for (int i = 0; i < contas.size(); i++) {
		if (contas[i].getNumConta() == numConta) { //Achou a conta
			contas[i].creditar(valor, "Deposito");
			break;
		}
	}
}

bool Banco::saqueConta(int numConta, double valor) {
	bool saqueRealizado = false;
	//Passa por todas as contas
	for (int i = 0; i < contas.size(); i++) {
		if (contas[i].getNumConta() == numConta) { //Achou a conta
			if (contas[i].debitar(valor, "Saque")) {
				saqueRealizado = true;
			}
			break;
		}
	}
	return saqueRealizado;
}


bool Banco::transferencia(int numContaOrigem, int numContaDestino, double valor) {
	bool transferenciaRealizada = false;
	for (int i = 0; i < contas.size(); i++) {
		if (contas[i].getNumConta() == numContaOrigem) { //Achou a conta
			for (int j = 0; j < contas.size(); i++) {
				if (contas[j].getNumConta() == numContaDestino) {
					if (contas[i].debitar(valor, "Transferencia (Origem)")) {
						contas[j].creditar(valor, "Transferencia (Destino)");
						transferenciaRealizada = true;
					}
					break;

				}
			}
			break;
		}
	}

	return transferenciaRealizada;
}

void Banco::cobrarTarifa() {
	for (int i = 0; i < contas.size(); i++) {
		contas[i] = contas[i] - 15.00;
	}
}

void Banco::cobrarCPMF() {
	for (int i = 0; i < contas.size(); i++) {
			contas[i] = contas[i] - (contas[i]*0.038);
		}
}

std::vector<Cliente> Banco::clientesLista() {
	return clientes;
}

std::vector<Conta> Banco::contasLista() {
	return contas;
}
