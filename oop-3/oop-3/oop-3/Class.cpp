#include "Class.h"



Cislo::Cislo(double x, double y)
{
	std::cin >> double x >> double y;



}

Cislo::~Cislo()				//destruktor
{
	std::cout << "Vypocet proveden, AVE" << std::endl;

}
auto Cislo::scitani(double x, double y)
{
	vys = x + y;

	return vys;
}
Cislo::nasobeni(double x, double y)
{
	vys = x * y;
	return vys;
}

Cislo::odcitani(double x, double y)
{
	vys = x - y;

	return vys;
}

Cislo::deleni(double x, double y)
{
	vys = x / y;


	return vys;
}