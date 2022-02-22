#include<iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

//static int cisla[100];//pole s hodnotama 
const char cesta[] = "C:\\Users\\jakub\\Desktop";
string vysledek;
char pole_cisel[800];// pole s sestnackove zapsanymi cisly 
int delka_pole_cisel=0;
char pole_dva[800]; //spravne jen cisla 
int pole_tri[800];	//jen cisla v int 
int delka_pole_dva = 0;
int pole_delka[400];
// pole s informaci jak ma byt cislo dlouhe 
int pole_len[]{1,2,2,2,2,2,2,2,2,2,2,2,1,2,1,2,1,2,1,4,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,1,4,4,2,1,2,2,2,2,2,1,2,2,2,4,2,2,2,2,2,2,2,4,4,4,4,2,2,1,4,4,4,2};
int pole_carka[400];
// pole s informaci kolik ma cislo desetinnych mist 
int pole_dec[]{ 0,0,1,0,0,0,0,0,0,0,0,3,0,3,0,3,0,3,0,3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,1,0,0,0,0,0,0,3,3,0,2,2,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0 };
const int delka_pole_len = 74;
int pole_vys[74];
//enum prevod {'0' = 0, '1' = 1,'2'=2,'3'=3,'4'=4,'5'=5,'6'=6,'7'=7,'8'=8,'9'=9,'a' = 10, 'b' = 11, 'c' = 12, 'd' = 13, 'e' = 14, 'f' = 15 };








void cteni(string jmeno) // nacteni stringu ze souboru do promenne vysledek
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
	
}
void plnicka(char *pole)		//prepis sestnackovych cisel z vysledek do pole int 
{
	 int odraz = 57;
		int n = 0;
	int i = 6;
	int j = 0;
	cout << endl << "Plnime pole" << endl;
	while (n != 2)
	{
		
		int mezi;
		mezi = vysledek[i];
			if (mezi== '\n')
			{
				n++;
				
				break;
				
			}
			else if (mezi == 84)			//zbytecne ? 
			{
				break;
			}
			else
			{
				
				pole[j] = mezi;
				i++, j++;
			

			}
			

	}
	delka_pole_cisel = j;
	cout << "prvku v poli " << j << " ";
	return;
}

void pole_trizeni(char* pole)		// trizeni pole_cisel aby zustala jen cisla a 0x se odseknulo
{
	int mezi = 0;
	int j=2, i=0;
	while (i < delka_pole_cisel)		//i<304
	{
		pole_dva[i] = pole[j];
		pole_dva[i + 1] = pole[j + 1];
		j = j + 5;
		i = i + 2;



	}
	delka_pole_dva = i;

	return;
}
void pole_trizeni2(char* pole)				//trizeni pro naplneni poli s informacemi o delce cisla a desetinne carce, zatim nepotrebne
{
	int mezi = 0;
	int j = 2, i = 315;
	while (i < 800)		//i<304
	{
		pole_delka[i] = pole[j];
		pole_carka[i +1] = pole[j + 1];
		j = j + 2;
		i = i + 2;



	}


	return;
}
void prevod_ascii(char* pole2, int* pole3)	//prevod z char na int pomoci ascii tabulky 
{
	for (int i = 0; i < delka_pole_dva; i++)
	{
		int mezi = 0;
		mezi = (int)pole2[i];
		if ((mezi >= 48) && (mezi <= 57))	//prevod cisel
		{
			mezi = mezi - 48;
			pole3[i] = mezi;

		}
		else if ((mezi >= 97) && (mezi <= 102))	//prevod pismen
		{
			mezi = mezi-87;
			pole3[i] = mezi;
		}
	}
}

void prehozeni(int* pole3, int* pole_del)		// cilem je seradit cisla aby sla spravne za sebou a nebyla na preskacku
{
	int i, j;
	int k = 0;
	int prvek_pole = 0;
	int* mezi;
	for (i = 0; i < delka_pole_len; i++)
	{
		mezi = new int[2 * pole_del[i]];
													//nasobi se dvema protoze ja pristupuju po jednotlivich cislech a ne po dvojicich 
		
		for (k = prvek_pole + (2 * pole_del[i]), j=0; k > prvek_pole; k=k-2, j=j+2)
		{
						
			
			mezi[j] = pole3[k-2];		//k-2 sedi potom od pocatku mozne problemy ke konci pole 
			mezi[j + 1] = pole3[k-1];
		}
		for (k = prvek_pole, j = 0; k < (prvek_pole + (2 * pole_del[i])); k=k+2, j=j+2)
		{
						
			pole3[k] = mezi[j];
			pole3[k+1] = mezi[j+1];
		}
		prvek_pole = prvek_pole + (2 * pole_del[i]);

			
		
		delete[] mezi;
	}










}
void vypocet_cisla(int* pole3, int* pole_del, int* pole_decimal)	//vypocet pomoci mocnin 16 + vydeleni aby byl pozadovany pocet desetinnych mist
{																//ohlidat deleni nulou !!!
	int vys=0;
	int i, j;
	int prvek_pole = 0;	

	for (i = 0; i < delka_pole_len; i++)
	{
		for (j = 0; j < (2*pole_del[i]); j++, prvek_pole++)
		{
			
			
			
				vys=pole3[prvek_pole + (2 * pole_del[i]) - j] << j;
				
				
				vys = vys + pole3[prvek_pole + (2 * pole_del[i]) - j];


			

			
		}
		pole_vys[i] = vys;
		vys = 0;
	}
}




int main()
{
	std::ifstream myfile("vojta_uloha1.txt");
	
	cteni("vojta_uloha1.txt");
	cout << vysledek << endl;
	plnicka(pole_cisel);
	std::cout << "Delka stringu " << vysledek.size() << std::endl;
	//posunovac(pole_cisel);
	//cout << endl << strlen(vysledek) << endl;
	pole_trizeni(pole_cisel);
	//pole_trizeni2(pole_cisel);
	cout << "delka pole dva " << delka_pole_dva<<endl;
	prevod_ascii(pole_dva, pole_tri);
	prehozeni(pole_tri, pole_len);
	vypocet_cisla(pole_tri, pole_len, pole_dec);
	for (int i = 0; i < delka_pole_dva; i++)
	{
		cout << pole_tri[i] << " ";

	}
	cout << endl;
	for (int i = 0; i < delka_pole_len; i++)
	{
		cout << pole_vys[i] << " ";

	}

	

	return 0;
}