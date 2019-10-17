#include <iostream>
#include <ctime> //already includes struct tm

using namespace std;

int main()
{
    time_t teraz = time(0);
    tm *ltm = localtime(&teraz);
    int rok = 0, miesiac = 0, dzien = 0, dzienRoku = 0;

    rok = (1900 + ltm->tm_year);
    miesiac = (1 + ltm->tm_mon);
    dzien = (ltm->tm_mday);
    dzienRoku = (ltm->tm_yday);

        // MAM DZIEKI TEMU ROK, MIESIAC I DZIEN W FORMIE INT - BEDZIE MOZNA WYKONYWAC DZIALANIA MATEMATYCZNE
    cout << "Rok: " << rok <<endl;
    cout << "Miesiac: "<< miesiac << endl;
    cout << "Dzien: " << dzien << endl;
    cout << "Jest to dzien roku numer: " << dzienRoku << endl;

    return 0;
}
