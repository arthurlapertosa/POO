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
#include <fstream>

using namespace std;

class Movimentacao {
private:
	time_t dataMov;
	std::string descricao;
	char debitoCredito;
	double valor;

public:
	Movimentacao();
	Movimentacao(std::string descricao, char debitoCredito, double valor);
	Movimentacao(time_t dataMov, std::string descricao, char debitoCredito, double valor);
	virtual ~Movimentacao();
	//Movimentacao(const Movimentacao &other);

	time_t getDataMov() const;
	char getDebitoCredito() const;
	const std::string& getDescricao() const;
	double getValor() const;

	//Write the member variables to stream objects
	friend std::ostream& operator << (std::ostream& out, const Movimentacao& obj);

	//Read data from stream object and fill it in member variables
	friend std::istream& operator >> (std::istream& in, Movimentacao& obj);

};

#endif /* MOVIMENTACAO_H_ */
