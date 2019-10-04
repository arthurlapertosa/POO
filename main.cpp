

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

	Banco *b = new Banco("Inter");
	Interface *i = new Interface(*b);

	i->menu();


	return 0;
}
