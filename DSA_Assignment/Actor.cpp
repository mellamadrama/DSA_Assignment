#include "Actor.h"
#include <iostream>
#include <ctime>
#include "Global.h"
using namespace std;

Actor::Actor(int id, string name, int yearOfBirth, float avgActorRating)
	: id(id), name(name), yearOfBirth(yearOfBirth), avgActorRating(avgActorRating) {
}

Actor::~Actor() {
}

string Actor::getName() {
	return name;
}

int Actor::getId() {
	return id;
}

int Actor::getYearOfBirth() {
	return yearOfBirth;
}

void Actor::addRating(float rating) {
	listOfRatings.add(rating);
	float sum = 0.0f;
	for (int i = 0; i < listOfRatings.getLength(); ++i) {
		sum += listOfRatings.get(i);
	}
	avgActorRating = sum / listOfRatings.getLength();
}

float Actor::getActorRating() {
	return avgActorRating;
}

bool Actor::listReports() {
	cout << "Reports for actor " << name << ":" << endl;
	if (listOfReports.isEmpty()) {
		cout << "No reports for this actor." << endl;
		return false;
	}
	for (int i = 0; i < listOfReports.getLength(); ++i) {
		cout << i + 1 << ". " << listOfReports.get(i)->getReportDescription() << endl;
	}
	return true;
}

LinkedList<Report*>& Actor::getReportList() {
	return listOfReports;
}

void Actor::displayReport(Report* report) {
	report->displayReport();
}

void Actor::addReport(Report* report) {
	listOfReports.add(report);
}

void Actor::addMovie(Movie* movie) {
	if (!listOfMovies.contains(movie)) {
		//cout << "Adding " << name << " to " << movie->getTitle() << endl;
		listOfMovies.add(movie);
		cout << "Added " << name << " to " << movie->getTitle() << endl;
		cout << listOfMovies.getLength() << endl;
		movie->addActor(this);
		return;
	}
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
	return 2025 - yearOfBirth;
}

// Update the actor's details
// pre: newName is a valid string, newYearOfBirth is a positive integer
// post: updates the name and year of birth of the actor
void Actor::updateActorDetails(string& newName, int newYearOfBirth) {
	if (newName.empty() || newYearOfBirth <= 0) {
		cout << "Invalid details provided. Update failed." << endl;
		return;
	}

	// Update attributes
	name = newName;
	yearOfBirth = newYearOfBirth;

	// Confirmation message
	cout << "Actor details updated: Name = " << name << ", Year of Birth = " << yearOfBirth << endl;
}

// Get the list of movies the actor has acted in
// pre : The Actor object must be properly initialized.
// post: Returns a constant reference to the vector containing pointers to the movies the actor is associated with.
LinkedList<Movie*>& Actor::getMovies() {
    return listOfMovies;
}
