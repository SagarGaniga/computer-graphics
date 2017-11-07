#include<stdio.h>
#include<graphics.h>
#include<bits/stdc++.h>
#include <math.h>
using namespace std;


//print
void draw(float x1, float y1, float x2, float y2)
{
    float h = (float)getwindowheight();
    float w = (float)getwindowwidth();
    line(x1+w/2, (h/2)-y1,x2+w/2, (h/2)-y2);
}

//Function for finding absolute value
int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}


//Transform Matrix
void Transform(int p[][18], float t[3][3])
{
    int i,j,k,sum=0,c[3][18];

    // Initialize the array c with 0
    for(i=0;i<3;i++)                    // 3 rows
    {
        for(j=0;j<18;j++)               //18 columns
        {
            c[i][j]=0;
        }
    }


    // Multiply p with t and store it in c
    for(i=0;i<3;i++)
    {
        for(j=0;j<18;j++)
        {
            sum=0;
            for(k=0;k<3;k++)
            {
                sum=sum+t[i][k]*p[k][j];
            }
            c[i][j]=sum;
        }
    }

    // transfer c into p
    for(i=0;i<3;i++)
    {
        for(j=0;j<18;j++)
             p[i][j] = c[i][j];
    }
}

void myCleardevice()
{
    float h = (float)getwindowheight();
    float w = (float)getwindowwidth();
    cleardevice();   /* clear the screen */
    line(0,h/2, w, h/2);
    line(w/2,0,w/2,h);
}

double d2r(double d) {
  return (d / 180.0) * ((double) M_PI);
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

    //Input values

    int p[3][18] =
    {
        {50,50,50,60,60,60,60,50,60,200,200,200,200,60,60,120,120,60},
        {50,200,200,200,200,50,50,50,200,200,200,120,120,120,120,160,160,200},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    for(int i = 0;i<18;i=i+2)
    {
        draw(p[0][i], p[1][i], p[0][i+1], p[1][i+1]);
    }

    int ch;
    do
    {
        // prompt user input
        printf("******** MENU ********\n");
        printf("1. Translate\n");
        printf("2. Scale\n");
        printf("3. Rotate\n");
        printf("4. Reflect\n");
        printf("5. Exit\n");
        printf("\nWhat do you want to do?\n");

        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                //translate
                float t[3][3] = {{1,0,100},{0,1,100},{0,0,1}};

                // call transform matrix function
                Transform(p,t);

                // Display the returned array

                myCleardevice();   /* clear the screen */

                for(int i = 0;i<18;i=i+2)
                {
                    draw(p[0][i], p[1][i], p[0][i+1], p[1][i+1]);
                }

            }

            break;

            case 2:
            {
                //scale
                float t[3][3] = {{-2,0,0},{0,2,0},{0,0,1}};

                // call transform matrix function
                Transform(p,t);

                // Display the returned array

                myCleardevice();   /* clear the screen */

                /* Magic here */

                for(int i = 0;i<18;i=i+2)
                {
                    draw(p[0][i], p[1][i], p[0][i+1], p[1][i+1]);
                }
            }

            break;

            case 3:
            {
                // rotate
                float t[3][3] = {{cos(d2r(30)),-sin(d2r(30)),0},{sin(d2r(30)),cos(d2r(30)),0},{0,0,1}};

                // call transform matrix function
                Transform(p,t);

                // Display the returned array

                myCleardevice();   /* clear the screen */

                for(int i = 0;i<18;i=i+2)
                {
                    draw(p[0][i], p[1][i], p[0][i+1], p[1][i+1]);
                }
            }

            break;

            case 4:
            {
                // reflect
                float t[3][3] = {{1,0,0},{0,-1,0},{0,0,1}};

                // call transform matrix function
                Transform(p,t);

                // Display the returned array

                myCleardevice();   /* clear the screen */

                for(int i = 0;i<18;i=i+2)
                {
                    draw(p[0][i], p[1][i], p[0][i+1], p[1][i+1]);
                }
            }
        }

    }while(ch!=5);
    getch();
    return 0;
}



