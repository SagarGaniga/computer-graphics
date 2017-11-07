# Liang Basky

## Algorithm

1. Make 2 arrays p and w with size 4

2. Create Boundray

3. Get line

4. calculater dx and dy

5. P Array
	
		p[0]=-dx;
		
		p[1]=dx;
		
		p[2]=-dy;
		
		p[3]=dy;

6. Q Array

		q[0]=x1-xmin;
	
		q[1]=xmax-x1;
		
		q[2]=y1-ymin;
		
		q[3]=ymax-y1;

7. t1 = max(0, tx);

8. t2 = min(1, ty);

9. for any i
		if ( p[i]==0 && q[i] < 0 )
			Line completely outside the window

10. Check t1 and t2
		if (t1 < t2)
		
		{
			 
			 xx1=x1+t1*dx;
			 
			 yy1=y1+t1*dy;

			 xx2=x1+t2*dx;
			 
			 yy2=y1+t2*dy;
			 
			 setcolor(WHITE);
			 
			 line(xx1,yy1,xx2,yy2);
		
		}
		else
		{
			Line completely outside the window
		}
