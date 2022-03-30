/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */

double mag(double x, double y, double z);

int seconds(int timeS);

int minutes(int timeM);

int millis(int time);

int buttonspressed(int a, int b, int c, int d);

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int triangle, circle, X, square;
         


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        scanf("%d,%d,%d,%d", &triangle, &circle, &X, &square); 
		
		printf("Currently you are pressing %d buttons down at the same time\n", buttonspressed(triangle,circle,X,square));
		fflush(stdout);
		
/* CODE SECTION 0 */
		/*double mstoSeconds = t/100.0;
		
        printf("Echoing output: %.3lf, %.4lf, %.4lf, %.4lf\n", mstoSeconds, ax, ay, az); */

/* CODE SECTION 1 */
        /*printf("At %d ms, the acceleration's magnitude was: %lf\n", 
            t, mag(ax, ay, az)); */
            
/* CODE SECTION 2 */

        /*printf("At %d minutes, %d seconds, and %d milliseconds for a total of %d mililiseconds overall, and it's magnitude of accel was: %lf\n", 
        minutes(t), seconds(t), millis(t), t, mag(ax,ay,az)); */

    }

return 0;
}

/* Put your functions here */

int buttonspressed(int a, int b, int c, int d) {
	return a + b + c + d;
}

double mag(double x, double y, double z) {	
return sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

int seconds(int timeS) {
	timeS = timeS / 100;
	return timeS % 60;
}

int minutes(int timeM) {
	return timeM / 6000;
}

int millis(int time) {
	time = time % 100;
	return time;
}
