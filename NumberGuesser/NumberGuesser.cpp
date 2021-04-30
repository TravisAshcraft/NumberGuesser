// NumberGuesser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <cctype>
#include <stdlib.h>
#include <ctime>

using namespace std;

/*
Create a program called number guesser
There will be a secret number that  is set at the start of the program
without any user input.
the secret number should be picked from a certain range
The range of the number should be output to the player
The player should be prompted to enter their guess.
The prompt should show how many guesses the player has left.
The player will then enter their guess.
If the guess is to high then the game will output that guess was to
high.
If the guess was to low then the game will output that it was to low.
The player only has a certain number of guesses.
The number of the guesses should be based on the range of the secret
number.
Any wrong guess will decrement the number of guesses left.
The game ends by saying what the secret number should be prompted
if they would like to play again.
If yes then the secret number should change.
Any input errors by the player should have proper handling.
*/

void PlayGame();
bool WantToPlayAgain();

bool IsGameOver(int SecretNumber, int NumberOfGuesses, int guess);
int GetGuess(int NumberOfGuesses);
void DisplayResult(int SecretNumber, int NumberOfGuesses);

const int IGNORE_CHARS = 256;

int main()
{
    //we need a variable that stores the secret number
    //range: 0 - 100

    //we need a variable that stores the number of guesses
    //that the player has left

    //we need a variable that will store the player's guess

    //number of guesses will be the log base 2 of the upper range
    //eg. log2(100) - 6.64 -> 7

    //how do we change the secret number?

    /*
    
    do
    {
        Play the Game
    }while (Want to play again)

    Play the Game:

    1. set the secret number - set it a known value for now
    2. set the number of guesses -> ceil(log2(100))

    do
    {
        3. Prompt the user to make a guess (output the number of 
        guesses left)
        4. Get the guess from the player.
        5.check to see if the guess is equal to the secret number
            5a. if the guess is not equal to the secret number then
                5a1. decrement the number of guesses left
                5a2. check to see if the guess was higher or lower than
                the secret number
                    5a2a. if it was higher - print that the guess was 
                    to high
                    5a2b. if the guess was lower - then print that the 
                    guess was to low.

    }while(the game is not over)

    Display the result - tell the player if he got it or not

    Functions:

    Play the Game -> PlayGame()
    Wants to play again -> WantToPlayAgain()
    Get the guess from the player -> GetGuess()

    This is not over -> IsGameOver()

    Number of guesses left == 0 || player's guess == secret number 

    Display result -> DisplayResult()

    if(the player got it)
    {
        print that they got it and print the secret number
    }
    else
    {
        print that they didn't get it and print the secret number
    }

    */
    srand((unsigned int)time(NULL));

    do
    {
        PlayGame();
    } while (WantToPlayAgain());

    return 0;

}

void PlayGame()
{
    const int UPPER_BOUND = 100;
    int SecretNumber = rand() % UPPER_BOUND;
    int NumberOfGuesses = ceil(log2(UPPER_BOUND));
    int guess = 0;

    cout << "The range of the number is between 0 and 100" << endl;

    do
    {
        guess = GetGuess(NumberOfGuesses);
        if (guess != SecretNumber)
        {
            NumberOfGuesses--;

            if (guess > SecretNumber)
            {
                cout << "Your guess was to high!" << endl;
            }
            else
            {
                cout << "Your guess was to low!" << endl;
            }
        }

    } while (!IsGameOver(SecretNumber, NumberOfGuesses, guess));

    DisplayResult(SecretNumber, NumberOfGuesses);
}

bool WantToPlayAgain()
{
    char input;
    bool failure;
    do
    {
        failure = false;

        cout << "Would you like to play again? (y/n) ";
        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << "Input Error! Please try again." << endl;
            failure = true;
        }
        else
        {
            cin.ignore(IGNORE_CHARS, '\n');

            input = tolower(input);
        }
    } while (failure);

    return input == 'y';
}


bool IsGameOver(int SecretNumber, int NumberOfGuesses, int guess)
{
    return SecretNumber == guess || NumberOfGuesses <= 0;
}

int GetGuess(int NumberOfGuesses)
{
    

    int guess;
    bool failure;

    do
    {
        failure = false;

        cout << "Please enter your guess (number of guess left: " << NumberOfGuesses << "): ";
        cin >> guess;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << "Input error! Please try again. " << endl;
            failure = true;
        }

    } while (failure);

    return guess;
}

void DisplayResult( int SecretNumber, int NumberOfGuesses)
{
    if (NumberOfGuesses > 0)
    {
        cout << "You got it! It was: " << SecretNumber << endl;
    }
    else
    {
        cout << "You didnt get it! It was: " << SecretNumber << endl;
    }
}