#ifndef PLANETARY_SYSTEM_SPACEBODY_H
#define PLANETARY_SYSTEM_SPACEBODY_H

#include <math.h>
#include <stdio.h>
#include "orbit.h"


class SpaceBody
{
protected:
    CircleShape s;
    Vector2f vector;
    Vector2f position = Vector2f(0, 0);
    float r;
    float m;
    float speed;
    float angle  = 0;
    Orbit orbit;
    Image img;
    Texture tr;
    float ti;

public:
    SpaceBody(){}
    SpaceBody(Vector2f vector, float r, float m, float speed, float orbit);

    void initShape();
    void setTexture(const char *str);
    void setTexture(const char *str, IntRect rect);
    void setVector(Vector2f vector);
    void setRadius(float r);
    void setMass(float m);
    void setSpeed(float speed);
    void setOrbit(float orbit);
    void setTick(float ti);
    void setAngle(float angle);

    CircleShape getShape();
    Vector2f getPos();
    float getRadius();
    float getMass();
    float getSpeed();
    Orbit getOrbit();

    virtual void move() = 0;

};


#endif
