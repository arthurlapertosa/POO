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


class Interface {
private:
	Banco banco;
public:
	Interface(Banco &banco);
	Banco getBanco();
	void menu();
	void cadastrarCliente();
	void criarConta();
	void excluirCliente();
	void excluirConta();
	void depositar();
	virtual ~Interface();
};

#endif /* INTERFACE_H_ */
