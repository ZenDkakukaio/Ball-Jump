#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace std;
using namespace sf;

Vector2i fen_screen(800, 500);

struct point
{
    int x, y;
};

int main()
{
    srand(time(0));

    RenderWindow fen(VideoMode(fen_screen.x, fen_screen.y), "BALL GAME!!!");
    fen.setFramerateLimit(60);

   struct point table[30];

            for (int i=0; i<10;i++)
            {
                table[i].x=rand()%400;
                table[i].y=rand()%533;
            }

            int x=100, y=100, h=200;
            float dx=0, dy=0;


    while(fen.isOpen())
    {
        Event event;

        Texture ciel;
        ciel.loadFromFile("images/ciel.png");

        Sprite sciel;

        sciel.setTexture(ciel);

        Texture t1, t2;
        Sprite s1, s2;

        if(!t1.loadFromFile("images/doodle.png"))
        {
            cout << "erreur de chargement" << endl;
            return EXIT_FAILURE;
        }
        else
            s1.setTexture(t1);


        if(!t2.loadFromFile("images/plat.png"))
        {
            cout << "erreur de chargement" << endl;
        }
        else
            s2.setTexture(t2);


        if (Keyboard::isKeyPressed(Keyboard::Right)) x+=4;
        if (Keyboard::isKeyPressed(Keyboard::Left)) x-=4;




        dy+=0.2;
        y+=dy;

        if (y>500) dy=-10;

        if (y<h)
        for (int i=0;i<10;i++)
        {
            y=h;
            table[i].y=table[i].y-dy;
            if (table[i].y>533) {table[i].y=0; table[i].x=rand()%400;}
        }

        for (int i=0;i<10;i++)
        if ((x+50>table[i].x) && (x+20<table[i].x+68)&& (y+70>table[i].y) && (y+70<table[i].y+14) && (dy>0) )  dy=-10;

        s1.setPosition(x,y);






        while(fen.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                fen.close();
            }
            else if(event.type == Event::KeyPressed)
            {
                if(event.key.code == Keyboard::Escape)
                {
                    fen.close();
                }
            }
        }

        Font f1;
        Text text1("BALL JUMP!!!!", f1, 40);
        text1.setPosition(20, 10);
        text1.setFillColor(Color::Blue);


        if (!f1.loadFromFile("fonts/GILSANUB.TTF"))
        {
            cout <<"erreur lors du chargement" << endl;
            return EXIT_FAILURE;
        }


        fen.clear();
        fen.draw(sciel);
        fen.draw(s1);

        fen.draw(text1);


        for (int i=0;i<10;i++)
        {
            s2.setPosition(table[i].x, table[i].y);
            fen.draw(s2);
        }


        fen.display();

    }
    return EXIT_SUCCESS;
}
