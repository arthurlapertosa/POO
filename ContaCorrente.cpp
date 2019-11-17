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

double ContaCorrente::getLimiteCredito() {
	return this->limiteCredito;
}
