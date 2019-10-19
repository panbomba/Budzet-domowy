#include "BudzetDomowy.h"

BudzetDomowy::BudzetDomowy(string nazwaPlikuZuzytkownikami)
{
    uzytkownikManager.wczytajUzytkownikowZPliku();
}

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


    //if (uzytkownikManager.czyUzytkownikJestZalogowany())
    //{
        //adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,)

    //}

}

void BudzetDomowy::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

void BudzetDomowy::wylogowanieUzytkownika()
{
    uzytkownikManager.wylogowanieUzytkownika();
    //delete adresatMenedzer;
    //adresatMenedzer = NULL;
}

void BudzetDomowy::dodajPrzychod()
{
      if (uzytkownikManager.czyUzytkownikJestZalogowany())
      {
          managerFinansow->dodajPrzychod();
      }
      /*else
      {
          cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
          system ("pause");
      }*/
}

void BudzetDomowy::dodajWydatek()
{
      if (uzytkownikManager.czyUzytkownikJestZalogowany())
      {
          managerFinansow->dodajWydatek();
      }
}

/*void BudzetDomowy::wyswietlWszystkichAdresatow()
{
    if (uzytkownikManager.czyUzytkownikJestZalogowany())
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
    cout << "1. Dodaj Przychod" << endl;
    cout << "2. Dodaj Wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> wybor;
                   switch (wybor)
            {
            case '1':
                dodajPrzychod();
                break;
            case '2':
                dodajWydatek();
                break;
            case '3':
                ;
                break;
            case '4':
                ;
                break;
            case '5':
                ;
                break;
            case '6':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '7':
                wylogowanieUzytkownika();
            }
    }
    return 0;
}

bool BudzetDomowy::czyUzytkownikJestZalogowany()
{
    uzytkownikManager.czyUzytkownikJestZalogowany();
}


