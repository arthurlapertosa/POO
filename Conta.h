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
	virtual const Cliente& getCliente() const;
	virtual const std::vector<Movimentacao> getMovimentacoes();
	virtual int getNumConta() const;
	//static int getProximoNumConta();
	virtual double getSaldo() const;

	//Seta o ponteiro pro cliente
	virtual void setCliente(Cliente *newCliente);

	//methods
	virtual bool debitar(double valor, std::string descricao) = 0;
	virtual void creditar(double valor, std::string descricao) = 0;
	virtual vector<Movimentacao> obterExtrato(std::string dataIni, std::string dataFim);
	virtual vector<Movimentacao> obterExtrato(std::string dataIni);
	virtual vector<Movimentacao> obterExtratoMesAtual();

	virtual void write(std::ostream& out) const = 0;

	virtual void read(std::istream& in) = 0;

	//Qual o tipo da conta
	virtual string type() const = 0;
};

#endif /* CONTA_H_ */
