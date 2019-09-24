/*
 * Cliente.h
 *
 *  Created on: 22 de set de 2019
 *      Author: rafaelamoreir
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>
#include <iostream>

using namespace std;

class Cliente {
private:
	std::string nomeCliente;
	std::string cpf_cnpj;
	std::string endereco;
	std::string fone;
public:
	//constructors
	Cliente(std::string nomeCliente, std::string cpf_cnpj, std::string endereco, std::string fone);
	Cliente();
	virtual ~Cliente();
	//Cliente(const Cliente &other);

	//getters and setters
	const std::string& getCpfCnpj() const;
	void setCpfCnpj(const std::string &cpfCnpj);
	const std::string& getEndereco() const;
	void setEndereco(const std::string &endereco);
	const std::string& getFone() const;
	void setFone(const std::string &fone);
	const std::string& getNomeCliente() const;
	void setNomeCliente(const std::string &nomeCliente);

};

#endif /* CLIENTE_H_ */
