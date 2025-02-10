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
	if (listOfMovies.isEmpty() || listOfMovies.get(0)->getTitle() > movie->getTitle()) {
		listOfMovies.add(0, movie);
	}
	else {
		for (int i = 0; i < listOfMovies.getLength(); ++i) {
			if (listOfMovies.get(i)->getTitle() > movie->getTitle()) {
				listOfMovies.add(i, movie);
				return;
			}
		}
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

LinkedList<Movie*>& Actor::getMovies() {
    return listOfMovies;
}
