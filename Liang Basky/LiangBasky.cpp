#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
int main()
{
    initwindow(700,700);

    int x1,y1,x2,y2,
        xmax,xmin,ymax,ymin,
        xx1,yy1,xx2,yy2,
        dx,dy,
        i;

    int p[4],q[4];

    float t1,t2,t[4];

    printf("Enter the lower co-ordinates of window : ");
	scanf("%d%d",&xmin,&ymin);

	printf("Enter the upper co-ordinates of window : ");
	scanf("%d%d",&xmax,&ymax);

    setcolor(RED);
    rectangle(xmin,ymin,xmax,ymax);

    printf("Enter x1 and y1 : ");
    scanf("%d%d",&x1,&y1);

    printf("Enter x2 and y2 : ");
    scanf("%d%d",&x2,&y2);

    line(x1,y1,x2,y2);

    dx=x2-x1;
    dy=y2-y1;

    // Liang Basky Formula

    // P Array
    p[0]=-dx;
    p[1]=dx;
    p[2]=-dy;
    p[3]=dy;


    // Q Array
    q[0]=x1-xmin;
    q[1]=xmax-x1;
    q[2]=y1-ymin;
    q[3]=ymax-y1;

    t1=0;   //max(0,tx)
    t2=1;   //min(1,tx)

    for(i=0;i < 4;i++)
    {
        if(p[i]!=0)
        {
            t[i]=(float)q[i]/p[i];
            if(p[i]<0)
        	{
            	if(t[i]>t1)
                	t1=t[i];
        	}
        	else{
            	if(t[i]<t2)
                	t2=t[i];
        	}

        }
        else
        {
                if(p[i]==0 && q[i] < 0)
                    printf("\nLine completely outside the window");
        }
    }

    if (t1 < t2)
    {
         xx1=x1+t1*dx;
         yy1=y1+t1*dy;

         xx2=x1+t2*dx;
         yy2=y1+t2*dy;
         setcolor(WHITE);
         line(xx1,yy1,xx2,yy2);
    }
    else{
         	printf("\nLine lies out of the window");
    }
    system("pause");
    return 0;
}
