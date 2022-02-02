#include <iostream>
#include "funkce.h"







int main ()
{
	cout << "pocet napisu: " << Napis::pocet_napisu() << endl;
	Napis napis("Hello world");//
	napis.vypis();// volani metody vypis
	cout << "pocet napisu: " << Napis::pocet_napisu() << endl;
	return 0;

}