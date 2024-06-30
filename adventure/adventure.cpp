//Shaon Bischoff's first text adventure!
//June 6th, 2024

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;



int main() {
    srand(time(NULL));          
    string userName = "";
    cout << "\tWelcome to a wonderful new world of Adventure!\n";
    cout << "What is your name, adventurer?\n";
    cin >> userName;
    cout << "Hello, " << userName << "! Let's go on an adventure!\n";
    cout << "On your quest you'll encounter lots of enemies that you'll have to fight.\n";
    cout << "You'll have to attack to lower the enemies health to win and block to preserve your own health.\n";
    cout << "If you win a fight in 3 turns, you'll earn gold!\n";
    cout << "You can choose to give up after each fight, but try to get as much gold before you give up or run out of health!\n";
    cout << "Are you ready to begin, " << userName << "?\n";
    char answerYN = 'y';
    cin >> answerYN;

   if (answerYN == 'y' || answerYN == 'yes' || answerYN == 'yep' || answerYN == 'yeah' || answerYN == 'yea' || answerYN == 'ya') {
        cout << "You gather your Sword, Shield, and all you Courage!\n";
        int gold = 0;
        int userHealth = 10;

        while (userHealth > 0) {
            int enemyHealth = rand() % 10 + 1;
            int turnCount = 1;
            string enemyName = "";
            string actionCommand = "";

            if(enemyHealth <= 5) {
                enemyName = "slime";
            } else if(enemyHealth <= 8 && enemyHealth > 5) {
                enemyName = "bandit";
            } else if(enemyHealth > 8) {
                enemyName = "dragon";
            }
            
            cout << "You encounter a " << enemyName << " with " << enemyHealth << " health!\n";

            while (userHealth > 0 && turnCount < 4 ) {
                
                cout << "Turn " << turnCount << ".\n";
                cout << "You have " << userHealth << " health.\n";
                if(userHealth < 4) {
                    cout << "You should probably go see a doctor.\n";
                }
                cout << "Will you attack or defend?\n";
                cin >> actionCommand;
                

                if(actionCommand == "attack") {
                    int userAttack = rand() % 4 + 1;
                    cout << "You deal " << userAttack << " damage!\n";
                    enemyHealth -= userAttack; 
                
                    if(enemyHealth > 0) {
                        int enemyAttack = 0;

                        if(enemyName == "slime") {
                            int enemyAttack = rand() % 2 + 1;
                            cout << "The enemy deals " << enemyAttack << " damage!\n";
                            userHealth -= enemyAttack;
                        } else if(enemyName == "bandit") {
                            int enemyAttack = rand() % 3 + 1;
                            cout << "The enemy deals " << enemyAttack << " damage!\n";
                            userHealth -= enemyAttack;
                        } else if(enemyName == "dragon") {
                            int enemyAttack = rand() % 4 + 1;
                            cout << "The enemy deals " << enemyAttack << " damage!\n";
                            userHealth -= enemyAttack;
                        }

                        cout << "The " << enemyName << " has " << enemyHealth << " health left.\n";

                    } else {
                        cout << "You defeated the enemy " << enemyName << "!\n";
                        int goldGet = 0;

                        if(enemyName == "slime") {
                            int goldGet = rand() % 60 + 25;
                            cout << "The enemy dropped " << goldGet << " gold!\n";
                            gold += goldGet;
                        } else if(enemyName == "bandit") {
                            int goldGet = rand() % 100 + 50;
                            cout << "The enemy dropped " << goldGet << " gold!\n";
                            gold += goldGet;
                        } else if(enemyName == "dragon") {
                            int goldGet = rand() % 250 + 150;
                            cout << "The enemy dropped " << goldGet << " gold!\n";
                            gold += goldGet;
                        }

                        cout << "You now have " << gold << " gold.\n";
                        cout << "Would you like to continue adventuring?\n";
                        cin >> answerYN;

                        if (answerYN == 'y' || answerYN == 'yes' || answerYN == 'yep') {
                            cout << "You gather your Sword, Shield, and all you Courage!\n";
                            break;
                        }else if(answerYN == 'no' || answerYN == 'n' || answerYN == 'nope') {
                            cout << "You take home a well earned " << gold << " gold. Good Job and Thanks For Playing!\n";
                            return 0;
                        } else {
                            cout << "Not sure what you meant by that, let's try again some other time.\n";
                            return 0;
                        }
                    }
                } else if(actionCommand == "defend") {
                    int userDefend = rand() % 4 + 1;
                    int enemyAttack = 0;

                    if(enemyName == "slime") {
                        int enemyAttack = rand() % 2 + 1;

                        if(enemyAttack > userDefend) {
                        cout << "You couldn't block the enemy " << enemyName << "'s attack and took " << enemyAttack << " damage.\n";
                            userHealth -= enemyAttack;
                        } else {
                            cout << "You completely blocked the enemy " << enemyName << "'s attack, taking 0 damage!\n";
                        }
                            
                        } else if(enemyName == "bandit") {
                            int enemyAttack = rand() % 3 + 1;

                            if(enemyAttack > userDefend) {
                                cout << "You couldn't block the enemy " << enemyName << "'s attack and took " << enemyAttack << " damage.\n";
                                userHealth -= enemyAttack;
                            } else {
                                cout << "You completely blocked the enemy " << enemyName << "'s attack, taking 0 damage!\n";
                            }
                            
                        } else if(enemyName == "dragon") {
                            int enemyAttack = rand() % 4 + 1;
                            if(enemyAttack > userDefend) {
                                cout << "You couldn't block the enemy " << enemyName << "'s attack and took " << enemyAttack << " damage.\n";
                                userHealth -= enemyAttack;
                            } else {
                                cout << "You completely blocked the enemy " << enemyName << "'s attack, taking 0 damage!\n";
                            }  
                        }
                    }
                turnCount += 1;
                if(turnCount > 3) {
                    cout << "Oh no, the enemy got away! Better luck next time.\n";
                }
            }
        } 
        cout << "You have been defeated.\n";
        cout << "You drop your " << gold << " gold.\n";
        cout << "Better luck next time!\n";


    } else if(answerYN == 'no' || answerYN == 'n' || answerYN == 'nope') {
            cout << "I guess you're not quite ready yet. Let's go adventuring again some other time.\n";
            return 0;
    } else {
            cout << "Not sure what you meant by that, let's try again some other time.\n";
            return 0;
    }
}

// Personal high-score: 526 gold