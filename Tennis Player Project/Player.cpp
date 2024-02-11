//Player.cpp

#include <iostream>
#include "Player.h"

using namespace std;

//Constructor with no arguments
Player::Player() {
	rank = 0;
	lastName = " ";
	firstName = " ";
	country = " ";
	points = 0;
}
//Constructor with arguments
Player::Player(int r_rank, string l_name, string f_name, string c_country, int p_points) {
	rank = r_rank;
	lastName = l_name;
	firstName = f_name;
	country = c_country;
	points = p_points;
}

//Getters return the value
int Player::getRank()const {
	return rank;
}

string Player::getLastName()const {
	return lastName;
}

string Player::getFirstName()const {
	return firstName;
}

string Player::getCountry()const {
	return country;
}
int Player::getPoints()const {
	return points;
}

//Setters set the private members to the variables thta can be accessed
void Player::setRank(int r_rank) {
	rank = r_rank;
}
void Player::setLastName(string l_name) {
	lastName = l_name;
}

void Player::setFirstName(string f_name) {
	firstName = f_name;
}

void Player::setCountry(string c_country) {
	country = c_country;
}

void Player::setPoints(int p_points) {
	points = p_points;
}

//passing the object type vector by reference allows for memory to be shared
//between the .cpp files so that the getter functons can be accessed
void Player::addPoints(int points) {
	this->points += points;
}
void Player::display()const {
	cout << "\nPlayer found:\n";
	cout << "Rank: " << rank << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Country: " << country << endl;
	cout << "Points: " << points << endl << endl;
}
bool Player::operator<(const Player& other)const {
	return this->getLastName() < other.getLastName();
}
bool Player::operator==(const Player& other) const {
	return this->getLastName() == other.getLastName();
}
Player& Player::operator=(const Player& other) {
	if (this != &other) {
		this->rank = other.getRank();
		this->lastName = other.getLastName();
		this->firstName = other.getFirstName();
		this->country = other.getCountry();
		this->points = other.getPoints();

	}
	return *this;
}
ostream& operator<<(ostream& out, const Player& player) {
	out << "Player found:\n";
	out << "Rank: " << player.getRank() << endl;
	out << "Last Name: " << player.getLastName() << endl;
	out << "First Name: " << player.getFirstName() << endl;
	out << "Country: " << player.getCountry() << endl;
	out << "Points: " << player.getPoints() << endl;
	return out;
}
istream& operator>>(istream& in, Player& player) {
	int Hrank;
	string HlastName;
	string HfirstName;
	string Hcountry;
	int Hpoints;
	in >> Hrank >> HlastName >> HfirstName >> Hcountry >> Hpoints;
	player.setRank(Hrank);
	player.setLastName(HlastName);
	player.setFirstName(HfirstName);
	player.setCountry(Hcountry);
	player.setPoints(Hpoints);
	return in;
}