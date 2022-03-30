/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name: Daniel Ripley-Betts
- 	Section: 3
-	NetID: dripleyb
-	Date: 2/5/2022
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
    double a, b, c;
    double filler;
    /* Put your code after this line */
	printf("Enter values for a and b separated by a single space:");
	scanf("%lf %lf", &a, &b);

    /*  This next line will calculate the square root of whatever value is
        inside the parenthesis and assigns it to the variable filler. */
    filler = sqrt((pow(a, 2) + pow(b, 2)));				//Initially I was getting incorrect values for c, 3 4 would result in 2.2360 not 5, determined the error due to a lack of parenthesis around the addition, program thought I was asking it to do sqrt(3^2 + 4^2)

	
	printf("The length of c is %.3lf", filler);

    return 0;


}

