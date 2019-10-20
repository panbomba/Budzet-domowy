#include "ObslugaPlikowXML.h"
#include "Uzytkownik.h"
#include "UzytkownikManager.h"
#include "Przychod.h"

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
    xml.AddElem( "ID_PRZYCHODU", idPrzychodu );
    xml.AddElem( "ID_UZYTKOWNIKA", idUzytkownika );
    xml.AddElem( "DATA", data );
    xml.AddElem( "OPIS", opis );
    xml.AddElem( "KWOTA", kwota );
    xml.Save("Incomes.xml");
}

void ObslugaPlikowXML::dodajWydatekDoPliku(Wydatek wydatek)
{
    Wydatek Wydatek;
    int idWydatku = 0, idUzytkownika = 0;
    string data="", opis="";
    float kwota = 0;
    CMarkup xml;

    bool fileExists = xml.Load( "Expenses.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    idWydatku = wydatek.pobierzIdWydatku();
    idUzytkownika = wydatek.pobierzIdUzytkownika();
    data = wydatek.pobierzDate();
    opis = wydatek.pobierzOpis();
    kwota = wydatek.pobierzKwote();

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem( "ID_WYDATKU", idWydatku ); // CZY TE NAZWY NIE POWINNE BYC PRIVATE ABY NIE DALO SIE NIMI MANIPULOWAC?
    xml.AddElem( "ID_UZYTKOWNIKA", idUzytkownika );
    xml.AddElem( "DATA", data );
    xml.AddElem( "OPIS", opis );
    xml.AddElem( "KWOTA", kwota );
    xml.Save("Expenses.xml");
}

void ObslugaPlikowXML::wczytajDaneUzytkownikaZPliku()
{
    CMarkup xml;
    string szukanyLogin = "";
    string hasloSzukanegoLoginu ="";

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


