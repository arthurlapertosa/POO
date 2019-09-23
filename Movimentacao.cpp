/*
 * Movimentacao.cpp
 *
 *  Created on: 22 de set de 2019
 *      Author: rafaelamoreira
 */

#include "Movimentacao.h"

Movimentacao::Movimentacao(std::string descricao, char debitoCredito, double valor) {
	this->descricao = descricao;
	this->debitoCredito = debitoCredito;
	this->valor = valor;
	this->dataMov = time(0);

}

Movimentacao::~Movimentacao() {
	// TODO Auto-generated destructor stub
}

Movimentacao::Movimentacao(const Movimentacao &other) {
	// TODO Auto-generated constructor stub

}


time_t Movimentacao::getDataMov() const {
	return dataMov;
}

char Movimentacao::getDebitoCredito() const {
	return debitoCredito;
}

const std::string& Movimentacao::getDescricao() const {
	return descricao;
}

double Movimentacao::getValor() const {
	return valor;
}


