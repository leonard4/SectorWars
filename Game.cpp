#include "Game.h"
#include <iostream>
#include <windows.h>

using namespace std;

Game::Game()
{
    playing = true;
}

Game::~Game()
{
    //dtor
}

void Game::runGame()
{
    //newRegion.displayRegionShort();
    cout << "SectorWars!" << endl;

    do
    {
        getRegion().displaySectorFull(getPlayer().getSector());
        //newRegion.displaySectorFull(1);
        cout << "Go to which sector? : (0 to Quit) ";
        cin >> choice;
        // 0 to Quit
        if (choice == 0)
        {
            playing = false;
            break;
        }
        // Make sure the sector is connected to the current one
        else if( !getRegion().checkSectors(choice, getPlayer().getSector()))
        {
            cout << "That sector isn't connected to this one" << endl;
            system("pause");
            system("cls");
            continue;
        }
        // Can't go to an invalid sector
        else if (choice > MAX_SECTORS || choice < 1)
        {
            cout << "Invalid sector.";
            system("pause");
            system("cls");
            continue;
        }
        // Set the players current sector
        setPlayerSector(choice);
        system("cls");

    } while(playing);

    cout << "Thanks for playing!" << endl;
}
