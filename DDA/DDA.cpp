#include<stdio.h>
#include<graphics.h>

//Function for finding absolute value
int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}

//DDA Function for line generation
void DDA(float X0, float Y0, float X1, float Y1)
{
    float h = (float)getwindowheight();
    float w = (float)getwindowwidth();

    // calculate dx & dy
    float dx = X1 - X0;
    float dy = Y1 - Y0;

    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        putpixel (X+w/2,(h/2) - Y,GREEN);   // put pixel at (X,Y)
        X += Xinc;                          // increment in x at each step
        Y += Yinc;                          // increment in y at each step
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

    DDA(-w/2,0, w/2, 0);
    DDA(0,h/2,0,-h/2);

    //Input values

    int p[2][18] =
    {
        {50,50,50,60,60,60,60,50,60,200,200,200,200,60,60,120,120,60},
        {50,200,200,200,200,50,50,50,200,200,200,120,120,120,120,160,160,200},
    };


    for(int i = 0;i<18;i=i+2)
    {
        DDA(p[0][i], p[1][i], p[0][i+1], p[1][i+1]);
    }

    getch();
    return 0;
}
