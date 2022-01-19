#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Expresie.h"
using namespace std;

int Expresie::numar = 1;

Expresie::Expresie() : numarExpresii(numar++)
{
	expresie = nullptr;
	numereExpresie = nullptr;
	caractereExpresie = nullptr;
	pozitiiCaractere = nullptr;
	cateNumere = 0;
	cateCaractere = 0;
	catePozitii = 0;
}
Expresie::Expresie(const char* expresie) : numarExpresii(numar++)
{
	if (expresie != nullptr)
	{
		this->expresie = new char[strlen(expresie) + 1];
		strcpy_s(this->expresie, strlen(expresie) + 1, expresie);
	}
	else
	{
		this->expresie = nullptr;
	}
	numereExpresie = nullptr;
	caractereExpresie = nullptr;
	pozitiiCaractere = nullptr;
	cateNumere = 0;
	cateCaractere = 0;
	catePozitii = 0;

}
Expresie::Expresie(const Expresie& e) : numarExpresii(e.numarExpresii)
{
	if (e.expresie != nullptr)
	{
		expresie = new char[strlen(e.expresie) + 1];
		strcpy_s(expresie, strlen(e.expresie) + 1, e.expresie);
	}
	else
	{
		expresie = nullptr;
	}
	if (e.numereExpresie != nullptr && e.cateNumere > 0)
	{
		cateNumere = e.cateNumere;
		numereExpresie = new double[cateNumere];
		for (int i = 0; i < cateNumere; i++)
			numereExpresie[i] = e.numereExpresie[i];
	}
	else
	{
		numereExpresie = nullptr;
		cateNumere = 0;
	}
	if (e.caractereExpresie != nullptr && e.cateCaractere > 0)
	{
		cateCaractere = e.cateCaractere;
		caractereExpresie = new char[strlen(e.caractereExpresie) + 1];
		strcpy_s(caractereExpresie, strlen(e.caractereExpresie) + 1, e.caractereExpresie);
	}
	else
	{
		caractereExpresie = nullptr;
		cateCaractere = 0;
	}
	if (e.pozitiiCaractere != nullptr && e.catePozitii > 0)
	{
		catePozitii = e.catePozitii;
		pozitiiCaractere = new int[catePozitii];
		for (int i = 0; i < catePozitii; i++)
			pozitiiCaractere[i] = e.pozitiiCaractere[i];
	}
	else
	{
		pozitiiCaractere = nullptr;
		catePozitii = 0;
	}
}
Expresie::~Expresie()
{
	if (expresie != nullptr)
	{
		delete[] expresie;
		expresie = nullptr;
	}
	if (numereExpresie != nullptr)
	{
		delete[] numereExpresie;
		numereExpresie = nullptr;
	}
	if (caractereExpresie != nullptr)
	{
		delete[] caractereExpresie;
		caractereExpresie = nullptr;
	}
	if (pozitiiCaractere != nullptr)
	{
		delete[] pozitiiCaractere;
		pozitiiCaractere = nullptr;
	}
}

Expresie& Expresie::operator=(const Expresie& e)
{
	if (this != &e)
	{
		if (expresie != nullptr)
		{
			delete[] expresie;
			expresie = nullptr;
		}
		if (numereExpresie != nullptr)
		{
			delete[] numereExpresie;
			numereExpresie = nullptr;
		}
		if (caractereExpresie != nullptr)
		{
			delete[] caractereExpresie;
			caractereExpresie = nullptr;
		}
		if (pozitiiCaractere != nullptr)
		{
			delete[] pozitiiCaractere;
			pozitiiCaractere = nullptr;
		}
		if (e.expresie != nullptr)
		{
			expresie = new char[strlen(e.expresie) + 1];
			strcpy_s(expresie, strlen(e.expresie) + 1, e.expresie);
		}
		else
			expresie = nullptr;
		if (e.numereExpresie != nullptr && e.cateNumere > 0)
		{
			cateNumere = e.cateNumere;
			numereExpresie = new double[cateNumere];
			for (int i = 0; i < cateNumere; i++)
				numereExpresie[i] = e.numereExpresie[i];
		}
		else
		{
			numereExpresie = nullptr;
			cateNumere = 0;
		}
		if (e.caractereExpresie != nullptr && e.cateCaractere > 0)
		{
			cateCaractere = e.cateCaractere;
			caractereExpresie = new char[strlen(e.caractereExpresie) + 1];
			strcpy_s(caractereExpresie, strlen(e.caractereExpresie) + 1, e.caractereExpresie);
		}
		else
		{
			caractereExpresie = nullptr;
			cateCaractere = 0;
		}
		if (e.pozitiiCaractere != nullptr && e.catePozitii > 0)
		{
			catePozitii = e.catePozitii;
			pozitiiCaractere = new int[catePozitii];
			for (int i = 0; i < catePozitii; i++)
				pozitiiCaractere[i] = e.pozitiiCaractere[i];
		}
		else
		{
			pozitiiCaractere = nullptr;
			catePozitii = 0;
		}
	}
	return *this;
}

char* Expresie::getExpresieCopie()
{
	if (expresie != nullptr)
	{
		char* copie = new char[strlen(expresie) + 1];
		strcpy_s(copie, strlen(expresie) + 1, expresie);
		return copie;
	}
	else
		return nullptr;
}
void Expresie::setExpresie(const char* expresieNoua)
{
	if (expresieNoua != nullptr)
	{
		if (expresie != nullptr)
			delete[] expresie;
		expresie = new char[strlen(expresieNoua) + 1];
		strcpy_s(expresie, strlen(expresieNoua) + 1, expresieNoua);
	}
}

double* Expresie::getNumereExpresieCopie()
{
	if (numereExpresie != nullptr && cateNumere > 0)
	{
		double* copie = new double[cateNumere];
		for (int i = 0; i < cateNumere; i++)
			copie[i] = numereExpresie[i];
		return copie;
	}
	else
		return nullptr;
}
void Expresie::setNumereExpresie(double* numereExpresieNoua, int cateNumereNoua)
{
	if (numereExpresieNoua != nullptr && cateNumereNoua > 0)
	{
		cateNumere = cateNumereNoua;
		if (numereExpresie != nullptr)
			delete[] numereExpresie;
		numereExpresie = new double[cateNumere];
		for (int i = 0; i < cateNumere; i++)
			numereExpresie[i] = numereExpresieNoua[i];
	}
}

char* Expresie::getCaractereExpresieCopie()
{
	if (caractereExpresie != nullptr)
	{
		char* copie = new char[strlen(caractereExpresie) + 1];
		strcpy_s(copie, strlen(caractereExpresie) + 1, caractereExpresie);
		return copie;
	}
	else
		return nullptr;
}
void Expresie::setCaractereExpresie(const char* CaractereExpresieNoua)
{
	if (CaractereExpresieNoua != nullptr)
	{
		if (caractereExpresie != nullptr)
			delete[] caractereExpresie;
		caractereExpresie = new char[strlen(CaractereExpresieNoua) + 1];
		strcpy_s(caractereExpresie, strlen(CaractereExpresieNoua) + 1, CaractereExpresieNoua);
	}
}

int* Expresie::getPozitiiCaractereCopie()
{
	if (pozitiiCaractere != nullptr && catePozitii > 0)
	{
		int* copie = new int[catePozitii];
		for (int i = 0; i < catePozitii; i++)
			copie[i] = pozitiiCaractere[i];
		return copie;
	}
	else
		return nullptr;
}
void Expresie::setPozitiiCaractere(int* pozitiiCaractereNoua, int catePozitiiNoua)
{
	if (pozitiiCaractereNoua != nullptr && catePozitiiNoua > 0)
	{
		catePozitii = catePozitiiNoua;
		if (pozitiiCaractere != nullptr)
			delete[] pozitiiCaractere;
		pozitiiCaractere = new int[catePozitii];
		for (int i = 0; i < catePozitii; i++)
			pozitiiCaractere[i] = pozitiiCaractereNoua[i];
	}
}

int& Expresie::getCateNumere()
{
	return cateNumere;
}
int& Expresie::getCateCaractere()
{
	return cateCaractere;
}
int& Expresie::getCatePozitii()
{
	return catePozitii;
}

char* Expresie::getExpresie()
{
	return expresie;
}
double* Expresie::getNumereExpresie()
{
	return numereExpresie;
}
char* Expresie::getCaractereExpresie()
{
	return caractereExpresie;
}
int* Expresie::getPozitiiCaractere()
{
	return pozitiiCaractere;
}

int Expresie::getNumarExpresii()
{
	return numarExpresii;
}
int Expresie::getNumar()
{
	return numar;
}
void Expresie::setNumar(int numarNou)
{
	if (numarNou > 0)
		numar = numarNou;
}

istream& operator>>(istream& in, Expresie& e)
{
	string buffer;
	in >> ws;
	getline(in, buffer);
	if (e.expresie != nullptr)
		delete[] e.expresie;
	e.numereExpresie = nullptr;
	e.caractereExpresie = nullptr;
	e.pozitiiCaractere = nullptr;
	e.expresie = new char[buffer.length() + 1];
	strcpy_s(e.expresie, buffer.length() + 1, buffer.c_str());
	return in;
}
ostream& operator<<(ostream& out, const Expresie& e)
{
	out << "Expresia numarul: " << e.numarExpresii << endl;
	if (e.expresie != nullptr)
		out << "Expresia: " << e.expresie << endl;
	else
		out << "Expresia nu exista." << endl;
	if (e.numereExpresie != nullptr && e.cateNumere > 0)
	{
		out << "Vectorul de numere: " << endl;
		for (int i = 0; i < e.cateNumere; i++)
			out << fixed << e.numereExpresie[i] << " ";
		out << endl;
	}
	else
		out << "Vectorul de numere nu exista." << endl;
	if (e.caractereExpresie != nullptr && e.cateCaractere > 0)
	{
		out << "Vectorul de caractere: " << endl;
		for (int i = 0; i < e.cateCaractere; i++)
			out << e.caractereExpresie[i] << " ";
		out << endl;
	}
	else
		out << "Vectorul de caractere nu exista." << endl;
	if (e.pozitiiCaractere != nullptr && e.catePozitii > 0)
	{
		out << "Vectorul de pozitii: " << endl;
		for (int i = 0; i < e.catePozitii; i++)
			out << e.pozitiiCaractere[i] << " ";
		out << endl;
	}
	else
		out << "Vectorul de pozitii nu exista." << endl;
	return out;
}

void Expresie::operator+=(double numar)
{
	if (numereExpresie != nullptr && cateNumere > 0)
	{
		double* copie = new double[cateNumere];
		for (int i = 0; i < cateNumere; i++)
			copie[i] = numereExpresie[i];
		cateNumere++;
		delete[] numereExpresie;
		numereExpresie = new double[cateNumere];
		for (int i = 0; i < cateNumere - 1; i++)
			numereExpresie[i] = copie[i];
		numereExpresie[cateNumere - 1] = numar;
		delete[] copie;
	}
	else
	{
		cateNumere = 1;
		numereExpresie = new double[cateNumere];
		numereExpresie[0] = numar;
	}
}
void Expresie::operator+=(char caracter)
{
	if (caractereExpresie != nullptr)
	{
		char* copie = new char[strlen(caractereExpresie) + 1];
		strcpy_s(copie, strlen(caractereExpresie) + 1, caractereExpresie);
		delete[] caractereExpresie;
		caractereExpresie = new char[strlen(copie) + 2];
		strcpy_s(caractereExpresie, strlen(copie) + 1, copie);
		caractereExpresie[strlen(copie)] = caracter;
		caractereExpresie[strlen(copie) + 1] = '\0';
		cateCaractere = strlen(copie) + 1;
		delete[] copie;
	}
	else
	{
		caractereExpresie = new char[2];
		caractereExpresie[0] = caracter;
		caractereExpresie[1] = '\0';
		cateCaractere = 1;
	}
}
void Expresie::operator+=(int pozitie)
{
	if (pozitiiCaractere != nullptr && catePozitii > 0)
	{
		int* copie = new int[catePozitii];
		for (int i = 0; i < catePozitii; i++)
			copie[i] = pozitiiCaractere[i];
		catePozitii++;
		delete[] pozitiiCaractere;
		pozitiiCaractere = new int[catePozitii];
		for (int i = 0; i < catePozitii - 1; i++)
			pozitiiCaractere[i] = copie[i];
		pozitiiCaractere[catePozitii - 1] = pozitie;
		delete[] copie;
	}
	else
	{
		catePozitii = 1;
		pozitiiCaractere = new int[catePozitii];
		pozitiiCaractere[0] = pozitie;
	}
}
double& Expresie::operator[](int index)
{
	if (index >= 0 && index < cateNumere)
	{
		return numereExpresie[index];
	}
	else
		throw exception("Index incorect");

}

void Expresie::verificareMinus()
{
	if (expresie != nullptr)
	{
		for (int i = 0; i < strlen(expresie); i++)
		{
			if ((expresie[i] == '-' && i == 0) || (expresie[i] == '-' && (expresie[i - 1] == '(' || expresie[i - 1] == '[')))
			{
				char* copie = new char[strlen(expresie) + 1];
				strcpy_s(copie, strlen(expresie) + 1, expresie);
				delete[] expresie;
				expresie = new char[strlen(copie) + 2];
				for (int i = 0; i < strlen(copie); i++)
					expresie[i] = copie[i];
				expresie[strlen(copie) + 1] = '\0';
				for (int j = strlen(expresie) - 1; j > i; j--)
					expresie[j] = expresie[j - 1];
				expresie[i] = '0';
				delete[] copie;
			}
		}
	}
}
void Expresie::verificareSpatiu()
{
	if (expresie != nullptr)
	{
		for (int i = 0; i < strlen(expresie); i++)
		{
			if (expresie[i] == ' ')
			{
				strcpy(expresie + i, expresie + i + 1);
				i--;
			}

		}
		char* copie = new char[strlen(expresie) + 1];
		strcpy_s(copie, strlen(expresie) + 1, expresie);
		delete[] expresie;
		expresie = new char[strlen(copie) + 1];
		strcpy_s(expresie, strlen(copie) + 1, copie);
		delete[] copie;
	}
}
void Expresie::creareVectori()
{
	if (expresie != nullptr)
	{
		int cpoz = 0;
		char* copie = new char[strlen(expresie) + 1];
		strcpy_s(copie, strlen(expresie) + 1, expresie);
		char* pointer;
		pointer = strtok(copie, "+-*/()[]#^");
		while (pointer != NULL)
		{
			*this += stod(pointer);
			pointer = strtok(NULL, "+-*/()[]#^");
		}
		for (int i = 0; i < strlen(expresie) + 1; i++)
		{
			if (expresie[i] != '+' && expresie[i] != '-' && expresie[i] != '*' && expresie[i] != '/' && expresie[i] != '(' &&
				expresie[i] != ')' && expresie[i] != '[' && expresie[i] != ']' && expresie[i] != '^' && expresie[i] != '#')
			{
				if ((expresie[i + 1] < '0' || expresie[i + 1] > '9') && expresie[i + 1] != '.')
					cpoz++;
			}
			else
			{
				if (expresie[i] != '.')
				{
					*this += expresie[i];
					*this += '_';
					if (expresie[i] == '(' || expresie[i] == '[')
					{
						*this += cpoz;
						*this += cpoz;
					}
					else if (expresie[i] == ')' || expresie[i] == ']')
					{
						*this += cpoz - 1;
						*this += cpoz - 1;
					}
					else
					{
						if (cpoz > 0)
							*this += cpoz - 1;
						else
							*this += cpoz;
						if (cpoz == 0)
							cpoz++;
						*this += cpoz;
					}
				}
			}
		}
		delete[] copie;
	}
	if (catePozitii > 0)
	{
		if (pozitiiCaractere[0] != 0)
			for (int i = 0; i < catePozitii; i++)
				pozitiiCaractere[i]--;
	}
}
