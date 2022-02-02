#include <iostream>
#include	"pozdrav.h"
using namespace std;

int main()
{
	pozdrav _Pozdrav;
	_Pozdrav.pozdrav1("Pepa");
	_Pozdrav.pozdrav1("karel");
	_Pozdrav.text = "Vitam te krali";
		_Pozdrav.pozdrav1("Jakube");
		_Pozdrav.nacteni();
		
		cin.get();
	return 0;
}