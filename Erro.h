/*
 * Erro.h
 *
 *  Created on: 16 de nov de 2019
 *      Author: rafaelamoreira
 */

#ifndef ERRO_H_
#define ERRO_H_

#include <iostream>
#include <string.h>

class Erro {
private:
	std::string message;
public:
	Erro(std::string message);
	virtual ~Erro();

	std::string what();
};

#endif /* ERRO_H_ */
