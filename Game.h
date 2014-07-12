//
//
//
//
//

#ifndef GAME_H
#define GAME_H
#include "Region.h"
#include "Player.h"

class Game
{
  public:
    Game();
    virtual ~Game();
    void runGame();
    // Returns the region
    Region getRegion() { return newRegion; }
    // Returns the player
    Player getPlayer() { return newPlayer; }
    // Sets the players sector to s
    void setPlayerSector(int s) { newPlayer.setSector(s); }
  protected:
  private:
    // Create a new region
    Region newRegion;
    // Create a new player
    Player newPlayer;
    // Choice for game loop
    int choice;
    // Is the player still playing?
    bool playing;
};

#endif // GAME_H
