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
    srand(time(0)); // Ensures a different random number each run

    // Generate a random number between 1 and 100
    int randomNumber = (rand() % 100) + 1; 
    int userGuess;
    int attempts = 5; // Number of chances

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Please guess a number between 1 and 100." << endl;
    cout << "You have " << attempts << " attempts to guess it correctly." << endl;

    // Loop to allow the user to guess
    for (int i = 1; i <= attempts; i++) { // Loop for number of attempts
        do { 
            cout << "You have " << (attempts - i + 1) << " attempts remaining. Enter your guess: ";
            cin >> userGuess;

            // Check if input is invalid (not a number)
            if (cin.fail()) { 
                cout << "Invalid input! Please enter a number between 1 and 100." << endl;
                cin.clear();  // Reset input state
                cin.ignore(1000, '\n'); // Ignore extra characters in input
                continue; // Restart the loop
            }

            // Check if the guess is out of range
            if (userGuess < 1 || userGuess > 100) { 
                cout << "Invalid number! Please enter a number between 1 and 100." << endl;
            }

        } while (cin.fail() || userGuess < 1 || userGuess > 100); // Ensure valid input

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
    }

    // If user runs out of attempts
    cout << "Sorry, you've used all your attempts!" << endl;
    cout << "The correct number was: " << randomNumber << endl; // Display correct answer

    return 0; // Ends the program
}

