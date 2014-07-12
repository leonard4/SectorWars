//
//
//
//
//

#ifndef REGION_H
#define REGION_H
#include "Sector.h"

const int MAX_SECTORS = 500;

const string regionPrefix[5] = { "Alpha",
                                 "Beta",
                                 "Gamma",
                                 "Delta",
                                 "Epsilon",
                               };

const string regionSuffix[5] = { "One",
                                 "Two",
                                 "Three",
                                 "Four",
                                 "Five",
                               };

class Region
{
  public:
    Region();
    virtual ~Region();
    // Sector Wrapper: Displays the full region info
    void displayRegionFull();
    // Sector Wrapper: Displays the short region info
    void displayRegionShort();
    // Function runs through all of the sectors and links them together to form a region
    void linkSectors();
    // Sector Wrapper: Displays the full sector info
    void displaySectorFull(int s);
    // Sector Wrapper: Displays the short sector info
    void displaySectorShort(int s);
    // Sector Wrapper: Returns true if the passed connection exists in the sector (valid movement etc)
    bool checkSectors(int c, int s);
  protected:
  private:
    Sector *sectors[MAX_SECTORS];
    int connectedSectors;

};

#endif // REGION_H
