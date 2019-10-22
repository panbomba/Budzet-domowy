#ifndef PLIKXML_H
#define PLIKXML_H

#include <iostream>

using namespace std;

class PlikXML
{
public:

    PlikXML(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku)
    {
    }
    const string NAZWA_PLIKU;
    string pobierzNazwePliku();
};

#endif
