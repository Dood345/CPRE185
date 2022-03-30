/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */

int debug() {
	return 1;
}

double mag(double x, double y, double z);

int seconds();

int minutes();

int millis();

int close_enough(double tollerance, double point, double value);

int on_off(int pressTriangle);

int checkPosition(int newPosition);

//todo test and try making this a conditional oldPosition = (oldPosition == newPosition) ? 1 : oldPosition = newPosition

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t, X, square, triangle, circle;
    double  ax, ay, az, nx, ny, nz; 
	int position = 20;
	

    /* This while loop makes your code repeat. Don't get rid of it. */
    while (on_off(triangle)) {
        scanf("%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,%d,%d", &t, &nx, &ny, &nz, &ax, &ay, &az, &triangle, &circle, &X, &square); 
		
		if (close_enough(.25, 1, ay)) {
			position = 1;
			if (checkPosition(position)) {//try putting this in one if statement "if (close_enough(.25, 1, ay) && (checkPosition(position))) {
				printf("Top\n");
			}
			
		}
		bottom: if (close_enough(.25, -1, ay)) {
			position = 2;
			if (checkPosition(position)) {
				printf("Bottom\n");
			}
		}
		if (close_enough(.25, 1, ax)) {
			position = 3;
			if (checkPosition(position)) {
				printf("Left\n");
			}
		}
		if (close_enough(.25, -1, ax)) {
			position = 4;
			if (checkPosition(position)) {
				printf("Right\n");
			}
		}
		if (close_enough(.25, -1, az)) {
			position = 5;
			if (checkPosition(position)) {
				printf("Front\n");
			}
		}
		if (close_enough(.25, 1, az)) {
			position = 6;
			if (checkPosition(position)) {
				printf("Back\n");
			}
		}
		
		on_off(triangle);
		
		checkPosition(position);
		
		fflush(stdout);
		
        //printf("acceleration magnitude was: %.2lf\n", 
          //  t, mag(ax, ay, az)); 
            
		/*double mstoSeconds = t/100.0;
		
        printf("Echoing output: %.3lf, %.4lf, %.4lf, %.4lf\n", mstoSeconds, ax, ay, az); */

        /*printf("At %d minutes, %d seconds, and %d milliseconds for a total of %d mililiseconds overall, and it's magnitude of accel was: %lf\n", 
        minutes(t), seconds(t), millis(t), t, mag(ax,ay,az));*/ 

    }

return 0;
}

/* Put your functions here */

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
int close_enough(double tollerance, double point, double value) {
	double upperLimit = point + tollerance;
	double lowerLimit = point - tollerance;
	if ((value <= upperLimit) && (value >= lowerLimit)) {
		return 1;
	}
	else {
		return 0;
	}
}

int on_off(int pressTriangle) {
	return (1 - pressTriangle);
}

int oldPosition = 0;
int checkPosition(int newPosition) {
	if (newPosition == oldPosition) {
		return 0;
	}
	else if (newPosition != oldPosition) {
		oldPosition = newPosition;
		return 1;
	}
}