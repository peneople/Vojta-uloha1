#include<iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

//static int cisla[100];//pole s hodnotama 
const char cesta[] = "C:\\Users\\jakub\\Desktop";
string vysledek;
int pole_cisel[];
void cteni(string jmeno)
{
	ifstream vstup(jmeno);
	if (!vstup)
	{
		cerr << "Failed attempt to open file " << jmeno << endl;
		return;
	}
	int i;
	while (vstup >> i)
	{
		cout << i << " ";
	}
	vstup.clear();
	string textik;
	while (vstup >> textik)
	{
		vysledek += textik + " ";
	}
	cout << vysledek << endl;
}

int main()
{
	std::ifstream myfile("vojta_uloha.txt");
	
	cteni("vojta_uloha.txt");
	cout << vysledek << endl;
	
	return 0;




}