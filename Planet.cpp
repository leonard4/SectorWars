#include "Planet.h"

Planet::Planet()
{
    planetName = "Blank";
    planetType = 1;

    planetClassType[0] = 'M';
    planetClassType[1] = 'K';
    planetClassType[2] = 'O';
    planetClassType[3] = 'L';
    planetClassType[4] = 'C';
    planetClassType[5] = 'H';
    planetClassType[6] = 'U';

    planetClassName[0] = "Earth";
    planetClassName[1] = "Desert";
    planetClassName[2] = "Oceanic";
    planetClassName[3] = "Mountain";
    planetClassName[4] = "Glacial";
    planetClassName[5] = "Volcanic";
    planetClassName[6] = "Gaseous";
}

Planet::~Planet()
{
    //dtor
}
