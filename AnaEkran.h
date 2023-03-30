#ifndef ANAEKRAN_H
#define ANAEKRAN_H
#include "Stok.h"
#include "Sevkiyat.h"
#include<iostream>

using namespace std;


class AnaEkran
{
	public:
	int menu();
	void giris();
	Stok stok;
	Sevkiyat sevk;
	
};

#endif