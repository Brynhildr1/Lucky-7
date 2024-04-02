#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <random>
#include <windows.h> // for windows

using namespace std;

int main()
{

    /*

    User inputs keyword for a set of ranges of numbers from 1-6 / 7 / 8-13
    1 - 6: is classified as 'lower'
    7 is classified as '7'
    8 - 13: is classified as 'higher'
    Both lower and higher have a 46.154% chance of winning, and 7 has a 7.692% chance of winning.

    The user will pick one of these 3 ranges.
    The program will then generate a random value between 1 - 13.
    If the user value of higher/lower is correct they will get a 2x payout,
    e.g. user bets 100 on lower. Lower wins. User wins 200.
    If the user bets on 7, and wins they will receive 4x payout.
    e.g. user bets 100 on 7. 7 wins. user wins 400.
    (Betting will be added to a seperate version of this program, this is solely to test making the game)

    Features:
    validate user input is either 'lower/7/higher'.
    randomly generate a value from 1 - 13.
    correctly identify that 1 - 6 = lower, 7 = 7, and 8 - 13 = higher, for confirming user win or loss.
    option to reply or not.

    */

    string userChoice;

    bool replay = true;
    while (replay == true)
    {
        cout << "Welcome to Lucky 7,\nPlease enter which category you would like to bet for ('lower' 1 - 6 / '7' / 'higher' 8 - 13): ";

        // validate userChoice as 'lower' / '7' / 'higher'
        while (true)
        {
            cin >> userChoice;
            if (userChoice == "lower" || userChoice == "LOWER" || userChoice == "7" || userChoice == "higher" || userChoice == "HIGHER")
            {
                break;
            }
            cout << "Invalid input, Please enter 'lower', '7' or 'higher': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (userChoice == "lower" || userChoice == "LOWER")
        {
            cout << "\n'Lower' has been locked in. Good Luck!" << endl;
        }
        else if (userChoice == "higher" || userChoice == "HIGHER")
        {
            cout << "\n'Higher' has been locked in. Good Luck!" << endl;
        }
        else
        {
            cout << "\nLucky 7 has been locked in. Good Luck!" << endl;
        }

        // begin the roll

        // Create a random number generator engine
        random_device rd;
        mt19937 rng(rd());

        // Create a uniform distribution for integers between 1 and 13
        uniform_int_distribution<int> dist(1, 13);

        // Generate a random number between 1 and 13
        int randNum = dist(rng);
        cout << "\nAnd the number is... ";

        sleep(1);

        cout << randNum;

        // check if the number rolled matches the userChoice, and respond accordingly
        if ((userChoice == "lower" || userChoice == "LOWER") && randNum < 7 || userChoice == "7" && randNum == 7 || (userChoice == "higher" || userChoice == "HIGHER") && randNum > 7)
        {
            cout << "\nCongratulations! you have won!";
        }
        else
        {
            cout << "\nYou lose, better luck next time.";
        }

        // replay buffer
        char replayKey;
        cout << "\n\nDo you want to play again (Y/N): ";

        while (true) // ensure user input is either Yy, Nn.
        {
            cin >> replayKey;
            if (replayKey == 'Y' || replayKey == 'y' || replayKey == 'N' || replayKey == 'n')
            {
                break;
            }
            cout << "\nInvalid input. Please enter 'Y' or 'N': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (replayKey == 'N' || replayKey == 'n')
        {
            break;
        }
        else
        {
            cout << "\n";
            continue;
        }

        int x;
        cin >> x;

        return 0;
    }
}