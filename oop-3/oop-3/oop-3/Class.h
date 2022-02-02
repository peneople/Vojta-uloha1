#ifndef __CLASS_H__
#define __CLASS_H__
#endif

#include <iostream>

class Cislo
{
public:
	Cislo(double x, double y);				//konstruktor

	~Cislo();				//destruktor
	  double scitani(double x, double y);
	  double nasobeni(double x, double y);
	  double  odcitani(double x, double y);
	  double deleni(double x, double y);
private:
	double x;
	double y;
	double vys;

};

