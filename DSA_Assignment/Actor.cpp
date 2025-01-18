#include "Actor.h"
#include <iostream>
#include <ctime>
using namespace std;

Actor::Actor(string name, int yearOfBirth, float rating) {
	this->name = name;
	this->yearOfBirth = yearOfBirth;
	this->rating = rating;
}

Actor::~Actor() {
}

string Actor::getName() const {
	return name;
}

int Actor::getYearOfBirth() const {
	return yearOfBirth;
}

float Actor::getRating() const {
	return rating;
}

void Actor::addMovie(Movie* movie) {
	listOfMovies.push_back(movie);
}

void Actor::displayMovies() const {
	cout << "Movies acted in by " << name << ":" << endl;
	for (Movie* movie : listOfMovies) {
		cout << movie->getTitle() << endl;
	}
}

int Actor::getAge() const {
	time_t timeUnix = time(0);
	tm* now = localtime(&timeUnix);
	int currentYear = now->tm_year + 1900;

	return currentYear - yearOfBirth;
}