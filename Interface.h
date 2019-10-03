/*
 * Interface.h
 *
 *  Created on: Oct 2, 2019
 *      Author: thayanlima
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_
#include "Banco.h"
#include "Movimentacao.h"
#include "Cliente.h"
#include "Conta.h"
#include <vector>


class Interface {
private:
	Banco banco;
public:
	Interface(Banco &banco);
	Banco getBanco();
	void menu();
	void printarContas();
	void printarClientes();
	void printarExtrato(vector<Movimentacao> extrato);
	void cadastrarCliente();
	void criarConta();
	void excluirCliente();
	void excluirConta();
	void depositar();
	void sacar();
	void transferir();
	void cobrarTarifa();
	void cobrarCPMF();
	void obterSaldo();
	void obterExtrato();
	virtual ~Interface();
};

#endif /* INTERFACE_H_ */
