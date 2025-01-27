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
LinkedList<User*> createUserList() {
    LinkedList<User*> userList;
    userList.add(new User("Alice Tan", 001));
    userList.add(new User("Bob Lim", 002));
    userList.add(new User("Charlie Lee", 003));
    return userList;
}

LinkedList<Admin*> createAdminList() {
    LinkedList<Admin*> adminList;
    adminList.add(new Admin("Jane Doe", 100));
    adminList.add(new Admin("John Doe", 101));
    return adminList;
}

void displayMainMenu();
void userOptions(User* user, LinkedList<Actor*>& actors, LinkedList<Movie*>& movies);
void adminOptions(Admin* admin, LinkedList<Actor*>& actors, LinkedList<Movie*>& movies);

void displayMainMeu()
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

    loadCSVData(actors, movies);

    // Initialize linked lists
    LinkedList<User*> userList = createUserList();
    LinkedList<Admin*> adminList = createAdminList();

    while (true)
    {
        displayMainMenu();
        int choice;
        cin >> choice;

        if (cin.fail() || (choice < 1 || choice > 3))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        if (choice == 1)
        {
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
            }
        }
        else if (choice == 2) 
        {
            cout << "Enter your full name: ";
            cin.ignore();
            string fullName;
            getline(cin, fullName);

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
            }
        }
        else if (choice == 3)
        {
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        }
    }

    return 0;
}

void userOptions(User* user, LinkedList<Actor*>& actors, LinkedList<Movie*>& movies)
{
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
        cout << "12. Back to Main Menu" << endl;
        cout << "Select an option: ";

        int choice;
        cin >> choice;

        if (choice < 1 || choice > 10)
        {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }

        if (choice == 1)
        {
            int x, y;
            cout << "Enter minimum age (x): ";
            cin >> x;
            cout << "Enter maximum age (y): ";
            cin >> y;
            user->displayActorInRange(actors, x, y);
        }
        else if (choice == 2)
        {
            user->displayMoviesInRange(movies);
        }
        else if (choice == 3)
        {
            cout << "Select an actor by index: " << endl;
            for (int i = 0; i < actors.getLength(); ++i)
            {
                Actor* actor = actors.get(i);
                cout << i + 1 << "." << actor->getName() << endl;
            }

            int actorChoice;
            cin >> actorChoice;

            if (actorChoice < 1 || actorChoice > actors.getLength()) {
                cout << "Invalid choice. Returning to user options." << endl;
                continue;
            }

            user->displayMovieWithActor(*actors.get(actorChoice - 1));
        }
        else if (choice == 4)
        {
            cout << "Select a movie by index: " << endl;
            for (int i = 0; i < movies.getLength(); ++i)
            {
                Movie* movie = movies.get(i);
                cout << i + 1 << ". " << movie->getTitle() << endl;
            }
            int movieChoice;
            cin >> movieChoice;

            if (movieChoice < 1 || movieChoice > movies.getLength()) {
                cout << "Invalid choice. Returning to user options." << endl;
                continue;
            }

            user->displayAllActorsInMovie(movies.get(movieChoice - 1));
        }
        else if (choice == 5)
        {
            cout << "Select an actor by index: " << endl;
            for (int i = 0; i < actors.getLength(); ++i)
            {
                Actor* actor = actors.get(i);
                cout << i + 1 << ". " << actor->getName() << endl;
            }

            int actorChoice;
            cin >> actorChoice;

            if (actorChoice < 1 || actorChoice > actors.getLength()) {
                cout << "Invalid choice. Returning to user options." << endl;
                continue;
            }

            user->displayActorConnections(actors.get(actorChoice - 1));
        }
        else if (choice == 6) 
        {
            //rateActor
        }
        else if (choice == 7) 
        {
            //rateMovie
        }
        else if (choice == 8) 
        {
            //getMovieRecommendation
        }
        else if (choice == 9) 
        {
            //getActorRecommendation(actors)
        }
        else if (choice == 10) 
        {
            //reportActorInfoError
        }
        else if (choice == 11)
        {
            //reportActorInfoError
        }
        else if (choice == 12) 
        {
            break;
        }
    }
}

void adminOptions(Admin* admin, LinkedList<Actor*>& actors, LinkedList<Movie*>& movies)
{
    cout << "Welcome, Admin " << admin->getName() << "!" << endl;
    while (true)
    {
        cout << "1. Add new actor" << endl;
        cout << "2. Add new movie" << endl;
        cout << "3. Add an actor to a movie" << endl;
        cout << "4. Update actor details" << endl;
        cout << "5. Update movie details" << endl;
        cout << "6. Back to Main Menu" << endl;
        cout << "Select an option: ";

        int choice;
        cin >> choice;

        if (choice < 1 || choice > 6) {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }

        if (choice == 1)
        {
            string actorName;
            int yearOfBirth;
            float rating;

            cout << "Enter actor name: ";
            cin.ignore();
            getline(cin, actorName);

            cout << "Enter year of birth: ";
            cin >> yearOfBirth;

            cout << "Enter rating: ";
            cin >> rating;

            admin->addActor(actors, actorName, yearOfBirth, rating);
        }
        else if (choice == 2) 
        {
            string title, plot;
            int yearOfRelease;
            float rating;

            cout << "Enter movie title: ";
            cin.ignore();
            getline(cin, title);

            cout << "Enter plot: ";
            cin >> plot;

            cout << "Enter year of release: ";
            cin >> yearOfRelease;

            cout << "Enter rating: ";
            cin >> rating;

            admin->addMovie(movies, title, plot, yearOfRelease, rating);
        }
        else if (choice == 3)
        {
            cout << "Select a movie by index: " << endl;
            for (int i = 0; i < movies.getLength(); ++i)
            {
                Movie* movie = movies.get(i);
                cout << i + 1 << ". " << movie->getTitle() << endl;
            }

            int movieChoice;
            cin >> movieChoice;

            if (movieChoice < 1 || movieChoice > movies.getLength()) {
                cout << "Invalid movie choice. Please try again." << endl;
                continue;
            }

            Movie* movie = movies.get(movieChoice - 1);
            cout << "Select an actor by index: " << endl;
            for (int i = 0; i < actors.getLength(); ++i)
            {
                Actor* actor = actors.get(i);
                cout << i + 1 << ". " << actor->getName() << endl;
            }

            int actorChoice;
            cin >> actorChoice;

            if (actorChoice < 1 || actorChoice > actors.getLength()) {
                cout << "Invalid actor choice. Please try again." << endl;
                continue;
            }

            admin->addActorToMovie(movie, actors.get(actorChoice - 1));
        }
        else if (choice == 4)
        {
            cout << "Select an actor by index: " << endl;
            for (int i = 0; i < actors.getLength(); ++i) {
                Actor* actor = actors.get(i);
                cout << i + 1 << ". " << actor->getName() << endl;
            }

            int actorChoice;
            cin >> actorChoice;

            if (actorChoice < 1 || actorChoice > actors.getLength()) {
                cout << "Invalid choice. Returning to admin options." << endl;
                continue;
            }

            Actor* actor = actors.get(actorChoice - 1);
            string newName;
            int newYearOfBirth;
            float newRating;

            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);

            cout << "Enter new year of birth: ";
            cin >> newYearOfBirth;

            cout << "Enter new rating: ";
            cin >> newRating;

            admin->updateActor(actor, newName, newYearOfBirth, newRating);
        }
        else if (choice == 5)
        {
            for (int i = 0; i < movies.getLength(); ++i) {
                Movie* movie = movies.get(i);
                cout << i + 1 << ". " << movie->getTitle() << endl;
            }
            int movieChoice;
            cin >> movieChoice;

            if (movieChoice < 1 || movieChoice > movies.getLength()) {
                cout << "Invalid movie choice. Returning to admin options." << endl;
                continue;
            }

            Movie* movie = movies.get(movieChoice - 1);
            string newTitle, newPlot;
            int newYearOfRelease;
            float newRating;

            cout << "Enter new title: ";
            cin.ignore();
            getline(cin, newTitle);

            cout << "Enter new plot: ";
            getline(cin, newPlot);

            cout << "Enter new year of release: ";
            cin >> newYearOfRelease;

            cout << "Enter new rating: ";
            cin >> newRating;

            admin->updateMovie(movie, newTitle, newPlot, newYearOfRelease, newRating);
        }
        else if (choice == 6) 
        {
            break;
        }
    }
}