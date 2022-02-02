#pragma once
#ifdef __VEKTOR_H_
#define __VEKTOR_H_
const int dim = 3;

class vektor
{
	double pole[dim];	//slozky vektoru
	public:
		vektor(double x, double y, double z);
		vektor(double _pole[]);
		vektor();
		vektor plus(vektor w);
		void vypis


};
#endif // __VEKTOR_H_
