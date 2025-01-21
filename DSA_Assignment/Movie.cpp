#include "Movie.h"
#include <iostream>
using namespace std;

// Constructor
Movie::Movie(string title, string plot, int yearOfRelease, float movieRating) {
	this->title = title;
	this->plot = plot;
	this->yearOfRelease = yearOfRelease;
	this->movieRating = movieRating;
}

// Destructor
Movie::~Movie() {
}

// Get the title of the movie
// pre: none
// post: returns the title of the movie
string Movie::getTitle() {
    return title;
}

// Get the plot of the movie
// pre: none
// post: returns the plot of the movie
string Movie::getPlot() {
    return plot;
}

// Get the year of release of the movie
// pre: none
// post: returns the year of release of the movie
int Movie::getYearOfRelease() {
    return yearOfRelease;
}

// Get the rating of the movie
// pre: none
// post: returns the rating of the movie
float Movie::getMovieRating() {
    return movieRating;
}

// Add an actor to the movie's list of actors
// pre: actor is a valid pointer to an Actor object
// post: adds the actor to the movie's list of actors and adds this movie to the actor's list of movies
void Movie::addActor(Actor* actor) {
    listOfActors.add(actor);
    actor->addMovie(this);
}

// Display all actors in the movie
// pre: none
// post: prints the names of all actors in the movie or a message if no actors are present
void Movie::displayActors() {
    cout << "Actors in the movie " << title << ":" << endl;
    if (listOfActors.isEmpty()) {
        cout << "No actors in this movie." << endl;
        return;
    }
    for (int i = 0; i < listOfActors.getLength(); ++i) {
        cout << "- " << listOfActors.get(i)->getName() << endl;
    }
}

// Update the movie's details
// pre: newTitle and newPlot are valid strings, newYearOfRelease is a positive integer
// post: updates the title, plot, and year of release of the movie
void Movie::updateMovieDetails(string& newTitle, string& newPlot, int newYearOfRelease, float newMovieRating) {
    // Validate inputs
    if (newTitle.empty() || newPlot.empty() || newYearOfRelease <= 0 || newMovieRating < 0.0 || newMovieRating > 5.0) {
        cout << "Invalid details provided. Update failed." << endl;
        return;
    }

    // Update attributes
    title = newTitle;
    plot = newPlot;
    yearOfRelease = newYearOfRelease;
    movieRating = newMovieRating;

    // Confirmation message
    cout << "Movie details updated: Title = \"" << title << "\", Plot = \"" << plot << "\", Year of Release = " << yearOfRelease << ", Rating = " << movieRating << endl;
}

// Get the list of actors in the movie
LinkedList<Actor*>& Movie::getActors() {
    return listOfActors;
}