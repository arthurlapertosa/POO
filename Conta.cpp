/*
 * Conta.cpp
 *
 *  Created on: 23 de set de 2019
 *      Author: rafaelamoreira
 */

#include "Conta.h"

Conta::Conta(Cliente cliente) {
	this->cliente = cliente;
	this->numConta = proximoNumConta;
	this->proximoNumConta = this->proximoNumConta++;
	this->saldo = 0.0;
}

Conta::~Conta() {
	// TODO Auto-generated destructor stub
}

Conta::Conta(const Conta &other) {
	// TODO Auto-generated constructor stub

}


const Cliente& Conta::getCliente() const {
	return cliente;
}

const std::vector<Movimentacao>& Conta::getMovimentacoes() const {
	return movimentacoes;
}

int Conta::getNumConta() const {
	return numConta;
}

static int Conta::getProximoNumConta() const {
	return proximoNumConta;
}

double Conta::getSaldo() const {
	return saldo;
}


