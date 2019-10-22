#include "Wydatek.h"

void Wydatek::ustawIdWydatku(int noweIdWydatku)
{
    if (noweIdWydatku >= 0)
        idWydatku = noweIdWydatku;
}

int Wydatek::pobierzIdWydatku()
{
    return idWydatku;
}

