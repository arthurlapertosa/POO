/*
 * ContaPoupanca.cpp
 *
 *  Created on: 16 de nov de 2019
 *      Author: rafaelamoreira
 */

#include "ContaPoupanca.h"
#include "SaldoDiaBase.h"
#include "Erro.h"

ContaPoupanca::ContaPoupanca(Cliente * clienteNovo): Conta(clienteNovo) {

}

ContaPoupanca::ContaPoupanca() : Conta() {

}

ContaPoupanca::~ContaPoupanca() {
	// TODO Auto-generated destructor stub
}

string ContaPoupanca::type() const {
	return "P";
}

void ContaPoupanca::write(std::ostream& out) const
{
	out << *this;
}

void ContaPoupanca::read(std::istream& in)
{
	in >> *this;
}

std::ostream& operator<<(std::ostream& out, const ContaPoupanca& obj)
{
	//Escreve o tipo da conta
	out << "C" << "\n";
	out << obj.numConta << "\n" << obj.saldo << "\n" << *obj.cliente << "\n" << obj.proximoNumConta << "\n" << obj.movimentacoes.size() << "\n";
	for (int i = 0; i < obj.movimentacoes.size(); i++) {
		out << obj.movimentacoes[i];
	}
	std::cout << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, ContaPoupanca& obj) {
	in >> obj.numConta;
	in >> obj.saldo;
	Cliente* novo = new Cliente;
	in >> *novo;
	obj.cliente = novo;
	in >> obj.proximoNumConta;
	int size;
	in >> size;
	for (int i = 0; i < size; i++) {
		Movimentacao* aux = new Movimentacao();
		in >> *aux;
		obj.movimentacoes.push_back(*aux);
		delete aux;
	}
	//in >> obj.limiteCredito;
	return in;
}


bool ContaPoupanca::debitar(double valor, std::string descricao)
{
	bool transacaorealizada = false;
	char debitoCredito = 'D';
	Movimentacao* mov = new Movimentacao(descricao, debitoCredito, valor);



    if (this->saldo  >= valor) //checa se possui saldo suficiente para fazer a movimentação de débito
    {
        this->saldo = this->saldo - valor;
        this->movimentacoes.push_back(*mov);
        transacaorealizada = true;

        time_t now = time(0);
        tm *ltm = localtime(&now);
        int hoje = ltm->tm_mday;//data do dia em que a transação é realizada;

        if (hoje > 28)
        {
            //débitos realizados nos dias 29, 30 e 31 são contabilizados no dia 28.
            hoje = 28;
        }

        double debitar = valor;
        //enquanto ainda houver valor a ser debitado
        while (debitar>0)
        {
            // percorre o vetor de dias base e calcula a diferença de dias entre a dia atual e cada dia base existente
            double dif[saldoDiaB.size()];
            for (std::size_t i=0; i<this->saldoDiaB.size(); i++)
            {
                if (this->saldoDiaB[i].getDiaBase() > hoje)
                    dif[i] = hoje + (28 - this->saldoDiaB[i].getDiaBase());
                else
                    dif[i] = hoje - this->saldoDiaB[i].getDiaBase();
            }

            //procura o dia Base mais próximo;
            size_t menor = -1;
            for (std::size_t i=0; i<this->saldoDiaB.size(); i++)
            {
                for (std::size_t j=0; j<this->saldoDiaB.size(); i++)
                {

                    if (dif[i]<dif[j])
                        menor = i;
                }
            }
            //se saldo do dia base anterior mais próximo for maior que o valor a ser debitado, debita o valor.
            if (this->saldoDiaB[menor].getSaldoDiaBase() > debitar){
            	this->saldoDiaB[menor].setSaldoDiaBase(this->saldoDiaB[menor].getSaldoDiaBase() - debitar);

            } else {
            //se o saldodo dia base anterior mais próximo for menor que o valor a ser debitado, exclui o dia base e diminui o valor
            //a ser debitado de acordo com o saldo do dia base

                debitar = debitar - this->saldoDiaB[menor].getSaldoDiaBase();
                this->removeElemento(menor);
            }

        }
	}
	else {
		throw Erro("Saldo insuficiente");
	}

	delete mov;

	return transacaorealizada;
}

void ContaPoupanca::removeElemento(int elemento) {
	this->saldoDiaB.erase(saldoDiaB.begin()+ elemento);

}

void ContaPoupanca::adicionaElemento(SaldoDiaBase & elemento) {
	this->saldoDiaB.push_back(elemento);
}

void ContaPoupanca::creditar(double valor, std::string descricao)
{

	char debitoCredito = 'C';
	Movimentacao* mov = new Movimentacao(descricao, debitoCredito, valor);

	time_t now = time(0);
    tm *ltm = localtime(&now);
    int hoje = ltm->tm_mday;//data do dia em que a transação é realizada;

    if (hoje > 28)
    {
        //débitos realizados nos dias 29, 30 e 31 são contabilizados no dia 28.
        hoje = 28;
    }
	bool transacaorealizada = false;
	for (size_t i=0; i<this->saldoDiaB.size(); i++) {
        if (this->saldoDiaB[i].getDiaBase() == hoje) {
            this->saldoDiaB[i].setSaldoDiaBase(this->saldoDiaB[i].getDiaBase() + valor);
            transacaorealizada = true;
            this->movimentacoes.push_back(*mov);
        }
    }
    if (!transacaorealizada) {
        SaldoDiaBase novo(hoje, valor);
        this->adicionaElemento(novo);
        transacaorealizada = true;
    }
}

//
//const Cliente& ContaPoupanca::getCliente() const
//{
//	return *cliente;
//}
//
//const std::vector<Movimentacao> ContaPoupanca::getMovimentacoes()
//{
//	return std::vector<Movimentacao>();
//}
//
//int ContaPoupanca::getNumConta() const
//{
//	return 0;
//}
//
//double ContaPoupanca::getSaldo() const
//{
//	return 0.0;
//}
//
//void ContaPoupanca::setCliente(Cliente* newCliente)
//{
//}
//
//vector<Movimentacao> ContaPoupanca::obterExtrato(std::string dataIni, std::string dataFim)
//{
//	return vector<Movimentacao>();
//}
//
//vector<Movimentacao> ContaPoupanca::obterExtrato(std::string dataIni)
//{
//	return vector<Movimentacao>();
//}
//
//vector<Movimentacao> ContaPoupanca::obterExtratoMesAtual()
//{
//	return vector<Movimentacao>();
//}
//


