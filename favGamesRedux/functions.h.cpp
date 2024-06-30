#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void Load(vector<string>& listRef) {
    string line;
    ifstream readFile("favGames.txt");
    if(readFile.is_open()) {
        while(getline(readFile, line)) {
            listRef.push_back(line);
        }
        cout << "Loaded favGames.txt\n";
    } else {
        cout << "Cannot load that file.\n";
    }
}

void Add(vector<string>& listRef) {
    string input = "";
    cout << "What game would you like to add?\n";
    getline(cin, input);
    listRef.push_back(input);
    cout << "Added " << input << " to your list.\n";
}

void Edit(vector<string>& listRef) {
    string input = "";
    vector<string>::iterator iter; 
    cout << "What game would you like to edit?\n";
    getline(cin, input);
    iter = find(listRef.begin(), listRef.end(), input);
    if(iter != listRef.end()) {
        cout << "Found " << input << "!\n";
        cout << "What would you like to change it to?\n";
        getline(cin, input);
        *iter = input;
    } else {
        cout << "Sorry, but I couldn't find " << input << ".\n";
    }
}

void Remove(vector<string>& listRef) {
    string input = "";
    vector<string>::iterator iter; 
    cout << "What game would you like to delete from your list?\n";
    getline(cin, input);
    iter = find(listRef.begin(), listRef.end(), input);
    if(iter != listRef.end()) {
        cout << "Found " << input << " and removed it!\n";
        listRef.erase(iter);
    } else {
        cout << "Sorry, but I couldn't find " << input << ".\n";
    }
}

void Show(vector<string>& listRef) {
    sort(listRef.begin(), listRef.end());
    cout << "Here are your favorite games!\n";
    for(int i = 0; i < listRef.size(); i++) {
        cout << (i + 1) << " " << listRef[i] << "\n";
    }
}

int Quit(vector<string>& listRef) {
    string input = "";
    cout << "Are you sure you want to quit?(yes/no)\n";
    getline(cin, input);
    if(input == "yes") {
        cout << "Would you like to save your changes? (yes/no)\n";
        getline(cin, input);
            if(input == "yes") {
                ofstream file;
                file.open("favGames.txt");
                file << "My Favorite Games:\n";
                for(int i = 0; i < listRef.size(); i++) {
                    file << listRef[i] << "\n";
                }
                file.close();
            }

        cout << "Thank you for using the program!\n";
        return 0;
    }
}