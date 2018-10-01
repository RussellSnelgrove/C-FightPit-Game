#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
using namespace std;

int createFighter() {
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
    int playerHealth = 10;
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
    cout << "How much health do you want to start with? ";
    cin >> playerHealth;

    cout << "Get ready to fight for your life, " << playerName << "!" << endl;

    // main game loop
    while (playerAlive && fightersKilled < fighterCount) {
        // create a random fighter
        int fighterSkill = createFighter();

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
        if (playerHealth < fighterSkill) {
            cout << "Your opponment has more Health than you do!" << endl;
            if (rand() % 5 < 2){
                cout << "You barely beat your opponment!" << endl;
                playerHealth = playerHealth -5;
            }else{
                playerAlive = false;
                cout << "You have been defeated." << endl;
            }

        }

        // player Beat the fighter
        else {
            if (playerHealth - fighterSkill > 15) {
                cout << "Your opponment did not stand a chance!" << endl;
                playerScore = playerScore + 3;
                playerHealth = playerHealth -1;
            }

            else if (playerHealth - fighterSkill > 10) {
                cout << "Your opponment put up a decent fight!" << endl;
                playerScore = playerScore + 2;
                playerHealth = playerHealth -2;
            }

            else if (playerHealth - fighterSkill > 7) {
                cout << "You beat your opponment!" << endl;
                playerScore = playerScore + 1;
                playerHealth = playerHealth -3;
            }

            else {
                cout << "You defeated your opponment, but suffered injuries." << endl;
                playerHealth = playerHealth -4;
            }

            fightersKilled++;

            if (rand() % 10 > 4){
                //cout << "You have found a Health Potion" << endl;
                playerHealth++;
            }
        }

        cout << endl;
        sleep(1);
    }

    // end game
    if (fightersKilled == fighterCount) {
        // victory
        cout << "You are the campion!" << endl;
    }
    else {
        // lost
        cout << "You have fallen in Combat" << endl;
    }

    cout << "Fighters Defeated: " << fightersKilled << endl;
    cout << "Final score: " << playerScore << endl << endl;
    cout << "Well Done " << playerName ;
    sleep(10);

}
