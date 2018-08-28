#include "asteroid.h"
#include <iostream>

float abs(float a)
{
    return (a >= 0) ? a : -a;
}

Asteroid::Asteroid(Vector2f position,Vector2f vector, float r, float m, float speed)
{
    this->r = r;
    this->m = m;
    this->speed = speed;
    this->vector = vector;
    this->position = position;

    updateEquation();

    s.setOutlineThickness(2);

}

void Asteroid::move()
{
    position.x += speed * ti;
    position.y = (-equation.z - (equation.x * position.x) )/equation.y;

    s.setPosition(position.x, position.y);
}

bool Asteroid::collision(SpaceBody *planet)
{
    return distance(planet) <= (planet->getRadius() + r);
}

void Asteroid::updateEquation()
{
    equation.x = vector.y - position.y;
    equation.y = -(vector.x - position.x);
    equation.z = position.y * vector.x - position.y * position.x - position.x * vector.y + position.x * position.y;
}

double Asteroid::distance(SpaceBody *planet)
{
    float a = abs(planet->getPos().x - position.x);
    float b = abs(planet->getPos().y - position.y);
    double len = sqrt( a * a + b * b);

    return len;
}
