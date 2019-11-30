/*
 * ContaPoupanca.cpp
 *
 *  Created on: 16 de nov de 2019
 *      Author: rafaelamoreira
 */

#include "ContaPoupanca.h"

ContaPoupanca::ContaPoupanca() : Conta()
{
	saldoDiaB = new SaldoDiaBase;
}

ContaPoupanca::ContaPoupanca(Cliente * clienteNovo): Conta(clienteNovo) {
	saldoDiaB = new SaldoDiaBase();
}

ContaPoupanca::~ContaPoupanca() {
	// TODO Auto-generated destructor stub
}

ContaPoupanca::ContaPoupanca(const ContaPoupanca &other) {
	// TODO Auto-generated constructor stub

}

bool ContaPoupanca::debitar(double valor, std::string descricao)
{
	bool transacaorealizada = false;
	char debitoCredito = 'D';
	Movimentacao* mov = new Movimentacao(descricao, debitoCredito, valor);

	if (this->saldo  >= valor) {
		this->saldo = this->saldo - valor;
		this->movimentacoes.push_back(*mov);
		transacaorealizada = true;
	}
	else {
		throw Erro("Saldo insuficiente");
	}

	delete mov;

	return transacaorealizada;
}

void ContaPoupanca::creditar(double valor, std::string descricao)
{
}

string ContaPoupanca::type() const
{
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

std::ostream& operator<<(std::ostream& out, const ContaPoupanca& obj)
{
	//Escreve o tipo da conta
	out << "P" << "\n";
	out << obj.numConta << "\n" << obj.saldo << "\n" << *obj.cliente << "\n" << obj.proximoNumConta << "\n" << obj.movimentacoes.size() << "\n";
	for (int i = 0; i < obj.movimentacoes.size(); i++) {
		out << obj.movimentacoes[i];
	}
	out << *(obj.saldoDiaB) << std::endl;
	std::cout << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, ContaPoupanca& obj)
{
	in >> obj.numConta;
	in >> obj.saldo;
	Cliente* novo = new Cliente;
	in >> *novo;
	obj.cliente = novo;
	in >> obj.proximoNumConta;
	int size;
	in >> size;
	for (int i = 0; i < size; i++) {
		Movimentacao* aux = new Movimentacao();
		in >> *aux;
		obj.movimentacoes.push_back(*aux);
		delete aux;
	}
	in >> *(obj.saldoDiaB);
	return in;
}

//const Cliente& ContaPoupanca::getCliente() const
//{
//	return *cliente;
//}
//
//const std::vector<Movimentacao> ContaPoupanca::getMovimentacoes()
//{
//	return std::vector<Movimentacao>();
//}
//
//int ContaPoupanca::getNumConta() const
//{
//	return 0;
//}
//
//double ContaPoupanca::getSaldo() const
//{
//	return 0.0;
//}
//
//void ContaPoupanca::setCliente(Cliente* newCliente)
//{
//}
//
//
//
//vector<Movimentacao> ContaPoupanca::obterExtrato(std::string dataIni, std::string dataFim)
//{
//	return vector<Movimentacao>();
//}
//
//vector<Movimentacao> ContaPoupanca::obterExtrato(std::string dataIni)
//{
//	return vector<Movimentacao>();
//}
//
//vector<Movimentacao> ContaPoupanca::obterExtratoMesAtual()
//{
//	return vector<Movimentacao>();
//}
//


