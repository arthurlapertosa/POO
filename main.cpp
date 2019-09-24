

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include "Cliente.h"
#include "Movimentacao.h"
#include "Conta.h"

int main(int argc, char* argv[]){

	Cliente *cli = new Cliente("Rafa", "123", "BH", "123123");
	Conta *conta = new Conta(*cli);
	Conta *conta2 = new Conta(*cli);
	Conta *conta3 = new Conta(*cli);

	cout << conta->getNumConta() << endl;
	cout << conta2->getNumConta() << endl;
	cout << conta3->getNumConta() << endl;


	conta->creditar(900.0, "Salario");
	conta->creditar(500.0, "Salario");
	conta->creditar(200.0, "Salario");

	vector<Movimentacao> extrato = conta->obterExtratoMesAtual();

	for(std::size_t i=0; i< extrato.size(); ++i) {
		cout << extrato[i].getValor() << " " << extrato[i].getDebitoCredito() << " " << extrato[i].getDataMov() << endl;
	}

	delete conta;
	delete conta2;
	delete conta3;
	delete cli;

	return 0;
}
