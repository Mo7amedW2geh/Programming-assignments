#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Returns a random word from the given word list
string getRandomWord(string wordList[], int size) {
    srand(time(NULL));
    int randomIndex = rand() % size;
    return wordList[randomIndex];
}

// Prompts the user to choose a theme and returns a word from the corresponding word list
string getTheme() {
    string themes[] = {"fruits", "animals", "countries", "programming languages" };

    cout << "Choose a theme: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << themes[i] << endl;
    }

    int themeChoice;
    cin >> themeChoice;

    string wordList[8];
    int wordListSize;

    if (themeChoice == 1) {
        string words[] = {"apple", "banana", "cherry", "kiwi", "lemon", "orange", "strawberry", "watermelon"};
        wordListSize = 8;
        for (int i = 0; i < wordListSize; i++) {
            wordList[i] = words[i];
        }
    }
    else if (themeChoice == 2) {
        string words[] = {"elephant", "giraffe", "kangaroo", "koala", "lion", "penguin", "tiger", "zebra"};
        wordListSize = 8;
        for (int i = 0; i < wordListSize; i++) {
            wordList[i] = words[i];
        }
    }
    else if (themeChoice == 3) {
        string words[] = {"canada", "china", "egypt", "france", "india", "japan", "russia", "spain"};
        wordListSize = 8;
        for (int i = 0; i < wordListSize; i++) {
            wordList[i] = words[i];
        }
    }
    else if (themeChoice == 4) {
        string words[] = {"python", "java", "csharp", "javascript", "ruby", "php", "scala", "kotlin"};
        wordListSize = 8;
        for (int i = 0; i < wordListSize; i++) {
            wordList[i] = words[i];
        }
    }
    else {
        cout << "Invalid choice. Please try again." << endl;
        return getTheme();
    }

    cout << "\n\nThe theme is \"" << themes[themeChoice - 1] << "\"\n\n";

    return getRandomWord(wordList, wordListSize);
}

int main() 
{

    cout << "Welcome to The Game!\n\n";

    string wordToGuess = getTheme();
    int wordLength = wordToGuess.length();
    int maxGuesses = 8;
    int remainingGuesses = maxGuesses;
    string lettersGuessed = "";
    string currentWordState = string(wordLength, '_');

    // Main game loop
    while (remainingGuesses > 0 && currentWordState != wordToGuess) {
        cout << "Word to guess: " << currentWordState << endl;
        cout << "Guesses remaining: " << remainingGuesses << endl;
        cout << "Guessed letters: " << lettersGuessed << endl;
        cout << "\nGuess a letter: ";

        char guess;
        cin >> guess;

        // Check if the input is a valid letter
        if (!isalpha(guess)) {
            cout << "\nInvalid input. Please enter a letter." << endl;
            continue;
        }

        // convert guess to lowercase
        guess = tolower(guess);

        // check if the guess has already been made
        if (lettersGuessed.find(guess) != string::npos) {
            cout << "\nYou've already guessed that letter. Please try again." << endl;
            continue;
        }

        // add the guess to the set of guessed letters
        lettersGuessed += guess;

        // check if the guess is in the word
        if (wordToGuess.find(guess) != string::npos) {
            cout << "\nGood guess! That letter is in the word." << endl;
            for (int i = 0; i < wordLength; i++) {
                if (wordToGuess[i] == guess) {
                    currentWordState[i] = guess;
                }
            }
        }
        else {
            cout << "\nSorry, the letter is not in the word." << endl;
            remainingGuesses--;
        }
    }

        // print the result of the game
        if (currentWordState == wordToGuess) {
            cout << "\nCongratulations! You guessed the word \"" << wordToGuess << "\"." << endl;
        }
        else {
            cout << "\nSorry, you ran out of guesses. The word was \"" << wordToGuess << "\"." << endl;
        }

        return 0;
    
}
