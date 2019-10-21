#include "UzytkownikManager.h"
#include "MetodyPomocnicze.h"

void UzytkownikManager::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dodajUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    MetodyPomocnicze metodyPomocnicze;

    uzytkownik.ustawIdUzytkownika(pobierzIdNowegoUzytkownika());

    string imie;
    cin.clear();
    cin.sync();
    cout << "Podaj imie: ";
    imie = metodyPomocnicze.wczytajLinie();
    uzytkownik.ustawImie(imie);

    string nazwisko;
    cin.clear();
    cin.sync();
    cout << "Podaj nazwisko: ";
    nazwisko = metodyPomocnicze.wczytajLinie();
    uzytkownik.ustawNazwisko(nazwisko);

    string login;
    do
    {
        cin.clear();
        cin.sync();
        cout << "Podaj login: ";
        login = metodyPomocnicze.wczytajLinie();
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cin.clear();
    cin.sync();
    cout << "Podaj haslo: ";
    haslo = metodyPomocnicze.wczytajLinie();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikManager::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzIdUzytkownika() + 1;
}

bool UzytkownikManager::czyIstniejeLogin(string login)
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UzytkownikManager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}


void UzytkownikManager::wypiszWszystkichUzytkownikow()
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzIdUzytkownika() << endl;
        cout << uzytkownicy[i].pobierzImie() << endl;
        cout << uzytkownicy[i].pobierzNazwisko() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
    system("pause");
}

void UzytkownikManager::logowanieUzytkownika()
{

    Uzytkownik uzytkownik;

    string login1 = "", haslo1 = "";

    cout << endl << "Podaj login: ";
    cin >> login1;

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login1)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo1;

                if (itr -> pobierzHaslo() == haslo1)
                {
                    idZalogowanegoUzytkownika = itr -> pobierzIdUzytkownika();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");

    return;
}

void UzytkownikManager::zmianaHaslaZalogowanegoUzytkownika()
{
    Uzytkownik uzytkownik;
    system("cls");
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzIdUzytkownika() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszNoweHasloDoPliku(idZalogowanegoUzytkownika, noweHaslo);
}

bool UzytkownikManager::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

void UzytkownikManager::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}

void UzytkownikManager::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}
