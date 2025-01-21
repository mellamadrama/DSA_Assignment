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
void Admin::addActor(LinkedList<Actor*>& actors, string& actorName, int yearOfBirth, float rating) {
    for (int i = 0; i < actors.getLength(); ++i) {
        Actor* actor = actors.get(i);
        if (actor->getName() == actorName) {
            cout << "Actor " << actorName << " already exists in the system." << endl;
            return;
        }
    }

    Actor* newActor = new Actor(actorName, yearOfBirth, 0.0f); // Default rating is 0.0
    actors.add(newActor);
    cout << "Actor " << actorName << " added successfully." << endl;
}

// Add a new movie to the list
// pre: title and plot are valid strings, yearOfRelease is a positive integer
// post: new movie is added to the vector; if movie already exists, no changes are made
void Admin::addMovie(LinkedList<Movie*>& movies, string& title, string& plot, int yearOfRelease, float rating) {
    for (int i = 0; i < movies.getLength(); ++i) {
        Movie* movie = movies.get(i);
        if (movie->getTitle() == title) {
            cout << "Movie " << title << " already exists in the system." << endl;
            return;
        }
    }

    Movie* newMovie = new Movie(title, plot, yearOfRelease, 0.0f); // Default rating is 0.0
    movies.add(newMovie);
    cout << "Movie " << title << " added successfully." << endl;
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
void Admin::updateActor(Actor* actor, string& newName, int newYearOfBirth, float newActorRating) {
    if (!actor) {
        cout << "Actor not found." << endl;
        return;
    }

    actor->updateActorDetails(newName, newYearOfBirth, newActorRating);
    cout << "Actor details updated successfully." << endl;
}

// Update a movie's details
// pre: movie is a valid pointer, yearOfRelease is a positive integer
// post: movie's details are updated
void Admin::updateMovie(Movie* movie, string& newTitle, string& newPlot, int newYearOfRelease, float newMovieRating) {
    if (!movie) {
        cout << "Movie not found." << endl;
        return;
    }

    movie->updateMovieDetails(newTitle, newPlot, newYearOfRelease, newMovieRating);
    cout << "Movie details updated successfully." << endl;
}

// Handle a report
// pre: report is a valid Report object
// post: prints the report details and handles accordingly
void Admin::handleReport(Report& report) {
    cout << "Handling Report ID: " << report.getReportId() << endl;
    cout << "Created By: " << report.getCreatedBy() << endl;
    cout << "Type: " << report.getType() << endl;
    cout << "Error Description: " << report.getErrorDescription() << endl;

    // Handle report logic (e.g., notify user, log details, etc.)
    cout << "Report handled successfully." << endl;
}