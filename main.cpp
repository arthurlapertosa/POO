

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
	Conta *conta = new Conta(*cli); // @suppress("Ambiguous problem")


	conta->creditar(900.0, "Salario");
	conta->creditar(500.0, "Salario");
	conta->creditar(200.0, "Salario");

	vector<Movimentacao> extrato = conta->obterExtratoMesAtual();

	for(std::size_t i=0; i< extrato.size(); ++i) {
		cout << extrato[i].getDataMov() << endl;
	}

	delete(conta);
	delete(cli);

	return 0;
}
