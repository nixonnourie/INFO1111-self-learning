#include <iostream>
#include <cstdlib>
#include <ctime>

class CasinoGame {
private:
    int money;
    int numToGuess;
    int maxNumToGuess;

public:
    CasinoGame() {
        money = 100;
        std::srand(std::time(0)); // set new seed value
        numToGuess = std::rand() % 100 + 1;
        maxNumToGuess = 100;
    }

    void setMaxNumToGuess(int maxNum) {
        maxNumToGuess = maxNum;
        std::srand(std::time(0)); // set new seed value
        numToGuess = std::rand() % maxNumToGuess + 1;
    }

    void play() {
        std::cout << "You have $" << money << std::endl;
        std::cout << "Guess a number between 1 and " << maxNumToGuess << ": ";
        int guess;
        std::cin >> guess;

        while (guess < 1 || guess > maxNumToGuess) {
            std::cout << "Invalid guess. Please enter a number between 1 and " << maxNumToGuess << std::endl;
            std::cin >> guess;
        }

        if (guess == numToGuess) {
            int reward = maxNumToGuess*10;
            money += reward;
            std::cout << "You win $" << reward << "!" << std::endl;
            numToGuess = std::rand() % maxNumToGuess + 1; // generate new number to guess
        } else {
            money -= 20;
            std::cout << "Sorry, the number was " << numToGuess << ". You lose $20." << std::endl;
            if (money <= 0) {
                std::cout << "Game over. You ran out of money." << std::endl;
                return;
            }
        }
    }

    int getMoney() const {
        return money;
    }
};

int main() {
    CasinoGame game;

    std::cout << "Welcome to the casino game!" << std::endl;

    while (true) {
        std::cout << "You have $" << game.getMoney() << std::endl;
        std::cout << "Press 1 to play, 2 to set maximum number to guess, or 3 to quit: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            game.play();
        } else if (choice == 2) {
            int maxNum;
            std::cout << "Enter maximum number to guess: ";
            std::cin >> maxNum;
            game.setMaxNumToGuess(maxNum);
        } else if (choice == 3) {
            std::cout << "Thanks for playing!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
