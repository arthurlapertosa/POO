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
#include "Erro.h"
#include "SaldoDiaBase.h"
class ContaPoupanca: public Conta {
protected:
	vector<SaldoDiaBase> saldoDiaB;

public:
	ContaPoupanca();
	ContaPoupanca(Cliente * clienteNovo);
	virtual ~ContaPoupanca();

	bool debitar(double valor, std::string descricao) override;
	//methods
	void creditar(double valor, std::string descricao) override;

	void adicionaElemento(SaldoDiaBase &novo );
	void removeElemento(int elemento);

	//Write the member variables to stream objects
	friend std::ostream& operator << (std::ostream& out, const ContaPoupanca& obj);

	//Read data from stream object and fill it in member variables
	friend std::istream& operator >> (std::istream& in, ContaPoupanca& obj);

	string type() const override;

	virtual void write(std::ostream& out) const override;

	virtual void read(std::istream& in) override;

	////getters and setters
	//const Cliente& getCliente() const override;
	//const std::vector<Movimentacao> getMovimentacoes() override;
	//int getNumConta() const override;
	////static int getProximoNumConta();
	//double getSaldo() const override;

	////Seta o ponteiro pro cliente
	//void setCliente(Cliente *newCliente) override;


	//vector<Movimentacao> obterExtrato(std::string dataIni, std::string dataFim) override;
	//vector<Movimentacao> obterExtrato(std::string dataIni) override;
	//vector<Movimentacao> obterExtratoMesAtual() override;
};

#endif /* CONTAPOUPANCA_H_ */
