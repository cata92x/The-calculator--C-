#include <iostream>
#include <string>
#include "Calcul.h"
using namespace std;

class Calculator
{
	Calcul calcul;
public:
	Calculator();
	Calculator(Calcul calcul);

	Calcul getCalcul();
	void setCalcul(Calcul calculNou);

	friend ostream& operator<<(ostream& out,const Calculator& calculator);
	friend istream& operator>>(istream& in, Calculator& calculator);

	explicit operator int();
	bool operator!=(const Calculator c);

	static bool erori(Expresie expresie);
	static void rezolvare();
};


