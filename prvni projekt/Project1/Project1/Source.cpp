#include <iostream>
using namespace std;

int main()
{
	// hello world
	cout << "Hello world" << endl;

	cout << "Zadej cele cislo" << endl;

	int hodnota1, hodnota2, vysledek;
	cin >> hodnota1 >> hodnota2;
	if (hodnota1 > hodnota2)
	{
		vysledek = hodnota1;
	}
	/*else if (hodnota1 == hodnota2)
	{
		cout << "Jsou stejna" << endl;
		vysledek = NULL;
	} */
	else
	{
		vysledek = hodnota2;

	}

	cout << "Vetsi je " << vysledek << endl;
	//verze dva 
	cout << "zadej dve cela cisla" << endl;
	int m, n;
	cin >> m >> n;
	cout << " vetsi je " << ((m > n) ? m : n) << endl;
	//uloha 3 faktorial
	cout << " Zadej cislo pro vypocet faktorialu" << endl;
	int faktorial;
	cin >> faktorial;
	int vypocet;
	int o{ 1 };
	vypocet = faktorial;

	if (faktorial >= 0)
	{
		while (o < vypocet)
		{
			faktorial = o * faktorial;
			o++;
		}
		cout << "Faktorial cisla " << vypocet << " je " << faktorial << endl;
	}
	else
	{
		cout << "Takovy faktorial nefunguje" << endl;
	}
	
	return 0;
}

















