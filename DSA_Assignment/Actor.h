#pragma once


#include <string>
#include <vector>
using namespace std;

class Movie;

class Actor {
private:
    string name;
    int yearOfBirth;
    float rating;
    vector<Movie*> listOfMovies;

public:
    Actor(string name, int yearOfBirth, float rating);

    string getName() const;
    int getYearOfBirth() const;
    float getRating() const;

    void addMovie(Movie* movie) { listOfMovies.push_back(movie); }

    void displayMovies() const;

    int getAge() const;

    ~Actor() = default;
};