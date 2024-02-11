// Team.cpp

#include <iostream>
#include <vector>
#include "Team.h"
#include "Player.h"
using namespace std;
#include "Team.h"

//Default constructor
Team::Team() {
    country = "";
    teamPlayers = nullptr;
    numberOfPlayers = 0;
}

//Constructor w/ parameters
Team::Team(const string& country) {
    this->country = country;
    teamPlayers = nullptr;
    numberOfPlayers = 0;
}

//Copy constructor
Team::Team(const Team& other) {
    country = other.country;
    numberOfPlayers = other.numberOfPlayers;
    teamPlayers = new Player[other.numberOfPlayers];
    for (int i = 0; i < other.numberOfPlayers; ++i) {
        teamPlayers[i] = other.teamPlayers[i]; 
    }
}

// Assignment operator
Team& Team::operator=(const Team& other) {
    if (this != &other) {
        country = other.country;
        numberOfPlayers = other.numberOfPlayers;

        Player* newTeamPlayers = new Player[other.numberOfPlayers];
        for (int i = 0; i < other.numberOfPlayers; ++i) {
            newTeamPlayers[i] = other.teamPlayers[i]; // This assumes Player has proper copy constructor or deep copy logic.
        }

        delete[] teamPlayers;
        teamPlayers = newTeamPlayers;
    }
    return *this;
}

// Destructor
Team::~Team() {
    delete[] teamPlayers; // Deallocate memory when the object is destroyed
}


void Team::addPlayer(const Player& player) {
    Player* newPlayers = new Player[numberOfPlayers + 1];
    for (int i = 0; i < numberOfPlayers; ++i) {
        newPlayers[i] = teamPlayers[i]; // Again, assuming proper Player deep copy logic.
    }
    newPlayers[numberOfPlayers] = player;
    numberOfPlayers++;

    delete[] teamPlayers; // Deallocate the old array after copying
    teamPlayers = newPlayers;
}



Player* Team::getPlayers() const {
    return teamPlayers;
}


string Team::getCountry() const {
    return country;
}
void Team::displayTeam(string targetCountry) const {
    bool found = false;
    for (int i = 0; i < numberOfPlayers; i++) {
        if (teamPlayers[i].getCountry() == targetCountry) {
            teamPlayers[i].display(); // Display player information
            found = true;
        }
    }
    if (!found) {
        cout << "No match" << endl; // If no player found from the target country
    }
}
int Team::getNumPlayers()const {
    return numberOfPlayers;
}


void Team::setCountry(const string& c) {
    this->country = c;
}