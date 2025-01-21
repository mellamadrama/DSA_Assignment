#include "Actor.h"
#include <iostream>
#include <ctime>
using namespace std;

Actor::Actor(string name, int yearOfBirth, float actorRating) {
	this->name = name;
	this->yearOfBirth = yearOfBirth;
	this->actorRating = actorRating;
}

Actor::~Actor() {
}

string Actor::getName() {
	return name;
}

int Actor::getYearOfBirth() {
	return yearOfBirth;
}

float Actor::getActorRating() {
	return actorRating;
}

void Actor::addMovie(Movie* movie) {
	listOfMovies.add(movie);
	movie->addActor(this);
}

void Actor::displayMovies() {
	cout << "Movies acted in by " << name << ":" << endl;
	if (listOfMovies.isEmpty()) {
		cout << "No movies for this actor." << endl;
		return;
	}
	for (int i = 0; i < listOfMovies.getLength(); ++i) {
		cout << listOfMovies.get(i)->getTitle() << endl;
	}
}

int Actor::getAge() {
	time_t timeUnix = time(0);
	tm now;
	localtime_s(&now, &timeUnix);
	int currentYear = now.tm_year + 1900;

	return currentYear - yearOfBirth;
}

// Update the actor's details
// pre: newName is a valid string, newYearOfBirth is a positive integer
// post: updates the name and year of birth of the actor
void Actor::updateActorDetails(string& newName, int newYearOfBirth, float newActorRating) {
	if (newName.empty() || newYearOfBirth <= 0 || newActorRating < 0.0 || newActorRating > 5.0) {
		cout << "Invalid details provided. Update failed." << endl;
		return;
	}

	// Update attributes
	name = newName;
	yearOfBirth = newYearOfBirth;
	actorRating = newActorRating;

	// Confirmation message
	cout << "Actor details updated: Name = " << name << ", Year of Birth = " << yearOfBirth << ", Rating = " << actorRating << endl;
}

// Get the list of movies the actor has acted in
// pre : The Actor object must be properly initialized.
// post: Returns a constant reference to the vector containing pointers to the movies the actor is associated with.
LinkedList<Movie*>& Actor::getMovies() {
    return listOfMovies;
}
