# Bresenham’s Circle Drawing Algorithm

In Bresenham’s algorithm at any point (x, y) we have two option either to choose the next pixel in the east i.e. (x+1, y) or in the south east i.e. (x+1, y-1).

And this can be decided by using the decision parameter d as:

1. If d > 0, then (x+1, y-1) is to be chosen as the next pixel as it will be closer to the arc.
2. else (x+1, y) is to be chosen as next pixel.

d = 3 - (2 * r)
x = 0
y = r

Now for each pixel, we will do the following operations:

1. Set initial values of (xc, yc) and (x, y)
2. Set decision parameter d to d = 3 – (2 * r).
3. Repeat steps 4 to 8 until x < = y
4. call drawCircle(int xc, int yc, int x, int y) function.
5. Increment value of x.
6. If d < 0, set d = d + (4*x) + 6
7. Else, set d = d + 4 * (x – y) + 10 and decrement y by 1.
8. call drawCircle(int xc, int yc, int x, int y) function