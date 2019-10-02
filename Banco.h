#ifndef BANCO_H
#define BANCO_H
#include "Cliente.h"
#include "Conta.h"
#include <list>

using namespace std;

class Banco {
private:
	std::string nomeBanco;
	std::list<Cliente> clientes;
	std::vector<Conta> contas;

public:
	//Cria um banco com o nome "nomeB"
	Banco();
	Banco(std::string nomeB);

	//Adiciona um nome cliente
	void adicionaCliente(Cliente& novo);

	//Cria uma nova conta retorna true se criado e false se não criado
	bool criarConta(std::string cpf);

	//Checa se o cliente tem alguma conta
	bool possuiConta(std::string cpf);

	//Deleta um cliente PRECONDI��O: Cliente n�o possui conta
	void deletaCliente(std::string cpf);

	//Printa a lista de clientes
	void printClientes();

	//Printa a lista de contas
	void printContas();

	//Exclui uma conta
	void deleteConta(int numConta);

	//Faz um deposito em uma conta
	void depositoConta(int numConta, double valor);

	//Faz um saque em uma conta
	bool saqueConta(int numConta, double valor);

	//Faz uma transferência entre contas
	bool transferencia(int numContaOrigem, int numContaDestino, double valor);

	void cobrarTarifa();

	void cobrarCPMF();

	//Obtem a lista de clientes
	std::list<Cliente> clientesLista();

	//Obtem a lista de contas
	std::vector<Conta> contasLista();
};

#endif // BANCO_H
