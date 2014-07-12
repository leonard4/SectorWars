#include <iostream>
#include "Sector.h"

using namespace std;

Sector::Sector()
{
    sectorNum = 0;
    regionName = "Empty Region";
    sectorName = "Empty Sector";
    explored = false;
    linked = false;

    // Setup connections to be null
    for (int i = 0; i < MAX_CONNECTIONS; i++)
    {
        connections[i] = 0;
    }
    // Setup each planet to be null
    for (int i = 0; i < MAX_PLANETS; i++)
    {
        planets[i] = new Planet();
    }
    // Setup each planet to be null
    for (int i = 0; i < MAX_STARPORTS; i++)
    {
        starports[i] = NULL;
    }
    // Setup each planet to be null
    for (int i = 0; i < MAX_CELESTIALS; i++)
    {
        celestials[i] = NULL;
    }
}

// Creates a blank sector for the number passed
Sector::Sector(int num)
{
    sectorNum = num;
    regionName = "Empty Region";
    sectorName = "Empty Sector";
    explored = false;
    linked = false;

    for (int i = 0; i < MAX_CONNECTIONS; i++)
    {
        connections[i] = 0;
    }
    // Setup each planet to be null
    for (int i = 0; i < MAX_PLANETS; i++)
    {
        planets[i] = new Planet();
    }
    // Setup each planet to be null
    for (int i = 0; i < MAX_STARPORTS; i++)
    {
        starports[i] = NULL;
    }
    // Setup each planet to be null
    for (int i = 0; i < MAX_CELESTIALS; i++)
    {
        celestials[i] = NULL;
    }
}

Sector::Sector(int num, string region, string sector, bool exp, bool link)
{
    sectorNum = num;
    regionName =  region;
    sectorName = sector;
    explored = exp;
    linked = link;

    for (int i = 0; i < MAX_CONNECTIONS; i++)
    {
        connections[i] = 0;
    }
    // Setup each planet to be null
    for (int i = 0; i < MAX_PLANETS; i++)
    {
        planets[i] = new Planet();
    }
    // Setup each planet to be null
    for (int i = 0; i < MAX_STARPORTS; i++)
    {
        starports[i] = new Starport();
    }
    // Setup each planet to be null
    for (int i = 0; i < MAX_CELESTIALS; i++)
    {
        celestials[i] = new Celestial();
    }
}
// Deconstructor
Sector::~Sector()
{
    // Clean up any leftover pointers
    // for (int i = 0; i < MAX_PLANETS; i++)
        delete planets;

    // for (int i = 0; i < MAX_PLANETS; i++)
        delete starports;

    // for (int i = 0; i < MAX_PLANETS; i++)
        delete celestials;
}

// Displays the sector info in a full mode
void Sector::displaySectorFull()
{
    cout << "Sector Number: " << sectorNum << endl;
    cout << "Region Name: " << regionName << endl;
    cout << "Sector Name: " << sectorName << endl;
    cout << "Explored? : " << (explored ? "Yes" : "No") << endl;
    cout << "Linked? : " << (linked ? "Yes" : "No") << endl;

    cout << "Connections: " << endl;

    for (int i = 0; i < MAX_CONNECTIONS; i++)
    {
        if (connections[i] != 0)
            cout << i + 1 << ": " << connections[i] << endl;
    }
    // Setup each planet to be null
    for (int i = 0; i < MAX_PLANETS; i++)
    {
        if (planets[i] != NULL)
            cout << "(P)" << i + 1 << ": " << planets[i]->getName() << endl;
    }
    // Setup each starport to be null
    for (int i = 0; i < MAX_STARPORTS; i++)
    {
        if (starports[i] != NULL)
            cout << "(S)" <<i + 1 << ": " << starports[i]->getName() << endl;
    }
    // Setup each celestial to be null
    for (int i = 0; i < MAX_CELESTIALS; i++)
    {
        if (celestials[i] != NULL)
            cout << "(C)" <<i + 1 << ": " << celestials[i]->getName() << endl;
    }
}

// Displays the sector info in a short mode
void Sector::displaySectorShort()
{
    cout << "Sector Number: " << sectorNum << endl;
    cout << "Region Name  : " << regionName << endl;
    cout << "Connections  : ";

    for (int i = 0; i < MAX_CONNECTIONS; i++)
    {
        if (connections[i] != 0)
            cout << i + 1 << ": <" << connections[i] << ">  ";
    }
    cout << endl;

    cout << "Total Connections  : " << getConnections() << endl;

    cout << endl << endl;
}

// Returns the total amount of connected sectors to the current one
int Sector::getConnections()
{
    int temp = 0;

    for (int i = 0; i < MAX_CONNECTIONS; i++)
    {
        if (connections[i] != 0)
            temp++;
    }

    return temp;
}

// Returns true if the passed sector is linked to the current one
bool Sector::checkSectors(int s)
{
    for (int i = 0; i < MAX_CONNECTIONS; i++)
    {
        if (connections[i] == s)
            return true;
    }

    return false;
}
