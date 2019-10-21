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
    string pobierzDateZSystemu();
    static string konwerjsaIntNaString(int liczba);


    // DODAC
    //sprawdzPoprawnoscFormatuDaty
    //zamienPrzecinekNaKropke
    //UstalIleDniJestWSprawdzanymOkresie ??
    //PosortujWynikiWedlugDaty

};

#endif
