# Fern leaf

## Driver
1.	Set x and y
2. 	Set length and angle
3. 	Call reccursion

## Recursion
1.	Calculate angular devialation t = ang_passed * pi / 180

2. 	if rl>0

	1.	calculate the new x1, y1 and l1 as

		x1 = x - length * sin(t);
		y1 = y - length * cos(t);
		l1 = length / 5
	
	2. 	Draw the line (x,y,x1,y1)
	
	3. Draw 5 branhces, loop it 5 times as (for i = 1 to i =5)
		1.	Calculate new x2, y2 and l2
		2.	x2 = x - i * l1 * sint(t)
		3. 	y2 = y - i * l1 * cos(t)
		4. 	l2 = l / (i+2)
		5. 	call drawFern recursively as
			1.	drawFern(x2,y2,l2,ang+a,rl-1);
			2. 	drawFern(x2,y2,l2,ang-a,rl-1);
	
	