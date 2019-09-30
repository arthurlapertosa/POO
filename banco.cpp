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

std::vector<Cliente> Banco::ClientesLista()
{
	return Clientes;
}

std::vector<Conta> Banco::ContasLista()
{
	return Contas;
}
