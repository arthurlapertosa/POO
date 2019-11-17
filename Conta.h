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
	virtual const std::vector<Movimentacao> getMovimentacoes() = 0;
	virtual int getNumConta() const = 0;
	//static int getProximoNumConta();
	virtual double getSaldo() const = 0;

	//Seta o ponteiro pro cliente
	virtual void setCliente(Cliente *newCliente) = 0;

	//methods
	virtual bool debitar(double valor, std::string descricao) = 0;
	virtual void creditar(double valor, std::string descricao) = 0;
	virtual vector<Movimentacao> obterExtrato(std::string dataIni, std::string dataFim) = 0;
	virtual vector<Movimentacao> obterExtrato(std::string dataIni) = 0;
	virtual vector<Movimentacao> obterExtratoMesAtual() = 0;

//	//Write the member variables to stream objects
//	virtual friend std::ostream& operator << (std::ostream& out, const Conta& obj);
//
//	//Read data from stream object and fill it in member variables
//	virtual friend std::istream& operator >> (std::istream& in, Conta& obj);
};

#endif /* CONTA_H_ */
