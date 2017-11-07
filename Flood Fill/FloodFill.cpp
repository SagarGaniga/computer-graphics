#include<stdio.h>
#include<graphics.h>
#include<dos.h>
void ff(int x,int y,int bc,int fillc)
{
	if(getpixel(x,y) != bc && getpixel(x,y) != fillc)
	{
    	putpixel(x,y,fillc);

    	ff(x+1,y+1,bc,fillc);
    	ff(x+1,y-1,bc,fillc);

    	ff(x-1,y+1,bc,fillc);
    	ff(x-1,y-1,bc,fillc);

    	ff(y+1,x-1,bc,fillc);
    	ff(y+1,x+1,bc,fillc);

    	ff(y-1,x+1,bc,fillc);
    	ff(y-1,x-1,bc,fillc);
	}
}

int main(){
	initwindow(700,700);
	setcolor(RED);

	circle(200,200,150);
	circle(200,200,151);
	circle(200,200,152);

	circle(200,200,100);
	circle(200,200,101);
	circle(200,200,102);

	ff(200,200,4,14);
	ff(310,200,4,15);

	delay(100);
	system("pause");
	return 0;
}
