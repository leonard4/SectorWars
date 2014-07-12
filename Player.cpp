#include "Player.h"

Player::Player()
{
    // Start the player in sector 1
    name = "Player";
    currentSector = 1;
    experience = 0;
    level = 1;
}

Player::~Player()
{
    //dtor
}
