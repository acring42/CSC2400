/***********************************************************************
	Title:  		acring_A.cpp
	Creation Date:  9-7-2021
	Purpose:		Find greatest common divisor (gcd) of two integers
					using Euclid's Algorithm
************************************************************************/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int isLargest(int a, int b);
int isSmallest(int a, int b);

int main(int argc, char* argv[]){
	// if the wrong amount of arguments are entered, this error message will appear and the program will stop
	if(argc != 3){
		cout << "\n\nUsage:  commandLine.exe age name\n";
		cout << "(where m & n are non-zero, non-negative integers)" << endl;
		return 0;
	}
    int r=-1, gcd; // r is the remainder and is set to -1 at default to allow while function to work
	int m=(atoi(argv[1])), n=atoi(argv[2]); //m is the first argument and n is the second argument
	int max = isLargest(m,n), min = isSmallest(m,n); // max and min take the arguments and send them to their 
													 // specific functions to return the higher and loweer of the two arguments
	
	// this funciton loops until the remainder is zero
	while(r!=0){
	    // if the max or min are ever 0 at the beginning of this loop, the program will consider the gcd undefined
		if(max==0 || min==0){
			cout << "\ngcd(" << m << ", " << n << ") is undefined" << endl;
			return 0;
		}
		r = max%min; // find the remainder for max%min
		max=min; // set max to equal min
		min=r; // set min to equal the remainer
	}
	gcd=max; // once the gcd is found, it will be stored until max, so it will be copied to gcd to display to the user
	cout << "\ngcd(" << m << ", " << n << ") is " << gcd << endl; // display the gcd
    return 0;
}
// takes arguments and returns the higher of the two
int isLargest(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}
// takes arguments and returns the lower of the two
int isSmallest(int a, int b){
	if(a>b)
		return b;
	else
		return a;
}