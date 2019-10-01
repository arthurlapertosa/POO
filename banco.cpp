#include "banco.h"

Banco::Banco(std::string nomeB)
{
	nomeBanco = nomeB;
}

void Banco::adicionaCliente(Cliente& novo)
{
	Clientes.push_back(novo);
}

void Banco::criarConta(Cliente& novaConta)
{
	Conta* conta = new Conta(novaConta);
	Contas.push_back(*conta);
	delete conta;
}

bool Banco::possuiConta(std::string cpf)
{
	//Passa por todas as contas no banco
	for (int i = 0; i < Contas.size(); i++) {
		if (Contas[i].getCliente().getCpfCnpj() == cpf) { //Achou o cliente
			return true;
		}
	}
	return false;
}

void Banco::deletaCliente(std::string cpf)
{
	if (!possuiConta(cpf)) {
		for (int i = 0; i < Clientes.size(); i++) {
			if (Clientes[i].getCpfCnpj() == cpf) {
				Clientes.erase(Clientes.begin() + i);
			}
		}
	}
}

void Banco::printClientes()
{
	for (int i = 0; i < Clientes.size(); i++) {
		std::cout << "CPF: " << Clientes[i].getCpfCnpj() << ", Nome: " << Clientes[i].getNomeCliente() << ", Endereco: " << Clientes[i].getEndereco() <<
			", Numero de telefone: " << Clientes[i].getFone() << std::endl;
	}
	std::cout << std::endl;
}

void Banco::printContas()
{
	for (int i = 0; i < Contas.size(); i++) {
		std::cout <<"Numero da conta: " << Contas[i].getNumConta() << ", Saldo: " << Contas[i].getSaldo() << ", CPF do titular: " << Contas[i].getCliente().getCpfCnpj() 
			<< ", Nome do titular: " << Contas[i].getCliente().getNomeCliente() << std::endl;
	}
	std::cout << std::endl;
}

void Banco::deleteConta(int numConta)
{
	//Passa por todas as contas
	for (int i = 0; i < Contas.size(); i++) {
		if (Contas[i].getNumConta() == numConta) { //Achou a conta
			Contas.erase(Contas.begin() + i);
			break;
		}
	}
}

void Banco::depositoConta(int numConta, double valor)
{
	//Passa por todas as contas
	for (int i = 0; i < Contas.size(); i++) {
		if (Contas[i].getNumConta() == numConta) { //Achou a conta
			Contas[i].creditar(valor, "Deposito");
			break;
		}
	}
}

std::vector<Cliente> Banco::ClientesLista()
{
	return Clientes;
}

std::vector<Conta> Banco::ContasLista()
{
	return Contas;
}
