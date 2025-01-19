#pragma once
#include <string>
#include "User.h"
#include <ctime>
#include <vector>
using namespace std;

// Constructor
User::User(string name, int userId) {
    this->name = name;
    this->userId = userId;
}

// Display all actors within a specified age range
// pre: none
// post: prints the names of all actors whose ages are within the specified range
void User::displayActorInRange(const vector<Actor*>& actors, int minAge, int maxAge) const {
    cout << "Actors in the age range [" << minAge << ", " << maxAge << "]:" << endl;
    for (const Actor* actor : actors) {
        if (actor) {
            int age = actor->getAge();
            if (age >= minAge && age <= maxAge) {
                cout << "- " << actor->getName() << " (Age: " << age << ")" << endl;
            }
        }
    }
}

// Display all movies made in the past 3 years
// pre: none
// post: prints the titles of all movies made in the past 3 years
void User::displayMoviesInRange(const vector<Movie*>& movies) const {
    // Get the current year dynamically
    time_t t = time(nullptr); // Get current time
    tm* now = localtime(&t); // Convert to local time
    int currentYear = now->tm_year + 1900; // tm_year is years since 1900

    cout << "Movies released in the past 3 years:" << endl;
    for (const Movie* movie : movies) {
        if (movie) {
            int releaseYear = movie->getYearOfRelease(); // Assuming this method exists in Movie
            if (releaseYear >= currentYear - 3 && releaseYear <= currentYear) {
                cout << "- " << movie->getTitle()
                    << " (Year: " << releaseYear
                    << ", Rating: " << movie->getMovieRating() << ")"
                    << endl;
            }
        }
    }
}

// Display all movies with a specific actor
// pre: none
// post: prints the titles of all movies that include the specified actor
void User::displayMovieWithActor(const Actor& actor) const {
    const vector<Movie*>& movies = actor.getMovies(); 
    cout << "Movies featuring actor " << actor.getName() << ":" << endl;

    // Iterate over the vector to display movie titles
    for (const Movie* movie : movies) {
        if (movie) {
            cout << "- " << movie->getTitle() << endl;
        }
    }
}

// Display all actors in a specific movie
// pre: none
// post: prints the names of all actors in the given movie
void User::displayAllActorsInMovie(const Movie* movie) const {
    if (!movie) {
        cout << "Invalid movie provided." << endl;
        return;
    }

    cout << "Actors in the movie " << movie->getTitle() << ":" << endl;
    movie->displayActors();
}

// Display all actors directly connected to a specific actor
// pre: none
// post: prints the names of all actors connected to the given actor through shared movies
void User::displayActorConnections(const Actor* actor) const {
    if (!actor) {
        cout << "Invalid actor provided." << endl;
        return;
    }

    cout << "Actors connected to \"" << actor->getName() << "\":" << endl;
    vector<Movie*> movies = actor->getMovies(); // Assuming getMovies() exists in Actor
    for (const Movie* movie : movies) {
        if (movie) {
            vector<Actor*> actors = movie->getActors(); // Assuming getActors() exists in Movie
            for (const Actor* connectedActor : actors) {
                if (connectedActor && connectedActor != actor) {
                    cout << "- " << connectedActor->getName() << endl;
                }
            }
        }
    }
}