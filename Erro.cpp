/*
 * Erro.cpp
 *
 *  Created on: 16 de nov de 2019
 *      Author: rafaelamoreira
 */

#include "Erro.h"
#include <iostream>
#include <string.h>

Erro::Erro(std::string message) {
	this->message = message;
}

Erro::~Erro() {
	// TODO Auto-generated destructor stub
}

std::string Erro::what() {
	return message;
}


