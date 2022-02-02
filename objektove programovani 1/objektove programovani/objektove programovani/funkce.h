#pragma once
#ifndef __FUNKCE_H__
#define __FUNKCE_H__
#include <string>
#include <iostream>
using namespace std;

class Napis
{
public:
	Napis(string txt);
	Napis();
	~Napis();
	string text() 
		{ return _text; }
	void text(string txt)
	{	_text = txt;}
	void vypis();
	static int pocet_napisu();
	
private:
	string _text;
	static int pocet;
};
#endif


