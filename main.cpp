

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include "Cliente.h"
#include "Movimentacao.h"
#include "Conta.h"
#include "banco.h"

int main(int argc, char* argv[]){

	Banco Itau("Itau");
	Cliente* cli = new Cliente("Rafa", "123", "BH", "123123");
	Itau.adicionaCliente(*cli);
	Itau.adicionaCliente(Cliente("Arthur", "06149", "BH", "10000"));

	Itau.criarConta(Cliente("Arthur", "06149", "BH", "10000"));
	Itau.criarConta(Cliente("Arthur", "06149", "BH", "10000"));
	Itau.criarConta(*new Cliente("Rafa", "123", "BH", "123123"));

	Itau.depositoConta(1, 350.0);

	Itau.printClientes();
	Itau.printContas();

	std::cout << std::endl;
	
	Itau.deleteConta(2);// deleta a conta 2
	Itau.deletaCliente("123"); //deleta, pois não tem conta associada
	Itau.deletaCliente("06149"); //Não deleta, pois tem conta associada

	Itau.printClientes();
	Itau.printContas();

	return 0;
}
