// 185 lab6.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of DS4 data, and returns
//  True when the square button is pressed
//  False Otherwise
//This function is the ONLY place scanf is allowed to be used
//POST: it modifies its arguments to return values read from the input line. √
int read_line(double* g_x, double *g_z, double *g_y, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C);




// PRE: roll values are -1.0 <= x_mag (or just x variable) <= 1.0
// This function computes the roll of the DS4 in radians, at -1 is pi/2 radians, at 1 is -pi/2 radians
// if x_mag outside of -1 to 1, treat it as if it were -1 or 1 √
// POST: -PI/2 <= return value <= PI/2 √
double roll(double x_mag);




// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the DS4 in radians
// if y_mag outside of -1 to 1, treat it as if it were -1 or 1 √
// POST: -PI/2 <= return value <= PI/2 √
double pitch(double y_mag);




// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39 √
int scaleRadsForScreen(double rad);
// couldn't I just have the pitch function go directly to -39 through 39 rather than radians first?



// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times √
void print_chars(int num, char use);




//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide. √
void graph_line(int number);




//PRE: Button as on or off
// one button press will report 1 for multiple loops (4-10)
//POST: Button pressed once flips it to 0 or One
int buttonToggle(int buttonValue, int *pressTime);




int main()
{
	double x, y, z;                             // magnitude values of x, y, and z
	int b_Triangle, b_X, b_Square, b_Circle;    // variables to hold the button statuses
	double roll_rad, pitch_rad;                 // value of the roll measured in radians
	int scaled_value;                           // value of the roll adjusted to fit screen display
	int time, timeX, timeS, timeC, timeT, toggleX;

	//insert any beginning needed code here
	
	timeX = 0;
	toggleX = 0;
	
	do
	{
		// Get line of input √
		
		read_line(&x, &z, &y, &time, &b_Triangle, &b_X, &b_Square, &b_Circle);
		
		// calculate roll and pitch.  Use the buttons to set the condition for roll and pitch √
		
		pitch_rad = pitch(y);
		
		roll_rad = roll(x);	
				
		// switch between roll and pitch(up vs. down button) √
		
		/*buttonToggle(b_X, &timeX);
		
		toggleX = 1 - timeX;*/
		
		if (b_X) {//MODIFY to use a toggle
			// Scale your output value √
			scaled_value = scaleRadsForScreen(pitch_rad);
		}
		else if (!(b_X)) {//MODIFY to use a toggle
			// Scale your output value √
			scaled_value = scaleRadsForScreen(roll_rad);
		}
				
		// Output your graph line √
		//printf("%d in\n", b_Square);
		graph_line(scaled_value);
		
		
		
		fflush(stdout);
	} while (b_Square == 0); // Modify to stop when the square button is pressed √
	return 0;
}

int read_line(double *g_x, double *g_z, double *g_y, int *time, int *Button_T, int *Button_X, int *Button_S, int *Button_C) { //changed g_y to g_z and vice versa to fit templates
	scanf(" %d, %lf, %lf, %lf, %d, %d, %d, %d", time, g_x, g_z, g_y, Button_T, Button_C, Button_X, Button_S); 
	//printf("%d fx\n", *Button_S);
	//many times did I encounter "segmentation failed core dumped" error and tried changing to a void function only to realize that it was due to the use of amperstands in front of the variables used with scanf
	return *Button_S;
}

int buttonToggle(int buttonValue, int *pressTime) {
	int useTime = 0;
	int toggle = 0;
	if (buttonValue == 1) {
		*pressTime++;
		useTime++;
	}
	toggle = useTime;
	toggle = toggle / 11;
	*pressTime = *pressTime/11;
	return toggle;
}

double roll(double x_mag) {
	if (x_mag < -1) {
		x_mag = -1;
	}
	else if (x_mag > 1) {
		x_mag = 1;
	}
	x_mag = x_mag * (-PI) / 2;
	
	return x_mag;
}

double pitch(double y_mag) {
	if (y_mag < -1) {
		y_mag = -1;
	}
	else if (y_mag > 1) {
		y_mag = 1;
	}
	y_mag = y_mag * (-PI) / 2;
	
	return y_mag;
}

int scaleRadsForScreen(double rad) {
	rad = sin(rad) * 39;
	
	return rad;
}

void print_chars(int num, char use) {
	for (int i = 0; i < num; i++) {
		printf("%c", use);
	}
}

void graph_line(int number) {
	for (int i = -39; i < 40; i++) {
		if (number > i && i < 0) {
			printf(" ");
		}
		if (number <= i && i < 0) { //if number = -4 and i = -5 space should be printed also if num = -5 and i = 4 block should print
			printf("█"); // thought about using █, ←, →
		
		}
		if (number < i && i > 0) {
			printf(" ");
		}
		if (number >= i && i > 0) { //if number = 4 and i = 5 space should be printed
			printf("█"); //also could try using print_chars((number of chars), "char")
		}
	}
	if (number == 0) {
		print_chars(40, ' ');
		printf("0");
	}
	printf("\n"); //comment this and the 0 statement out for some form of art
}