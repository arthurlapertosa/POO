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

using namespace std;

class Conta {
private:
	int numConta;
	double saldo;
	Cliente cliente;
	std::vector<Movimentacao> movimentacoes;
	static int proximoNumConta;

public:
	Conta(Cliente cliente);
	virtual ~Conta();
	Conta(const Conta &other);

	const Cliente& getCliente() const;
	const std::vector<Movimentacao>& getMovimentacoes() const;
	int getNumConta() const;
	static int getProximoNumConta() const;
	double getSaldo() const;
};

#endif /* CONTA_H_ */
