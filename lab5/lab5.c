#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */

int debug() {
	return 1;
}

double mag(double x, double y, double z);

double seconds(double timeS);

int minutes(int timeM);

int millis(int time);

int close_enough(double tollerance, double point, double value);

int on_off(int pressTriangle);

double checkPosition(double newPosition1, double newPosition2, double newPosition3);

//todo test and try making this a conditional oldPosition = (oldPosition == newPosition) ? 1 : oldPosition = newPosition

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t, X, square, triangle, circle;
    double  ax, ay, az, nx, ny, nz; 
	int position = 20;
	int checkOnce = 0;
	int connection = 0;
	int printFallingOnce = 0;
	int printSafeOnce = 0;
	double fallingTime = 0.0;
	double fallingDistance = 0.0;
	
	t = 0;
	ax = 0.0;
	ay = 0.0;
	az = 0.0;
	
	printf("Daniel Ripley-Betts\ndripleyb\n");

    /* This while loop makes your code repeat. Don't get rid of it. */
	
    while (on_off(triangle)) {																										//You could also do this with 2 loops, one that checks if it's stationary, then breaks to 2nd
        scanf("%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,%d,%d", &t, &nx, &ny, &nz, &ax, &ay, &az, &triangle, &circle, &X, &square); 
		
		if (t != 0 && ax != 0 && az != 0 && ay != 0 && checkOnce == 0) {
			printf("Okay I'm connected\n");
			connection = 1;
			checkOnce = 7;
		}
		
		if (close_enough(0.1, 0.5, mag(ax, ay, az))) {
			if (printFallingOnce == 0) {
				printf("\nI'm Falling!");
			}
			printFallingOnce = 7;
			fallingTime++;
			if (t % 100 < 10) {
				printf("!");
			}
		}
		
		if (fallingTime == 0) {
			if (printSafeOnce == 0) {
				printf("I'm safe.");
				printSafeOnce = 7;
			}
			if (t % 100 < 10) {
				printf(".");
			}
		}
		
		if (checkPosition(ax, ay, az)) {
			printf("Blegh, I'm dead");
			connection = 0;
			break;
		}
		
		if (!(close_enough(0.1, 0.5, mag(ax, ay, az))) && (fallingTime != 0)) {
			break;
		}
		
		
		/*if (close_enough(.25, 1, ay)) {
			position = 1;
			if (checkPosition(position)) {
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
		}*/
		
		on_off(triangle);
		
		checkPosition(ax, ay, az);
		
		fflush(stdout);
		
        //printf("acceleration magnitude was: %.2lf\n", 
          //  t, mag(ax, ay, az)); 
            
		/*double mstoSeconds = t/100.0;
		
        printf("Echoing output: %.3lf, %.4lf, %.4lf, %.4lf\n", mstoSeconds, ax, ay, az); */

        /*printf("At %d minutes, %d seconds, and %d milliseconds for a total of %d mililiseconds overall, and it's magnitude of accel was: %lf\n", 
        minutes(t), seconds(t), millis(t), t, mag(ax,ay,az));*/ 

    }
	fflush(stdout);
	//printf("%.2lf\n", fallingTime);
	//printf("%.2lf\n", seconds(fallingTime));
	fallingDistance = seconds(fallingTime) + (9.8 * pow(seconds(fallingTime), 2)) / 2;
	if (connection) {
		printf("\n \n");
		if (on_off(triangle)) {
			printf("Why would you do that? I fell %.3lf meters for %.3lf seconds", fallingDistance, seconds(fallingTime));
		}
	}
	if (!(on_off(triangle))) {
		printf("Goodbye!");
	}

return 0;
}

/* Put your functions here */

double mag(double x, double y, double z) {	
return sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

double seconds(double timeS) {
	timeS = timeS / 100.0;
return timeS;
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
	double lowerLimit = 0.0;
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

double oldPosition1 = 0.0;
double oldPosition2 = 0.0;
double oldPosition3 = 0.0;
double checkPosition(double newPosition1, double newPosition2, double newPosition3) {
	if ((newPosition1 == oldPosition1) && (newPosition2 == oldPosition2) && (newPosition3 == oldPosition3)) {
		return 1;
	}
	else if ((newPosition1 != oldPosition1) || (newPosition2 != oldPosition2) || (newPosition3 != oldPosition3)) {
		oldPosition1 = newPosition1;
		oldPosition2 = newPosition2;
		oldPosition3 = newPosition3;
		return 0;
	}
}