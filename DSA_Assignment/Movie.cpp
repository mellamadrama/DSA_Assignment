#include "Movie.h"
#include <iostream>
#include "Global.h"
using namespace std;

Movie::Movie(int id, string& title, string& plot, int yearOfRelease, float initialRating)
	: id(id), title(title), plot(plot), yearOfRelease(yearOfRelease), avgMovieRating(initialRating) {
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
    if (listOfActors.isEmpty() || listOfActors.get(0)->getName() > actor->getName()) {
        listOfActors.add(0, actor);
    }
    else {
        for (int i = 0; i < listOfActors.getLength(); ++i) {
            if (listOfActors.get(i)->getName() > actor->getName()) {
                listOfActors.add(i, actor);
                return;
            }
        }
        // If the actor's name is greater than all existing actors' names, add to the end
        listOfActors.add(listOfActors.getLength(), actor);
    }
}

void Movie::displayActors() {
    if (listOfActors.isEmpty()) {
        cout << "No actors in this movie." << endl;
        return;
    }

    cout << "Actors in the movie " << title << ":" << endl;
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
