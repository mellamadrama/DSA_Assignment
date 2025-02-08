/*
* Name: Hervin Sie(S10262115C), Charlotte Lee(s10258027k)
* Group: 6
*/

#pragma once
#include <string>
#include "Actor.h"
#include "Movie.h"
#include "HashTable.h"
#include "Report.h"
#include "LinkedList.h"
using namespace std;

class Admin {
private:
    string name;
    int adminId;

public:
    // Constructor
    // create an Admin object with initialized hash tables for actors and movies
    // pre : actorTableSize and movieTableSize are positive integers
    // post: Admin object is initialized with hash tables of specified sizes
    Admin(string name, int adminId);

    // Destructor
    ~Admin() = default;

	// Get the name of the admin
	// pre : none
	// post: returns the name of the admin
    string getName();

	// Get the admin ID
	// pre : none
	// post: returns the admin ID
    int getAdminId();

    // add a new actor to the hash table
    // pre : key is unique, name is a valid string, yearOfBirth is a positive integer
    // post: new actor is added to the hash table; if actor already exists, no changes are made
    bool addActor(int id, LinkedList<Actor*>& actors, string& actorName, int yearOfBirth);

    // add a new movie to the hash table
    // pre : key is unique, title and plot are valid strings, yearOfRelease is a positive integer
    // post: new movie is added to the hash table; if movie already exists, no changes are made
    bool addMovie(int id, LinkedList<Movie*>& movies, string& title, string& plot, int yearOfRelease);

    // associate an actor with a movie
    // pre : actorKey and movieKey are valid and exist in their respective hash tables
    // post: actor is added to the movie and vice versa; if either is missing, no changes are made
    void addActorToMovie(Movie* movie, Actor* actor);

	// display all reports for an actor
	// pre : actor is a valid pointer
	// post: prints all reports for the actor
	bool displayActorReports(Actor* actor);

	// display all reports for a movie
	// pre : movie is a valid pointer
	// post: prints all reports for the movie
	bool displayMovieReports(Movie* movie);

	// display a report for an actor
	// pre : actor is a valid pointer
	// post: prints the details of the report
	void displayActorReport(Actor* actor, Report* report);

	// display a report for a movie
	// pre : movie is a valid pointer
	// post: prints the details of the report
	void displayMovieReport(Movie* movie, Report* report);

    // update an actor's details
    // pre : key exists in the hash table, yearOfBirth is a positive integer, and rating is within a valid range
    // post: actor's details are updated; if actor is not found, no changes are made
    void updateActor(Actor* actor, string& newName, int newYearOfBirth);

	// update a movie's details
	// pre : key exists in the hash table, yearOfRelease is a positive integer, and rating is within a valid range
	// post: movie's details are updated; if movie is not found, no changes are made
    void updateMovie(Movie* movie, string& newTitle, string& newPlot, int newYearOfRelease);
};

