//
//
//
//
//

#ifndef SECTOR_H
#define SECTOR_H
#include <string>
#include "Planet.h"
#include "Starport.h"
#include "Celestial.h"

const int MAX_CONNECTIONS = 6;
const int MAX_PLANETS = 6;
const int MAX_STARPORTS = 1;
const int MAX_CELESTIALS = 3;

using namespace std;

class Sector
{
  public:
    Sector();
    Sector(int num);
    Sector(int num, string region, string sector, bool exp, bool link);
    virtual ~Sector();
    // Displays the sector info in a full mode
    void displaySectorFull();
    // Displays the sector info in a short mode
    void displaySectorShort();
    // Returns the total amount of connected sectors to the current one
    int getConnections();
    // Sets the connection to the sector thats passed
    void setConnections(int c, int sector) { connections[c] = sector; }
    // Returns the sector number
    int getSectorNum() { return sectorNum; }
    // Sets the sectors linked state to true or false
    void setLinked(int l) { linked = l; }
    // Returns wether or not the sector is linked to anything
    bool getLinked() { return linked; }
    // Returns true if the passed sector is one of the sectors connections
    bool checkSectors(int s);
  protected:
  private:
    // Region name for the sector
    string regionName;
    // Sector name
    string sectorName;
    // Sector number
    int sectorNum;
    // If its been explored yet
    bool explored;
    // If its linked to anything else
    bool linked;
    // Other sectors that its connected to
    int connections[MAX_CONNECTIONS];

    // Array of planets
    Planet *planets[MAX_PLANETS];
    // Array of starports
    Starport *starports[MAX_STARPORTS];
    // Array of celestial objects
    Celestial *celestials[MAX_CELESTIALS];

};

#endif // SECTOR_H
