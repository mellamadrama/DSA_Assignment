#pragma once
#include <string>
#include "Admin.h"
using namespace std;

// Constructor
Admin::Admin(string name, int adminId) {
    this->name = name;
    this->adminId = adminId;
}

// Get the name of the admin
// pre: none
// post: returns the name of the admin
string Admin::getName() {
    return name;
}

// Get the admin ID
// pre: none
// post: returns the admin ID
int Admin::getAdminId() {
    return adminId;
}

// Add a new actor to the list
// pre: actorName is a valid string, yearOfBirth is a positive integer
// post: new actor is added to the vector; if actor already exists, no changes are made
bool Admin::addActor(int id, LinkedList<Actor*>& actors, string& actorName, int yearOfBirth) {
    for (int i = 0; i < actors.getLength(); ++i) {
        Actor* actor = actors.get(i);
    }

    Actor* newActor = new Actor(id, actorName, yearOfBirth, 0.0f);
    actors.add(newActor);
    cout << "Actor " << actorName << " added successfully." << endl;
    return true;
}

bool Admin::displayActorReports(Actor* actor) {
	if (!actor) {
		cout << "Actor not found." << endl;
		return false;
	}

	return actor->listReports();
}

bool Admin::displayMovieReports(Movie* movie) {
	if (!movie) {
		cout << "Movie not found." << endl;
		return false;
	}
	return movie->listReports();
}

void Admin::displayActorReport(Actor* actor, Report* report) {
	if (!actor) {
		cout << "Actor not found." << endl;
		return;
	}

	actor->displayReport(report);
}

void Admin::displayMovieReport(Movie* movie, Report* report) {
	movie->displayReport(report);
}

bool Admin::addMovie(int id, LinkedList<Movie*>& movies, string& title, string& plot, int yearOfRelease) {
    for (int i = 0; i < movies.getLength(); ++i) {
        Movie* movie = movies.get(i);
        if (movie->getTitle() == title) {
            cout << "Movie " << title << " already exists in the system." << endl;
            return false;
        }
    }

    Movie* newMovie = new Movie(id, title, plot, yearOfRelease, 0.0f); // Default rating is 0.0
    movies.add(newMovie);
    cout << "Movie " << title << " added successfully." << endl;
    return true;
}

void Admin::addActorToMovie(Movie* movie, Actor* actor) {
    if (!movie || !actor) {
        cout << "Invalid actor or movie provided." << endl;
        return;
    }

    movie->addActor(actor);
    cout << "Actor " << actor->getName() << " added to movie " << movie->getTitle() << "." << endl;
}

void Admin::updateActor(Actor* actor, string& newName, int newYearOfBirth) {
    if (!actor) {
        cout << "Actor not found." << endl;
        return;
    }

    actor->updateActorDetails(newName, newYearOfBirth);
    cout << "Actor details updated successfully." << endl;
}

void Admin::updateMovie(Movie* movie, string& newTitle, string& newPlot, int newYearOfRelease) {
    if (!movie) {
        cout << "Movie not found." << endl;
        return;
    }

    movie->updateMovieDetails(newTitle, newPlot, newYearOfRelease);
    cout << "Movie details updated successfully." << endl;
}