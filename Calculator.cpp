#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;

Calculator::Calculator() 
{
	calcul = Calcul::Calcul();
}
Calculator::Calculator(Calcul calcul)
{
	this->calcul = calcul;
}

Calcul Calculator::getCalcul()
{
	return calcul;
}
void Calculator::setCalcul(Calcul calculNou)
{
	calcul = calculNou;
}

ostream& operator<<(ostream& out, const Calculator& calculator)
{
	out << calculator.calcul;
	return out;
}
istream& operator>>(istream& in, Calculator& calculator)
{
	in >> calculator.calcul;
	return in;
}

Calculator::operator int()
{
	Expresie expresieLocala = calcul.getExpresie();
	expresieLocala.creareVectori();
	return expresieLocala.getCateNumere();
}
bool Calculator::operator!=(Calculator c)
{
	if (strcmp(calcul.getExpresie().getExpresie(), c.calcul.getExpresie().getExpresie()) == 0)
		return false;
	return true;
}

bool Calculator::erori(Expresie expresie)
{
	char* expresieLocala = expresie.getExpresieCopie();
	int contorRotundaStanga = 0, contorRotundaDreapta = 0, contorDreaptaStanga = 0, contorDreaptaDreapta = 0;
	for (int i = 0; i < strlen(expresieLocala); i++)
		if (expresieLocala[i] == '(')
			contorRotundaStanga++;
		else if (expresieLocala[i] == ')')
			contorRotundaDreapta++;
		else if (expresieLocala[i] == '[')
			contorDreaptaStanga++;
		else if (expresieLocala[i] == ']')
			contorDreaptaDreapta++;

	if (contorRotundaDreapta != contorRotundaStanga)
	{
		cout << "---EROARE: PARANTEZE ROTUNDE INTRODUSE INCORECT---" << endl << endl;
		delete[] expresieLocala;
		return true;
	}
	if (contorDreaptaDreapta != contorDreaptaStanga)
	{
		cout << "---EROARE: PARANTEZE PATRATE INTRODUSE INCORECT---" << endl << endl;
		delete[] expresieLocala;
		return true;
	}
	bool ok = true;
	char operatori[7] = "+-*/^#";
	for (int i = 0; i < strlen(expresieLocala) - 1; i++)
	{
		if (strchr(operatori, expresieLocala[i]) != NULL && strchr(operatori, expresieLocala[i + 1]) != NULL)
			ok = false;
	}
	if (ok == false)
	{
		cout << "---EROARE: EXPRESIA ARE 2 OPERATORI ADIACENTI---" << endl << endl;
		delete[] expresieLocala;
		return true;
	}

	bool citire = true;
	for (int i = 0; i < strlen(expresieLocala) + 1; i++)
		if (strchr("1234567890.+-*/#^()[]", expresieLocala[i]) == NULL)
		{
			citire = false;
			break;
		}
	if (citire == false)
	{
		cout << "---EROARE: EXPRESIA ARE CARACTERE NEPERMISE---" << endl << endl;
		delete[] expresieLocala;
		return true;
	}

	delete[] expresieLocala;
	return false;
}
void Calculator::rezolvare()
{
	Calcul calcul;
	cout << endl << "---Calculatorul a fost pornit---" << endl << endl;
	cout << "Introduceti expresia sau 'exit' pentru iesire: ";
	cin >> calcul;
	Expresie expresie;
	expresie = calcul.getExpresie();
	expresie.verificareSpatiu();
	while (strcmp(expresie.getExpresieCopie(), "exit") != 0)
	{
		if (erori(expresie) == false)
		{
			expresie.verificareMinus();
			expresie.creareVectori();
			//if (expresie.getCateNumere() <= 0 || expresie.getCateCaractere() <= 0 || expresie.getCatePozitii() <= 0)
			//	cout << "Expresia este introdusa incorect." << endl << endl;
			//else
			//{
			calcul(expresie);
			if (calcul.getCorectitudine() == Corectitudine::impartire)
				cout << "---EROARE: IMPARTIRE LA 0---" << endl << endl;
			else if (calcul.getCorectitudine() == Corectitudine::ordinParValoareNegativa)
				cout << "---EROARE: RADICAL INCORECT- RADICAL DE ORDIN PAR DINTR-UN NUMAR NEGATIV---" << endl << endl;
			else if (calcul.getCorectitudine() == Corectitudine::putere)
				cout << "---EROARE: EXPONENTIALA INCORECTA- BAZA ESTE NUMAR NEGATIV, PUTEREA TREBUIE SA FIE NATURALA---" << endl << endl;
			else if (calcul.getCorectitudine() == Corectitudine::ordinMaiMicDecat2)
				cout << "---EROARE: RADICAL INCORECT- ORDINUL RADICALULUI TREBUIE SA FIE >=2---" << endl << endl;
			else if (calcul.getCorectitudine() == Corectitudine::ordinNuEsteNatural)
				cout << "---EROARE: RADICAL INCORECT- ORDINUL RADICALULUI TREBUIE SA FIE UN NUMAR NATURAL---" << endl << endl;
			else
				if (expresie.getCateCaractere() > 0 || expresie.getCateNumere() != 1 || expresie.getCatePozitii() > 0)
					cout << "---EROARE: EXPRESIE ESTE INTRODUSA INCORECT---" << endl << endl;
				else
				{
					char* sirAfisare = calcul.precizie(expresie[0]);
					cout << "Rezulatul este = " << sirAfisare << endl << endl;
					delete[] sirAfisare;
				}
			//}
		}
		cout << "Introduceti noua expresie sau 'exit' pentru iesire: ";
		cin >> calcul;
		expresie = calcul.getExpresie();
		expresie.verificareSpatiu();
		calcul.setCorectitudine(Corectitudine::corect);
	}
	cout << endl;
	cout << "---Caculatorul a fost oprit---" << endl;
}
