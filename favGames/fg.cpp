// Favorite Games Program
// Shaon Bischoff June 20, 2024

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<string> favGames = {"The Legend Of Zelda: Tears Of The Kingdom", "Super Mario Sunshine"};
    vector<string>::iterator iter; 
    string input = "";
    cout << "Welcome ot my program! Let's make a list of your favorite games!\n";

    while(true) {
        cout << "What would you like to do?\n";
        cout << "Options:\n"
                        "Add\n"
                        "Edit\n"
                        "Delete\n"
                        "Show\n"
                        "Quit\n";
        getline(cin, input);
        if(input == "add") {
            cout << "What game would you like to add?\n";
            getline(cin, input);
            favGames.push_back(input);
            cout << "Added " << input << " to your list.\n";
        } else if(input == "edit") {
            cout << "What game would you like to edit?\n";
            getline(cin, input);
            iter = find(favGames.begin(), favGames.end(), input);
            if(iter != favGames.end()) {
                cout << "Found " << input << "!\n";
                cout << "What would you like to change it to?\n";
                getline(cin, input);
                *iter = input;
            } else {
                cout << "Sorry, but I couldn't find " << input << ".\n";
            }
        } else if(input == "delete") {
            cout << "What game would you like to delete from your list?\n";
            getline(cin, input);
            iter = find(favGames.begin(), favGames.end(), input);
            if(iter != favGames.end()) {
                cout << "Found " << input << " and removed it!\n";
                favGames.erase(iter);
            } else {
                cout << "Sorry, but I couldn't find " << input << ".\n";
            }
        } else if(input == "show") {
            sort(favGames.begin(), favGames.end());
            cout << "Here are your favorite games!\n";
            for(int i = 0; i < favGames.size(); i++) {
                cout << favGames[i].insert(0, to_string(i + 1) + " ") << "\n";
                favGames[i].erase(0, 2);
            }
        } else if(input == "quit") {
            cout << "Are you sure you want to quit?(yes/no)\n";
            getline(cin, input);
            if(input == "yes") {
                cout << "Thank you for using the program!\n";
                return 0;
            }
        } else {
            cout << "Sorry, I don't know what you meant by that.\n";
        }

        
    }
    



}