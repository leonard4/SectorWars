// Celestials are things like comets, black holes,
// wormholes, anything that isn't a player, ship,
// planet, or starport basically.
//
//

#ifndef CELESTIAL_H
#define CELESTIAL_H
#include <string>
#include "Player.h"

using namespace std;

class Celestial
{
  public:
    Celestial();
    virtual ~Celestial();
    // Returns the Celestials name
    string getName() { return celestialName; }
    // Returns the Celestials type
    int getType() { return celestialType; }
  protected:
  private:
    // Celestials name
    string celestialName;
    // Who owns the celestial
    Player celestialOwner;
    // Celestials type
    int celestialType;
};

#endif // CELESTIAL_H
