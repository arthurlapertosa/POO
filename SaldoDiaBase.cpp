#include "SaldoDiaBase.h"

std::ostream& operator<<(std::ostream& out, const SaldoDiaBase& obj)
{
	out << obj.diaBase << "\n" << obj.saldoDiaBase << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, SaldoDiaBase& obj)
{
	in >> obj.diaBase;
	in >> obj.saldoDiaBase;
	return in;
}
