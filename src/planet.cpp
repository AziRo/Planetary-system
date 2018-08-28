#include "planet.h"

Planet::Planet(Vector2f vector, float r, float m, float speed, float orbit):SpaceBody(vector, r, m, speed, orbit)
{
    position.y = orbit * cosf(angle) + vector.y;
    position.x = orbit * sinf(angle) + vector.x;
}

void Planet::move()
{
    position.y = orbit.getOrbit() * cosf(angle) + vector.y;
    position.x = orbit.getOrbit() * sinf(angle) + vector.x;
    s.setPosition(position);
    angle += speed * ti;
    s.rotate(speed  * ti * -500);
}


