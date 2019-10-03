/*
 * Movimentacao.cpp
 *
 *  Created on: 22 de set de 2019
 *      Author: rafaelamoreira
 */

#include "Movimentacao.h"

Movimentacao::Movimentacao()
{
	descricao = "";
	debitoCredito = 'n';
	valor = 0;
}

Movimentacao::Movimentacao(std::string descricao, char debitoCredito, double valor) {
	this->descricao = descricao;
	this->debitoCredito = debitoCredito;
	this->valor = valor;
	this->dataMov = time(0);

}

Movimentacao::Movimentacao(time_t dataMov, std::string descricao, char debitoCredito, double valor) {
	this->descricao = descricao;
	this->debitoCredito = debitoCredito;
	this->valor = valor;
	this->dataMov = dataMov;

}

Movimentacao::~Movimentacao() {
	// TODO Auto-generated destructor stub
}

//Movimentacao::Movimentacao(const Movimentacao &other) {
//	// TODO Auto-generated constructor stub
//
//}


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

std::ostream& operator<<(std::ostream& out, const Movimentacao& obj)
{
	out << obj.dataMov << "\n" << obj.descricao << "\n" << obj.debitoCredito << "\n" << obj.valor << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Movimentacao& obj)
{
	in >> obj.dataMov;
	in >> obj.descricao;
	in >> obj.debitoCredito;
	in >> obj.valor;
	return in;
}
