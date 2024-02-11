// main.cpp


#include <iostream>
#include <fstream>
#include <vector>
#include "Player.h"
#include "Team.h"

using namespace std;

static void sortPlayersByCountry(vector<Player>& players) {
    size_t n = players.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (players[j].getCountry() > players[j + 1].getCountry()) {
                swap(players[j], players[j + 1]);
            }
        }
    }
}

/**/
int main() {
    
    vector<Team> teams;
    fstream infile;
    infile.open("WomensSinglesSorted.txt");

    int rank = 0, points = 0;
    string lastNames, firstNames, countries;
    vector<Player> playerInfo;


    if (!infile.is_open()) {
        cout << "File not found";
        exit(1);

    }
    while (infile >> rank >> lastNames >> firstNames >> countries >> points) {
        Player player(rank, lastNames, firstNames, countries, points);
        playerInfo.push_back(player);
    }
    infile.close();

    sortPlayersByCountry(playerInfo);

    bool countryFound = false;
    int j = 0;
    for (int i = 0; i < playerInfo.size(); i++) {
        if (teams.size() != 0) {
            if (playerInfo.at(i).getCountry() == teams.at(j).getCountry()) {
                teams.at(j).addPlayer(playerInfo.at(i));
                countryFound = true;
            }
        }
        if (!countryFound) {
            if (teams.size() != 0) {
                j++;
            }
            Team* tempTeam = new Team;
            tempTeam->addPlayer(playerInfo.at(i));
            tempTeam->setCountry(playerInfo.at(i).getCountry());
            teams.push_back(*tempTeam);
            delete tempTeam;

        }
        countryFound = false;
    }
    



    //menu
    int userChoice;
    cout << "Womens Singles Sorted (Be sure to use all caps!)\n\n";
    cout << "1. Display a Team\n";
    cout << "2. Add points to a player\n";
    cout << "0. Exit\n\n";

    cout << "Enter your choice : ";
    cin >> userChoice;
    while (userChoice != 0) {
        switch (userChoice) {
        case 1: {
            string targetCountry;
            cout << "Enter the country to display its team: ";
            cin >> targetCountry;

            // Find and display the team for the entered country
            bool countryFound = false;
            for (const auto& team : teams) {
                if (team.getCountry() == targetCountry) {
                    team.displayTeam(targetCountry);
                    countryFound = true;
                    break;
                }
            }

            if (!countryFound)
                cout << "Team not found for " << targetCountry << endl;

            break;
        }
        case 2: {
            string searchFirstName, searchLastName, searchCountry;
            cout << "Enter the first name of the player: ";
            cin >> searchFirstName;
            cout << "Enter the last name of the player: ";
            cin >> searchLastName;
            cout << "Enter the country of the player: ";
            cin >> searchCountry;

            bool playerFound = false;
            int pointsToAdd;

            for (int i = 0; i < teams.size(); i++) {

                for (int j = 0; j < teams.at(i).getNumPlayers(); j++) {
                    if (((teams.at(i).getPlayers())[j]).getFirstName() == searchFirstName &&
                        (teams.at(i).getPlayers())[j].getLastName() == searchLastName &&
                        teams.at(i).getPlayers()[j].getCountry() == searchCountry) {
                        playerFound = true;
                        int previousPoints = teams.at(i).getPlayers()[j].getPoints();
                        cout << "Player's previous points: " << previousPoints << endl;

                        cout << "Enter the points to add: ";
                        cin >> pointsToAdd;
                        (teams.at(i).getPlayers()[j]).addPoints(pointsToAdd);

                        int newPoints = teams.at(i).getPlayers()[j].getPoints();
                        cout << "Points added successfully!" << endl;
                        cout << "Player's new points: " << newPoints << endl;
                        break;
                    }
                }
                if (playerFound) break;
            }

            if (!playerFound) {
                cout << "Player not found in any team." << endl;
            }

            break;
        }

        

        }
        cout << "\n\nWomens Singles Sorted(Be sure to use all caps!)\n\n";
        cout << "1. Display a Team\n";
        cout << "2. Add points to a player\n";
        cout << "0. Exit\n\n";

        cout << "Enter your choice : ";
        cin >> userChoice;
    }
    return 0;
}