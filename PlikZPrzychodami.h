#ifndef PLIKZPRZYCHODAMI_H
#define PLIKZPRZYCHODAMI_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Przychod.h"
#include "MetodyPomocnicze.h"
#include "PlikXML.h"

using namespace std;

class PlikZPrzychodami :public PlikXML

{
    //string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    int idOstatniegoAdresata;
    //string pobierzLiczbe(string tekst, int pozycjaZnaku);
    //Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    //int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    //int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:

    PlikZPrzychodami(string nazwaPliku) : PlikXML(nazwaPliku) {
    idOstatniegoAdresata = 0;
    };

    //bool dopiszAdresataDoPliku(Adresat adresat);
    //vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    //int pobierzIdOstatniegoAdresata();
    //void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
    //void usunPlik(string nazwaPlikuZRozszerzeniem);
    //void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    //string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    //void edytujWybranaLinieWPliku(Adresat adresat);
};

#endif
