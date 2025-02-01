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
        if (actor->getName() == actorName) {
            cout << "Actor " << actorName << " already exists in the system." << endl;
			return false;
        }
    }

    Actor* newActor = new Actor(id, actorName, yearOfBirth, 0.0f);
    actors.add(newActor);
    cout << "Actor " << actorName << " added successfully." << endl;
    return true;
}

bool Admin::displayActorReports(Actor* actor) {
	return actor->listReports();
}

bool Admin::displayMovieReports(Movie* movie) {
	return movie->listReports();
}

void Admin::displayActorReport(Actor* actor, Report* report) {
	actor->displayReport(report);
}

void Admin::displayMovieReport(Movie* movie, Report* report) {
	movie->displayReport(report);
}

// Add a new movie to the list
// pre: title and plot are valid strings, yearOfRelease is a positive integer
// post: new movie is added to the vector; if movie already exists, no changes are made
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

// Associate an actor with a movie
// pre: actor and movie are valid pointers
// post: actor is added to the movie's list of actors, and the movie is added to the actor's list of movies
void Admin::addActorToMovie(Movie* movie, Actor* actor) {
    if (!movie || !actor) {
        cout << "Invalid actor or movie provided." << endl;
        return;
    }

    movie->addActor(actor);
    cout << "Actor " << actor->getName() << " added to movie " << movie->getTitle() << "." << endl;
}

// Update an actor's details
// pre: actor is a valid pointer, yearOfBirth is a positive integer
// post: actor's details are updated
void Admin::updateActor(Actor* actor, string& newName, int newYearOfBirth) {
    if (!actor) {
        cout << "Actor not found." << endl;
        return;
    }

    actor->updateActorDetails(newName, newYearOfBirth);
    cout << "Actor details updated successfully." << endl;
}

// Update a movie's details
// pre: movie is a valid pointer, yearOfRelease is a positive integer
// post: movie's details are updated
void Admin::updateMovie(Movie* movie, string& newTitle, string& newPlot, int newYearOfRelease) {
    if (!movie) {
        cout << "Movie not found." << endl;
        return;
    }

    movie->updateMovieDetails(newTitle, newPlot, newYearOfRelease);
    cout << "Movie details updated successfully." << endl;
}

// Handle a report
// pre: report is a valid Report object
// post: prints the report details and handles accordingly
void Admin::handleReport(Report& report) {
    cout << "Handling Report ID: " << report.getReportId() << endl;
    cout << "Created By: " << report.getCreatedBy() << endl;
    cout << "Error Description: " << report.getReportDescription() << endl;

    // Handle report logic (e.g., notify user, log details, etc.)
    cout << "Report handled successfully." << endl;
}