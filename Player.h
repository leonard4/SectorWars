//
//
//
//
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Player
{
  public:
    Player();
    virtual ~Player();
    // Returns the players current sector
    int getSector() { return currentSector; }
    // Sets the players current sector
    void setSector(int s) { currentSector = s; }
  protected:
  private:
    // Players name
    string name;
    // Players current sector
    int currentSector;
    // Players current experience
    int experience;
    // Players current level
    int level;

};

#endif // PLAYER_H
