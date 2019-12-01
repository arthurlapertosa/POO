#ifndef BANCO_H
#define BANCO_H
#include "Cliente.h"
#include "Conta.h"
#include <list>
#include <fstream>
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "SaldoDiaBase.h"
#include "Erro.h"

using namespace std;

class Banco {
private:
	std::string nomeBanco;
	std::list<Cliente> clientes;
	std::vector<Conta*> contas;

public:
	//Cria um banco com o nome "nomeB"
	Banco();
	Banco(std::string nomeB);

	//Adiciona um nome cliente
	void adicionaCliente(Cliente& novo);

	//Cria uma nova conta retorna true se criado e false se não criado
	bool criarConta(std::string cpf, std::string tipo, double limite);

	//Checa se o cliente tem alguma conta
	bool possuiConta(std::string cpf);

	//Deleta um cliente PRECONDI��O: Cliente n�o possui conta
	bool deletaCliente(std::string cpf);

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


	void cadastrarDiaBase(int numConta, SaldoDiaBase &db);

	//Retorna o saldo de uma conta
	double obterSaldo (int numConta);

	//Retorna o extrato do último mês de uma conta
	std::vector<Movimentacao> obterExtratoMesAtual(int numConta);

	//Retorna o extrato de uma conta desde a data inicial
	std::vector<Movimentacao> obterExtrato(std::string dataIni, int numConta);

	//Retorna o extrato de uma conta no período especificado
	std::vector<Movimentacao> obterExtrato(std::string dataIni, std::string dataFim, int numConta);

	//Obtem a lista de clientes
	std::list<Cliente> clientesLista();

	//Obtem a lista de contas
	std::vector<Conta*> contasLista();

	//Escreve os dados no arquivo
	void writeFile();

	//Lê os dados no arquivo
	void readFile();

	//Write the member variables to stream objects
	friend std::ostream& operator << (std::ostream& out, const Banco& obj);

	//Read data from stream object and fill it in member variables
	friend std::istream& operator >> (std::istream& in, Banco& obj);
};

#endif // BANCO_H
