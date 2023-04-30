#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Returns a random word from the given word list
string getRandomWord(string wordList[], int size) {
    srand(time(NULL));
    int randomIndex = rand() % size;
    return wordList[randomIndex];
}

// Prompts the user to choose a theme and returns a word from the corresponding word list
string getTheme() {
    string themes[] = {"Fruits", "Animals", "Countries", "Programming Languages"};

    cout << "Choose a theme (1-4): " << endl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << themes[i] << endl;
    }
    cout << ">";

    int themeChoice;
    cin >> themeChoice;

    // input validation
    while (cin.fail() || themeChoice < 1 || themeChoice > 4) {
        cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> themeChoice;
    }

    string wordList[8];
    int wordListSize = 0;

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

    return getRandomWord(wordList, wordListSize);
}

int getDifficulty() {

    const int easyMaxGuesses = 8;
    const int mediumMaxGuesses = 5;
    const int hardMaxGuesses = 3;
    const int insaneMaxGuesses = 1;

    string difficulty[] = {"Easy", "Medium", "Hard", "Insane"};

    cout << "Choose a difficulty (1-4): " << endl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << difficulty[i] << endl;
    }
    cout << ">";

    int difficultyChoice;
    cin >> difficultyChoice;

    // input validation
    while (cin.fail() || difficultyChoice < 1 || difficultyChoice > 4) {
        cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> difficultyChoice;
    }

    if (difficultyChoice == 1) {
        return easyMaxGuesses;
    }
    else if (difficultyChoice == 2) {
        return mediumMaxGuesses;
    }
    else if (difficultyChoice == 3) {
        return hardMaxGuesses;
    }
    else if (difficultyChoice == 4) {
        return insaneMaxGuesses;
    }

}

int main()
{

    cout << "Welcome to The Game!\n\n";

    string wordToGuess = getTheme();
    int wordLength = wordToGuess.length();

    int maxGuesses = getDifficulty();
    int remainingGuesses = maxGuesses;

    string lettersGuessed = "";
    string currentWordState = string(wordLength, '_');

    // Main game loop
    while (remainingGuesses > 0 && currentWordState != wordToGuess) {
        cout << "Word to guess: " << currentWordState << endl;
        cout << "Guesses remaining: " << remainingGuesses << endl;
        cout << "Guessed letters: " << lettersGuessed << endl;
        cout << "\nGuess a letter: ";

        string Guess;
        cin >> Guess;

        // Check if the input is a single letter
        if (Guess.length() != 1) {
            cout << "\n\nInvalid input. Please enter a single letter." << endl;
            continue;
        }

        // Check if the input is a valid letter
        if (!isalpha(Guess[0])) {
            cout << "\n\nInvalid input. Please enter a valid letter." << endl;
            continue;
        }

        // convert guess to lowercase
        char guess = tolower(Guess[0]);

        // check if the guess has already been made
        if (lettersGuessed.find(guess) != string::npos) {
            cout << "\n\nYou've already guessed that letter. Please try again." << endl;
            continue;
        }

        // add the guess to the set of guessed letters
        lettersGuessed += guess;

        // check if the guess is in the word
        if (wordToGuess.find(guess) != string::npos) {
            cout << "\n\nGood guess! That letter is in the word." << endl;
            for (int i = 0; i < wordLength; i++) {
                if (wordToGuess[i] == guess) {
                    currentWordState[i] = guess;
                }
            }
        }
        else {
            cout << "\n\nSorry, the letter is not in the word." << endl;
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
