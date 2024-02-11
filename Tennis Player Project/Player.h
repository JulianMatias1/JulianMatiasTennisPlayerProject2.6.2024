//Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
using namespace std;

//Class is written here with only the declarations of the functions, constructors, and private data

class Player {
public:
	Player();
	Player(int, string, string, string, int);

	//getter functions have a const so that there is no
	//way they can alter the data that is passed through them
	int getRank()const;
	string getLastName()const;
	string getFirstName()const;
	string getCountry()const;
	int getPoints()const;

	//setter function accesss and set the value of private data members
	void setRank(int);
	void setLastName(string);
	void setFirstName(string);
	void setCountry(string);
	void setPoints(int);
	bool operator<(const Player& other)const;
	bool operator==(const Player& other) const;
	void display()const;
	void addPoints(int points);

	Player& operator=(const Player& other);
	friend ostream& operator <<(ostream& out, const Player& player);
	//passing the object type vector by reference allows for memory to be shared
	//between the .cpp files so that the getter functons can be accessed
	friend istream& operator >> (istream& in, Player& player);

private:
	int rank;
	string lastName;
	string firstName;
	string country;
	int points;
};

#endif