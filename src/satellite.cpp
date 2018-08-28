#include "satellite.h"

Satellite::Satellite(Planet *planet, Vector2f vector, float r, float m, float speed, float orbit) :
        planet(planet), SpaceBody(vector, r, m, speed, orbit)
{
    position.x = orbit * cosf(angle) + planet->getPos().x;
    position.y = orbit * sinf(angle) + planet->getPos().y;
}

void Satellite::move()
{
    orbit.setVector(planet->getPos());
    position.x = orbit.getOrbit() * cosf(angle) + planet->getPos().x;
    position.y = orbit.getOrbit() * sinf(angle) + planet->getPos().y;

    s.setPosition(position);
    angle += speed * ti;
    s.rotate(speed * -1);
}

Planet *Satellite::getPlanet()
{
    return planet;
}

void Satellite::setNumPlanet(int n)
{
    numberPlanet = n;
}

int Satellite::getNumPlanet()
{
    return numberPlanet;
}
