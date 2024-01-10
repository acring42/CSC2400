#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	/*
		-argc is the number of command line arguments (including the executable file name which is weird)
		-argc stands for argument count
	*/
	/*
		-argv is the actual arguments
		-argv stands for argument vector, which is defined as an array of c-stringstream
		-argv[0] is the executable file name
	*/
	
	//	First make sure that the user typed in enough arguments.  If not, end program.
	if(argc != 3)
	{
		cout << "\n\nIncorrect Number of Arguments!\n";
		return 1; //exit program
	}
	/* The user will pass the age of the person and the name of the person as command line arguments */
	/* Everything the user passes will come into the program as a character array and so I have to convert age to integer */
	if(atoi(argv[1]) > 90)
		cout << "\n\nWow, " << argv[2] << " you are really old!\n";
	else if(atoi(argv[1]) > 25)
		cout << "\n\nHello, " << argv[2] << "!\n";
	else
		cout << "\n\nAwwweee, hello baby " << argv[2] << ", how are you today?\n";
	
	return 0;
}