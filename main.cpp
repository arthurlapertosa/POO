

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

	//Cliente *cli = new Cliente("Rafa", "123", "BH", "123123");
	//Conta *conta = new Conta(*cli);
	//Conta *conta2 = new Conta(*cli);
	//Conta *conta3 = new Conta(*cli);

	//cout << conta->getNumConta() << endl;
	//cout << conta2->getNumConta() << endl;
	//cout << conta3->getNumConta() << endl;


	//conta->creditar(900.0, "Salario");
	//conta->creditar(500.0, "Salario");
	//conta->creditar(200.0, "Salario");
	//conta->debitar (100.0, "Débito");

	//vector<Movimentacao> extrato = conta->obterExtratoMesAtual();

	//for(std::size_t i=0; i< extrato.size(); ++i) {
	//	cout << extrato[i].getValor() << " " << extrato[i].getDebitoCredito() << " " << extrato[i].getDataMov() <<  " Datas." << endl;
	//}

	//delete conta;
	//delete conta2;
	//delete conta3;
	//delete cli;
	Banco Um("abc");
	Cliente* cli = new Cliente("Rafa", "123", "BH", "123123");
	Um.adicionaCliente(*cli);
	Um.adicionaCliente(Cliente("Arthur", "12345", "BH", "10000"));
	Um.criarConta(Cliente("Arthur", "12345", "BH", "10000"));

	Um.deletaCliente("12345");
	Um.deletaCliente("123");

	std::vector<Cliente> Clientes = Um.ClientesLista();
	std::vector<Conta> Contas = Um.ContasLista();

	for (int i = 0; i < Clientes.size(); i++) {
		cout << Clientes[i].getCpfCnpj() << " " << Clientes[i].getNomeCliente() << endl;
	}
	for (int i = 0; i < Contas.size(); i++) {
		cout << Contas[i].getCliente().getCpfCnpj() << endl;
	}


	return 0;
}
