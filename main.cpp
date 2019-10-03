

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

//	Banco *b = new Banco("Itau");
//	Cliente* cli = new Cliente("Rafa", "123", "BH", "123123");
//	b->adicionaCliente(*cli);
//	b->adicionaCliente(*new Cliente("Arthur", "06149", "BH", "10000"));
//
//	b->criarConta("06149");
//	b->criarConta("123");
////
////	b->depositoConta(1, 300.0);
////	b->depositoConta(2, 300.0);
//
//	Interface *i = new Interface(*b);
//
//	i->getBanco().printContas();
//	i->depositar();
//	i->getBanco().printContas();
//
//
	//Movimentacao a("Teste", 'd', 138.2);
	//std::ofstream out("students.txt");
	//out << a;

	//Movimentacao b;
	//std::ifstream in("students.txt");
	//in >> b;
	//std::cout << b.getDescricao() << endl;
	//Conta a(new Cliente("Arthur", "061", "BH", "3296"));
	//a.creditar(138.0, "Teste");
	//a.creditar(300.0, "Teste2");
	//std::ofstream out("test.txt");
	//out << a;

	//Conta b;
	//std::ifstream in("test.txt");
	//in >> b;

	Banco itau("Itau");
	itau.adicionaCliente(*new Cliente("Arthur", "061", "BH", "3296"));
	itau.adicionaCliente(*new Cliente("Rafa", "123", "BH", "9873"));
	itau.adicionaCliente(*new Cliente("Rafa2", "1234", "BH", "99873"));
	itau.criarConta("061");
	itau.criarConta("123");
	itau.depositoConta(0, 300.0);
	itau.depositoConta(1, 270.0);
	itau.cobrarCPMF();
	
	itau.writeFile();

	Banco b;
	b.readFile();
	b.printContas();
	b.printClientes();
	for (auto& i : b.clientes) {
		i.setEndereco("Mudou!");
	}
	b.printContas();
	b.printClientes();
	return 0;
}
