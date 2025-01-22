#include "Movie.h"
#include "Admin.h"
#include "User.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void loadCSVData(LinkedList<Actor*>& actors, LinkedList<Movie*>& movies) {
    ifstream actorsFile("actors.csv");
    ifstream moviesFile("movies.csv");
    ifstream castFile("cast.csv");

    // Load Actors
    if (actorsFile.is_open()) {
        string line;
        getline(actorsFile, line);
        while (getline(actorsFile, line)) {
            stringstream ss(line);
            string id, name, birth;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, birth, ',');

            actors.add(new Actor(name, stoi(birth), 0.0f));
        }
        actorsFile.close();
    }

    // Load Movies
    if (moviesFile.is_open()) {
        string line;
        getline(moviesFile, line);
        while (getline(moviesFile, line)) {
            stringstream ss(line);
            string id, title, plot, year;
            getline(ss, id, ',');
            getline(ss, title, ',');
            getline(ss, plot, ',');
            getline(ss, year, ',');

			cout << title << " " << year << endl;

            movies.add(new Movie(title, plot, stoi(year), 0.0f));
        }
        moviesFile.close();
    }

    if (castFile.is_open()) {
        string line;
		getline(castFile, line);
        while (getline(castFile, line)) {
            stringstream ss(line);
            string person_id, movie_id;
            getline(ss, person_id, ',');
            getline(ss, movie_id, ',');

            // Find actor and movie by Id
            // Link actor and movie objects
        }
        castFile.close();
    }
}

// Predefined user and admin lists
LinkedList<User> createUserList() {
    LinkedList<User> userList;
    userList.add(User("Alice Tan", 001));
    userList.add(User("Bob Lim", 002));
    userList.add(User("Charlie Lee", 003));
    return userList;
}

LinkedList<Admin> createAdminList() {
    LinkedList<Admin> adminList;
    adminList.add(Admin("Jane Doe", 100));
    adminList.add(Admin("John Doe", 101));
    return adminList;
}

int main()
{
    LinkedList<Actor*> actors;
    LinkedList<Movie*> movies;

    loadCSVData(actors, movies);

    // Initialize linked lists
    LinkedList<User> userList = createUserList();
    LinkedList<Admin> adminList = createAdminList();
}
