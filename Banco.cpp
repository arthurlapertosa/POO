#include "Banco.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"

Banco::Banco() {

}

Banco::Banco(std::string nomeB) {
	nomeBanco = nomeB;
}

void Banco::adicionaCliente(Cliente& novo) {
	clientes.push_back(novo);
}

bool Banco::criarConta(std::string cpf, std::string tipo, double limite) {
	//passa pelos clientes ate achar o cliente com o cpf
	for (auto &i : clientes) {
		if (i.getCpfCnpj() == cpf) {
			Cliente* novo = &i;

			Conta * c = new ContaCorrente(novo, limite);

			if (tipo == "P") {
				Conta * c = new ContaPoupanca(novo);
			}

			contas.push_back(c);
			return true;
		}
	}
	return false;
	
}

bool Banco::possuiConta(std::string cpf) {
	//Passa por todas as contas no banco
	for (long unsigned int i = 0; i < contas.size(); i++) {
		if (contas[i]->getCliente().getCpfCnpj() == cpf) { //Achou o cliente
			return true;
		}
	}
	return false;
}

bool Banco::deletaCliente(std::string cpf) {
	if (!possuiConta(cpf)) {
		for (auto i = clientes.begin(); i != clientes.end(); i++) {
			if (i->getCpfCnpj() == cpf) {
				clientes.erase(i);
				break;
			}
		}
		return true;
	} else {
		return false;
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
	for (long unsigned int i = 0; i < contas.size(); i++) {
		std::cout <<"Numero da conta: " << contas[i]->getNumConta() << ", Saldo: " << contas[i]->getSaldo() << ", CPF do titular: " << contas[i]->getCliente().getCpfCnpj()
			<< ", Nome do titular: " << contas[i]->getCliente().getNomeCliente() << ", Endereco: " << contas[i]->getCliente().getEndereco() << std::endl;
	}
	std::cout << std::endl;
}

void Banco::deleteConta(int numConta) {
	//Passa por todas as contas
	for (long unsigned int i = 0; i < contas.size(); i++) {
		if (contas[i]->getNumConta() == numConta) { //Achou a conta
			contas.erase(contas.begin() + i);
			break;
		}
	}
}

void Banco::depositoConta(int numConta, double valor) {
	//Passa por todas as contas
	for (long unsigned int i = 0; i < contas.size(); i++) {
		if (contas[i]->getNumConta() == numConta) { //Achou a conta
			contas[i]->creditar(valor, "Deposito");
			break;
		}
	}
}

bool Banco::saqueConta(int numConta, double valor) {
	bool saqueRealizado = false;
	//Passa por todas as contas
	for (long unsigned int i = 0; i < contas.size(); i++) {
		if (contas[i]->getNumConta() == numConta) { //Achou a conta
			if (contas[i]->debitar(valor, "Saque")) {
				saqueRealizado = true;
			}
			break;
		}
	}
	return saqueRealizado;
}


bool Banco::transferencia(int numContaOrigem, int numContaDestino, double valor) {


	bool transferenciaRealizada = false;
	for (long unsigned int i = 0; i < contas.size(); i++) {
		if (contas[i]->getNumConta() == numContaOrigem) { //Achou a conta
			for (long unsigned int j = 0; j < contas.size(); j++) {
				if (contas[j]->getNumConta() == numContaDestino) {
					if (contas[i]->debitar(valor, "Transferencia (Origem)")) {
						contas[j]->creditar(valor, "Transferencia (Destino)");
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

double Banco::obterSaldo (int numConta) {
	double saldo;
	for (long unsigned int i = 0; i < contas.size(); i++) {
		if (contas[i]->getNumConta() == numConta) { //Achou a conta
			saldo = contas[i]->getSaldo();
		}
	}
	return saldo;
}

std::vector<Movimentacao> Banco::obterExtratoMesAtual(int numConta){
	vector<Movimentacao> extrato;
	for (long unsigned int i = 0; i < contas.size(); i++) {

		if (contas[i]->getNumConta() == numConta) { //Achou a conta
			extrato = contas[i]->obterExtratoMesAtual();
		}
	}

	return extrato;
}

std::vector<Movimentacao> Banco::obterExtrato(std::string dataIni, int numConta){
	vector<Movimentacao> extrato;
	for (long unsigned int i = 0; i < contas.size(); i++) {
		if (contas[i]->getNumConta() == numConta) { //Achou a conta
			extrato = contas[i]->obterExtrato(dataIni);
		}
	}
	return extrato;
}

std::vector<Movimentacao> Banco::obterExtrato(std::string dataIni, std::string dataFim, int numConta){
	vector<Movimentacao> extrato;
	for (long unsigned int i = 0; i < contas.size(); i++) {
		if (contas[i]->getNumConta() == numConta) { //Achou a conta
			extrato = contas[i]->obterExtrato(dataIni, dataFim);
		}
	}
	return extrato;
}

void Banco::cobrarTarifa() {
	for (long unsigned int i = 0; i < this->contas.size(); i++) {
		this->contas[i]->debitar(15.0, "Tarifa");
	}
}

void Banco::cobrarCPMF() {
	for (long unsigned int i = 0; i < contas.size(); i++) {
		contas[i]->debitar(contas[i]->getSaldo()*0.038, "Tarifa");
	}
}

std::list<Cliente> Banco::clientesLista() {
	return clientes;
}

std::vector<Conta*> Banco::contasLista() {
	return contas;
}

void Banco::writeFile()
{
//	std::ofstream out("banco.txt");
//	out << *this;
}

void Banco::readFile()
{
//	std::ifstream in("banco.txt");
//	if (in.is_open()){
//		contas.clear();
//		clientes.clear();
//		in >> *this;
//	}
}
//
//std::ostream& operator<<(std::ostream& out, const Banco& obj)
//{
//	// Primeiro escreve o nome do banco
//	string nomeBanco = obj.nomeBanco;
//	nomeBanco = replaceCharr(nomeBanco, ' ', '~');
//	out << nomeBanco << "\n";
//
//	//Começa escreve a lista de clientes
//	out << obj.clientes.size() << "\n";
//	for (auto i : obj.clientes) {
//		out << i << "\n";
//	}
//
//	//Escreve o vetor de contas
//	out << obj.contas.size() << "\n";
//	for (int i = 0; i < obj.contas.size(); i++) {
//		out << obj.contas[i] << "\n";
//	}
//	std::cout << std::endl;
//
//	return out;
//}

//std::istream& operator>>(std::istream& in, Banco& obj)
//{
//	//Primeiro pega o nome do banco
//	in >> obj.nomeBanco;
//	obj.nomeBanco = replaceCharr(obj.nomeBanco, '~', ' ');
//
//	//Pega os clientes
//	int numClientes;
//	in >> numClientes;
//	for (int i = 0; i < numClientes; i++) {
//		Cliente* novo = new Cliente;
//		in >> *novo;
//		obj.clientes.push_back(*novo);
//		delete novo;
//	}
//
//	//Pega as contas
//	int numContas;
//	in >> numContas;
//	for (int i = 0; i < numContas; i++) {
//		Conta* nova = new Conta;
//		in >> *nova;
//		std::string cpf;
//		cpf = nova->getCliente().getCpfCnpj();
//
//		//Acha o endereço do cliente associado para colocar na conta corretamente
//		for (auto& i : obj.clientes) {
//			if (i.getCpfCnpj() == cpf) {
//				Cliente* novo = &i;
//				nova->setCliente(novo);
//			}
//		}
//
//		obj.contas.push_back(*nova);
//		delete nova;
//	}
//
//}
