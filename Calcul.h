#include <iostream>
#include <string>
#include "Expresie.h"
using namespace std;

enum class Corectitudine
{
	corect,
	putere,
	impartire,
	ordinParValoareNegativa,
	ordinMaiMicDecat2,
	ordinNuEsteNatural
};

class Calcul
{
	static Corectitudine corectitudine;
	Expresie expresie;
public:
	Calcul();
	Calcul(Expresie expresie);

	Corectitudine getCorectitudine();
	void setCorectitudine(Corectitudine corectitudineNoua);

	Expresie getExpresie();
	void setExpresie(Expresie expresieNoua);

	friend ostream& operator<<(ostream& out, const Calcul& c);
	friend istream& operator>>(istream& in, Calcul& c);

	char* precizie(double& valoare);

	bool operator!();
	void operator()(Expresie& e);

	void adunareSiScadere(double* numereExpresie, int& cateNumereExpresie, char* caractereExpresie, int& cateCaractere, int* pozitiiExpresie, int& catePozitiiExpresie, int start, int& stop);
	void inmultireSiImpartire(double* numereExpresie, int& cateNumereExpresie, char* caractereExpresie, int& cateCaractere, int* pozitiiExpresie, int& catePozitiiExpresie, int start, int& stop);
	void putere(double* numereExpresie, int& cateNumereExpresie, char* caractereExpresie, int& cateCaractere, int* pozitiiExpresie, int& catePozitiiExpresie, int start, int& stop);
	void radical(double* numereExpresie, int& cateNumereExpresie, char* caractereExpresie, int& cateCaractere, int* pozitiiExpresie, int& catePozitiiExpresie, int start, int& stop);
	void rotunda(double* numereExpresie, int& cateNumereExpresie, char* caractereExpresie, int& cateCaractere, int* pozitiiExpresie, int& catePozitiiExpresie, int start, int& stop);
	void patrata(double* numereExpresie, int& cateNumereExpresie, char* caractereExpresie, int& cateCaractere, int* pozitiiExpresie, int& catePozitiiExpresie);
};