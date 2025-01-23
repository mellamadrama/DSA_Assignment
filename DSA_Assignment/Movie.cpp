#include "Movie.h"
#include <iostream>
using namespace std;

// Constructor
// pre: title and plot are valid strings, yearOfRelease is a positive integer, initialRating is within a valid range
// post: Movie object is initialized with the given attributes
Movie::Movie(string& title, string& plot, int yearOfRelease, float avgMovieRating){
	this->title = title;
	this->plot = plot;
	this->yearOfRelease = yearOfRelease;
	this->avgMovieRating = avgMovieRating;
}

// Destructor
// pre : none
// post: Movie object is properly destroyed
Movie::~Movie() {}

// Get the title of the movie
// pre : none
// post: returns the title of the movie
string Movie::getTitle() {
    return title;
}

// Get the plot of the movie
// pre : none
// post: returns the plot of the movie
string Movie::getPlot() {
    return plot;
}

// Get the year of release of the movie
// pre : none
// post: returns the year of release of the movie
int Movie::getYearOfRelease() {
    return yearOfRelease;
}

// Add a rating to the movie's ratings list
// pre : rating is within a valid range
// post: rating is added to the ratings list and avgMovieRating is updated
void Movie::addRating(float rating) {
    if (rating < 0.0f || rating > 5.0f) {
        cout << "Invalid rating. Must be between 0 and 5." << endl;
        return;
    }
    listOfRatings.add(rating);
    float sum = 0.0f;
    for (int i = 0; i < listOfRatings.getLength(); ++i) {
        sum += listOfRatings.get(i);
    }
    avgMovieRating = sum / listOfRatings.getLength();
}

// Get the average rating of the movie
// pre : none
// post: returns the average rating of the movie
float Movie::getMovieRating() {
    return avgMovieRating;
}

// Add an actor to the movie's list of actors
// pre : actor is a valid pointer to an Actor object
// post: actor is added to the movie's list of actors and adds this movie to the actor's list of movies
void Movie::addActor(Actor* actor) {
    listOfActors.add(actor);
    actor->addMovie(this);
}

// Display all actors in the movie
// pre : none
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
void Movie::updateMovieDetails(string& newTitle, string& newPlot, int newYearOfRelease) {
    if (newTitle.empty() || newPlot.empty() || newYearOfRelease <= 0) {
        cout << "Invalid details provided. Update failed." << endl;
        return;
    }
    title = newTitle;
    plot = newPlot;
    yearOfRelease = newYearOfRelease;

    cout << "Movie details updated: Title = \"" << title << "\", Plot = \"" << plot << "\", Year of Release = " << yearOfRelease << endl;
}

// Get the list of actors in the movie
// pre : none
// post: returns a reference to the list of actors
LinkedList<Actor*>& Movie::getActors() {
    return listOfActors;
}
