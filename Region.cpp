/*
Create an array of 1000 sectors.

Randomly pick a 5 to 25 sector group.
For each of the sectors in the group:
Connect it(A) to a random one(B) of the others
Connect (B) to (A)

Randomly pick 5 to 25 more sectors, but make sure they haven''t been picked before.
Do the same loop to connect those sectors.

After the final group is settled, you'll have a selection of grouped sectors. The grouped
sectors each should have their own name, like "The Marmalade Nebulae" or "Halaf Zone" or whatever.
You should have 40-200 of these groups. You can, of course, adjust the amount by changing the
amount of sectors per group.

To connect these groups to each other, do something similar.

Loop through each group and connect one to five or so of the sectors randomly to one of the other groups.

This method still leaves the chance that there are sectors that cannot ever reach other sectors.
You'd have to run through a pathfinding algorithm for each sector from the same starting point to be sure of that.

*/
#include "Region.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

Region::Region()
{
    connectedSectors = 0;

    for (int i = 1; i <= MAX_SECTORS; i++)
    {
        // Sector(int num, string region, string sector, bool exp, bool link);
        sectors[i] = new Sector(i, regionPrefix[rand() % 5] + " " + regionSuffix[rand() % 5], "Empty Sector", false, false);
    }

    linkSectors();

}

Region::~Region()
{
    delete sectors;
}

// Sector Wrapper: Displays the full region info
void Region::displayRegionFull()
{
    for (int i = 1; i <= MAX_SECTORS; i++)
    {
        sectors[i]->displaySectorFull();
    }
}

// Sector Wrapper: Displays the short region info
void Region::displayRegionShort()
{
    int zero, one, two, three, four, five, six = 0;

    zero = one = two = three = four = five = six;

    for (int i = 1; i <= MAX_SECTORS; i++)
    {
        sectors[i]->displaySectorShort();
    }

    for (int j = 1; j <= MAX_SECTORS; j++)
    {
        if (sectors[j]->getConnections() == 0)
            zero++;
        if (sectors[j]->getConnections() == 1)
            one++;
        if (sectors[j]->getConnections() == 2)
            two++;
        if (sectors[j]->getConnections() == 3)
            three++;
        if (sectors[j]->getConnections() == 4)
            four++;
        if (sectors[j]->getConnections() == 5)
            five++;
        if (sectors[j]->getConnections() == 6)
            six++;
    }

    cout << "Sectors with (1) connection: " << one << endl;
    cout << "Sectors with (2) connection: " << two << endl;
    cout << "Sectors with (3) connection: " << three << endl;
    cout << "Sectors with (4) connection: " << four << endl;
    cout << "Sectors with (5) connection: " << five << endl;
    cout << "Sectors with (6) connection: " << six << endl;
    cout << "Sectors with (0) connection: " << zero << endl;
}

// Sector Wrapper: Displays the full sector info
void Region::displaySectorFull(int s)
{
    sectors[s]->displaySectorFull();
}

// Sector Wrapper: Displays the short sector info
void Region::displaySectorShort(int s)
{
    sectors[s]->displaySectorShort();
}

// Sector Wrapper: Returns true if the passed connection exists in the sector (valid movement etc)
bool Region::checkSectors(int c, int s)
{
    return sectors[c]->checkSectors(s);
}

// Function runs through all of the sectors and links them together to form a region
void Region::linkSectors()
{
    //int tempNum = 0;
    srand(time(NULL));

    vector<int> frontVec;
    vector<int> backVec;

    vector<int>::iterator it;

    // Push the first half of the sector #'s onto the vector list
    for (int i = 1; i <= MAX_SECTORS / 2; i++)
        frontVec.push_back(i);

    // Push the second half of the sector #'s onto the vector list
    for (int i = MAX_SECTORS / 2 + 1; i <= MAX_SECTORS; i++)
        backVec.push_back(i);

    // Shuffle the entire vector list
    random_shuffle(frontVec.begin(), frontVec.end());
    random_shuffle(backVec.begin(), backVec.end());

    //vector<int> vec1 (vec.begin(), vec.end());


    // Randomly link half of all the sectors to half of the other sectors and back.
    for (int i = 1; i <= MAX_SECTORS / 2; i++)
    {
        //if (sectors[i]->getConnections() == 0)
        //{
            sectors[frontVec.back()]->setConnections(0, backVec.back());
            sectors[backVec.back()]->setConnections(0, frontVec.back());
            //cout << "Front = " << setw(2) << left << frontVec.back() << " Back = " << backVec.back() << endl;
            // Set each linked sector link to true
            sectors[frontVec.back()]->setLinked(true);
            sectors[backVec.back()]->setLinked(true);
            frontVec.pop_back();
            backVec.pop_back();
       // }
    }

    // Push the first half of the sector #'s onto the vector list
    for (int i = 1; i <= MAX_SECTORS / 3; i++)
        frontVec.push_back(i);

    // Push the second half of the sector #'s onto the vector list
    for (int i = MAX_SECTORS / 3 + 1; i <= MAX_SECTORS; i++)
        backVec.push_back(i);

    // Shuffle the entire vector list
    random_shuffle(frontVec.begin(), frontVec.end());
    random_shuffle(backVec.begin(), backVec.end());

    //vector<int> vec2 (vec.begin(), vec.end());

    // Randomly link 1/3 of all the sectors to the remaiming 1/3
    for (int i = 1; i <= MAX_SECTORS / 3; i++)
    {
        sectors[frontVec.back()]->setConnections(1, backVec.back());
        sectors[backVec.back()]->setConnections(1, frontVec.back());
        //cout << "Front = " << setw(2) << left << frontVec.back() << " Back = " << backVec.back() << endl;
        // Set each linked sector link to true
        sectors[frontVec.back()]->setLinked(true);
        sectors[backVec.back()]->setLinked(true);
        frontVec.pop_back();
        backVec.pop_back();
    }

    // Push the first half of the sector #'s onto the vector list
    for (int i = 1; i <= MAX_SECTORS / 2; i++)
        frontVec.push_back(i);

    // Push the second half of the sector #'s onto the vector list
    for (int i = MAX_SECTORS / 2 + 1; i <= MAX_SECTORS; i++)
        backVec.push_back(i);

    // Shuffle the entire vector list
    random_shuffle(frontVec.begin(), frontVec.end());
    random_shuffle(backVec.begin(), backVec.end());

    //vector<int> vec2 (vec.begin(), vec.end());

    // Randomly link 1/3 of all the sectors to the remaiming 1/3
    for (int i = 1; i <= MAX_SECTORS / 4; i++)
    {

        sectors[frontVec.back()]->setConnections(2, backVec.back());
        sectors[backVec.back()]->setConnections(2, frontVec.back());
        //cout << "Front = " << setw(2) << left << frontVec.back() << " Back = " << backVec.back() << endl;
        // Set each linked sector link to true
        sectors[frontVec.back()]->setLinked(true);
        sectors[backVec.back()]->setLinked(true);
        frontVec.pop_back();
        backVec.pop_back();
    }

    // Push the first half of the sector #'s onto the vector list
    for (int i = 1; i <= MAX_SECTORS / 2; i++)
        frontVec.push_back(i);

    // Push the second half of the sector #'s onto the vector list
    for (int i = MAX_SECTORS / 2 + 1; i <= MAX_SECTORS; i++)
        backVec.push_back(i);

    // Shuffle the entire vector list
    random_shuffle(frontVec.begin(), frontVec.end());
    random_shuffle(backVec.begin(), backVec.end());

    //vector<int> vec2 (vec.begin(), vec.end());

    // Randomly link 1/3 of all the sectors to the remaiming 1/3
    for (int i = 1; i <= MAX_SECTORS / 5; i++)
    {

        sectors[frontVec.back()]->setConnections(3, backVec.back());
        sectors[backVec.back()]->setConnections(3, frontVec.back());
        //cout << "Front = " << setw(2) << left << frontVec.back() << " Back = " << backVec.back() << endl;
        // Set each linked sector link to true
        sectors[frontVec.back()]->setLinked(true);
        sectors[backVec.back()]->setLinked(true);
        frontVec.pop_back();
        backVec.pop_back();
    }

}
