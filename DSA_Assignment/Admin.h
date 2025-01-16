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

    Admin(string name, int adminId);

    string getName() const;
    int getAdminId() const;

    void addActor(vector<Actor*>& actors, const string& actorName, int yearOfBirth);

    void addMovie(vector<Movie*>& movies, const string& title, const string& plot, int yearOfRelease);

    void addActorToMovie(Movie* movie, Actor* actor);

    void updateActor(Actor* actor, const string& newName, int newYearOfBirth);

    void updateMovie(Movie* movie, const string& newTitle, const string& newPlot, int newYearOfRelease);

    void handleReport(const Report& report);

    ~Admin() = default;
};

