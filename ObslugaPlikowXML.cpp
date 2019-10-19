#include "ObslugaPlikowXML.h"
#include "Uzytkownik.h"
#include "UzytkownikManager.h"
#include "Przychod.h"

void  ObslugaPlikowXML::dodajUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    Uzytkownik Uzytkownik;
    int id = 0;
    string imie="", nazwisko="", login="", haslo="";
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
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
    xml.AddElem( "ID_UZYTKOWNIKA", id ); // CZY TE NAZWY NIE POWINNE BYC PRIVATE ABY NIE DALO SIE NIMI MANIPULOWAC?
    xml.AddElem( "IMIE", imie );
    xml.AddElem( "NAZWISKO", nazwisko );
    xml.AddElem( "LOGIN", login );
    xml.AddElem( "HASLO", haslo );
    xml.Save("users.xml");
}

void ObslugaPlikowXML::dodajPrzychodDoPliku(Przychod przychod)
{
    Przychod Przychod;
    int idPrzychodu = 0, idUzytkownika = 0;
    string data="", opis="";
    float kwota = 0;
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
    xml.AddElem( "ID_PRZYCHODU", idPrzychodu ); // CZY TE NAZWY NIE POWINNE BYC PRIVATE ABY NIE DALO SIE NIMI MANIPULOWAC?
    xml.AddElem( "ID_UZYTKOWNIKA", idUzytkownika );
    xml.AddElem( "DATA", data );
    xml.AddElem( "OPIS", opis );
    xml.AddElem( "KWOTA", kwota );
    xml.Save("Incomes.xml");
}

void ObslugaPlikowXML::wczytajDaneUzytkownikaZPliku()
{
    CMarkup xml;
    string szukanyLogin = "";
    string hasloSzukanegoLoginu ="";

//DLA ZADANEGO LOGINU FUNKCJA ZWRACA HASLO

    cout << "Podaj login, dla ktorego mam podac haslo: ";
    cin >> szukanyLogin;
    xml.Load( "users.xml" );
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("User") )
    {
        xml.FindChildElem( "LOGIN" );
        if ( xml.GetChildData() == szukanyLogin )
        {
            xml.FindChildElem("HASLO");
            cout << "OK" << endl;;
            hasloSzukanegoLoginu = xml.GetChildData();
            cout << "Haslo tego uzytkownika to: " << hasloSzukanegoLoginu << endl;
            system ("pause");
        }
    }
}

vector<Uzytkownik> ObslugaPlikowXML::wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;
    vector<Uzytkownik> uzytkownicy;
    int id = 0;
    string imie ="", nazwisko ="", login="", haslo="";
    CMarkup xml;

    xml.Load( "users.xml" );
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

void ObslugaPlikowXML::zapiszNoweHasloDoPliku(int idZalogowanegoUzytkownika, string noweHaslo)
{
    CMarkup xml;
    UzytkownikManager uzytkownikManager;

    xml.Load( "users.xml" );
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
            xml.Save("users.xml");
        }
    }
}

