#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Calcul.h"
using namespace std;

Corectitudine Calcul::corectitudine = Corectitudine::corect;

Calcul::Calcul()
{
	expresie = Expresie::Expresie();
}
Calcul::Calcul(Expresie expresie) : Calcul()
{
	this->expresie = expresie;
}

Corectitudine Calcul::getCorectitudine()
{
	return corectitudine;
}
void Calcul::setCorectitudine(Corectitudine corectitudineNoua)
{
	corectitudine = corectitudineNoua;
}

Expresie Calcul::getExpresie()
{
	return expresie;
}
void Calcul::setExpresie(Expresie expresieNoua)
{
	expresie = expresieNoua;
}

ostream& operator<<(ostream& out, const Calcul& c)
{
	out << c.expresie;
	return out;
}
istream& operator>>(istream& in, Calcul& c)
{
	in >> c.expresie;
	return in;
}

char* Calcul::precizie(double& valoare)
{
	string valoareString = to_string(valoare);
	char* valoareChar = new char[valoareString.length() + 1];
	strcpy_s(valoareChar, valoareString.length() + 1, valoareString.c_str());
	for (int i = strlen(valoareChar) - 1; i > 0; i--)
	{
		if (valoareChar[i] <= '0' || valoareChar[i - 1] > '9')
		{
			if (valoareChar[i] == '.')
			{
				strcpy_s(valoareChar + i, strlen(valoareChar + i + 1) + 1, valoareChar + i + 1);
				break;
			}
			else
				strcpy_s(valoareChar + i, strlen(valoareChar + i + 1) + 1, valoareChar + i + 1);
		}
		else
			break;
	}
	valoare = stod(valoareChar);
	return valoareChar;
}

bool Calcul::operator!()
{
	if (strlen(expresie.getExpresie()) >= 3)
		return false;
	return true;
}
void Calcul::operator()(Expresie& e)
{
	patrata(e.getNumereExpresie(), e.getCateNumere(), e.getCaractereExpresie(), e.getCateCaractere(), e.getPozitiiCaractere(), e.getCatePozitii());
	rotunda(e.getNumereExpresie(), e.getCateNumere(), e.getCaractereExpresie(), e.getCateCaractere(), e.getPozitiiCaractere(), e.getCatePozitii(), 0, e.getCateCaractere());
	radical(e.getNumereExpresie(), e.getCateNumere(), e.getCaractereExpresie(), e.getCateCaractere(), e.getPozitiiCaractere(), e.getCatePozitii(), 0, e.getCateCaractere());	putere(expresie.getNumereExpresie(), expresie.getCateNumere(), expresie.getCaractereExpresie(), expresie.getCateCaractere(), expresie.getPozitiiCaractere(), expresie.getCatePozitii(), 0, expresie.getCateCaractere());
	putere(e.getNumereExpresie(), e.getCateNumere(), e.getCaractereExpresie(), e.getCateCaractere(), e.getPozitiiCaractere(), e.getCatePozitii(), 0, e.getCateCaractere());	putere(expresie.getNumereExpresie(), expresie.getCateNumere(), expresie.getCaractereExpresie(), expresie.getCateCaractere(), expresie.getPozitiiCaractere(), expresie.getCatePozitii(), 0, expresie.getCateCaractere());
	inmultireSiImpartire(e.getNumereExpresie(), e.getCateNumere(), e.getCaractereExpresie(), e.getCateCaractere(), e.getPozitiiCaractere(), e.getCatePozitii(), 0, e.getCateCaractere());	putere(expresie.getNumereExpresie(), expresie.getCateNumere(), expresie.getCaractereExpresie(), expresie.getCateCaractere(), expresie.getPozitiiCaractere(), expresie.getCatePozitii(), 0, expresie.getCateCaractere());
	adunareSiScadere(e.getNumereExpresie(), e.getCateNumere(), e.getCaractereExpresie(), e.getCateCaractere(), e.getPozitiiCaractere(), e.getCatePozitii(), 0, e.getCateCaractere());
}

void Calcul::adunareSiScadere(double* numereExpresie, int& cateNumereExpresie, char* caractereExpresie, int& cateCaractere, int* pozitiiExpresie, int& catePozitiiExpresie, int start, int& stop)
{
	for (int i = start; i < stop - 1; i++)
		if (caractereExpresie[i] == '+')
		{
			numereExpresie[pozitiiExpresie[i]] += numereExpresie[pozitiiExpresie[i + 1]];
			for (int j = pozitiiExpresie[i + 1]; j < cateNumereExpresie - 1; j++)
				numereExpresie[j] = numereExpresie[j + 1];
			cateNumereExpresie--;
			int aux = strlen(caractereExpresie) - 3;
			for (int j = i; j < aux; j++)
			{
				caractereExpresie[j] = caractereExpresie[j + 2];
			}
			for (int j = i; j < catePozitiiExpresie - 3; j = j + 2)
			{
				if (pozitiiExpresie[j + 1] == pozitiiExpresie[j + 2])
				{
					pozitiiExpresie[j] = pozitiiExpresie[j + 2] - 1;
					pozitiiExpresie[j + 1] = pozitiiExpresie[j + 3] - 1;
				}
				else
				{
					pozitiiExpresie[j] = pozitiiExpresie[j + 2] - 2;
					pozitiiExpresie[j + 1] = pozitiiExpresie[j + 3] - 2;
				}
			}
			catePozitiiExpresie -= 2;
			stop -= 2;
			i--;
		}
		else if (caractereExpresie[i] == '-')
		{
			numereExpresie[pozitiiExpresie[i]] -= numereExpresie[pozitiiExpresie[i + 1]];
			for (int j = pozitiiExpresie[i + 1]; j < cateNumereExpresie - 1; j++)
				numereExpresie[j] = numereExpresie[j + 1];
			cateNumereExpresie--;
			int aux = strlen(caractereExpresie) - 3;
			for (int j = i; j < aux; j++)
			{
				caractereExpresie[j] = caractereExpresie[j + 2];
			}
			for (int j = i; j < catePozitiiExpresie - 3; j = j + 2)
			{
				if (pozitiiExpresie[j + 1] == pozitiiExpresie[j + 2])
				{
					pozitiiExpresie[j] = pozitiiExpresie[j + 2] - 1;
					pozitiiExpresie[j + 1] = pozitiiExpresie[j + 3] - 1;
				}
				else
				{
					pozitiiExpresie[j] = pozitiiExpresie[j + 2] - 2;
					pozitiiExpresie[j + 1] = pozitiiExpresie[j + 3] - 2;
				}
			}
			catePozitiiExpresie -= 2;
			//cateCaractere -= 2;
			stop -= 2;
			i--;
		}
}
void Calcul::inmultireSiImpartire(double* numereExpresie, int& cateNumereExpresie, char* caractereExpresie, int& cateCaractere, int* pozitiiExpresie, int& catePozitiiExpresie, int start, int& stop)
{
	for (int i = start; i < stop; i++)
		if (caractereExpresie[i] == '*')
		{
			numereExpresie[pozitiiExpresie[i]] *= numereExpresie[pozitiiExpresie[i + 1]];
			for (int j = pozitiiExpresie[i + 1]; j < cateNumereExpresie - 1; j++)
			{
				numereExpresie[j] = numereExpresie[j + 1];
			}
			cateNumereExpresie--;
			for (int j = i; j < cateCaractere - 2; j++)
			{
				caractereExpresie[j] = caractereExpresie[j + 2];
			}
			for (int j = i; j < catePozitiiExpresie - 2; j++)
				pozitiiExpresie[j] = pozitiiExpresie[j + 2] - 1;
			catePozitiiExpresie -= 2;
			stop -= 2;
			i--;
		}
		else if (caractereExpresie[i] == '/')
		{
			if (numereExpresie[pozitiiExpresie[i + 1]] == 0)
			{
				corectitudine = Corectitudine::impartire;
				break;
			}
			else
			{
				numereExpresie[pozitiiExpresie[i]] /= numereExpresie[pozitiiExpresie[i + 1]];
				for (int j = pozitiiExpresie[i + 1]; j < cateNumereExpresie - 1; j++)
					numereExpresie[j] = numereExpresie[j + 1];
				cateNumereExpresie--;
				for (int j = i; j < cateCaractere - 2; j++)
				{
					caractereExpresie[j] = caractereExpresie[j + 2];
				}
				for (int j = i; j < catePozitiiExpresie - 2; j++)
					pozitiiExpresie[j] = pozitiiExpresie[j + 2] - 1;
				catePozitiiExpresie -= 2;
				stop -= 2;
				i--;
			}
		}
}
void Calcul::putere(double* numereExpresie, int& cateNumereExpresie, char* caractereExpresie, int& cateCaractere, int* pozitiiExpresie, int& catePozitiiExpresie, int start, int& stop)
{
	for (int i = start; i < stop; i++)
		if (caractereExpresie[i] == '^')
		{
			if (numereExpresie[pozitiiExpresie[i]] < 0 && (int)numereExpresie[pozitiiExpresie[i + 1]] != numereExpresie[pozitiiExpresie[i + 1]])
			{
				corectitudine = Corectitudine::putere;
				break;
			}
			numereExpresie[pozitiiExpresie[i]] = pow(numereExpresie[pozitiiExpresie[i]], numereExpresie[pozitiiExpresie[i + 1]]);
			for (int j = pozitiiExpresie[i + 1]; j < cateNumereExpresie - 1; j++)
				numereExpresie[j] = numereExpresie[j + 1];
			cateNumereExpresie--;
			for (int j = i; j < cateCaractere - 2; j++)
			{
				caractereExpresie[j] = caractereExpresie[j + 2];
			}
			for (int j = i; j < catePozitiiExpresie - 2; j++)
				pozitiiExpresie[j] = pozitiiExpresie[j + 2] - 1;
			catePozitiiExpresie -= 2;
			stop -= 2;
			i--;
		}
}
void Calcul::radical(double* numereExpresie, int& cateNumereExpresie, char* caractereExpresie, int& cateCaractere, int* pozitiiExpresie, int& catePozitiiExpresie, int start, int& stop)
{
	for (int i = start; i < stop; i++)
		if (caractereExpresie[i] == '#')
		{
			double ordin = numereExpresie[pozitiiExpresie[i + 1]];
			if ((numereExpresie[pozitiiExpresie[i]] <= 0 && (int)ordin % 2 == 0 && (int)ordin == ordin))
			{
				corectitudine = Corectitudine::ordinParValoareNegativa;
				break;
			}
			else if (numereExpresie[pozitiiExpresie[i + 1]] < 2)
			{
				corectitudine = Corectitudine::ordinMaiMicDecat2;
				break;
			}
			else if (int(ordin) != ordin)
			{
				corectitudine = Corectitudine::ordinNuEsteNatural;
				break;
			}
			else if (numereExpresie[pozitiiExpresie[i]] <= 0)
			{
				numereExpresie[pozitiiExpresie[i]] = (-1) * pow((-1) * numereExpresie[pozitiiExpresie[i]], 1 / numereExpresie[pozitiiExpresie[i + 1]]);
			}
			else
				numereExpresie[pozitiiExpresie[i]] = pow(numereExpresie[pozitiiExpresie[i]], 1 / numereExpresie[pozitiiExpresie[i + 1]]);
			for (int j = pozitiiExpresie[i + 1]; j < cateNumereExpresie - 1; j++)
				numereExpresie[j] = numereExpresie[j + 1];
			cateNumereExpresie--;
			for (int j = i; j < cateCaractere - 2; j++)
			{
				caractereExpresie[j] = caractereExpresie[j + 2];
			}
			for (int j = i; j < catePozitiiExpresie - 2; j++)
				pozitiiExpresie[j] = pozitiiExpresie[j + 2] - 1;
			catePozitiiExpresie -= 2;
			stop -= 2;
			i--;
		}
}
void Calcul::rotunda(double* numereExpresie, int& cateNumereExpresie, char* caractereExpresie, int& cateCaractere, int* pozitiiExpresie, int& catePozitiiExpresie, int start, int& stop)
{
	int j, aux = 0, jinitial;
	for (int i = start; i < stop; i++)
		if (caractereExpresie[i] == '(')
		{
			j = i + 1;
			while (caractereExpresie[j] != ')')
				j++;
			j++;
			jinitial = j;
			radical(numereExpresie, cateNumereExpresie, caractereExpresie, cateCaractere, pozitiiExpresie, catePozitiiExpresie, i + 1, j);
			putere(numereExpresie, cateNumereExpresie, caractereExpresie, cateCaractere, pozitiiExpresie, catePozitiiExpresie, i + 1, j);
			inmultireSiImpartire(numereExpresie, cateNumereExpresie, caractereExpresie, cateCaractere, pozitiiExpresie, catePozitiiExpresie, i + 1, j);
			adunareSiScadere(numereExpresie, cateNumereExpresie, caractereExpresie, cateCaractere, pozitiiExpresie, catePozitiiExpresie, i + 1, j);
			aux += jinitial - j;
			for (int k = i; k < cateCaractere - 4; k++)
			{
				caractereExpresie[k] = caractereExpresie[k + 4];
			}
			stop -= 4;
			for (int k = i + 1; k < catePozitiiExpresie - 4; k++)
			{
				pozitiiExpresie[k] = pozitiiExpresie[k + 4];
			}
			catePozitiiExpresie -= 4;
		}
	stop -= aux;
}
void Calcul::patrata(double* numereExpresie, int& cateNumereExpresie, char* caractereExpresie, int& cateCaractere, int* pozitiiExpresie, int& catePozitiiExpresie)
{
	int j, jinitial, aux = 0;
	for (int i = 0; i < cateCaractere; i++)
		if (caractereExpresie[i] == '[')
		{
			j = i + 1;
			while (caractereExpresie[j] != ']')
				j++;
			jinitial = j;
			rotunda(numereExpresie, cateNumereExpresie, caractereExpresie, cateCaractere, pozitiiExpresie, catePozitiiExpresie, i + 1, j);
			radical(numereExpresie, cateNumereExpresie, caractereExpresie, cateCaractere, pozitiiExpresie, catePozitiiExpresie, i + 1, j);
			putere(numereExpresie, cateNumereExpresie, caractereExpresie, cateCaractere, pozitiiExpresie, catePozitiiExpresie, i + 1, j);
			inmultireSiImpartire(numereExpresie, cateNumereExpresie, caractereExpresie, cateCaractere, pozitiiExpresie, catePozitiiExpresie, i + 1, j);
			adunareSiScadere(numereExpresie, cateNumereExpresie, caractereExpresie, cateCaractere, pozitiiExpresie, catePozitiiExpresie, i + 1, j);
			aux = jinitial - j;
			for (int k = i; k < cateCaractere - 4; k++)
			{
				caractereExpresie[k] = caractereExpresie[k + 4];
			}
			cateCaractere -= 4;
			for (int k = i + 1; k < catePozitiiExpresie - 4; k++)
			{
				pozitiiExpresie[k] = pozitiiExpresie[k + 4];
			}
			catePozitiiExpresie -= 4;
		}
	cateCaractere -= aux;
}