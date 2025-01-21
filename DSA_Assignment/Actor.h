#pragma once
#include <string>
#include "LinkedList.h"
#include "Movie.h"
using namespace std;

class Movie;

class Actor {
private:
    string name;
    int yearOfBirth;
    float actorRating;
    LinkedList<Movie*> listOfMovies;

public:
    // Constructor
    Actor(string name, int yearOfBirth, float actorRating);

    // Destructor
    ~Actor();

    // Get the name of the actor
    // pre : none
    // post: returns the name of the actor
    string getName();

    // Get the year of birth of the actor
    // pre : none
    // post: returns the year of birth of the actor
    int getYearOfBirth();

	// Get the rating of the actor
	// pre : none
	// post: returns the rating of the actor
    float getActorRating();

    // Add a movie to the actor's list of movies
    // pre : movie is a valid Movie object
    // post: movie is added to the actor's list of movies
    void addMovie(Movie* movie);

    // Display all movies the actor has acted in
    // pre : none
    // post: prints the titles of all movies the actor has acted in
    void displayMovies();

	// Get the age of the actor
	// pre : none
	// post: returns the age of the actor
    int getAge(); 

    // Update the actor's details
    // pre: newName is a valid string, newYearOfBirth is a positive integer
    // post: updates the name and year of birth of the actor
    void updateActorDetails(string& newName, int newYearOfBirth, float newActorRating);

    // Get the list of movies the actor has acted in
    // pre : actor must have acted in movies
    // post: returns a constant reference to the list of movies
    LinkedList<Movie*>& getMovies();
};