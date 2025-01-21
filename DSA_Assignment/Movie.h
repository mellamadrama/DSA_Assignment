#pragma once

#include <string>
#include "LinkedList.h"
#include "Actor.h"
using namespace std;

class Actor;

class Movie {
private:
    string title;
    string plot;
    int yearOfRelease;
    float movieRating;
    LinkedList<Actor*> listOfActors;

public:
	//Constructor
    Movie(string title, string plot, int yearOfRelease, float movieRating);

	//Destructor
	~Movie();

	// Get the title of the movie
	// pre : none
	// post: returns the title of the movie
    string getTitle();

	// Get the plot of the movie
	// pre : none
	// post: returns the plot of the movie
    string getPlot();

	// Get the year of release of the movie
	// pre : none
	// post: returns the year of release of the movie
    int getYearOfRelease();

	// Get the rating of the movie
	// pre : none
	// post: returns the rating of the movie
    float getMovieRating();

	// Add an actor to the movie's list of actors
	// pre : actor is a valid Actor object
	// post: actor is added to the movie's list of actors
	void addActor(Actor* actor);

	// Display all actors in the movie
	// pre : none
	// post: prints the names of all actors in the movie
    void displayActors();

	// Update the movie's details
	// pre: newTitle and newPlot are valid strings, newYearOfRelease is a positive integer
	// post: updates the title, plot, and year of release of the movie
	void updateMovieDetails(string& newTitle, string& newPlot, int newYearOfRelease, float newMovieRating);

	// Get the list of actors in the movie
	// pre : none
	// post: returns a constant reference to the list of actors
	LinkedList<Actor*>& getActors();
};