#ifndef PLANETARY_SYSTEM_SPACE_H
#define PLANETARY_SYSTEM_SPACE_H

#include <iostream>
#include "satellite.h"
#include "asteroid.h"
#include <string.h>

#define MAXSIZE 5400
#define MINSIZE 800


using namespace std;


struct FilePath
{
    char *Path;
    IntRect *r;
};


class Space
{
private:
    RenderWindow *window;
    View *view;
    Vector2f center;
    Vector2f size;
    RectangleShape *bg;
    Texture tr;
    FilePath filePath[9];
    Planet sun;
    Planet **p;
    Satellite **s;
    Asteroid *a;
    int p_count;
    int s_count;
    int click_p;
    Vector2f view_size;
    bool pause;


    void setFilePath();
    void createPlanets();
    void createSatellites();
    void createAsteroids();
    void handler(Event event);
    bool collision(SpaceBody *p1, float x,float y, float r);

public:
    Space();

    void show();


};


#endif
