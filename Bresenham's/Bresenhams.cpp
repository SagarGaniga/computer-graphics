#include<stdio.h>
#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;


//print
void putpixels(float x, float y)
{
    float h = (float)getwindowheight();
    float w = (float)getwindowwidth();
    putpixel(x+w/2, (h/2)-y, GREEN);
}

//Function for finding absolute value
int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}

// Function for line generation
void bresenham(float x1, float y1, float x2, float y2)
{
    // Find Delta
    float dx = x2-x1;
    float dy = y2-y1;

    // Find Signs
    int sx = (dx>=0) ? 1 : (-1);
    int sy = (dy>=0) ? 1 : (-1);

    // Get Initial Points
    float x = x1;
    float y = y1;

    // Flag to check if swapping happens
    int isSwaped = 0;

    // Swap if needed
    if(abs(dy) > abs(dx))
    {
        // swap dx and dy
        float tdx = dx;
        dx =dy;
        dy = tdx;

        isSwaped = 1;
    }

    // Decision parameter
    float p = 2*(abs(dy)) - abs(dx);

    //Print Initial Point
    putpixels(x,y);

    // Loop for dx times
    for(int i = 0; i<= abs(dx);i++)
    {
        // Depending on decision parameter
        if(p < 0)
        {
            if(isSwaped == 0){
                x = x + sx;
                putpixels(x,y);
            }
            else{
                y = y+sy;
                putpixels(x,y);
            }
            p = p + 2*abs(dy);
        }
        else
        {
            x = x+sx;
            y = y+sy;
            putpixels(x,y);
            p = p + 2*abs(dy) - 2*abs(dx);
        }
    }
}

// Driver program
int main()
{
    int gd = DETECT, gm;

    // Initialize graphics function
    initgraph (&gd, &gm, "");

    float h = (float)getwindowheight();
    float w = (float)getwindowwidth();

    // Axis
    bresenham(-w/2,0, w/2, 0);
    bresenham(0,h/2,0,-h/2);

    //Input values

    int p[2][18] =
    {
        {50,50,50,60,60,60,60,50,60,200,200,200,200,60,60,120,120,60},
        {50,200,200,200,200,50,50,50,200,200,200,120,120,120,120,160,160,200},
    };


    for(int i = 0;i<18;i=i+2)
    {
        bresenham(p[0][i], p[1][i], p[0][i+1], p[1][i+1]);
    }

    getch();
    return 0;
}



