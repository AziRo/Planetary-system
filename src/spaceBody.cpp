#include "spaceBody.h"


SpaceBody::SpaceBody(Vector2f vector, float r, float m, float speed, float orbit):
        vector(vector), r(r), m(m), speed(speed)
{
 this->orbit = Orbit(orbit, vector);
}

void SpaceBody::initShape()
{
    s.setRadius(r);
    s.setOrigin(r,r);

    s.setPosition(position);
    s.setTexture(&tr);
}


void SpaceBody::setTexture(const char *str)
{
    img.loadFromFile(str);
    tr.loadFromImage(img);
    tr.setSmooth(true);
}

void SpaceBody::setTexture(const char *str, IntRect rect)
{
    img.loadFromFile(str);

    tr.loadFromImage(img,rect);
    tr.setSmooth(true);
}

void SpaceBody::setVector(Vector2f vector)
{
    this->vector = vector;
}

void SpaceBody::setRadius(float r)
{
    this->r = r;
    s.setRadius(r);
}

void SpaceBody::setMass(float m)
{
    this->m = m;
}

void SpaceBody::setSpeed(float speed)
{
    this->speed = speed;
}

void SpaceBody::setOrbit(float orbit)
{
    this->orbit.setOrbit(orbit);
}

Vector2f SpaceBody::getPos()
{
    return position;
}

float SpaceBody::getRadius()
{
    return r;
}

float SpaceBody::getMass()
{
    return m;
}

float SpaceBody::getSpeed()
{
    return speed;
}

Orbit SpaceBody::getOrbit()
{
    return orbit;
}

CircleShape SpaceBody::getShape() {
    return s;
}

void SpaceBody::setTick(float ti)
{
    this->ti  = ti;
}

void SpaceBody::setAngle(float angle)
{
    this->angle = angle;
}

