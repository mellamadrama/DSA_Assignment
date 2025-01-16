#pragma once

#include <string>
#include "Actor.h"
#include "Movie.h"
#include "HashTable.h"
using namespace std;

class User {
private:
    string name;
    int userId;

public:

    User(string name, int userId);

    string getName() const { return name; }
    int getUserId() const { return userId; }

    void displayActorInRange(const vector<Actor*>& actors, int minAge, int maxAge) const;

    void displayMoviesInRange(const vector<Movie*>& movies) const;

    void displayMovieWithActor(const vector<Movie*>& movies, const string& actorName) const;

    void displayAllActorsInMovie(const Movie* mvoie) const;

    void displayActorConnections(const Actor* actor) const;

    ~User() = default;
};