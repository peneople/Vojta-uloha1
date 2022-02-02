#include "pozdrav.h"
#include <iostream>


void pozdrav::pozdrav1(std::string jmeno )
{
	std::cout << text << " " << jmeno << std::endl;


}
void pozdrav::nacteni()
{
	std::cin >> pozdrav::x;
	std::cin >> pozdrav::y;
	std::cout << x << y << std::endl;



}
