#pragma once

#include <string>
#include <vector>
#include "Actor.h"
using namespace std;

class Actor;

class Movie {
private:
    string title;
    string plot;
    int yearOfRelease;
    float rating;
    vector<Actor*> listOfActors;

public:
    Movie(string title, string plot, int yearOfRelease, float rating);

    string getTitle() const;
    string getPlot() const;
    int getYearOfRelease() const;
    float getRating() const;

    void addActor(Actor* actor) { listOfActors.push_back(actor); }

    void displayActors() const;

    ~Movie() = default;
};