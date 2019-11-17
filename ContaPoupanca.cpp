/*
 * ContaPoupanca.cpp
 *
 *  Created on: 16 de nov de 2019
 *      Author: rafaelamoreira
 */

#include "ContaPoupanca.h"

ContaPoupanca::ContaPoupanca(Cliente * clienteNovo): Conta(clienteNovo) {

}

ContaPoupanca::~ContaPoupanca() {
	// TODO Auto-generated destructor stub
}

ContaPoupanca::ContaPoupanca(const ContaPoupanca &other) {
	// TODO Auto-generated constructor stub

}

bool ContaPoupanca::debitar(double valor, std::string descricao)
{
	return false;
}

const Cliente& ContaPoupanca::getCliente() const
{
	return *cliente;
}

const std::vector<Movimentacao> ContaPoupanca::getMovimentacoes()
{
	return std::vector<Movimentacao>();
}

int ContaPoupanca::getNumConta() const
{
	return 0;
}

double ContaPoupanca::getSaldo() const
{
	return 0.0;
}

void ContaPoupanca::setCliente(Cliente* newCliente)
{
}

void ContaPoupanca::creditar(double valor, std::string descricao)
{
}

vector<Movimentacao> ContaPoupanca::obterExtrato(std::string dataIni, std::string dataFim)
{
	return vector<Movimentacao>();
}

vector<Movimentacao> ContaPoupanca::obterExtrato(std::string dataIni)
{
	return vector<Movimentacao>();
}

vector<Movimentacao> ContaPoupanca::obterExtratoMesAtual()
{
	return vector<Movimentacao>();
}

