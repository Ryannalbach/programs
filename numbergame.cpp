/*******************************************************************************
* Program Name: Number Generator
* Created Date: 2/22/2025
* Created By: Ryan Nalbach
* Purpose: TO generator a random number and have the user guess the number
* Acknowledgements: Tony Gaddis C++ pearson book, professor Cayton Polen
*******************************************************************************/
#include <iostream> //to print to console and have input
#include <iomanip> //to change configuration of output  
#include <cstdlib>    // For rand() and srand() this will help generate the random number
#include <ctime>      // For time() this will help generate the random number

using namespace std; //this is the standard library

/*******************************************************************************
* Function Name: main()
* Parameters: None
* Return Value: int
* Purpose: to generator a random number that the user guesses
*******************************************************************************/

int main() {
    // Seed the random number generator
    srand(time(0)); //by using the time we change the random numbers without this it would generate the same random number

    // Generate a random number between 1 and 100
    int randomNumber = (rand() % 100) + 1; 
    int userGuess;
    int attempts = 5; // Number of chances

    cout << "Welcome to the Number Guessing Game!" << endl; //this is the introduction to the game for the user to see
    cout << "Please guess a number between 1 and 100." << endl;
    cout << "You have " << attempts << " attempts to guess it correctly." << endl; //clarifying the attempts logic below, doing it this way uses less lines of code

    // Loop to allow the user to guess
    for (int i = 1; i <= attempts; i++) { //this is the logic for calculating the number of guesses left
        do { //using the do allows the code to run once for the loop
            cout << "Attempt " << i << ": Enter your guess: "; //this is the prompt for the user  to input a guess
            cin >> userGuess; //this allows the user to eneter the guess

            // Check if the guess is out of range
            if (userGuess < 1 || userGuess > 100) { // the || acts as or statement
                cout << "Invalid number! Please enter a number between 1 and 100." << endl;
            }// output to show the user they have an invalid input

        } while (userGuess < 1 || userGuess > 100); // Repeat until valid input is given

        // Check if the guess is correct
        if (userGuess == randomNumber) {
            cout << "Congratulations! You guessed the right number!" << endl;
            return 0; // Ends the program
        }
        else if (userGuess > randomNumber) { //this continues if the guess isn't is high
            cout << "your guess is too high! Try again." << endl;
        }
        else { //this is for the guess being too low
            cout << "your guess is too low! Try again." << endl;
        }
    }

    // If user runs out of attempts
    cout << "Sorry, you've used all your attempts!" << endl;
    cout << "The correct number was: " << randomNumber << endl; //this shows the user the number if they couldn't guess it

    return 0; //this ends the program running 
}
