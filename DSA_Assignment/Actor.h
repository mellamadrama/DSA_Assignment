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

public:
    Actor(string name, int yearOfBirth);

    string getName() const;
    int getYearOfBirth() const;

    void addMovie(Movie* movie) { listOfMovies.push_back(movie); }

    void displayMovies() const;

    int getAge() const;

    ~Actor() = default;
};