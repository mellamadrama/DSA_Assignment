#pragma once


#include <string>
#include <vector>
using namespace std;

class Movie;

class Actor {
private:
    string name;
    int yearOfBirth;
    float rating;
    vector<Movie*> listOfMovies;

public:
    // Constructor
    Actor(string name, int yearOfBirth, float rating);

    // Destructor
    ~Actor() = default;

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
    float getRating() const;

    // Add a movie to the actor's list of movies
    // pre : movie is a valid Movie object
    // post: movie is added to the actor's list of movies
    void addMovie(Movie* movie) { listOfMovies.push_back(movie); }

    // Display all movies the actor has acted in
    // pre : none
    // post: prints the titles of all movies the actor has acted in
    void displayMovies() const;

	// Get the age of the actor
	// pre : none
	// post: returns the age of the actor
    int getAge() const;
};