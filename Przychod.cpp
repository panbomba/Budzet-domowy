#include "Przychod.h"

void Przychod::ustawIdPrzychodu(int noweIdPrzychodu)
{
    if (noweIdPrzychodu >= 0)
        idPrzychodu = noweIdPrzychodu;
}

int Przychod::pobierzIdPrzychodu()
{
    return idPrzychodu;
}

