#ifndef SEVKIYAT_H
#define SEVKIYAT_H
#include "Tanimlama.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<stdio.h>
#include<fstream>
#include <stddef.h>
#include<conio.h>

using namespace std;

class Sevkiyat
{
	public:
		Sevkiyat();
		~Sevkiyat();

       Tanimlama t1;
       int SevkiyatNumarasiUret();
       void aracGiris();
       void aracCikis();
       void bekleyenAraclar();
       void raporlar();

       int menu();

       void giris();



};

#endif
