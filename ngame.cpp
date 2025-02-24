/*******************************************************************************
* Program Name: Number Generator
* Created Date: 2/22/2025
* Created By: Ryan Nalbach
* Purpose: To generate a random number and have the user guess the number
* Acknowledgements: Tony Gaddis C++ Pearson book, Professor Cayton Polen
*******************************************************************************/

#include <iostream>  // To print to console and have input
#include <iomanip>   // To change configuration of output  
#include <cstdlib>   // For rand() and srand() - generates the random number
#include <ctime>     // For time() - helps seed the random number generator

using namespace std; // This is the standard library

/*******************************************************************************
* Function Name: main()
* Parameters: None
* Return Value: int
* Purpose: To generate a random number that the user guesses
*******************************************************************************/


int main() {
    // Seed the random number generator
    srand(time(0)); //using time will generate a new random number each time

    // Generate a random number between 1 and 100
    int randomNumber = (rand() % 100) + 1; 
    int userGuess;
    int attempts = 5; // Number of chances

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Please guess a number between 1 and 100." << endl;
    cout << "You have " << attempts << " attempts to guess it correctly." << endl;

    // Loop for the number of attempts
    for (int remainingAttempts = attempts; remainingAttempts > 0; ) { // No decrement in for loop
        cout << "You have " << remainingAttempts << " attempts remaining. Enter your guess: ";

        // Input validation loop
        while (!(cin >> userGuess) || userGuess < 1 || userGuess > 100) { 
            cout << "Invalid input! Please enter a number between 1 and 100: ";
            cin.clear();  // Reset the error state
            cin.ignore(1000, '\n'); // Ignore incorrect input
        }

        // Check if the guess is correct
        if (userGuess == randomNumber) {
            cout << "Congratulations! You guessed the right number!" << endl;
            return 0; // Ends the program
        }
        else if (userGuess > randomNumber) { 
            cout << "Your guess is too high! Try again." << endl;
        }
        else { 
            cout << "Your guess is too low! Try again." << endl;
        }

        remainingAttempts--; // Decrement only after valid input
    }

    // If user runs out of attempts
    cout << "Sorry, you've used all your attempts!" << endl;
    cout << "The correct number was: " << randomNumber << endl;

    return 0; // Ends the program
}
