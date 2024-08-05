#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <limits>  // for numeric_limits

// Function to print a welcome message with ASCII art
void printWelcomeMessage()
{
    std::cout << "========================================" << std::endl;
    std::cout << "              NUMBER GUESSING GAME!" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "  ____                         " << std::endl;
    std::cout << " / ___| __ _ _ __ ___   ___    " << std::endl;
    std::cout << "| |  _ / _` | '_ ` _ \\ / _ \\   " << std::endl;
    std::cout << "| |_| | (_| | | | | | |  __/   " << std::endl;
    std::cout << " \\____|\\__,_|_| |_| |_|\\___|   " << std::endl;
    std::cout << "                               " << std::endl;
    std::cout << "I have selected a number between 1 and 100." << std::endl;
    std::cout << "Can you guess what it is?" << std::endl;
    std::cout << "========================================" << std::endl;
}

// Function to print a congratulations message 
void printCongratulationsMessage(int attempts)
{
    std::cout << "\n========================================" << std::endl;
    std::cout << "              CONGRATULATIONS!" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "                                                           " << std::endl;
    std::cout << "You guessed the correct number in " << attempts << " attempts!" << std::endl;
    if (attempts <= 5)
    {
        std::cout << "Excellent job! You're a natural!" << std::endl;
    }
    else if (attempts <= 10)
    {
        std::cout << "Great work! You have a good intuition." << std::endl;
    }
    else
    {
        std::cout << "Good effort! Keep practicing and you'll improve." << std::endl;
    }
    std::cout << "========================================" << std::endl;
}

int main()
{
    //  random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    // Print the welcome message
    printWelcomeMessage();

    // Loop until the user guesses the correct number
    do
    {
        std::cout << "\nEnter your guess: ";
        std::cin >> userGuess;

        // Handle invalid input
        while (std::cin.fail())
        {
            std::cin.clear();                                                   
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a number between 1 and 100: ";
            std::cin >> userGuess;
        }

        attempts++;

        if (userGuess > randomNumber)
        {
            std::cout << "Too high! Try again." << std::endl;
        }
        else if (userGuess < randomNumber)
        {
            std::cout << "Too low! Try again." << std::endl;
        }
        else
        {
            printCongratulationsMessage(attempts);
        }
    } while (userGuess != randomNumber);

    return 0;
}
