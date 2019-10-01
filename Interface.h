/*
 * Interface.h
 *
 *  Created on: 30 de set de 2019
 *      Author: rafaelamoreira
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

class Interface {
public:
	Interface();
	void Menu();
	void cadastraCliente();
	void criaConta();
	void excluiCliente();
	void excluiConta();
	void efetuaSaque();
	void efetuaDeposito();
	void efetuaTransferencia();
	void cobraTarifa();
	void cobraCPMF();

	virtual ~Interface();
};

#endif /* INTERFACE_H_ */
