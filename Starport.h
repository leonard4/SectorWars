//
//
//
//
//

#ifndef STARPORT_H
#define STARPORT_H
#include <string>
#include "Player.h"

using namespace std;

class Starport
{
  public:
    Starport();
    virtual ~Starport();
    // Returns the Starports name
    string getName() { return starportName; }
    // Returns the Starports type
    int getType() { return starportType; }
  protected:
  private:
    // Name of the Starport
    string starportName;
    // Who owns the planet
    Player starportOwner;
    // Type of the Starport
    int starportType;

};

#endif // STARPORT_H
