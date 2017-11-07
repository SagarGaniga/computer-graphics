#include<math.h>
#include<stdio.h>
#include<graphics.h>


// Function to calculate factorial
int fact(int n)
{
    if(n>1)
        return n*fact(n-1);
    else if(n>=0)
        return 1;
}

void bezier(int px[], int py[], int n)
{
    float u,x,y,b;

    // print first point
    putpixel(px[0],py[0],WHITE);

    // get factorial of n-1
    int nfact=fact(n-1);

    // Run loop from 0.0001 to 1
    for(u=0.0001;u<1;u+=0.0001)
    {
        // Initially x and y = 0
        x=0;
        y=0;

        // calculate wrt the formula for all n points
        for(int i=0;i<n;i++)
        {
            /*
                formula:

                b(u) =     n! * (1-u)^(n-i) * u^i
                        -------
                        i!(n-i)!
            */

            // here n-1 bcoz swag

            b=(nfact*pow(1-u,n-1-i)*pow(u,i))/(fact(n-1-i)*fact(i));

            // update x and y
            x+=b*px[i];
            y+=b*py[i];
        }

        // print x and y
        putpixel(x,y,WHITE);
    }

    // print last point
    putpixel(px[n-1],py[n-1],WHITE);
}

int main()
{
    // Initialize Display
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // User prompt
    printf("Enter number of control points: ");
    int n;
    scanf("%d",&n);

    // 2 array one curve
    int px[n],py[n];

    printf("Enter %d Points: ",n);

    for(int i=0;i<n;i++)
        scanf("%d %d",&px[i],&py[i]);

    bezier(px,py,n);

    getch();
}
