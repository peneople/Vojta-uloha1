#include	"vektor.h"
const int dim = 3;

vektor::vektor(double _pole[])
{
	for (int i = 0; i < dim; i++)
	{
		vektor::pole[i] = _pole[i];
		
	}
}
vektor::vektor(double x, double y, double z)
{
	pole[0] = x;
	pole[1] = y;
	pole[2] = z;
}