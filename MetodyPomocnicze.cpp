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

bool MetodyPomocnicze::sprawdzaniePoprawnegoFormatuDaty(string wpisanaData)
{
    int dlugosc = 0;
    dlugosc = wpisanaData.length();

    if ((dlugosc == 10)&&(wpisanaData[4] == '-') && (wpisanaData[7] == '-')
            && ((wpisanaData[0] >= 48) &&(wpisanaData[0] <=57))
            && ((wpisanaData[1] >= 48) &&(wpisanaData[1] <=57))
            && ((wpisanaData[2] >= 48) &&(wpisanaData[2] <=57))
            && ((wpisanaData[3] >= 48) &&(wpisanaData[3] <=57))
            && ((wpisanaData[5] >= 48) &&(wpisanaData[5] <=57))
            && ((wpisanaData[6] >= 48) &&(wpisanaData[6] <=57))
            && ((wpisanaData[8] >= 48) &&(wpisanaData[8] <=57))
            && ((wpisanaData[9] >= 48) &&(wpisanaData[9] <=57)))
        return true;

    else
        return false;


}

bool MetodyPomocnicze:: sprawdzaniePoprawnychWartosciWpisanejDaty(string wpisanaData)
{
    string tylkoRok = "", tylkoMiesiac = "", tylkoDzien = "";
    int tylkoRokLiczba = 0, tylkoMiesiacLiczba = 0, tylkoDzienLiczba = 0;
    tylkoRok = wpisanaData.substr(0,4);
    tylkoMiesiac = wpisanaData.substr(5,2);
    tylkoDzien = wpisanaData.substr(8,2);

    tylkoRokLiczba = atoi(tylkoRok.c_str());
    tylkoMiesiacLiczba = atoi(tylkoMiesiac.c_str());
    tylkoDzienLiczba = atoi(tylkoDzien.c_str());

    ;
}

string MetodyPomocnicze::zamianaDatyNaSameCyfry(string wpisanaData)
{
    string sformatowanaData = "";
    string tylkoRok = "";
    string tylkoMiesiac = "";
    string tylkoDzien = "";

    tylkoRok = wpisanaData.substr(0,4);
    tylkoMiesiac = wpisanaData.substr(5,2);
    tylkoDzien = wpisanaData.substr(8,2);
    cout << tylkoRok << endl;
    cout << tylkoMiesiac << endl;
    cout << tylkoDzien << endl;
    system ("pause");
    sformatowanaData = tylkoRok + tylkoMiesiac + tylkoDzien;
    cout << sformatowanaData;
    system("pause");
    return sformatowanaData;
}



