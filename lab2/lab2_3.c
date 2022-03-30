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
    int integerResult;
    double decimalResult;

    integerResult = 77 / 5;
    printf("The value of 77/5 is %d, using integer math\n", 
	integerResult); //%lf was used to call a integer variable, %d should be used

    integerResult = 2 + 3;
    printf("The value of 2+3 is %d\n", 
	integerResult);  //no variable called for %d, added integerResult

    decimalResult = 1.0 / 22.0;
    printf("The value 1.0/22.0 is %lf\n", 
	decimalResult); //%d was used to call a double variable, %lf should be used

    return 0;
}

