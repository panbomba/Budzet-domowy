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

