#pragma once
#include <string>
#include "Actor.h"
#include "Movie.h"
#include "HashTable.h"
#include "LinkedList.h"
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
    string getName() { return name; }

	// Get the user ID
	// pre : none
	// post: returns the user ID
    int getUserId() { return userId; }

	// Add a rating to a movie
	// pre : rating is within a valid range
	// post: rating is added to the movie's ratings list

	void addMovieRating(Movie* movie, float rating);

	void displayMovieRating(Movie* movie);

	void addActorRating(Actor* actor, float rating);

	void displayActorRating(Actor* actor);

	void displayMovieRecommendation(LinkedList<Movie*>& movies);

	void displayActorRecommendation(LinkedList<Actor*>& actors);

	void addMovieReport(Movie* movie, Report* report);

	void addActorReport(Actor* actor, Report* report);

	// Display all actors in the range of age
	// pre : none
	// post: prints the names of all actors in the range of age
    void displayActorInRange(LinkedList<Actor*>& actors, int minAge, int maxAge);

	// Display all actors in the range of rating
	// pre : none
	// post: prints the names of all actors in the range of rating
    void displayMoviesPast3Years(LinkedList<Movie*>& movies);

	// Display all actors in the range of rating
	// pre : none
	// post: prints the names of all actors in the range of rating
    void displayMovieWithActor(Actor& actor);

	// Display all actors in the range of rating
	// pre : none
	// post: prints the names of all actors in the range of rating
    void displayAllActorsInMovie(Movie* mvoie);

	// Display all actors in the range of rating
	// pre : none
	// post: prints the names of all actors in the range of rating
    void displayActorConnections(Actor* actor);
};