#pragma once

#include <string>
#include "LinkedList.h"
#include "Actor.h"
#include "Report.h"
using namespace std;

class Actor;

class Movie {
private:
    int id;
    string title;                   
    string plot;                    
    int yearOfRelease;
    float avgMovieRating;
    LinkedList<float> listOfRatings;      
    LinkedList<Actor*> listOfActors;
	LinkedList<Report*> listOfReports;
    
public:
    // Constructor
    // pre: title and plot are valid strings, yearOfRelease is a positive integer, avgMovieRating is within a valid range
    // post: Movie object is initialized with the given attributes
    Movie (int id, string& title, string& plot, int yearOfRelease, float avgMovieRating);

    // Destructor
    // pre : none
    // post: Movie object is properly destroyed
    ~Movie();

    // Get the title of the movie
    // pre : none
    // post: returns the title of the movie
    string getTitle();

	// Get the id of the movie
	// pre : none
	// post: returns the id of the movie
	int getId();

    // Get the plot of the movie
    // pre : none
    // post: returns the plot of the movie
    string getPlot();

	bool listReports();

	void displayReport(Report* report);

	void addReport(Report* report);

	LinkedList<Report*>& getReportList();

    // Get the year of release of the movie
    // pre : none
    // post: returns the year of release of the movie
    int getYearOfRelease();

    // Add a rating to the movie's ratings list
    // pre : rating is within a valid range
    // post: rating is added to the ratings list
    void addRating(float rating);

    // Get the average rating of the movie
    // pre : none
    // post: returns the average rating of the movie
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
    // post: updates the title, plot, year of release, and average rating
    void updateMovieDetails(string& newTitle, string& newPlot, int newYearOfRelease);

    // Get the list of actors in the movie
    // pre : none
    // post: returns a constant reference to the list of actors
    LinkedList<Actor*>& getActors();
};
