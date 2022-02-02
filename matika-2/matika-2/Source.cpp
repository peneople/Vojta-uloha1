#include <iostream>
#include "bod.h"
#include <cstdlib>

double sqr(double x)
{

	return x * x;
}
double vzdalenost(bod A, bod B)
{

	return std::sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}

double plocha_trojuhelnika(bod A, bod B, bod C)
{
	double a = vzdalenost(A, B);
	double b = vzdalenost(B, C);
	double c = vzdalenost(C, A);
	double s = (a + b + c) / 2;
		return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
	bod A{ 0,0 }, B{ 0,1 }, C{ 1,0 };
	std::cout << "Plocha trojuhelnika je " << plocha_trojuhelnika(A, B, C) << std::endl;
}