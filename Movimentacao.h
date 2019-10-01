/*
 * Movimentacao.h
 *
 *  Created on: 22 de set de 2019
 *      Author: rafaelamoreira
 */

#ifndef MOVIMENTACAO_H_
#define MOVIMENTACAO_H_

#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Movimentacao {
private:
	time_t dataMov;
	std::string descricao;
	char debitoCredito;
	double valor;

public:
	Movimentacao(std::string descricao, char debitoCredito, double valor);
	Movimentacao(time_t dataMov, std::string descricao, char debitoCredito, double valor);
	virtual ~Movimentacao();
	//Movimentacao(const Movimentacao &other);

	time_t getDataMov() const;
	char getDebitoCredito() const;
	const std::string& getDescricao() const;
	double getValor() const;
};

#endif /* MOVIMENTACAO_H_ */
