#ifndef PLANETARY_SYSTEM_ASTEROID_H
#define PLANETARY_SYSTEM_ASTEROID_H

#include "spaceBody.h"
#include "planet.h"

class Asteroid : public SpaceBody
{
private:
    Vector3f equation;

public:
    Asteroid(){}
    Asteroid(Vector2f position, Vector2f vector, float r, float m, float speed);

    double distance(SpaceBody *planet);

    void updateEquation();

    bool collision(SpaceBody *planet);

    void move();

};


#endif
