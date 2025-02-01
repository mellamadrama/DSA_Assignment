#include "Movie.h"
#include <iostream>
using namespace std;

// Constructor
// pre: title and plot are valid strings, yearOfRelease is a positive integer, initialRating is within a valid range
// post: Movie object is initialized with the given attributes
Movie::Movie(int id, string& title, string& plot, int yearOfRelease, float avgMovieRating){
	this->id = id;
	this->title = title;
	this->plot = plot;
	this->yearOfRelease = yearOfRelease;
	this->avgMovieRating = avgMovieRating;
}

Movie::~Movie() {}

string Movie::getTitle() {
    return title;
}

int Movie::getId() {
	return id;
}

string Movie::getPlot() {
    return plot;
}

bool Movie::listReports() {
	cout << "Reports for movie " << title << ":" << endl;
	if (listOfReports.isEmpty()) {
		cout << "No reports for this movie." << endl;
		return false;
	}
	for (int i = 0; i < listOfReports.getLength(); ++i) {
		cout << i + 1 << ". " << listOfReports.get(i)->getReportDescription() << endl;
	}
    return true;
}

void Movie::displayReport(Report* report) {
	report->displayReport();
}

void Movie::addReport(Report* report) {
	listOfReports.add(report);
}

LinkedList<Report*>& Movie::getReportList() {
	return listOfReports;
}

int Movie::getYearOfRelease() {
    return yearOfRelease;
}

void Movie::addRating(float rating) {
    listOfRatings.add(rating);
    float sum = 0.0f;
    for (int i = 0; i < listOfRatings.getLength(); ++i) {
        sum += listOfRatings.get(i);
    }
    avgMovieRating = sum / listOfRatings.getLength();
}

float Movie::getMovieRating() {
    return avgMovieRating;
}

void Movie::addActor(Actor* actor) {
    if (!listOfActors.contains(actor)) {
        listOfActors.add(actor);
        actor->addMovie(this);
    }
}

void Movie::displayActors() {
    cout << "Actors in the movie " << title << ":" << endl;
    if (listOfActors.isEmpty()) {
        cout << "No actors in this movie." << endl;
        return;
    }

	listOfActors.sort([](Actor* a, Actor* b) {
		return a->getName() < b->getName();
	});

    for (int i = 0; i < listOfActors.getLength(); ++i) {
        cout << "- " << listOfActors.get(i)->getName() << endl;
    }
}

void Movie::updateMovieDetails(string& newTitle, string& newPlot, int newYearOfRelease) {
    if (newTitle.empty() || newPlot.empty()) {
        cout << "Invalid details provided. Update failed." << endl;
        return;
    }
    title = newTitle;
    plot = newPlot;
    yearOfRelease = newYearOfRelease;

    cout << "Movie details updated: Title = \"" << title << "\", Plot = \"" << plot << "\", Year of Release = " << yearOfRelease << endl;
}

LinkedList<Actor*>& Movie::getActors() {
    return listOfActors;
}
