# Bazier Curve

These curves can be generated under the control of other points. Approximate tangents by using control points are used to generate curve.

The first and last control points are always the end points of the curve; however, the intermediate control points (if any) generally do not lie on the curve. The sums in the following sections are to be understood as affine combinations, the coefficients sum to 1. 

## Algorithm

1. 	Print first point

2. 	Get factorial of n-1

3. 	Run loop from 0.0001 to 1

	3.1	Initially x and y = 0

	3.2	Calculate wrt the formula for all n points
	
		3.2.1	formula:
		
					b(u) =     n! * (1-u)^(n-i) * u^i
							-------
							i!(n-i)!
							
		3.2.2	update x and y as
		
					x = x + b * px[i];
					
					y = y + b * py[i];
					
	3.3 Print x and y

4. Print last point


