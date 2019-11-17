/*
 * ContaPoupanca.h
 *
 *  Created on: 16 de nov de 2019
 *      Author: rafaelamoreira
 */

#ifndef CONTAPOUPANCA_H_
#define CONTAPOUPANCA_H_

#include "Conta.h"
#include "Cliente.h"

class ContaPoupanca: public Conta {
public:
	ContaPoupanca(Cliente * clienteNovo);
	virtual ~ContaPoupanca();
	ContaPoupanca(const ContaPoupanca &other);

	bool debitar(double valor, std::string descricao) override;

	//getters and setters
	const Cliente& getCliente() const override;
	const std::vector<Movimentacao> getMovimentacoes() override;
	int getNumConta() const override;
	//static int getProximoNumConta();
	double getSaldo() const override;

	//Seta o ponteiro pro cliente
	void setCliente(Cliente *newCliente) override;

	//methods
	void creditar(double valor, std::string descricao) override;
	vector<Movimentacao> obterExtrato(std::string dataIni, std::string dataFim) override;
	vector<Movimentacao> obterExtrato(std::string dataIni) override;
	vector<Movimentacao> obterExtratoMesAtual() override;
};

#endif /* CONTAPOUPANCA_H_ */
