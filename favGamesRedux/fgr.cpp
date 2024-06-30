// Favorite Games Redux Program
// Shaon Bischoff June 26, 2024

#include "functions.h.cpp"

int main() {

    vector<string> favGames;
    vector<string>& favGamesRef = favGames;
    string input = "";
    cout << "Welcome to my program! Let's make a list of your favorite games!\n";

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
            Add(favGamesRef);
        } else if(input == "load") {
            Load(favGamesRef);
        } else if(input == "edit") {
            Edit(favGamesRef);
        } else if(input == "delete") {
            Remove(favGamesRef);
        } else if(input == "show") {
            Show(favGamesRef);
        } else if(input == "quit") {
            if(!Quit(favGamesRef)) {
                return 0;
            }
        } else {
            cout << "Sorry, I don't know what you meant by that.\n";
        }
    }
}