#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Initialize random number generation
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int random_number = std::rand() % 100 + 1;

    // Declare a variable for the user's guess
    int user_guess;

    // Greet the user and explain the game
    std::cout << "Welcome to the Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100. Can you guess what it is?" << std::endl;

    // Initialize attempts counter
    int attempts = 0;

    // Loop until the user guesses correctly
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> user_guess;
        attempts++;

        // Check the guess and give feedback
        if (user_guess < random_number) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (user_guess > random_number) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number " << random_number << " correctly in " << attempts << " attempts." << std::endl;
            break;
        }
    }

    return 0;
}
