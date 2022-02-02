#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>


std::string binarizace(int m)
{
	if (m == 0)
	{

		return 0;
	}
	std::string vysledek;
	bool zaporne = m < 0;
	m = std::abs(m);
	char znak[2]{ '0', '1' };
	while (m != 0)
	{
		vysledek = znak[m % 2] + vysledek;
		m = m / 2;
	}
	if (zaporne)
	{
		vysledek = '-' + vysledek;

	}
	return vysledek;
}

int main()
{
	std::cout << binarizace(2566664) << std::endl;


}