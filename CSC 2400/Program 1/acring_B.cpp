/***********************************************************************
	Title:  		acring_B.cpp
	Creation Date:  9-7-2021
	Purpose:		Find greatest common divisor (gcd) of two integers
					using Euclid's Algorithm
************************************************************************/
#include <iostream>
#include <cmath>
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

    int m=atoi(argv[1]), n=atoi(argv[2]); // m is the first argument and n is the second
	int max = isLargest(m,n), min = isSmallest(m,n); //m is the first argument and n is the second argument
	int test=min; // test is the incrementing variable that will eventually turn into the gcd and is set to 
		         // the lowest number by default
	
	// if the max or min are 0, the program will consider the gcd undefined
	if(max==0 || min==0){
		cout << "\ngcd(" << m << ", " << n << ") is undefined" << endl;
		return 0;
	}
	// this function will loop as long on the incrementing variable is positive or until the gcd is found
	while(test>0){
		// checks if the remainder of the max and test variable as well as the max and test variable
		// are both zero. If they are, the gcd is displayed and the program ends. If not, the test variable 
		// decrements and continues loop
		if(max%test==0 && min%test==0){
			cout << "\ngcd(" << m << ", " << n << ") is " << test;
			return 0;
		}
		else
			--test;
	}	
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