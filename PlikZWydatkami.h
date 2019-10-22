#ifndef PLIKZWYDATKAMI_H
#define PLIKZWYDATKAMI_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Wydatek.h"
#include "PlikXML.h"
#include "Markup.h"
#include "PracaZDatami.h"

using namespace std;

class PlikZWydatkami :public PlikXML

{
    int idOstatniegoWydatku;

public:

    PlikZWydatkami(string nazwaPliku) : PlikXML(nazwaPliku)
    {
        idOstatniegoWydatku = 0;
    };

    void dodajWydatekDoPliku(Wydatek wydatek);
    vector<Wydatek> wczytajWydatkiZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoWydatku();
};

#endif
