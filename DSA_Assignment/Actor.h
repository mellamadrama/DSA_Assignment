#pragma once


#include <string>
#include <vector>
using namespace std;

class Movie;

class Actor {
private:
    string name;
    int yearOfBirth;
    vector<Movie*> listOfMovies;
};