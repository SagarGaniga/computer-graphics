using namespace std;
#include <iostream>
#include <graphics.h>
#include <cstdio>
#include <cmath>
#include<math.h>

void drawCirlce(float x, float y)
{
    // Axis
    //void ellipse(int x, int y, int stangle, int endangle, int xradius, int yradius);
    //ellipse(x, y, 0, 360, 50, 20);

    // Planet
    circle(x, y, 10);


}

int main()
{
    int gd=DETECT,gm,x,y,length,angle;
	initgraph(&gd, &gm, "");

	float h = (float)getwindowheight();
    float w = (float)getwindowwidth();

    int i,andle = 0,x1=w/2 - 100,y1=h/2,x2=w/2-150,y2 = h/2- 50;
    // Infinite Loop of swimming
    for(;;)
    {
        // draw sun
        circle(w/2,h/2,20);

        //planet1
        drawCirlce(x1, y1);
        x1= (x1 + 50*sin(M_PI/180));
        y1= (y1 + 50*cos(M_PI/180));

        //drawCirlce(x2, y2);
        x2= (x2+70*sin(M_PI/180));
        y2= (y2+70*cos(M_PI/180));












        angle = (angle + 15);








        delay(100);
        //break;
        cleardevice();

    }

    getch();
    return 1;
}
