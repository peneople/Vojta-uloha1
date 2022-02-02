#include "funkce.h"


Napis::Napis(string txt)
{
	text(txt);
	pocet++;
}
Napis::~Napis()
{
	cout << "Destruktor utoci" << endl;
	pocet--;
}

void Napis::vypis()
{
	cout << _text << endl;
}

int Napis::pocet_napisu()
{
	return pocet;
}

