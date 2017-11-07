# Cohen Sutherland
Cohen-Sutherland algorithm divides a two-dimensional space into 9 regions and then efficiently determines the lines and portions of lines that are inside the given rectangular area.

## There are three possible cases for any given line.

Completely inside the given rectangle : 
Bitwise OR of region of two end points of line is 0 (Both points are inside the rectangle)

Completely outside the given rectangle : 
Both endpoints share at least one outside region which implies that the line does not cross the visible region. (bitwise AND of endpoints != 0).

Partially inside the window : 
Both endpoints are in different regions. In this case, the algorithm finds one of the two points that is outside the rectangular region. The intersection of the line from outside point and rectangular window becomes new corner point and the algorithm repeats

## Pseudo Code:

Step 1 : 	Assign a region code for two endpoints of given line.
Step 2 : 	If both endpoints have a region code 0000 then given line is completely inside.
Step 3 : 	Else, perform the logical AND operation for both region codes.
			Step 3.1 : If the result is not 0000, then given line is completely outside.
			Step 3.2 : Else line is partially inside.
			Step 3.2.1 : Choose an endpoint of the line that is outside the given rectangle.
			Step 3.2.2 : Find the intersection point of the rectangular boundary (based on region code).
			Step 3.2.3 : Replace endpoint with the intersection point and update the region code.
			Step 3.2.4 : Repeat step 2 until we find a clipped line either trivially accepted or trivially rejected.
Step 4 : 	Repeat step 1 for other lines
