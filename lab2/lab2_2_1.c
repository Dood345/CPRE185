/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name: Daniel Ripley-Betts
- 	Section: 3
-	NetID: dripleyb
-	Date:2/4/2022
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

    /* Put your code after this line */
	char Name[19] = "Daniel Ripley-Betts";
	char Course[] = "Computer Engineering 185";
	char Date[10] = "02/04/2022";
	int x=0, y=0;

	printf("%s \n", Name);
	printf("%s \n", Course);
	printf("%s \n", Date);

	printf("Enter a width: ");
	scanf("%d", &x);
	printf("Enter a height: ");
	scanf("%d", &y);
	printf("A %d by %d rectangle's area is %d", x, y, x * y);


    return 0;

}

