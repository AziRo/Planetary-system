#ifndef PLANETARY_SYSTEM_SATELLITE_H
#define PLANETARY_SYSTEM_SATELLITE_H

#include "planet.h"

class Satellite : public SpaceBody
{
private:
    Planet *planet;
    int numberPlanet;

public:
    Satellite(){}
    Satellite(Planet *planet, Vector2f vector, float r, float m, float speed, float orbit);

    void move();

    void setNumPlanet(int n);
    Planet* getPlanet();
    int getNumPlanet();
};


#endif 
