# Transformations

## Matrix Multiplication
	
	for(i=0;i<3;i++)
    {
        for(j=0;j<18;j++)
        {
            sum=0;
            for(k=0;k<3;k++)
            {
                sum=sum+t[i][k]*p[k][j];
            }
            c[i][j]=sum;

        }
    }
	
## translate
float t[3][3] = {{1,0,100},{0,1,100},{0,0,1}};


## scale
float d[3][3] = {{tx,0,0},{0,ty,0},{0,0,1}};


## rotate
float t[3][3] = {{cos(d2r(30)),-sin(d2r(30)),0},{sin(d2r(30)),cos(d2r(30)),0},{0,0,1}};

### degree to radians
double d2r(double d) {
  return (d / 180.0) * ((double) M_PI);
}

## reflect
float t[3][3] = {{1,0,0},{0,-1,0},{0,0,1}};

	