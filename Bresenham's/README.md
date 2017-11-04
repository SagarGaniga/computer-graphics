# Bresenham’s Line Generation Algorithm

The idea of Bresenham's algorithm is to avoid floating point multiplication and addition to compute mx + c, 
and then computing round value of (mx + c) in every step. In Bresenham's algorithm, 
we move across the x-axis in unit intervals.


1. We always increase x by 1, and we choose about next y, whether we need to go to y+1 or remain on y. 
2. In other words, from any position (Xk, Yk) we need to choose between (Xk + 1, Yk) and (Xk + 1, Yk + 1).
3. We would like to pick the y value (among Yk + 1 and Yk) corresponding to a point that is closer to the original line.


