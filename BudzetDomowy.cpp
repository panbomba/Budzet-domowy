#include "BudzetDomowy.h"

void BudzetDomowy::rejestracjaUzytkownika()
{
    uzytkownikManager.rejestracjaUzytkownika();
}

void BudzetDomowy::wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

int BudzetDomowy::logowanieUzytkownika()
{
    uzytkownikManager.logowanieUzytkownika();
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        ; //adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void BudzetDomowy::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

/*void BudzetDomowy::usunAdresata()
{
    adresatMenedzer->usunAdresata();
}

void BudzetDomowy::edytujAdresata()
{
    adresatMenedzer->edytujAdresata();
}*/

void BudzetDomowy::wylogowanieUzytkownika()
{
    uzytkownikManager.wylogowanieUzytkownika();
    //delete adresatMenedzer;
    //adresatMenedzer = NULL;
}

/*void BudzetDomowy::dodajAdresata()
{
      if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
      {
          adresatMenedzer->dodajAdresata();
      }
      else
      {
          cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
          system ("pause");
      }
}

void BudzetDomowy::wyswietlWszystkichAdresatow()
{
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer->wyswietlWszystkichAdresatow();
    }
}*/

char BudzetDomowy::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;
    //MetodyPomocnicze metodyPomocnicze;
    while (uzytkownikManager.czyUzytkownikJestZalogowany())
    {
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> wybor; //TO ZAMIENIC NA FUNKCJE BO POTRZEBNY JEST CHECK CZY PRAWIDLOWA WARTOSC
    //wybor = metodyPomocnicze.wczytajZnak();
                   switch (wybor)
            {
            case '1':
                ;
                //dodajAdresata();
                break;
            case '2':
                ;
                break;
            case '3':
                ;
                break;
            case '4':
                ;
                //wyswietlWszystkichAdresatow();
                break;
            case '5':
                ;
                //usunAdresata();
                break;
            case '6':
                ;
                //edytujAdresata();
                break;
            case '7':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                wylogowanieUzytkownika();
            }
    }
    return 0;
}


