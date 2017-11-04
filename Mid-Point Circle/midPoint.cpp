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

// Implementing Mid-Point Circle Drawing Algorithm
void midPointCircleDraw(float x_centre, float y_centre, float r)
{
    // put x = radius and y = 0
    float x = r, y = 0;



    // Printing the initial point on the axes after translation
    putpixels(x + x_centre, y + y_centre);

    // When radius is zero only a single point will be printed
    if (r > 0)
    {
        putpixels(x + x_centre, -y + y_centre);
        putpixels(y + y_centre, x + x_centre);
        putpixels(-y + y_centre, x + x_centre);
    }

    /************
        Combinations
        x and y
        x and -y
        y and x
        -y and x
    *************/

    // Initialising the value of P
    int P = 1 - r;

    while (x > y)
    {
        y++;

        // Mid-point is inside or on the perimeter
        if (P <= 0)
            P = P + 2*y + 1;

        // Mid-point is outside the perimeter
        else
        {
            x--;
            P = P + 2*y - 2*x + 1;
        }

        // All the perimeter points have already been printed
        if (x < y)
            break;

        // Printing the generated point and its reflection
        // in the other octants after translation
        putpixels(x + x_centre, y + y_centre);
        putpixels(-x + x_centre, y + y_centre);
        putpixels(x + x_centre, -y + y_centre);
        putpixels(-x + x_centre, -y + y_centre);

        // If the generated point is on the line x = y then
        // the perimeter points have already been printed
        if (x != y)
        {
            putpixels(y + y_centre, x + x_centre);
            putpixels(-y + y_centre, x + x_centre);
            putpixels(y + y_centre, -x + x_centre);
            putpixels(-y + y_centre, -x + x_centre);

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
    line(0,h/2, w, h/2);
    line(w/2,0,w/2,h);

    midPointCircleDraw(0, 0, 100);
    midPointCircleDraw(0, 0, 40);
    getch();
    return 0;
}



