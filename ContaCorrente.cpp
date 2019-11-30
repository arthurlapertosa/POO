/*
 * ContaCorrente.cpp
 *
 *  Created on: 16 de nov de 2019
 *      Author: rafaelamoreira
 */

#include "ContaCorrente.h"
#include "Cliente.h"
#include "Erro.h"

ContaCorrente::ContaCorrente(Cliente * clienteNovo, double limiteCredito): Conta(clienteNovo) {
	this->limiteCredito = limiteCredito;
}

ContaCorrente::~ContaCorrente() {
	// TODO Auto-generated destructor stub
}

double ContaCorrente::getLimiteCredito()
{
	return this->limiteCredito;
}


bool ContaCorrente::debitar(double valor, std::string descricao) {
	bool transacaorealizada = false;
	char debitoCredito = 'D';
	Movimentacao * mov = new Movimentacao(descricao, debitoCredito, valor);

	if (this->saldo + this->limiteCredito >= valor) {
		this->saldo = this->saldo - valor;
		this->movimentacoes.push_back(* mov);
		transacaorealizada = true;
	} else {
		throw Erro("Saldo insuficiente");
	}

	delete mov;

	return transacaorealizada;
}

void ContaCorrente::creditar(double valor, std::string descricao)
{
}

//const Cliente& ContaCorrente::getCliente() const
//{
//	return *cliente;
//}
//
//const std::vector<Movimentacao> ContaCorrente::getMovimentacoes()
//{
//	return std::vector<Movimentacao>();
//}
//
//int ContaCorrente::getNumConta() const
//{
//	return 0;
//}
//
//double ContaCorrente::getSaldo() const
//{
//	return 0.0;
//}
//
//void ContaCorrente::setCliente(Cliente* newCliente)
//{
//}



//vector<Movimentacao> ContaCorrente::obterExtrato(std::string dataIni, std::string dataFim)
//{
//	return vector<Movimentacao>();
//}
//
//vector<Movimentacao> ContaCorrente::obterExtrato(std::string dataIni)
//{
//	return vector<Movimentacao>();
//}
//
//vector<Movimentacao> ContaCorrente::obterExtratoMesAtual()
//{
//	return vector<Movimentacao>();
//}
//
//double ContaCorrente::getLimiteCredito() {
//	return this->limiteCredito;
//}
