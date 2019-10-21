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

void PlikZPrzychodami::dodajPrzychodDoPliku(Przychod przychod)
{
    Przychod Przychod;
    int idPrzychodu = 0, idUzytkownika = 0;
    string data="", opis="", kwota="";

    CMarkup xml;

    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    idPrzychodu = przychod.pobierzIdPrzychodu();
    idUzytkownika = przychod.pobierzIdUzytkownika();
    data = przychod.pobierzDate();
    opis = przychod.pobierzOpis();
    kwota = przychod.pobierzKwote();

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem( "ID_PRZYCHODU", idPrzychodu );
    xml.AddElem( "ID_UZYTKOWNIKA", idUzytkownika );
    xml.AddElem( "DATA", data );
    xml.AddElem( "OPIS", opis );
    xml.AddElem( "KWOTA", kwota );
    xml.Save("Incomes.xml");
}

vector<Przychod> PlikZPrzychodami::wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    vector<Przychod> przychody;
    Przychod przychod;

    int idPrzychodu = 0, idUzytkownika = 0;
    string data ="", opis ="", kwota ="";
    double kwotaLiczbowo =0;

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
            kwota = xml.GetChildData();
            przychod.ustawKwote(kwota);
            kwotaLiczbowo = atof(xml.GetChildData().c_str());
            przychod.ustawKwoteLiczbowo(kwotaLiczbowo);
            przychody.push_back(przychod);
        }
    }
    return przychody;
}

