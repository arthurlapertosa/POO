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
	Interface(Banco Banco);
	void menu();
	void cadastrarCliente();
	void criarConta();
	virtual ~Interface();
};

#endif /* INTERFACE_H_ */
