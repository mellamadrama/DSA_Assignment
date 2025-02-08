#pragma once
#include <string>
#include "User.h"
#include <ctime>
#include <iomanip>
using namespace std;

User::User(string name, int userId) {
    this->name = name;
    this->userId = userId;
}

void User::addMovieRating(Movie* movie, float rating) {
	if (!movie) {
		cout << "Movie not found." << endl;
		return;
	}

	movie->addRating(rating);
}

void User::displayMovieRating(Movie* movie) {
	if (!movie) {
		cout << "Movie not found." << endl;
		return;
	}

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
	if (!actor) {
		cout << "Actor not found." << endl;
		return;
	}

	actor->addRating(rating);
}

void User::displayActorRating(Actor* actor) {
	if (!actor) {
		return;
	}

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
	if (!movie) {
		cout << "Movie not found." << endl;
		return;
	}

	movie->addReport(report);
    cout << "Report added successfully." << endl;
}

void User::addActorReport(Actor* actor, Report* report) {
	if (!actor) {
		cout << "Actor not found." << endl;
		return;
	}

	actor->addReport(report);
    cout << "Report added successfully." << endl;
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

    // Display the sorted actors
    cout << "Actors in the age range [" << minAge << ", " << maxAge << "] in ascending order of age:" << endl;
    for (int i = 0; i < filteredActors.getLength(); ++i) {
        Actor* actor = filteredActors.get(i);
        cout << "- " << setw(25) << left << actor->getName() << " (Age: " << actor->getAge() << ")" << endl;
    }
}

void User::displayMoviesPast3Years(LinkedList<Movie*>& movies) {
    LinkedList<Movie*> filteredMovies;

    time_t t = time(nullptr); // Get current time
    tm now;
    localtime_s(&now, &t);// Convert to local time
    int currentYear = now.tm_year + 1900; // tm_year is years since 1900

    // Filter movies released in the past 3 years
    for (int i = 0; i < movies.getLength(); ++i) {
        Movie* movie = movies.get(i);
        if (movie) {
            int releaseYear = movie->getYearOfRelease();
            if (releaseYear >= currentYear - 3 && releaseYear <= currentYear) {
                filteredMovies.add(movie);
            }
        }
    }

    // Sort the filtered movies by year of release
    filteredMovies.sort([](Movie* a, Movie* b) {
        return a->getYearOfRelease() < b->getYearOfRelease();
        });

    // Display the sorted movies
    cout << "Movies released in the past 3 years:" << endl;
    for (int i = 0; i < filteredMovies.getLength(); ++i) {
        Movie* movie = filteredMovies.get(i);
        cout << "- " << setw(40) << left << movie->getTitle()
            << " (Year: " << movie->getYearOfRelease()
            << ", Rating: " << fixed << setprecision(1) << movie->getMovieRating() << ")"
            << endl;
    }
}

void User::displayMovieWithActor(Actor* actor) {
	if (!actor) {
		cout << "Actor not found." << endl;
		return;
	}

    actor->displayMovies();
}

void User::displayAllActorsInMovie(Movie* movie) {
	if (!movie) {
		cout << "Movie not found." << endl;
		return;
	}

    movie->displayActors();
}

void User::displayActorConnections(Actor* actor) {
	if (!actor) {
		cout << "Actor not found." << endl;
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
                if (connectedActor && connectedActor->getId() != actor->getId()) {
                    cout << "- " << connectedActor->getName() << endl;
                }
            }
        }
    }
}