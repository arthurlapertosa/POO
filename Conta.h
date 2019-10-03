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
	const Cliente& getCliente() const;
	const std::vector<Movimentacao> getMovimentacoes();
	int getNumConta() const;
	//static int getProximoNumConta();
	double getSaldo() const;

	//Seta o ponteiro pro cliente
	void setCliente(Cliente *newCliente);

	//methods
	bool debitar(double valor, std::string descricao);
	void creditar(double valor, std::string descricao);
	vector<Movimentacao> obterExtrato(std::string dataIni, std::string dataFim);
	vector<Movimentacao> obterExtrato(std::string dataIni);
	vector<Movimentacao> obterExtratoMesAtual();

	//Write the member variables to stream objects
	friend std::ostream& operator << (std::ostream& out, const Conta& obj);

	//Read data from stream object and fill it in member variables
	friend std::istream& operator >> (std::istream& in, Conta& obj);
};

#endif /* CONTA_H_ */
