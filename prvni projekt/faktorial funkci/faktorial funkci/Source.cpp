#include <iostream>
#include "funkce.h"


int faktorial(int hodnota)
{
	if (hodnota == 0)
	{
		return 1;
	}
	else
	{
		return hodnota * faktorial(hodnota - 1);
	}

}