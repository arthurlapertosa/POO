/*
 * Cliente.cpp
 *
 *  Created on: 22 de set de 2019
 *      Author: rafaelamoreira
 */

#include "Cliente.h"

Cliente::Cliente(std::string nomeCliente, std::string cpf_cnpj, std::string endereco, std::string fone) {
	this->nomeCliente = nomeCliente;
	this->cpf_cnpj = cpf_cnpj;
	this->endereco = endereco;
	this->fone = fone;
}

Cliente::Cliente() {

}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

//Cliente::Cliente(const Cliente &other) {
//	// TODO Auto-generated constructor stub
//
//}

const std::string& Cliente::getCpfCnpj() const {
	return cpf_cnpj;
}

void Cliente::setCpfCnpj(const std::string &cpfCnpj) {
	cpf_cnpj = cpfCnpj;
}

const std::string& Cliente::getEndereco() const {
	return endereco;
}

void Cliente::setEndereco(const std::string &endereco) {
	this->endereco = endereco;
}

const std::string& Cliente::getFone() const {
	return fone;
}

void Cliente::setFone(const std::string &fone) {
	this->fone = fone;
}

const std::string& Cliente::getNomeCliente() const {
	return nomeCliente;
}

void Cliente::setNomeCliente(const std::string &nomeCliente) {
	this->nomeCliente = nomeCliente;
}

std::ostream& operator<<(std::ostream& out, const Cliente& obj)
{
	out << obj.nomeCliente << "\n" << obj.cpf_cnpj << "\n" << obj.endereco << "\n" << obj.fone << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Cliente& obj)
{
	in >> obj.nomeCliente;
	in >> obj.cpf_cnpj;
	in >> obj.endereco;
	in >> obj.fone;
	return in;
}
