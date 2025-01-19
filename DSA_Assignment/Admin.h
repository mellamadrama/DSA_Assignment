#pragma once
#include <string>
#include "Actor.h"
#include "Movie.h"
#include "HashTable.h"
#include "Report.h"
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

    string getName() const;

    int getAdminId() const;

    // add a new actor to the hash table
    // pre : key is unique, name is a valid string, yearOfBirth is a positive integer, and rating is within a valid range
    // post: new actor is added to the hash table; if actor already exists, no changes are made
    void addActor(vector<Actor*>& actors, const string& actorName, int yearOfBirth, float rating);

    // add a new movie to the hash table
    // pre : key is unique, title and plot are valid strings, yearOfRelease is a positive integer, and rating is within a valid range
    // post: new movie is added to the hash table; if movie already exists, no changes are made
    void addMovie(vector<Movie*>& movies, const string& title, const string& plot, int yearOfRelease, float rating);

    // associate an actor with a movie
    // pre : actorKey and movieKey are valid and exist in their respective hash tables
    // post: actor is added to the movie and vice versa; if either is missing, no changes are made
    void addActorToMovie(Movie* movie, Actor* actor);

    // update an actor's details
    // pre : key exists in the hash table, yearOfBirth is a positive integer, and rating is within a valid range
    // post: actor's details are updated; if actor is not found, no changes are made
    void updateActor(Actor* actor, const string& newName, int newYearOfBirth, float newRating);

	// update a movie's details
	// pre : key exists in the hash table, yearOfRelease is a positive integer, and rating is within a valid range
	// post: movie's details are updated; if movie is not found, no changes are made
    void updateMovie(Movie* movie, const string& newTitle, const string& newPlot, int newYearOfRelease, float newRating);

    void handleReport(const Report& report);
};

