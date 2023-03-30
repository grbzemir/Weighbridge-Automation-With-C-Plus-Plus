#ifndef STOK_H
#define STOK_H
#include "Tanimlama.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<stdio.h>
#include<fstream>
#include <stddef.h>
#include<conio.h>

using namespace std;

class Stok
{
	public:
		Stok();
		~Stok();

       Tanimlama t1;
       int stokNumarasiUret();
       void aracGiris();
       void aracCikis();
       void bekleyenAraclar();
       void raporlar();

       int menu();

       void giris();



};

#endif