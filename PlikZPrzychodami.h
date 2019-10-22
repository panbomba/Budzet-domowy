#ifndef PLIKZPRZYCHODAMI_H
#define PLIKZPRZYCHODAMI_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Przychod.h"
#include "PlikXML.h"
#include "Markup.h"
#include "PracaZDatami.h"

using namespace std;

class PlikZPrzychodami :public PlikXML

{
    int idOstatniegoPrzychodu;

public:

    PlikZPrzychodami(string nazwaPliku) : PlikXML(nazwaPliku)
    {
        idOstatniegoPrzychodu = 0;
    };

    void dodajPrzychodDoPliku(Przychod przychod);
    vector<Przychod> wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoPrzychodu();
};

#endif
