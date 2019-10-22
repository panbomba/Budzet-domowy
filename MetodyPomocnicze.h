#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
using namespace std;

class MetodyPomocnicze
{
public:
    string wczytajLinie();
    char wczytajZnak();
    static string konwerjsaIntNaString(int liczba);
    string zamienPrzecinekNaKropke (string wpisanaKwota);
};

#endif
