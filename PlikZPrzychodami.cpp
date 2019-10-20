#include "PlikZPrzychodami.h"

int PlikZPrzychodami::pobierzIdOstatniegoPrzychodu()
{
    int idOstatniegoPrzychodu = 0;

    CMarkup xml;

    xml.Load( NAZWA_PLIKU );
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Income") )
    {
        idOstatniegoPrzychodu++;
    }
    return idOstatniegoPrzychodu;
}

vector<Przychod> PlikZPrzychodami::wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    vector<Przychod> przychody;
    Przychod przychod;

    int idPrzychodu = 0, idUzytkownika = 0;
    string data ="", opis ="";
    float kwota =0;

    CMarkup xml;

    xml.Load( NAZWA_PLIKU );
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Income") )
    {
        xml.FindChildElem( "ID_UZYTKOWNIKA" );
        if (atoi(xml.GetChildData().c_str()) == idZalogowanegoUzytkownika )
        {
            xml.ResetChildPos();

            xml.FindChildElem("ID_PRZYCHODU");
            idPrzychodu = atoi(xml.GetChildData().c_str());
            przychod.ustawIdPrzychodu(idPrzychodu);
            xml.FindChildElem("ID_UZYTKOWNIKA");
            idUzytkownika = atoi(xml.GetChildData().c_str());
            przychod.ustawIdUzytkownika(idUzytkownika);
            xml.FindChildElem("DATA");
            data = xml.GetChildData();
            przychod.ustawDate(data);
            xml.FindChildElem("OPIS");
            opis = xml.GetChildData();
            przychod.ustawOpis(opis);
            xml.FindChildElem("KWOTA");
            kwota = atof(xml.GetChildData().c_str());
            przychod.ustawKwote(kwota);
            przychody.push_back(przychod);
        }
    }
    return przychody;
}

