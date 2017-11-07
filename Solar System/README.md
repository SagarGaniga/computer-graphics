# Solar System

## Steps

1. Set initial positions of planets
2. Loop
	2. Change the displacement as a = (pi/180) * initial position
	3. Draw the circle with new position as
		circle(320+x*sin(b),240-y*cos(b),12);
        ellipse(320,240,0,360,x,y);
		x and y with incremnet of 30 and differece of 30