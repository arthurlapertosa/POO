

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>

#include "Banco.h"
#include "Cliente.h"
#include "Movimentacao.h"
#include "Conta.h"

using namespace std;

int main(int argc, char* argv[]){

	Banco Itau("Itau");
	Cliente* cli = new Cliente("Rafa", "123", "BH", "123123");
	Itau.adicionaCliente(*cli);
	Itau.adicionaCliente(*new Cliente("Arthur", "06149", "BH", "10000"));

	Itau.criarConta("06149");
	Itau.criarConta("06149");
	Itau.criarConta("123");

	Itau.depositoConta(1, 300.0);
	Itau.depositoConta(2, 300.0);

	Itau.printClientes();
	Itau.printContas();
	//Itau.cobrarCPMF();

	//Itau.printContas();
	//for (auto &i : Itau.clientes) {  // Só funciona se deixar o atributo "clientes" como público na classe conta (para testar se a mudança de um atributo do cliente, muda também na conta dele)
	//	i.setEndereco("New address");
	//}
	std::cout << std::endl;

	Itau.deleteConta(2);// deleta a conta 2
	Itau.deletaCliente("123"); //deleta, pois n�o tem conta associada
	Itau.deletaCliente("06149"); //N�o deleta, pois tem conta associada

	Itau.printClientes();
	Itau.printContas();

	return 0;
}
