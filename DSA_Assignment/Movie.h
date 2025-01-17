#pragma once

#include <string>
#include <vector>
#include "Actor.h"
using namespace std;

class Actor;

class Movie {
private:
    string title;
    string plot;
    int yearOfRelease;
    float rating;
    vector<Actor*> listOfActors;

public:
	//Constructor
    Movie(string title, string plot, int yearOfRelease, float rating);

	//Destructor
    ~Movie() = default;

	// Get the title of the movie
	// pre : none
	// post: returns the title of the movie
    string getTitle() const;

	// Get the plot of the movie
	// pre : none
	// post: returns the plot of the movie
    string getPlot() const;

	// Get the year of release of the movie
	// pre : none
	// post: returns the year of release of the movie
    int getYearOfRelease() const;

	// Get the rating of the movie
	// pre : none
	// post: returns the rating of the movie
    float getRating() const;

	// Add an actor to the movie's list of actors
	// pre : actor is a valid Actor object
	// post: actor is added to the movie's list of actors
    void addActor(Actor* actor) { listOfActors.push_back(actor); }

	// Display all actors in the movie
	// pre : none
	// post: prints the names of all actors in the movie
    void displayActors() const;

    
};