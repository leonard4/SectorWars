//
//
//
//
//

#ifndef STARSHIP_H
#define STARSHIP_H
#include <string>

using namespace std;

class Starship
{
  public:
    Starship();
    virtual ~Starship();
  protected:
  private:
    // Starship name
    string shipName;
    // Starship number
    int shipNum;
    // Amount of carg holds
    int cargoHolds;
    // Amount of torpedoes
    int torpedoes;
    // Amount of crew
    int crew;
    // Type of starship
    int shipType[20];
    // Starship thing
    int shipThing;
    // Starship crew thing
    int shipCrew;
    // Number of battles the starship has seen
    int battles;
    // Starships age
    int age;
};

#endif // STARSHIP_H
