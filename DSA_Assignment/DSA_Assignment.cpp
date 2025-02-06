#include "Movie.h"
#include "Admin.h"
#include "User.h"
#include "Actor.h"
#include "Report.h"
#include "LinkedList.h"
#include "HashTable.h"
#include "Global.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

HashTable<Actor*> actorTable(29989);
HashTable<Movie*> movieTable(29989);
template<>
HashTable<Actor*>* hashTable<Actor*> = new HashTable<Actor*>(20000);

template<>
HashTable<Movie*>* hashTable<Movie*> = new HashTable<Movie*>(20000);

template<>
HashTable<User*>* hashTable<User*> = new HashTable<User*>(20000);

template<>
HashTable<Admin*>* hashTable<Admin*> = new HashTable<Admin*>(20000);

template<>
HashTable<Report*>* hashTable<Report*> = new HashTable<Report*>(20000);

template<>
HashTable<float>* hashTable<float> = new HashTable<float>(20000);

void clearInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidIntInput(const string& prompt, int minValue = 0) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail() || input < minValue) {
            clearInputStream();
            cout << "Invalid input. Please try again." << endl;
        }
        else {
            return input;
        }
    }
}

float getValidFloatInput(const string& prompt, float minValue = 0.0f, float maxValue = 5.0f) {
    float input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail() || input < minValue || input > maxValue) {
            clearInputStream();
            cout << "Invalid input. Please enter a value between " << minValue << " and " << maxValue << "." << endl;
        }
        else {
            return input;
        }
    }
}

string getValidStringInput(const string& prompt) {
    string input;
    cout << prompt;
    cin.ignore();
    getline(cin, input);
    return input;
}

void loadCSVData(LinkedList<Actor*>& actors, LinkedList<Movie*>& movies, HashTable<Actor*>& actorTable, HashTable<Movie*>& movieTable){
    ifstream actorsFile("actors.csv");
    ifstream moviesFile("movies.csv");
    ifstream castFile("cast.csv");

    if (actorsFile.is_open()) {
        string line;
        getline(actorsFile, line);  // Skip header
        while (getline(actorsFile, line)) {
            stringstream ss(line);
            string id, name, birth, rating;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, birth, ',');

            int actorId = stoi(id);
            //if (actorTable.search(actorId) == nullptr) {  // Only insert if actor doesn't exist
                Actor* actor = new Actor(actorId, name, stoi(birth), 0.0f);
				actors.add(actor);
                actorTable.insert(actorId, actor);
            //}
        }
        actorsFile.close();
    }

    // Load Movies
    if (moviesFile.is_open()) {
        string line;
        getline(moviesFile, line);

        while (getline(moviesFile, line)) {
            stringstream ss(line);
            string id, title, plot, year, temp;

            getline(ss, id, ',');

            title = "";
            while (getline(ss, temp, ',')) {
                if (ss.peek() == EOF) {
                    year = temp;
                    break;
                }
                if (plot.empty()) {
                    plot = temp;
                }
                else {
                    if (!title.empty()) title += ",";
                    title += plot;
                    plot = temp;
                }
            }

            int movieId = stoi(id);
			Movie* movie = new Movie(movieId, title, plot, stoi(year), 0.0f);
			movies.add(movie);
            movieTable.insert(movieId, movie);
        }
        moviesFile.close();
    }
    else {
        cout << "Error opening movie file!" << endl;
    }


    if (castFile.is_open()) {
        string line;
        getline(castFile, line);  // Skip header

        while (getline(castFile, line)) {
            stringstream ss(line);
            string actorId, movieId;
            getline(ss, actorId, ',');
            getline(ss, movieId, ',');

            // Find actor and movie by Id
            Actor* actor = actorTable.search(stol(actorId));
            Movie* movie = movieTable.search(stol(movieId));

            // Link movie with actor
            if (actor && movie) {
                actor->addMovie(movie);
                movie->addActor(actor);
            }
        }
        castFile.close();

    }
}

// Predefined user and admin lists
LinkedList<User*> createUserList() {
    LinkedList<User*> userList;
    userList.add(new User("Hervin", 001));
    userList.add(new User("Bob Lim", 002));
    userList.add(new User("Charlie Lee", 003));
    return userList;
}

LinkedList<Admin*> createAdminList() {
    LinkedList<Admin*> adminList;
    adminList.add(new Admin("Hervin", 102));
    adminList.add(new Admin("Jane Doe", 100));
    adminList.add(new Admin("John Doe", 101));
    return adminList;
}

void displayMainMenu();
void userOptions(User* user, LinkedList<Actor*>& actors, LinkedList<Movie*>& movies);
void adminOptions(Admin* admin, LinkedList<Actor*>& actors, LinkedList<Movie*>& movies);

void displayMainMenu()
{
    cout << "Welcome to the Movie Fun System!" << endl;
    cout << "1. Login as User" << endl;
    cout << "2. Login as Admin" << endl;
    cout << "3. Exit" << endl;
    cout << "Please select an option: ";
}

int main()
{
    LinkedList<Actor*> actors;
    LinkedList<Movie*> movies;

    loadCSVData(actors, movies, actorTable, movieTable);

    actorTable.getCapacity();
    movieTable.getCapacity();

    // Initialize linked lists
    LinkedList<User*> userList = createUserList();
    LinkedList<Admin*> adminList = createAdminList();

    while (true)
    {
        displayMainMenu();
        int choice = getValidIntInput("", 1);

        if (choice == 1)
        {
            cout << endl;
            cout << "Enter your full name: ";
            cin.ignore();
            string fullName;
            getline(cin, fullName);

            User* selectedUser = nullptr;
            for (int i = 0; i < userList.getLength(); ++i) 
            {
                if (userList.get(i)->getName() == fullName) 
                {
                    selectedUser = userList.get(i);
                    break;
                }
            }

            if (selectedUser)
            {
                userOptions(selectedUser, actors, movies);
            }
            else
            {
                cout << "User not found. Returning to main menu." << endl;
                cout << endl;
            }
        }
        else if (choice == 2) 
        {
            string fullName = getValidStringInput("Enter your full name: ");
            Admin* selectedAdmin = nullptr;
            for (int i = 0; i < adminList.getLength(); ++i)
            {
                if (adminList.get(i)->getName() == fullName)
                {
                    selectedAdmin = adminList.get(i);
                    break;
                }
            }

            if (selectedAdmin) 
            {
                adminOptions(selectedAdmin, actors, movies);
            }
            else
            {
                cout << "Admin not found. Returning to main menu." << endl;
                cout << endl;
            }
        }
        else if (choice == 3)
        {
            cout << endl;
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        }
    }

    return 0;
}

void userOptions(User* user, LinkedList<Actor*>& actors, LinkedList<Movie*>& movies)
{
    cout << endl;
    cout << "Welcome, " << user->getName() << "!" << endl;
    while (true)
    {
        cout << "1. Display actors by age range (ascending order)" << endl;
        cout << "2. Display movies made within the past 3 years (ascending order of year)" << endl;
        cout << "3. Display all movies an actor starred in (alphabetical order)" << endl;
        cout << "4. Display all actors in a particular movie (alphabetical order)" << endl;
        cout << "5. Display a list of all actors that a particular actor knows" << endl;
        cout << "6. Rate an actor" << endl;
        cout << "7. Rate a movie" << endl;
        cout << "8. Get movie recommendation" << endl;
        cout << "9. Get actor recommendation" << endl;
        cout << "10. Report actor info error" << endl;
        cout << "11. Report movie info error" << endl;
        cout << "12. Logout" << endl;
        cout << "Select an option: ";

        int choice = getValidIntInput("Select an option: ", 1);
		if (choice < 1 || choice > 12)
		{
			cout << "Invalid choice. Please try again." << endl;
			continue;
		}

        if (choice == 1)
        {
            cout << endl;
            int x = getValidIntInput("Enter minimum age (x): ", 0);
            int y = getValidIntInput("Enter maximum age (y): ", x);
            cout << endl;
            user->displayActorInRange(actors, x, y);
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << endl;
            user->displayMoviesPast3Years(movies);
            cout << endl;
        }
        else if (choice == 3)
        {
            cout << endl;
            int idChoice = getValidIntInput("Enter an actor by actor id: ");
            cout << endl;
            user->displayMovieWithActor(*actors.getById(idChoice));
            cout << endl;
        }
        else if (choice == 4)
        {
            cout << endl;
            int idChoice = getValidIntInput("Enter a movie by movie id: ");
            cout << endl;
            user->displayAllActorsInMovie(movies.getById(idChoice));
            cout << endl;
        }
        else if (choice == 5)
        {
            cout << endl;
            int idChoice = getValidIntInput("Enter an actor by actor id: ");
            cout << endl;
            user->displayActorConnections(actors.getById(idChoice));
            cout << endl;
        }
        else if (choice == 6)
        {
            cout << endl;
            int idChoice = getValidIntInput("Enter an actor id to rate: ");
            float rating = getValidFloatInput("Enter rating for the actor: ");
            user->addActorRating(actors.getById(idChoice), rating);
            cout << endl;
            user->displayActorRating(actors.getById(idChoice));
            cout << endl;
        }
        else if (choice == 7)
        {
            cout << endl;
            int idChoice = getValidIntInput("Enter a movie id to rate: ");
            float rating = getValidFloatInput("Enter rating for the movie: ");
            user->addMovieRating(movies.getById(idChoice), rating);
            cout << endl;
            user->displayMovieRating(movies.getById(idChoice));
            cout << endl;
        }
        else if (choice == 8)
        {
            cout << endl;
            user->displayMovieRecommendation(movies);
            cout << endl;
        }
        else if (choice == 9)
        {
            cout << endl;
            user->displayActorRecommendation(actors);
            cout << endl;
        }
        else if (choice == 10)
        {
            cout << endl;
            int idChoice = getValidIntInput("Enter an actor id: ");
            string reportDescription = getValidStringInput("Enter report description: ");
            Report* report = new Report(user->getName(), reportDescription);
            user->addActorReport(actors.getById(idChoice), report);
            cout << "Report added successfully." << endl;
            cout << endl;
        }
        else if (choice == 11)
        {
            cout << endl;
            int idChoice = getValidIntInput("Enter a movie id: ");
            string reportDescription = getValidStringInput("Enter report description: ");
            Report* report = new Report(user->getName(), reportDescription);
            user->addMovieReport(movies.getById(idChoice), report);
            cout << "Report added successfully." << endl;
            cout << endl;
        }
        else if (choice == 12)
        {
            cout << endl;
            break;
        }
    }
}

void adminOptions(Admin* admin, LinkedList<Actor*>& actors, LinkedList<Movie*>& movies)
{
    cout << endl;
    cout << "Welcome, Admin " << admin->getName() << "!" << endl;
    while (true)
    {
        cout << "1. Add new actor" << endl;
        cout << "2. Add new movie" << endl;
        cout << "3. Add an actor to a movie" << endl;
        cout << "4. Update actor details" << endl;
        cout << "5. Update movie details" << endl;
        cout << "6. View Actor Reports" << endl;
        cout << "7. View Movie Reports" << endl;
        cout << "8. Logout" << endl;

        int choice = getValidIntInput("Select an option: ", 1);
		if (choice < 1 || choice > 8)
		{
			cout << "Invalid choice. Please try again." << endl;
			continue;
		}

        if (choice == 1)
        {
            cout << endl;
            int id = getValidIntInput("Enter Actor ID: ");
            string actorName = getValidStringInput("Enter actor name: ");
            int yearOfBirth = getValidIntInput("Enter year of birth: ", 1900);
            if (admin->addActor(id, actors, actorName, yearOfBirth))
                cout << "Actor added successfully." << endl;
        }
        else if (choice == 2)
        {
            int id = getValidIntInput("Enter Movie ID: ");
            string title = getValidStringInput("Enter movie title: ");
            string plot = getValidStringInput("Enter plot: ");
            int yearOfRelease = getValidIntInput("Enter year of release: ", 1900);
            if (admin->addMovie(id, movies, title, plot, yearOfRelease))
                cout << "Movie added successfully." << endl;
        }
        else if (choice == 3)
        {
            int movieId = getValidIntInput("Enter a movie id: ");
            int actorId = getValidIntInput("Enter an actor id: ");
            admin->addActorToMovie(movies.getById(movieId), actors.getById(actorId));
        }
        else if (choice == 4)
        {
            int idChoice = getValidIntInput("Enter an actor id: ");
            string newName = getValidStringInput("Enter new name: ");
            int newYearOfBirth = getValidIntInput("Enter new year of birth: ", 1900);
            admin->updateActor(actors.getById(idChoice), newName, newYearOfBirth);
        }
        else if (choice == 5)
        {
            int idChoice = getValidIntInput("Enter a movie id: ");
            string newTitle = getValidStringInput("Enter new title: ");
            string newPlot = getValidStringInput("Enter new plot: ");
            int newYearOfRelease = getValidIntInput("Enter new year of release: ", 1900);
            admin->updateMovie(movies.getById(idChoice), newTitle, newPlot, newYearOfRelease);
        }
        else if (choice == 6)
        {
            int idChoice = getValidIntInput("Enter an actor id: ");
            admin->displayActorReports(actors.getById(idChoice));
        }
        else if (choice == 7)
        {
            int idChoice = getValidIntInput("Enter a movie id: ");
            admin->displayMovieReports(movies.getById(idChoice));
        }
        else if (choice == 8)
        {
            break;
        }
    }
}