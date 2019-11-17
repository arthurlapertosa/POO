/*
 * Conta.h
 *
 *  Created on: 23 de set de 2019
 *      Author: rafaelamoreira
 */

#ifndef CONTA_H_
#define CONTA_H_

#include "Cliente.h"
#include "Movimentacao.h"
#include <vector>

class Conta {
protected:
	int numConta;
	double saldo;
	Cliente *cliente;
	std::vector<Movimentacao> movimentacoes;
	static int proximoNumConta;
public:
	//constructors
	Conta();

	Conta(Cliente *clienteNovo);

	virtual ~Conta();
	//Conta(const Conta &other);

	//getters and setters
	virtual const Cliente& getCliente() const = 0;
	virtual const std::vector<Movimentacao> getMovimentacoes();
	virtual int getNumConta() const;
	//static int getProximoNumConta();
	virtual double getSaldo() const;

	//Seta o ponteiro pro cliente
	virtual void setCliente(Cliente *newCliente);

	//methods
	virtual bool debitar(double valor, std::string descricao);
	virtual void creditar(double valor, std::string descricao);
	virtual vector<Movimentacao> obterExtrato(std::string dataIni, std::string dataFim);
	virtual vector<Movimentacao> obterExtrato(std::string dataIni);
	virtual vector<Movimentacao> obterExtratoMesAtual();

//	//Write the member variables to stream objects
//	virtual friend std::ostream& operator << (std::ostream& out, const Conta& obj);
//
//	//Read data from stream object and fill it in member variables
//	virtual friend std::istream& operator >> (std::istream& in, Conta& obj);
};

#endif /* CONTA_H_ */
