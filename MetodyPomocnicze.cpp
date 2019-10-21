#include <sstream>
#include <algorithm>
#include "MetodyPomocnicze.h"
#include <ctime>

string MetodyPomocnicze::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

char MetodyPomocnicze::wczytajZnak()
{
    cin.clear();
    cin.sync();
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::pobierzDateZSystemu()
{
    string rokString ="", miesiacString ="", dzienString ="", dzisiejszaData ="";
    int rok = 0, miesiac = 0, dzien = 0, dzienRoku = 0;
    time_t teraz = time(0);
    tm *ltm = localtime(&teraz);

    rok = (1900 + ltm->tm_year);
    rokString = konwerjsaIntNaString(rok);
    miesiac = (1 + ltm->tm_mon);
    miesiacString = konwerjsaIntNaString(miesiac);
    dzien = (ltm->tm_mday);
    dzienString = konwerjsaIntNaString(dzien);

    dzisiejszaData = (rokString + "-" + miesiacString + "-" + dzienString);

    return dzisiejszaData;
}



