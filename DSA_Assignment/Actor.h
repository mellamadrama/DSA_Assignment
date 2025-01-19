#pragma once
#include <string>
#include <vector>
#include "Movie.h"
using namespace std;

class Movie;

class Actor {
private:
    string name;
    int yearOfBirth;
    float actorRating;
    vector<Movie*> listOfMovies;

public:
    // Constructor
    Actor(string name, int yearOfBirth, float rating);

    // Destructor
    ~Actor();

    // Get the name of the actor
    // pre : none
    // post: returns the name of the actor
    string getName() const;

    // Get the year of birth of the actor
    // pre : none
    // post: returns the year of birth of the actor
    int getYearOfBirth() const;

	// Get the rating of the actor
	// pre : none
	// post: returns the rating of the actor
    float getActorRating() const;

    // Add a movie to the actor's list of movies
    // pre : movie is a valid Movie object
    // post: movie is added to the actor's list of movies
    void addMovie(Movie* movie);

    // Display all movies the actor has acted in
    // pre : none
    // post: prints the titles of all movies the actor has acted in
    void displayMovies() const;

	// Get the age of the actor
	// pre : none
	// post: returns the age of the actor
    int getAge() const; 

    // Update the actor's details
    // pre: newName is a valid string, newYearOfBirth is a positive integer
    // post: updates the name and year of birth of the actor
    void updateActorDetails(const string& newName, int newYearOfBirth, float newActorRating);

    // Get the list of movies the actor has acted in
    // pre : actor must have acted in movies
    // post: returns a constant reference to the list of movies
    const vector<Movie*>& getMovies() const;
};