/*
 * Interface.cpp
 *
 *  Created on: 30 de set de 2019
 *      Author: rafaelamoreira
 */

#include "Interface.h"

Interface::Interface() {
	// TODO Auto-generated constructor stub

}
Interface::Menu(){
  while(1){
    std::cout<< "------------- " <<"MENU"<< " -------------" <<"\n\t\t\t";
    std::cout << "Escolha qual opção deseja realizar" << "\n\t\t\t";
    std::cout << "(1) - Cadastrar cliente" << "\n\t\t\t"
    std::cout << "(2) - Criar nova conta" << "\n\t\t\t"
    std::cout << "(3) - Excluir cliente" << "\n\t\t\t"
    std::cout << "(4) - Excluir conta" << "\n\t\t\t"
    std::cout << "(5) - Efetuar depósito" << "\n\t\t\t"
    std::cout << "(6) - Efetuar saque" << "\n\t\t\t"
    std::cout << "(7) - Efetuar transferência" << "\n\t\t\t"
    std::cout << "(8) - Cobrar tarifa" << "\n\t\t\t"
    std::cout << "(9) - Cobrar CPMF" << "\n\t\t\t"
    std::cout << "(A) - Obter saldo" << "\n\t\t\t"
    std::cout << "(B) - Obter extrato" << "\n\t\t\t"
    std::cout << "(C) - Listar clientes" << "\n\t\t\t"
    std::cout << "(D) - Listar contas" << "\n\t\t\t"
    std::cout << "(0) - Sair" << "\n\t\t\t"

    int entrada = 0;
    std::cin >> entrada;

    switch (entrada){
    case 0:
      goto end;
    case 1:

    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case A:
    case B:
    case C:
    case D:

  }
}
void Interface::cadastraCliente(Cliente &obj){
 std::cout<<"Insira o nome do Cliente"<<
 std::cin>>obj.nomeCliente;
 std::cout<<"Insira o CPF do Cliente"<<
 std::cin>>obj.cpf_cnpj;
 std::cout<<"Insira o endereço do Cliente"<<
 std::cin>>obj.endereco;
 std::cout<<"Insira o telefone do Cliente"<<
 std::cin>>obj.fone;
}
void Interface::criaConta{

}
void Interface::excluiCliente{

}
void Interface::excluiConta{

}
void Interface::efetuaSaque{

}
void Interface::cadastraCliente{

}
void Interface::efetuaDeposito{

}
void Interface::efetuaTransferencia{

}
void Interface::cobraTarifa{

}
void Interface::cobraCPMF{

}

Interface::~Interface() {
	// TODO Auto-generated destructor stub
}
