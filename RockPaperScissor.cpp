#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string getMove(int choice)
{
    if (choice == 1)
        return "Rock";
    if (choice == 2)
        return "Paper";
    return "Scissors";
}

int main()
{
    srand(time(nullptr)); // Seed random number generator
    int userChoice, computerChoice;
    int playerWins = 0, computerWins = 0;

    cout << "Rock, Paper, Scissors - Best of Three Mode!\n";

    while (playerWins < 2 && computerWins < 2)
    {
        cout << "\nChoose:\n1. Rock\n2. Paper\n3. Scissors\nYour choice: ";
        cin >> userChoice;

        if (userChoice < 1 || userChoice > 3)
        {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        computerChoice = rand() % 3 + 1;
        cout << "You chose: " << getMove(userChoice) << endl;
        cout << "Computer chose: " << getMove(computerChoice) << endl;

        if (userChoice == computerChoice)
        {
            cout << "It's a tie!\n";
        }
        else if ((userChoice == 1 && computerChoice == 3) ||
                 (userChoice == 2 && computerChoice == 1) ||
                 (userChoice == 3 && computerChoice == 2))
        {
            cout << "You win this round!\n";
            playerWins++;
        }
        else
        {
            cout << "Computer wins this round!\n";
            computerWins++;
        }

        cout << "Score: You " << playerWins << " - " << computerWins << " Computer\n";
    }

    if (playerWins == 2)
    {
        cout << "\nCongratulations! You won the game!\n";
    }
    else
    {
        cout << "\nComputer wins the game! Better luck next time.\n";
    }

    return 0;
}
