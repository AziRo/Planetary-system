#ifndef PLANETARY_SYSTEM_ORBIT_H
#define PLANETARY_SYSTEM_ORBIT_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Orbit
{
private:
    float orbit;
    Vector2f vector;
    Vertex vertices[71];

public:
    Orbit(){}
    Orbit(float orbit, Vector2f vector);

    void setOrbit(float orbit);
    void setVector(Vector2f vector);

    Vertex* getVertices();
    float getOrbit();
};


#endif
