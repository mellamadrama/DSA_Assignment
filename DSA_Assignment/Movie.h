#pragma once

#include <string>
#include <vector>
using namespace std;

class Actor;

class Movie {
private:
    string title;
    string plot;
    int yearOfRelease;
    vector<Actor*> listOfActors;
};