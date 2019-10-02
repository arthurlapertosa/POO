

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include "Interface.h"
#include "Banco.h"
#include "Cliente.h"
#include "Movimentacao.h"
#include "Conta.h"

using namespace std;

int main(int argc, char* argv[]){

	Banco *b = new Banco("Itau");
	Cliente* cli = new Cliente("Rafa", "123", "BH", "123123");
	b->adicionaCliente(*cli);
	b->adicionaCliente(*new Cliente("Arthur", "06149", "BH", "10000"));

	b->criarConta(*new Cliente("Arthur", "06149", "BH", "10000"));
	b->criarConta(*new Cliente("Rafa", "123", "BH", "123123"));
//
//	b->depositoConta(1, 300.0);
//	b->depositoConta(2, 300.0);

	Interface *i = new Interface(*b);

	i->getBanco().printContas();
	i->depositar();
	i->getBanco().printContas();


	return 0;
}
