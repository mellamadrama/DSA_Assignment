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

void User::addMovieRating(Movie* movie, float rating) {
	movie->addRating(rating);
}

void User::displayMovieRating(Movie* movie) {
	cout << "Average Rating: " << movie->getMovieRating() << endl;
}

void User::displayMovieRecommendation(LinkedList<Movie*>& movies) {
	cout << "Recommended movies:" << endl;
	for (int i = 0; i < movies.getLength(); ++i) {
		Movie* movie = movies.get(i);
		if (movie->getMovieRating() >= 4.0) {
			cout << "- " << movie->getTitle() << " (Rating: " << movie->getMovieRating() << ")" << endl;
		}
	}
}

void User::addActorRating(Actor* actor, float rating) {
	actor->addRating(rating);
}

void User::displayActorRating(Actor* actor) {
	cout << "Average Rating: " << actor->getActorRating() << endl;
}

void User::displayActorRecommendation(LinkedList<Actor*>& actors) {
	cout << "Recommended actors:" << endl;
	for (int i = 0; i < actors.getLength(); ++i) {
		Actor* actor = actors.get(i);
		if (actor->getActorRating() >= 4.0) {
			cout << "- " << actor->getName() << " (Rating: " << actor->getActorRating() << ")" << endl;
		}
	}
}

void User::addMovieReport(Movie* movie, Report* report) {
	movie->addReport(report);
}

void User::addActorReport(Actor* actor, Report* report) {
	actor->addReport(report);
}

void User::displayActorInRange(LinkedList<Actor*>& actors, int minAge, int maxAge) {
    LinkedList<Actor*> filteredActors;

    //Filter actors within the age range
    for (int i = 0; i < actors.getLength(); ++i) {
        Actor* actor = actors.get(i);
        if (actor) {
            int age = actor->getAge();
            if (age >= minAge && age <= maxAge) {
                filteredActors.add(actor);
            }
        }
    }

    //Sort using Merge Sort
    filteredActors.sort([](Actor* a, Actor* b) {
        return a->getAge() < b->getAge();
    });

    //Display the sorted actors
    cout << "Actors in the age range [" << minAge << ", " << maxAge << "] in ascending order of age:" << endl;
    for (int i = 0; i < filteredActors.getLength(); ++i) {
        Actor* actor = filteredActors.get(i);
        cout << "- " << actor->getName() << " (Age: " << actor->getAge() << ")" << endl;
    }
}


void User::displayMoviesPast3Years(LinkedList<Movie*>& movies) {
    // Get the current year dynamically
    time_t t = time(nullptr); // Get current time
    tm now;
    localtime_s(&now, &t);// Convert to local time
    int currentYear = now.tm_year + 1900; // tm_year is years since 1900

	movies.sort([](Movie* a, Movie* b) {
		return a->getYearOfRelease() < b->getYearOfRelease();
	});

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

void User::displayMovieWithActor(Actor& actor) {
    LinkedList<Movie*>& movies = actor.getMovies();
    cout << "Movies featuring actor " << actor.getName() << ":" << endl;

	movies.sort([](Movie* a, Movie* b) {
		return a->getTitle() < b->getTitle();
	});

    for (int i = 0; i < movies.getLength(); ++i) {
        Movie* movie = movies.get(i);
        if (movie) {
            cout << "- " << movie->getTitle() << endl;
        }
    }
}

void User::displayAllActorsInMovie(Movie* movie) {
    if (!movie) {
        cout << "Invalid movie provided." << endl;
        return;
    }

    cout << "Actors in the movie " << movie->getTitle() << ":" << endl;
    movie->displayActors();
}

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