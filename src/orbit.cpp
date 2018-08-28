#include "orbit.h"

Orbit::Orbit(float orbit, Vector2f vector) : orbit(orbit), vector(vector)
{
    for(int i = 0; i <= 70; ++i)
    {
        Vector2f v = Vector2f(orbit * cosf(6.28 * i/70) + vector.x, orbit * sinf(6.28 * i/70) + vector.y);
        vertices[i] = Vertex(v, Color(0,150,255));
    }
}

void Orbit::setOrbit(float orbit)
{
    this->orbit = orbit;

    for(int i = 0; i <= 70; ++i)
    {
        Vector2f v = Vector2f(orbit * cosf(6.28 * i/70) + vector.x, orbit * sinf(6.28 * i/70) + vector.y);
        vertices[i] = Vertex(v, Color(0,150,255));
    }
}

Vertex* Orbit::getVertices()
{
    return vertices;
}

float Orbit::getOrbit()
{
    return orbit;
}

void Orbit::setVector(Vector2f vector)
{
    this->vector = vector;

    for(int i = 0; i <= 70; ++i)
    {
        Vector2f v = Vector2f(orbit * cosf(6.28 * i/70) + vector.x, orbit * sinf(6.28 * i/70) + vector.y);
        vertices[i] = Vertex(v, Color(0,150,255));
    }
}
