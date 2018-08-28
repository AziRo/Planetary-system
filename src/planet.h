#ifndef PLANETARY_SYSTEM_PLANET_H
#define PLANETARY_SYSTEM_PLANET_H

#include "spaceBody.h"

class Planet : public SpaceBody
{
public:
    Planet(){};
    Planet(Vector2f vector, float r, float m, float speed, float orbit);

    void move();
};


#endif
