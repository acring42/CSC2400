#include <iostream>
#include <cstring>
using namespace std;

void JohnsonTrotter(string);
void Lexicographic(string);
void printJohnsonTrotter(char[], bool[], int, int);
void printLexicographic(char[], int, int, int, int);

int main(){
    // getting input from the user
    string input;
    cout << "Enter a string to find its permutations: " << endl;
    getline(cin,input);

    JohnsonTrotter(input);
    Lexicographic(input);
    cout << "\nAll Done!" << endl;
    return 0;
    
}
// Johnson-Trotter algorithm function 
void JohnsonTrotter(string input){
    // taking the user input and putting it into char array
    // to ensure algorithm works with numbers and letters
    cout << "\nJohnson-Trotter Algorithm";
    int length=input.length();
    char array[length];
    strcpy(array, input.c_str());

    // array of arrow directions
    // left means from right to left and right means from left to right 
    // "<-" is left and "->" is right
    bool direction[length], right=true, left=false;
    for(int i=0; i<length; i++)
        direction[i]=left;
    
    // current is the current mobile number, last is the last mobile number,
    // count is number of permutations, and mobilePos is the position of the current mobile
    // current and last are set to seperate numbers so the do-while loop will start
    int count=0, mobilePos;
    char current=0, last=1;
    printJohnsonTrotter(array, direction, length, count);
    //loop will continue until there is no mobile number
    do{
        current=0, last=0;
        // finding the current mobile number
        for(int i=0; i<length; i++){
            if(direction[i]==right && i!=(length-1)){
                if(array[i]>=last && array[i]>array[i+1]){
                    current=array[i];
                    last=current;
                }
            }
            if(direction[i]==left && i!=0){
                if(array[i]>=last && array[i]>array[i-1]){
                    current=array[i];
                    last=current;
                }
            }
        }
        // section below is just is to void the rest of the do-while loop
        // if there are no more mobiles
        if(current!=0 && last!=0){
            ++count;
            //finding the mobile number's position in array
            for(int i=0; i<length; i++){
                if(array[i]==current)
                    mobilePos=i;
            }

            // current mobile number switches places with whichever number
            // it is pointing to and the arrows swap with along with them
            if(direction[mobilePos]==left){
                swap(array[mobilePos], array[mobilePos-1]);
                swap(direction[mobilePos], direction[mobilePos-1]);
            }
            else{
                swap(array[mobilePos+1], array[mobilePos]);
                swap(direction[mobilePos+1], direction[mobilePos]);
            }

            // reverses arrows of elements larger than mobile number
            for(int i=0; i<length; i++){
                if(array[i]>current){
                    if(direction[i]==left){
                        direction[i]=right;
                    }
                    else{
                        direction[i]=left;
                    }
                }
            }
            printJohnsonTrotter(array, direction, length, count);
        }
    }while(current!=0 && last!=0);
    cout << "\n\nJohnson-Trotter Algorithm Complete!" << endl; 
}
// Lexicographic Order Algorithm function
void Lexicographic(string input){
    // taking the user input and putting it into char array
    // to ensure algorithm works with numbers and letters
    int length=input.length();
    char array[length];
    strcpy(array, input.c_str());
    // putting length in array index form to make code neater
    int arraySize=length-1, i, j, count=1;
    // temp is the P[i] element in step one of the slides
    char temp;
    // Will loop until there are no more permutations which
    // will happen when "i" is less than 0
    while(i>=0){
        // finding the P[i] element that is less than P[i+1]
        for(i=arraySize-1; i>-1; i--){
            if(array[i]<array[i+1]){
                temp=array[i];
                break;
            }
        }
        // j is set to "i+1" by default in case there is no
        // element greater than P[i] but less than P[i+1]
        j=i+1;
        // finding j
        for(int x=i+1; x<=arraySize; x++){
            if(array[x]>temp && array[x]<array[i+1]){
                j=x;
            }
        }
        printLexicographic(array, i, j, count, length);
        // swapping "i" and "j" positions in array
        swap(array[i], array[j]);

        // sorting array[i+1...arraySize]
        for(int low=i+1, high=arraySize; low<high; low++,high--)
            swap(array[low], array[high]);
        count++;
    }
    cout << "\n\nLexicographic Algorithm Complete!" << endl;
}

// prints all Johnson-Trotter permutations
void printJohnsonTrotter(char array[], bool direction[], int length, int count){
    cout << endl << endl;
    cout << count+1 << ":  ";
    for(int i=0; i<length; i++){
        if(direction[i])
            cout << "-> ";
        else
            cout << "<- ";
    }
    cout << endl;
    cout << "     ";
    for(int i=0; i<length; i++){
        cout << array[i] << "  ";
    }
}

// prints all Lexicographic permutations along with "i" and "j" values
void printLexicographic(char array[], int i, int j, int count, int length){
    cout << endl;
    cout << count << ":\t";
    for(int x=0; x<length; x++)
        cout << array[x];
    // prints the "i" and "j" values up til the last permutation    
    if(i>=0)
    cout << "  i = " << i << "  j = " << j << endl;
    
}





