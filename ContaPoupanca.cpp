/*
 * ContaPoupanca.cpp
 *
 *  Created on: 16 de nov de 2019
 *      Author: rafaelamoreira
 */

#include "ContaPoupanca.h"
#include "SaldoDiaBase.h"
#include "Erro.h"

ContaPoupanca::ContaPoupanca(Cliente * clienteNovo): Conta(clienteNovo) {

}

ContaPoupanca::ContaPoupanca() : Conta() {

}

ContaPoupanca::~ContaPoupanca() {
	// TODO Auto-generated destructor stub
}

string ContaPoupanca::type() const {
	return "P";
}

void ContaPoupanca::write(std::ostream& out) const
{
	out << *this;
}

void ContaPoupanca::read(std::istream& in)
{
	in >> *this;
}


vector<SaldoDiaBase> ContaPoupanca::getSaldoDiaBase() {
	return this->saldoDiaB;

}

std::ostream& operator<<(std::ostream& out, const ContaPoupanca& obj)
{
	//Escreve o tipo da conta
	out << "P" << "\n";

	out << obj.numConta << "\n" << obj.saldo << "\n" << *obj.cliente << "\n" << obj.proximoNumConta << "\n" << obj.movimentacoes.size()<< endl;
	for (int i = 0; i < obj.movimentacoes.size(); i++) {
		out << obj.movimentacoes[i];
	}
	out << obj.saldoDiaB.size() << std::endl;
	for (int i = 0; i < obj.saldoDiaB.size(); i++) {
		out << obj.saldoDiaB[i];
	}
	out << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, ContaPoupanca& obj) {
	in >> obj.numConta;
	in >> obj.saldo;
	Cliente* novo = new Cliente;
	in >> *novo;
	obj.cliente = novo;
	in >> obj.proximoNumConta;
	int size, size1;
	in >> size;
	for (int i = 0; i < size; i++) {
		Movimentacao* aux = new Movimentacao();
		in >> *aux;
		obj.movimentacoes.push_back(*aux);
		delete aux;
	}

	in >> size1;
	for (int i = 0; i < size1; i++) {
		SaldoDiaBase* aux = new SaldoDiaBase();
		in >> *aux;
		obj.saldoDiaB.push_back(*aux);
		delete aux;
	}

	return in;
}


bool ContaPoupanca::debitar(double valor, std::string descricao) {
	bool transacaorealizada = false;
	char debitoCredito = 'D';
	Movimentacao* mov = new Movimentacao(descricao, debitoCredito, valor);

	this->movimentacoes.push_back(*mov);

	if (this->saldo >= valor) {
		this-> saldo -= valor;
		transacaorealizada = true;
	} else {
		throw Erro("Saldo insuficiente");
	}

	return transacaorealizada;
}

void ContaPoupanca::removeElemento(int elemento) {
	this->saldoDiaB.erase(saldoDiaB.begin()+ elemento);

}

void ContaPoupanca::adicionaElemento(SaldoDiaBase & elemento) {
	this->saldoDiaB.push_back(elemento);
}

void ContaPoupanca::creditar(double valor, std::string descricao) {

	Movimentacao* mov = new Movimentacao(descricao, 'C', valor);

	this->saldo += valor;
    this->movimentacoes.push_back(*mov);

	time_t now = time(0);
    tm *ltm = localtime(&now);
    int hoje = ltm->tm_mday;//data do dia em que a transação é realizada;

    if (hoje > 28) {
    	hoje = 1;
    }
    bool existe = false;
	for (int i = 0; i < this->saldoDiaB.size(); i++) {
        if (this->saldoDiaB[i].getDiaBase() == hoje && this->saldoDiaB[i].getSaldoDiaBase() == hoje ) {
        	existe = true;
        }
    }
	if (!existe) {
        SaldoDiaBase novo(1, valor);
        this->adicionaElemento(novo);
	}

}




