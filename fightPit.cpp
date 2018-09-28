#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
using namespace std;

int createEnemy() {
    if (rand() % 20 < 10)
        return 11;

    else
        return rand() % 10 + 1;
}

int main() {
    srand(time(NULL));
    char enter;

    // game stats
    int playerAlive = true;
    int playerSkill = 10;
    int playerScore = 1;
    string playerName = "";
    int fighterCount = 0;
    int fightersKilled = 0;

    // title
    cout << "Welcome to the fight pit." << endl << "Press [ENTER] to start.";
    cin.get();

    // player name
    cout << "Please enter your name: ";
    cin >> playerName;

    // ask how many fighters
    cout << "How many fighters do you wish to fight? ";
    cin >> fighterCount;

    // ask how many fighters
    cout << "What skill level do you want (10-100)? ";
    cin >> playerSkill;

    cout << "Get ready to fight for your life, " << playerName << "!" << endl;

    // main game loop
    while (playerAlive && fightersKilled < fighterCount) {
        // create a random fighter
        int fighterSkill = createEnemy();

        // battle sequence
        if (fighterSkill > 10) {
            cout << endl << "Here comes a tough Fighter!" << endl;
        }
        else {
            cout << endl << "Here comes a Fighter " << fightersKilled + 1 << endl;
        }

        cout << "Fighting..." << endl;
        sleep(2);

        // fighter beat the player
        if (playerSkill < fighterSkill) {
            playerAlive = false;
            cout << "You have died." << endl;
        }

        // player Beat the fighter
        else {
            if (playerSkill - fighterSkill > 15) {
                cout << "Your opponment did not stand a chance!" << endl;
                playerScore = playerScore + 3;
                playerSkill = playerSkill -1;
            }

            else if (playerSkill - fighterSkill > 10) {
                cout << "Your opponment put up a decent fight!" << endl;
                playerScore = playerScore + 2;
                playerSkill = playerSkill -2;
            }

            else if (playerSkill - fighterSkill > 7) {
                cout << "You beat your opponment!" << endl;
                playerScore = playerScore + 1;
                playerSkill = playerSkill -3;
            }

            else {
                cout << "You defeated your opponment, but suffered injuries." << endl;
                playerSkill = playerSkill -4;
            }

            fightersKilled++;
        }

        cout << endl;
        sleep(1);
    }

    // end game
    if (fightersKilled == fighterCount) {
        // victory
        cout << "You have survived the onslaught!" << endl;
    }
    else {
        // lost
        cout << "You did not survive the fighter war." << endl;
    }

    cout << "Fighters Defeated: " << fightersKilled << endl;
    cout << "Final score: " << playerScore << endl << endl;
    cout << "Well Done " << playerName ;
    sleep(10);

}
