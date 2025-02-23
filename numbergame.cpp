// Number Guessing Game with Input Validation
#include <iostream>  
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time()

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = (rand() % 100) + 1;
    int userGuess;
    int attempts = 5; // Number of chances

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "You have " << attempts << " attempts to guess it correctly." << endl;

    // Loop to allow the user to guess
    for (int i = 1; i <= attempts; i++) {
        do {
            cout << "Attempt " << i << ": Enter your guess (1 - 100): ";
            cin >> userGuess;

            // Check if the guess is out of range
            if (userGuess < 1 || userGuess > 100) {
                cout << "Invalid input! Please enter a number between 1 and 100." << endl;
            }

        } while (userGuess < 1 || userGuess > 100); // Repeat until valid input is given

        // Check if the guess is correct
        if (userGuess == secretNumber) {
            cout << "Congratulations! You guessed the right number!" << endl;
            return 0; // End the program
        }
        else if (userGuess > secretNumber) {
            cout << "Too high! Try again." << endl;
        }
        else {
            cout << "Too low! Try again." << endl;
        }
    }

    // If user runs out of attempts
    cout << "Sorry, you've used all your attempts!" << endl;
    cout << "The correct number was: " << secretNumber << endl;

    return 0;
}
