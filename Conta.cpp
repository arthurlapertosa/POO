/*
 * Conta.cpp
 *
 *  Created on: 23 de set de 2019
 *      Author: rafaelamoreira
 */

#include "Conta.h"
#include "Cliente.h"
#include <ctime>

int Conta::proximoNumConta;

Conta::Conta(Cliente *clienteNovo) {
	this->saldo = 0.0;
	this->cliente = clienteNovo;
	this->numConta = Conta::proximoNumConta;
	Conta::proximoNumConta++;


}

Conta::~Conta() {
	// TODO Auto-generated destructor stub
}

//getters and setters

const Cliente& Conta::getCliente() const {
	return *cliente;
}

const std::vector<Movimentacao> Conta::getMovimentacoes() {
	return movimentacoes;
}

int Conta::getNumConta() const {
	return numConta;
}

double Conta::getSaldo() const {
	return saldo;
}

//methods

bool Conta::debitar(double valor, std::string descricao) {
	char debitoCredito = 'D';
	Movimentacao * mov = new Movimentacao(descricao, debitoCredito, valor);

	if (valor <= this->saldo) {
		this->saldo = this->saldo - valor;
		this->movimentacoes.push_back(* mov);

		delete mov;

		return true;
	} else {
		return false;
	}

}

bool Conta::creditar(double valor, std::string descricao){
	char debitoCredito = 'C';
	Movimentacao * mov = new Movimentacao(descricao, debitoCredito, valor);


	this->saldo = this->saldo + valor;
	this->movimentacoes.push_back(* mov);

	delete mov;

	return true;
}


vector<Movimentacao> Conta::obterExtrato(std::string dataIni, std::string dataFim) {
	time_t seconds;
	tm * curr_tm;
	char date_string[10];

	vector<Movimentacao> * extrato = new vector<Movimentacao>;
	for(std::size_t i=0; i< this->getMovimentacoes().size(); ++i) {

		//convert time_t to string
		seconds = this->getMovimentacoes()[i].getDataMov();
		time(&seconds);
		curr_tm = localtime(&seconds);
		strftime(date_string, 50, "%d/%m/%Y", curr_tm);
		std::string s(date_string);

		//date compare
		if(s >= dataIni) {
			if (s <= dataFim) {
				Movimentacao *mov = new Movimentacao( this->getMovimentacoes()[i].getDataMov(), this->getMovimentacoes()[i].getDescricao(), this->getMovimentacoes()[i].getDebitoCredito(), this->getMovimentacoes()[i].getValor());
				extrato->push_back(*mov);
			}
		}
	}

	return *extrato;
}

vector<Movimentacao> Conta::obterExtrato(std::string dataIni) {
	time_t seconds;
	tm * curr_tm;
	char date_string[10];

	vector<Movimentacao> * extrato = new vector<Movimentacao>;
	for(std::size_t i=0; i< this->getMovimentacoes().size(); ++i) {

		//convert time_t to string
		seconds = this->getMovimentacoes()[i].getDataMov();
		time(&seconds);
		curr_tm = localtime(&seconds);
		strftime(date_string, 50, "%d/%m/%Y", curr_tm);
		std::string s(date_string);

		//date compare
		if(s >= dataIni) {
			Movimentacao *mov = new Movimentacao( this->getMovimentacoes()[i].getDataMov(), this->getMovimentacoes()[i].getDescricao(), this->getMovimentacoes()[i].getDebitoCredito(), this->getMovimentacoes()[i].getValor());
			extrato->push_back(*mov);
			delete(mov);
		}
	}

	delete curr_tm;
	return *extrato;
}

vector<Movimentacao> Conta::obterExtratoMesAtual() {
	time_t seconds;
	tm * curr_tm;
	char date_string[10];


	//find current month
	time(&seconds);
	curr_tm = localtime(&seconds);
	strftime(date_string, 50, "%m", curr_tm);
	std::string mesAtual(date_string);


	vector<Movimentacao> * extrato = new vector<Movimentacao>;
	for(std::size_t i=0; i< this->getMovimentacoes().size(); ++i) {

		//convert time_t to string
		seconds = this->getMovimentacoes()[i].getDataMov();
		time(&seconds);
		curr_tm = localtime(&seconds);
		strftime(date_string, 50, "%m", curr_tm);
		std::string mes(date_string);

		//date compare
		if(mesAtual == mes) {
			Movimentacao *mov = new Movimentacao( this->getMovimentacoes()[i].getDataMov(), this->getMovimentacoes()[i].getDescricao(), this->getMovimentacoes()[i].getDebitoCredito(), this->getMovimentacoes()[i].getValor());
			extrato->push_back(*mov);
			delete(mov);

		}
	}

	return *extrato;
}

