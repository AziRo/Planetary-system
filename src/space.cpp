#include "space.h"

Space::Space()
{
    window = new RenderWindow(sf::VideoMode(1280, 1280), "Planetary System", sf::Style::Default,sf::ContextSettings(24,8,8,1,1));

    size = Vector2f(window->getSize());
    center.x = window->getSize().x/2;
    center.y = window->getSize().y/2;

    view = new View(center, size);

    Image image;
    image.loadFromFile("./texture/space.png");

    tr.loadFromImage(image);
    tr.setSmooth(true);

    bg = new RectangleShape[4];

    bg[0] = RectangleShape(size);
    bg[0].setOrigin(center);
    bg[0].setTexture(&tr);
    bg[0].setPosition(center.x - ((float)3.5 * size.x), center.y - ((float)2 * size.y));
    bg[0].scale(7,4);


    bg[1] = RectangleShape(size);
    bg[1].setOrigin(center);
    bg[1].setTexture(&tr);
    bg[1].setPosition(center.x - ((float)3.5 * size.x), center.y + ((float)2 * size.y));
    bg[1].scale(7,4);


    bg[2] = RectangleShape(size);
    bg[2].setOrigin(center);
    bg[2].setTexture(&tr);
    bg[2].setPosition(center.x + ((float)3.5 * size.x), center.y + ((float)2 * size.y));
    bg[2].scale(7,4);


    bg[3] = RectangleShape(size);
    bg[3].setOrigin(center);
    bg[3].setTexture(&tr);
    bg[3].setPosition(center.x + ((float)3.5 * size.x), center.y - ((float)2 * size.y));
    bg[3].scale(7,4);

    view = new View(center, size);
    createPlanets();
    createSatellites();

    a = NULL;

    click_p = -1;

    pause = false;
}

void Space::createPlanets()
{
    sun = Planet(center, 55, 1000, 0, 0);
    sun.setTexture("./texture/sun.jpg");
    sun.initShape();

    p_count = rand()%5 + 4;
    p = new Planet*[p_count];

    setFilePath();

    float orbit = sun.getRadius();
    float speed = 4, radius, mass;
    int fp = 9;

    for(int i = 0; i < p_count; ++i)
    {
        radius = rand()%25+15;
        orbit += radius + rand()%15+40;
        mass = (float)1.3 * radius * radius * radius * (float)3.14;
        p[i] = new Planet(center, radius, mass, speed, orbit);
        if(filePath[i%fp].r != NULL) p[i]->setTexture(filePath[i%fp].Path , *(filePath[i%fp].r));
        else p[i]->setTexture(filePath[i%fp].Path);
        p[i]->initShape();
        p[i]->setAngle(rand()%20);
        orbit +=p[i]->getRadius();
        speed *= 0.5;
    }

}

void Space::createSatellites()
{
    setFilePath();

    float radius, speed, orbit, mass;
    int fp = 9, count = 0, n_planet[p_count];

    s_count = 0;

    n_planet[0] = 0;

    for(int i = 1; i < p_count; ++i)
    {
        n_planet[i] = rand()%5;
        s_count += n_planet[i];
    }

    s = new Satellite*[s_count];


    int k = 0, dOrbit = 0;

    for(int i = 0; i < p_count; ++i)
    {
        orbit = 0;
        orbit += p[i]->getRadius();
        speed = 4;

        for(int j = 0; j < n_planet[i]; ++j)
        {
            radius = p[i]->getRadius()/(rand()%3+2);
            orbit += radius + p[i]->getRadius()/4 + 0.5;
            mass = (float)1.3 * radius * radius * radius * (float)3.14;
            s[k] = new Satellite(p[i], Vector2f(0,0), radius, mass, speed, orbit);
            s[k]->setNumPlanet(i);
            if(filePath[k%fp].r != NULL) s[k]->setTexture(filePath[k%fp].Path , *(filePath[k%fp].r));
            else s[k]->setTexture(filePath[k%fp].Path);
            s[k]->initShape();
            s[k]->setAngle(rand()%20);
            orbit += s[k++]->getRadius();
            speed *= 0.5;
        }
        dOrbit += orbit;
        p[i]->setOrbit(p[i]->getOrbit().getOrbit() + dOrbit);
        if(k > count){ count++; dOrbit += s[k-1]->getOrbit().getOrbit(); }

    }

}

void Space::createAsteroids()
{
    float angle = rand()%50 + 1;
    float dx = size.x * 3 * cosf(angle) + center.x;
    float dy = size.y * 3 * sinf(angle) + center.y;
    float x, y;

    if(dx > center.x) x = dx - (rand()%100 + 10);
    else x = dx + rand()%100 + 10;
    if(dy > center.y) y = dy - (rand()%100 + 10);
    else y = dy + rand()%100 + 10;


    float radius = rand()%31 + 5, mass = (float)1.3 * radius * radius * radius * (float)3.14;

    a = new Asteroid(Vector2f(dx, dy), Vector2f(x, y), radius, mass, rand()%101 + 220);
    if(dx > center.x) a->setSpeed(a->getSpeed() * (-1));
    a->setTexture("./texture/asteroid.jpg", IntRect(0, 0, 10, 10));
    a->initShape();
}

void Space::setFilePath()
{
    int n = 9;
    int i = rand()%n;

    filePath[i].Path = new char[50];
    strcpy(filePath[i].Path, "./texture/planetgroup.png");
    filePath[i++].r = new IntRect(342, 24, 273, 270);
    i %= n;
    filePath[i].Path = new char[50];
    strcpy(filePath[i].Path, "./texture/planetgroup.png");
    filePath[i++].r = new IntRect(24, 24, 273, 270);
    i %= n;
    filePath[i].Path = new char[50];
    strcpy(filePath[i].Path, "./texture/planetgroup.png");
    filePath[i++].r = new IntRect(982, 24, 273, 270);
    i %= n;
    filePath[i].Path = new char[50];
    strcpy(filePath[i].Path, "./texture/planetgroup.png");
    filePath[i++].r = new IntRect(342, 343, 273, 270);
    i %= n;
    filePath[i].Path = new char[50];
    strcpy(filePath[i].Path, "./texture/planetgroup.png");
    filePath[i++].r = new IntRect(664, 344, 273, 270);
    i %= n;
    filePath[i].Path = new char[50];
    strcpy(filePath[i].Path, "./texture/planetgroup.png");
    filePath[i++].r = new IntRect(25, 664, 273, 270);
    i %= n;
    filePath[i].Path = new char[50];
    strcpy(filePath[i].Path, "./texture/planetgroup.png");
    filePath[i++].r = new IntRect(665, 664, 273, 270);
    i %= n;
    filePath[i].Path = new char[50];
    strcpy(filePath[i].Path, "./texture/planetgroup.png");
    filePath[i++].r = new IntRect(347, 664, 273, 270);
    i %= n;
    filePath[i].Path = new char[50];
    strcpy(filePath[i].Path, "./texture/planetgroup.png");
    filePath[i].r = new IntRect(1051, 728, 139, 141);
}

void Space::handler(Event event)
{
    Vector2i pixelPos = Mouse::getPosition(*window);
    Vector2f pos = window->mapPixelToCoords(pixelPos);

    while (window->pollEvent(event))
    {
        switch (event.type)
        {
            case Event::Closed :
                window->close();
                break;

            case Event::MouseButtonPressed :

                if(event.key.code == Mouse::Left)
                {
                    click_p = -1;

                    for(int i = 0; i < p_count; ++i)
                    {
                        if(p[i] && p[i]->getShape().getGlobalBounds().contains(pos))
                        {
                            click_p = i;
                            break;
                        }
                    }

                }
                break;

            case Event::KeyPressed :

                if(event.key.code == Keyboard::Up && view_size.x > MINSIZE)
                {
                    view_size = Vector2f(view_size.x - (size.x/100), view_size.y - (size.y/100));
                }

                if(event.key.code == Keyboard::Down  && view_size.x < MAXSIZE)
                {
                    view_size = Vector2f(view_size.x + (size.x/100), view_size.y + (size.y/100));
                }

                if(event.key.code == Keyboard::Space)
                {
                    pause = bool(1 - pause);
                }

                break;

            default :
                break;
        }
    }
}

void Space::show()
{
    Clock c;
    Time t;
    float ti;

    view_size = Vector2f(size.x * 3, size.y * 3);
    view->setSize(view_size);
    view->setCenter(center);


    float dx = size.x * 3 * cosf(1) + center.x;
    float dy = size.y * 3 * sinf(1) + center.y;

    float r_edge = sqrt(dx*dx + dy*dy);


    while(window->isOpen())
    {
        Event event;
        handler(event);

        if(a == NULL) { createAsteroids(); }

        if(click_p != -1 && p[click_p] != NULL)
        {
            view->setSize(view_size);
            view->setCenter(p[click_p]->getPos());
        }else
        {
            view->setSize(view_size);
            view->setCenter(center);
        }

        window->setView(*view);

        for(int i = 0; i < 4; ++i) window->draw(bg[i]);

        t = c.getElapsedTime();
        ti = t.asSeconds();


        a->setTick(ti);
        if(!pause) a->move();

        window->draw(a->getShape());

        for(int i = 0; i < p_count; ++i)
        {
            if(!p[i]) continue;
            p[i]->setTick(ti);
            if(!pause) p[i]->move();
            window->draw(p[i]->getOrbit().getVertices(), 71, LinesStrip);
            window->draw(p[i]->getShape());
        }

        for(int i = 0; i < s_count; ++i)
        {
            if(!s[i]) continue;
            if(!p[s[i]->getNumPlanet()]) { delete s[i]; s[i] = NULL; continue; }
            s[i]->setTick(ti);
            if(!pause) s[i]->move();
            window->draw(s[i]->getOrbit().getVertices(), 71, LinesStrip);
            window->draw(s[i]->getShape());
        }

        window->draw(sun.getShape());

        c.restart();


        if(a->collision(&sun)) { delete a; a = NULL; }

        if(a != NULL)
            for(int i = 0; i < p_count; ++i)
            {
                if(p[i])
                    if(a->collision(p[i]))
                    {
                        if(a->getMass() >= p[i]->getMass()/5)
                        {
                            delete a;
                            delete p[i];
                            a = NULL;
                            p[i] = NULL;

                            break;
                        }
                        else { delete a; a = NULL; }

                        break;
                    }
            }


        if(a != NULL)
            for(int i = 0; i < s_count; ++i)
            {
                if(s[i])
                    if(a->collision(s[i]))
                    {
                        if(a->getMass()/5 >= s[i]->getMass())
                        {
                            delete a;
                            delete s[i];
                            a = NULL;
                            s[i] = NULL;

                            break;
                        }
                        else { delete a; a = NULL; }

                        break;
                    }
            }

        if(a != NULL)
            if (!collision(a, center.x, center.y, r_edge)) { delete a; a = NULL; }

        window->display();
    }

}

bool Space::collision(SpaceBody *p1, float x,float y, float r)
{
    float a = abs(p1->getPos().x - x);
    float b = abs(p1->getPos().y - y);
    double len = sqrt( a * a + b * b);

    return len <= r;
}