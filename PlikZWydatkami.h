#ifndef PLIKZWYDATKAMI_H
#define PLIKZWYDATKAMI_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Wydatek.h"
#include "MetodyPomocnicze.h"
#include "PlikXML.h"
#include "Markup.h"

using namespace std;

class PlikZWydatkami :public PlikXML

{
    //string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    int idOstatniegoWydatku;
    //string pobierzLiczbe(string tekst, int pozycjaZnaku);
    //Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    //int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    //int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:

    PlikZWydatkami(string nazwaPliku) : PlikXML(nazwaPliku) {
    idOstatniegoWydatku = 0;
    };

    //bool dopiszAdresataDoPliku(Adresat adresat);
    //vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoWydatku();
    //void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
    //void usunPlik(string nazwaPlikuZRozszerzeniem);
    //void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    //string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    //void edytujWybranaLinieWPliku(Adresat adresat);
};

#endif
