# Mid-Point Circle Drawing Algorithm

We use the above algorithm to calculate all the perimeter points of the circle in the first octant and then print them along with their 
mirror points in the other octants. This will work only because a circle is symmetric about it’s centre.

For any given pixel (x, y), the next pixel to be plotted is either (x, y+1) or (x-1, y+1). This can be decided by following the steps below.

1. Find the mid-point p of the two possible pixels i.e (x-0.5, y+1)
2. If p lies inside or on the circle perimeter, we plot the pixel (x, y+1), otherwise if it’s outside we plot the pixel (x-1, y+1)

## Algorithm

1. put x = radius and y = 0
2. Printing the initial point on the axes after translation
3. Combinations
        x and y
        x and -y
        y and x
        -y and x
4. Initialising the value of P
    int P = 1 - r;
5. loop till x > y and y++
6. if p > 0
	P = P + 2*y - 2*x + 1; and x--;
7. if p <= 0
	P = P + 2*y + 1;
8. Print All octant
