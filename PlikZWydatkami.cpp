#include "PlikZWydatkami.h"

int PlikZWydatkami::pobierzIdOstatniegoWydatku()
{
    int idOstatniegoWydatku = 0;

    CMarkup xml;

    xml.Load( NAZWA_PLIKU );
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") )
    {
        idOstatniegoWydatku++;
    }
    return idOstatniegoWydatku;
}

vector<Wydatek> PlikZWydatkami::wczytajWydatkiZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    vector<Wydatek> wydatki;
    Wydatek wydatek;

    int idWydatku = 0, idUzytkownika = 0;
    string data ="", opis ="";
    float kwota =0;

    CMarkup xml;

    xml.Load( NAZWA_PLIKU );
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") )
    {
        xml.FindChildElem( "ID_UZYTKOWNIKA" );
        if (atoi(xml.GetChildData().c_str()) == idZalogowanegoUzytkownika )
        {
            xml.ResetChildPos();

            xml.FindChildElem("ID_WYDATKU");
            idWydatku = atoi(xml.GetChildData().c_str());
            wydatek.ustawIdWydatku(idWydatku);
            xml.FindChildElem("ID_UZYTKOWNIKA");
            idUzytkownika = atoi(xml.GetChildData().c_str());
            wydatek.ustawIdUzytkownika(idUzytkownika);
            xml.FindChildElem("DATA");
            data = xml.GetChildData();
            wydatek.ustawDate(data);
            xml.FindChildElem("OPIS");
            opis = xml.GetChildData();
            wydatek.ustawOpis(opis);
            xml.FindChildElem("KWOTA");
            kwota = atof(xml.GetChildData().c_str());
            wydatek.ustawKwote(kwota);
            wydatki.push_back(wydatek);
        }
    }
    return wydatki;
}

