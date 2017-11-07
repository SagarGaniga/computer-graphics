# Koch Curve

## Algorithm

1.	int x1 = 100, y1 = 200, x2 = 400, y2 = 200, x3 = 250, y3 = 450  (IDK Why)
2.	Recursion with 1,2 and 3
		order: 12, 21, 13

		
## Recursive Method
1. 	find angle = 60*pi /180

2.	find p3 near p1 
		(2P1 + P2)/3


3. 	find p4 near p2
		(P1 + 2P2)/3

4.	find joining pt
		dx = x4 - x3
		dy = y4 - y3
		
5. 	Calculate x
		x = x3 + dx*cos(angle)+dy*sin(angle)

6. 	Calculate y
		y = y3 - dx*sin(angle)+dy*cos(angle);

7. 	if rl > 0
		recurse like
			13,30,04,42
	else
		line like	
			1,40,04,42
