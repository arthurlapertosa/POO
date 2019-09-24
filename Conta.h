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
private:
	int numConta;
	double saldo;
	Cliente cliente;
	std::vector<Movimentacao> movimentacoes;
	static int proximoNumConta;
public:
	//constructors
	Conta(Cliente cliente);

	virtual ~Conta();
	//Conta(const Conta &other);

	//getters and setters
	const Cliente& getCliente() const;
	const std::vector<Movimentacao> getMovimentacoes();
	int getNumConta() const;
	//static int getProximoNumConta();
	double getSaldo() const;

	//methods
	bool debitar(double valor, std::string descricao);
	bool creditar(double valor, std::string descricao);
	vector<Movimentacao> obterExtrato(std::string dataIni, std::string dataFim);
	vector<Movimentacao> obterExtrato(std::string dataIni);
	vector<Movimentacao> obterExtratoMesAtual();
};

#endif /* CONTA_H_ */
