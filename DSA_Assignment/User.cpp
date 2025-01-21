#pragma once
#include <string>
#include "User.h"
#include <ctime>
using namespace std;

// Constructor
User::User(string name, int userId) {
    this->name = name;
    this->userId = userId;
}

// Display all actors within a specified age range
// pre: none
// post: prints the names of all actors whose ages are within the specified range
void User::displayActorInRange(LinkedList<Actor*>& actors, int minAge, int maxAge) {
    cout << "Actors in the age range [" << minAge << ", " << maxAge << "]:" << endl;
    for (int i = 0; i < actors.getLength(); ++i) {
        Actor* actor = actors.get(i);
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
void User::displayMoviesInRange(LinkedList<Movie*>& movies) {
    // Get the current year dynamically
    time_t t = time(nullptr); // Get current time
    tm now;
    localtime_s(&now, &t);// Convert to local time
    int currentYear = now.tm_year + 1900; // tm_year is years since 1900

    cout << "Movies released in the past 3 years:" << endl;
    for (int i = 0; i < movies.getLength(); ++i) {
        Movie* movie = movies.get(i);
        if (movie) {
            int releaseYear = movie->getYearOfRelease();
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
void User::displayMovieWithActor(Actor& actor) {
    LinkedList<Movie*>& movies = actor.getMovies();
    cout << "Movies featuring actor " << actor.getName() << ":" << endl;

    for (int i = 0; i < movies.getLength(); ++i) {
        Movie* movie = movies.get(i);
        if (movie) {
            cout << "- " << movie->getTitle() << endl;
        }
    }
}

// Display all actors in a specific movie
// pre: none
// post: prints the names of all actors in the given movie
void User::displayAllActorsInMovie(Movie* movie) {
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
void User::displayActorConnections(Actor* actor) {
    if (!actor) {
        cout << "Invalid actor provided." << endl;
        return;
    }

    cout << "Actors connected to \"" << actor->getName() << "\":" << endl;
    LinkedList<Movie*>& movies = actor->getMovies();
    for (int i = 0; i < movies.getLength(); ++i) {
        Movie* movie = movies.get(i);
        if (movie) {
            LinkedList<Actor*>& actors = movie->getActors();
            for (int j = 0; j < actors.getLength(); ++j) {
                Actor* connectedActor = actors.get(j);
                if (connectedActor && connectedActor != actor) {
                    cout << "- " << connectedActor->getName() << endl;
                }
            }
        }
    }
};