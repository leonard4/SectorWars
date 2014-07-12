//
//
//
//
//

#ifndef PLANET_H
#define PLANET_H
#include <string>
#include "Player.h"

using namespace std;

class Planet
{
  public:
    Planet();
    virtual ~Planet();
    // Returns the planets name
    string getName() { return planetName; }
    // Returns the planets name
    int getNum() { return planetNum; }
    // Returns the Starports type
    int getType() { return planetType; }
    char getClassType() { return planetClassType[getType()]; }
    string getClassName() { return planetClassName[getType()]; }
  protected:
  private:
    // Planers name
    string planetName;
    // Number of planet
    int planetNum;
    // Who owns the planet
    Player planetOwner;
    // Planets type
    int planetType;
    // Class of the planet
    char planetClassType[7];
    // Name of the class of the planet
    string planetClassName[7];
};

#endif // PLANET_H
