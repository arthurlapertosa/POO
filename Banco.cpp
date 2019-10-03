#include "Banco.h"

Banco::Banco() {

}

Banco::Banco(std::string nomeB) {
	nomeBanco = nomeB;
}

void Banco::adicionaCliente(Cliente& novo) {
	clientes.push_back(novo);
}

bool Banco::criarConta(std::string cpf) {
	//passa pelos clientes at� achar o cliente com o cpf
	for (auto &i : clientes) {
		if (i.getCpfCnpj() == cpf) {
			Cliente* novo = &i;
			Conta* conta = new Conta(novo);
			contas.push_back(*conta);
			return true;
		}
	}
	return false;
	
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
		for (auto i = clientes.begin(); i != clientes.end(); i++) {
			if (i->getCpfCnpj() == cpf) {
				clientes.erase(i);
				break;
			}
		}
	}
}

void Banco::printClientes() {
	for (auto i : clientes) {
		std::cout << "CPF: " << i.getCpfCnpj() << ", Nome: " << i.getNomeCliente() << ", Endereco: " << i.getEndereco() <<
			", Numero de telefone: " << i.getFone() << std::endl;
	}
	std::cout << std::endl;
}

void Banco::printContas() {
	for (int i = 0; i < contas.size(); i++) {
		std::cout <<"Numero da conta: " << contas[i].getNumConta() << ", Saldo: " << contas[i].getSaldo() << ", CPF do titular: " << contas[i].getCliente().getCpfCnpj()
			<< ", Nome do titular: " << contas[i].getCliente().getNomeCliente() << ", Endereco: " << contas[i].getCliente().getEndereco() << std::endl;
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
			for (int j = 0; j < contas.size(); j++) {
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
	for (int i = 0; i < this->contas.size(); i++) {
		this->contas[i].debitar(15.0, "Tarifa");
	}
}

void Banco::cobrarCPMF() {
	for (int i = 0; i < contas.size(); i++) {
		contas[i].debitar(contas[i].getSaldo()*0.038, "Tarifa");
	}
}

std::list<Cliente> Banco::clientesLista() {
	return clientes;
}

std::vector<Conta> Banco::contasLista() {
	return contas;
}
