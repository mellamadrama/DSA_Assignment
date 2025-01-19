#pragma once
#include <string>
#include "Actor.h"
#include "Movie.h"
#include "HashTable.h"
using namespace std;

class User {
private:
    string name;
    int userId;

public:
	//Constructor
    User(string name, int userId);

	//Deconstructor
    ~User() = default;

	// Get the name of the user
	// pre : none
	// post: returns the name of the user
    string getName() const { return name; }

	// Get the user ID
	// pre : none
	// post: returns the user ID
    int getUserId() const { return userId; }

	// Display all actors in the range of age
	// pre : none
	// post: prints the names of all actors in the range of age
    void displayActorInRange(const vector<Actor*>& actors, int minAge, int maxAge) const;

	// Display all actors in the range of rating
	// pre : none
	// post: prints the names of all actors in the range of rating
    void displayMoviesInRange(const vector<Movie*>& movies) const;

	// Display all actors in the range of rating
	// pre : none
	// post: prints the names of all actors in the range of rating
    void displayMovieWithActor(const Actor& actor) const;

	// Display all actors in the range of rating
	// pre : none
	// post: prints the names of all actors in the range of rating
    void displayAllActorsInMovie(const Movie* mvoie) const;

	// Display all actors in the range of rating
	// pre : none
	// post: prints the names of all actors in the range of rating
    void displayActorConnections(const Actor* actor) const;
};