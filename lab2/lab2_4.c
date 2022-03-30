/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name: Daniel Ripley-Betts
- 	Section: 3
-	NetID: dripleyb
-	Date: 02/04/2022
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-							 Implementation
-----------------------------------------------------------------------------*/
int main()
{
    
	//calculations
	
	int a, b, e, f, j;
    double c, d, g, h, i, k;

	a = 6427 + 1725;					//first attempt this returned 8152
	b = 6971 * 3925 - 95;				//first attempt this returned 27361080
	c = 79 + 12 / 5;					//first attempt this returned 81.00
	d = 3640.0 / 107.9;					//first attempt this returned 33.73
	e = (22 / 3) * 3;					//first attempt this returned 21
	f = 22 / (3 * 3);					//first attempt this returned 2 makes sense, printed an integer
	g = 22 / (3 * 3);					//first attempt this returned 2.00, doesn't make sense when printing a double
	h = 22 / 3 * 3;						//first attempt this returned 21
	i = (22.0 / 3) * 3.0;				//first attempt this returned 22
	j = 22.0 / (3 * 3.0);				//first attempt this returned 2 makes sense, printed an integer
	k = 22.0 / 3.0 * 3.0;				//first attempt this returned 22, tried parenthesis to no avail, no luck with removing spaces either
	
	printf("The requested calculations result in the following: \n");
	printf("a = %d \n", a);				// could have just not defined any varriable and put the expression after the comma
	printf("b = %d \n", b);
	printf("c = %.2lf \n", c);
	printf("d = %.2lf \n", d);
	printf("e = %d \n", e);
	printf("f = %d \n", f);
	printf("g = %.2lf \n", g);
	printf("h = %.2lf \n", h);
	printf("i = %.2lf \n", i);
	printf("j = %d \n", j);
	printf("k = %.2lf \n", k);
	
	printf("\n");
	
	
	//equations to solve
    
	double areaCircle = 0.0;
	double perimeterCircle = 23.567;
	int tempFarenheit = 76;
	double tempCelcius = 0.0;
	double feetInMeeters = 0.0;
	int distanceFeet = 14;
	
	
	printf("enter perimeter of circle:");
	scanf("%lf", &perimeterCircle);			//added this to test myself and play with code after setting up cygwin64 on my machine, almost built new gcc to get compiler working
	
	areaCircle = pow((perimeterCircle / (2 * M_PI)), 2.0) * M_PI;
	
	
	feetInMeeters = distanceFeet * 0.3048;
	
	
	tempCelcius = (tempFarenheit - 32) / 1.8;
	
	printf("The solutions equations result in the following: \n");
	printf("Area of a Circle of perimeter %.3lf = %.3lf \n", perimeterCircle, areaCircle);
	printf("%d Feet converted to Meeters = %.2lf m \n", distanceFeet, feetInMeeters);
	printf("%d degrees Farenheit in Celcius = %.2lf C \n", tempFarenheit, tempCelcius);
	
	
	
    return 0;
}

