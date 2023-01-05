#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const int MAX_INCORRECT_GUESSES = 6; // maximum number of incorrect guesses allowed

int main()
{
  // Read in the secret word
  std::cout << "Enter the secret word: ";
  std::string secretWord;
  std::cin >> secretWord;

  // Initialize the number of incorrect guesses to 0
  int numIncorrectGuesses = 0;

  // Create a vector to store the correct guesses
  std::vector<char> correctGuesses;

  // Create a vector to store the incorrect guesses
  std::vector<char> incorrectGuesses;

  // Keep looping until the player has won or lost
  while (numIncorrectGuesses < MAX_INCORRECT_GUESSES)
  {
    // Print the current state of the game
    std::cout << "Incorrect Guesses: ";
    for (char ch : incorrectGuesses)
    {
      std::cout << ch << " ";
    }
    std::cout << std::endl;

    std::cout << "Word: ";
    for (char ch : secretWord)
    {
      if (std::find(correctGuesses.begin(), correctGuesses.end(), ch) != correctGuesses.end())
      {
        std::cout << ch << " "; // print the letter if it has been guessed
      }
      else
      {
        std::cout << "_ "; // print a blank if the letter has not been guessed
      }
    }
    std::cout << std::endl;

    // Prompt the player to enter a guess
    std::cout << "Enter a guess: ";
    char guess;
    std::cin >> guess;

    // Check if the guess is correct
    if (std::find(secretWord.begin(), secretWord.end(), guess) != secretWord.end())
    {
      // Add the guess to the correct guesses vector
      correctGuesses.push_back(guess);

      // Check if the player has won
      bool won = true;
      for (char ch : secretWord)
      {
        if (std::find(correctGuesses.begin(), correctGuesses.end(), ch) == correctGuesses.end())
        {
          won = false;
          break;
        }
      }

      if (won)
      {
        std::cout << "Congratulations, you won!" << std::endl;
        break;
      }
    }
    else
    {
      // Add the guess to the incorrect guesses vector
      incorrectGuesses.push_back(guess);

      // Increment the number of incorrect guesses
      numIncorrectGuesses++;
    }
  }

  // Check if the player lost the game
  if (numIncorrectGuesses == MAX_INCORRECT_GUESSES)
  {
    std::cout << "Sorry, you lost. The secret word was: " << secretWord << std::endl;
  }

  return 0;
