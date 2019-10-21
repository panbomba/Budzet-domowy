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

bool sprawdzaniePoprawnegoFormatuDaty(string wpisanaData);
bool sprawdzaniePoprawnychWartosciWpisanejDaty(string wpisanaData);

string zamianaDatyNaSameCyfry(string wpisanaData);
string zamienPrzecinekNaKropke (string wpisanaKwota);
    //UstalIleDniJestWSprawdzanymOkresie ??
    //PosortujWynikiWedlugDaty

};

#endif
