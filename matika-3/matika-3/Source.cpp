#include <iostream>
#include <math.h>
const int realne{ 0 }, komplexni{ 1 }, chybne_zadani{ 2 };


int res_q_rovnici(double koef[], double x[])
{
	if (koef[0] == 0)
	{
		return chybne_zadani;
	}
	double d = koef[1] * koef[1] - 4 * koef[0] * koef[2];
	if (d >= 0)
	{
		x[0] = (-koef[1] + std::sqrt(d)) / (2 * koef[0]);
		x[1] = (-koef[1] - std::sqrt(d)) / (2 * koef[0]);
			return realne;
	}
	else
	{
		x[0] = -koef[1] / (2 * koef[0]);
		x[1] = std::sqrt(-d) / (2 * koef[0]);

			return komplexni;
	}
}

void vypis_reseni(int priznak, double koef[], double koreny[])
{
	std::cout << "Øešení kvadratické rovnice " << koef[0] << "x¡2 + "
		<< koef[1] << "x + " << koef[2] <<  " =0" << std::endl;
	switch (priznak)
	{
	case realne:
		std::cout << "Reáné koøeny";
		std::cout << "x1 = " << koreny[0] << ", x2 = " << koreny[1];

	case komplexni:
		std::cout << "KOMPLEXNE SDRUZENE KORENY";
		std::cout << "x1, x2 = " << koreny[0] << "+- i."
			<< koreny[1];
	case chybne_zadani:
		std::cout << "Zadani nepredstavuje kvadratickou rovnici!";
	}
	std::cout << std::endl;
}
int main()
{
	double koreny[2];
	double koeficienty1[3]{ 1,2,1 };
	int priznak = res_q_rovnici(koeficienty1, koreny);
	vypis_reseni(priznak, koeficienty1, koreny);


	return 0;
}