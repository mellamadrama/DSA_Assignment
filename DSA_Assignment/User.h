/*
* Name: Hervin Sie(S10262115C), Charlotte Lee(s10258027k)
* Group: 6
*/

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

	// Display the rating of a movie
	// pre : movie is not null
	// post: prints the rating of the movie
	void displayMovieRating(Movie* movie);

	// Add a rating to an actor
	// pre : rating is within a valid range AND actor is not null
	// post: rating is added to the actor's ratings list
	void addActorRating(Actor* actor, float rating);

	// Display the rating of an actor
	// pre : actor is not null
	// post: prints the rating of the actor
	void displayActorRating(Actor* actor);

	// Display all movies with a rating of 4.0 or higher
	// pre : none
	// post: prints the names of all movies with a rating of 4.0 or higher
	void displayMovieRecommendation(LinkedList<Movie*>& movies);

	// Display all actors with a rating of 4.0 or higher
	// pre : none
	// post: prints the names of all actors with a rating of 4.0 or higher
	void displayActorRecommendation(LinkedList<Actor*>& actors);

	// Add a report to a movie
	// pre : movie is not null
	// post: report is added to the movie's list of reports
	void addMovieReport(Movie* movie, Report* report);

	// Add a report to an actor
	// pre : actor is not null
	// post: report is added to the actor's list of reports
	void addActorReport(Actor* actor, Report* report);

	// Display all actors in the range of age
	// pre : none
	// post: prints the names of all actors in the range of age
    void displayActorInRange(LinkedList<Actor*>& actors, int minAge, int maxAge);

	// Display all movies released in the past 3 years
	// pre : none
	// post: prints the names of all movies released in the past 3 years
    void displayMoviesPast3Years(LinkedList<Movie*>& movies);

	// Display all movies with an actor
	// pre: actor is not null
	// post: prints the names of all movies with the actor
    void displayMovieWithActor(Actor* actor);

	// Display all actors in a movie
	// pre : movie is not null
	// post: prints the names of all actors in the movie
    void displayAllActorsInMovie(Movie* mvoie);

	// Display actors another actor has worked with
	// pre : actor is not null
	// post: prints the names of all actors the actor has worked with
    void displayActorConnections(Actor* actor);
};