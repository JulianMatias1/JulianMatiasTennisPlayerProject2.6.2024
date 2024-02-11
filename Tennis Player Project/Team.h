//Team.h

#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <vector>
#include "Player.h"

class Team {
public:
    // Constructors and rule of 3 methods
    Team();
    Team(const string& country);

    Team(const Team& other);
    Team& operator=(const Team& other);
    ~Team();

    void addPlayer(const Player& other);
    string getCountry() const;

    Player* getPlayers() const;
    void displayTeam(string targetCountry) const;
    void setCountry(const string& country);


    int getNumPlayers() const;
private:
    string country;
    Player* teamPlayers; // Dynamically allocated array of Player objects
    int numberOfPlayers;
};

#endif
