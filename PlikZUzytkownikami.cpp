#include "PlikZUzytkownikami.h"
#include "Markup.h"

vector<Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;
    vector<Uzytkownik> uzytkownicy;
    int id = 0;
    string imie ="", nazwisko ="", login="", haslo="";
    CMarkup xml;

    xml.Load( NAZWA_PLIKU );
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("User") )
    {
        xml.FindChildElem( "ID_UZYTKOWNIKA" );
        id = atoi(xml.GetChildData().c_str());
        xml.FindChildElem("IMIE");
        imie = xml.GetChildData();
        xml.FindChildElem("NAZWISKO");
        nazwisko = xml.GetChildData();
        xml.FindChildElem("LOGIN");
        login = xml.GetChildData();
        xml.FindChildElem("HASLO");
        haslo = xml.GetChildData();

        uzytkownik.ustawIdUzytkownika(id);
        uzytkownik.ustawImie(imie);
        uzytkownik.ustawNazwisko(nazwisko);
        uzytkownik.ustawLogin(login);
        uzytkownik.ustawHaslo(haslo);

        uzytkownicy.push_back(uzytkownik);
    }

    return uzytkownicy;
}

void PlikZUzytkownikami::dodajUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    Uzytkownik Uzytkownik;
    int id = 0;
    string imie="", nazwisko="", login="", haslo="";
    CMarkup xml;

    bool fileExists = xml.Load( NAZWA_PLIKU );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(NAZWA_PLIKU);
    }

    id = uzytkownik.pobierzIdUzytkownika();
    imie = uzytkownik.pobierzImie();
    nazwisko = uzytkownik.pobierzNazwisko();
    login = uzytkownik.pobierzLogin();
    haslo = uzytkownik.pobierzHaslo();

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem( "ID_UZYTKOWNIKA", id );
    xml.AddElem( "IMIE", imie );
    xml.AddElem( "NAZWISKO", nazwisko );
    xml.AddElem( "LOGIN", login );
    xml.AddElem( "HASLO", haslo );
    xml.Save( NAZWA_PLIKU);
}

void PlikZUzytkownikami::zapiszNoweHasloDoPliku(int idZalogowanegoUzytkownika, string noweHaslo)
{
    CMarkup xml;

    xml.Load( NAZWA_PLIKU );
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("User") )
    {
        xml.FindChildElem( "ID_UZYTKOWNIKA" );
        if (atoi(xml.GetChildData().c_str()) == idZalogowanegoUzytkownika )
        {
            xml.FindChildElem("HASLO");
            xml.IntoElem();
            xml.RemoveElem();
            xml.AddElem( "HASLO", noweHaslo );
            xml.Save(NAZWA_PLIKU);
        }
    }
}
