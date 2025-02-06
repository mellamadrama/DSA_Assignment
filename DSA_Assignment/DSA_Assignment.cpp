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

HashTable<Actor*> actorTable(20000);
HashTable<Movie*> movieTable(20000);
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
            if (actorTable.search(actorId) == nullptr) {  // Only insert if actor doesn't exist
                Actor* actor = new Actor(actorId, name, stoi(birth), 0.0f);
				actors.add(actor);
                actorTable.insert(actorId, actor);
            }
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
            Actor** actorPtr = actorTable.search(stol(actorId));
            Actor* actor = actorPtr ? *actorPtr : nullptr;

            Movie** moviePtr = movieTable.search(stol(movieId));
            Movie* movie = moviePtr ? *moviePtr : nullptr;

			cout << "Actor: " << stol(actorId) << " Movie: " << stol(movieId) << endl;

			cout << "Movie: " << movie->getTitle() << " ID: " << movie->getId() << endl;
			cout << "Actor: " << actor->getName() << " ID: " << actor->getId() << endl;

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
            cout << endl;
            continue;
        }

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
            cout << endl;
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

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 12) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid option. Please try again." << endl;
            cout << endl;
            continue;
        }

        if (choice == 1)
        {
            cout << endl;
            int x, y;
            cout << "Enter minimum age (x): ";
            cin >> x;
            while (cin.fail() || x < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter again: ";
                cin >> x;
            }

            cout << endl;
            cout << "Enter maximum age (y): ";
            cin >> y;
            while (cin.fail() || y < 0 || y < x) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter again: ";
                cin >> y;
            }

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
            for (int i = 0; i < actors.getLength(); ++i)
            {
                Actor* actor = actors.get(i);
                cout << i + 1 << "." << actor->getName() << endl;
            }
            cout << "Select an actor by index: ";

            int actorChoice;
            cin >> actorChoice;
            while (cin.fail() || actorChoice < 1 || actorChoice > actors.getLength()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter again: ";
                cin >> actorChoice;
            }

            cout << endl;
            user->displayMovieWithActor(*actors.get(actorChoice - 1));
            cout << endl;
        }
        else if (choice == 4)
        {
            cout << endl;
            for (int i = 0; i < movies.getLength(); ++i)
            {
                Movie* movie = movies.get(i);
                cout << i + 1 << ". " << movie->getTitle() << endl;
            }
            cout << "Select a movie by index: ";
         
            int movieChoice;
            cin >> movieChoice;
            while (cin.fail() || movieChoice < 1 || movieChoice > movies.getLength()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter again: ";
                cin >> movieChoice;
            }

            cout << endl;
            user->displayAllActorsInMovie(movies.get(movieChoice - 1));
            cout << endl;
        }
        else if (choice == 5)
        {
            cout << endl;
            for (int i = 0; i < actors.getLength(); ++i)
            {
                Actor* actor = actors.get(i);
                cout << i + 1 << ". " << actor->getName() << endl;
            }
            cout << "Select an actor by index: ";

            int actorChoice;
            cin >> actorChoice;
            while (cin.fail() || actorChoice < 1 || actorChoice > actors.getLength()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter again: ";
                cin >> actorChoice;
            }

            cout << endl;
            user->displayActorConnections(actors.get(actorChoice - 1));
            cout << endl;
        }
        else if (choice == 6) 
        {
            cout << endl;
            for (int i = 0; i < actors.getLength(); ++i)
            {
                Actor* actor = actors.get(i);
                cout << i + 1 << ". " << actor->getName() << endl;
            }
			cout << "Select an actor to rate: ";

			int actorChoice;
			cin >> actorChoice;
            while (cin.fail() || actorChoice < 1 || actorChoice > actors.getLength()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter again: ";
                cin >> actorChoice;
            }

            cout << endl;
			cout << "Enter rating for the actor: ";
			float rating;
			cin >> rating;
			while (cin.fail() || rating < 0.0f || rating > 5.0f) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid rating. Must be between 0 and 5. Please enter again: ";
				cin >> rating;
			}
			user->addActorRating(actors.get(actorChoice - 1), rating);
            cout << endl;
			user->displayActorRating(actors.get(actorChoice - 1));
            cout << endl;
        }
        else if (choice == 7) 
        {
            cout << endl;
            for (int i = 0; i < movies.getLength(); ++i)
            {
                Movie* movie = movies.get(i);
                cout << i + 1 << ". " << movie->getTitle() << endl;
            }
			cout << "Select a movie to rate: ";

            int movieChoice;
            cin >> movieChoice;
            while (cin.fail() || movieChoice < 1 || movieChoice > movies.getLength()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter again: ";
                continue;
            }

            cout << endl;
            cout << "Enter rating for the movie: ";
            float rating;
            cin >> rating;
            while (cin.fail() || rating < 0.0f || rating > 5.0f) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid rating. Must be between 0 and 5. Please enter again: ";
                cin >> rating;
            }

			user->addMovieRating(movies.get(movieChoice - 1), rating);
            cout << endl;
			user->displayMovieRating(movies.get(movieChoice - 1));
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
			string userName = user->getName();
            for (int i = 0; i < actors.getLength(); ++i)
            {
                Actor* actor = actors.get(i);
                cout << i + 1 << ". " << actor->getName() << endl;
            }
			cout << "Select an actor by index: ";

			int actorChoice;
			cin >> actorChoice;
            while (cin.fail() || actorChoice < 1 || actorChoice > actors.getLength()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter again: ";
                cin >> actorChoice;
            }

            cout << endl;
			string reportDescription;
			cout << "Enter report description: ";
			cin.ignore();
			getline(cin, reportDescription);
			Report* report = new Report(userName, reportDescription);
			user->addActorReport(actors.get(actorChoice - 1), report);
			cout << "Report added successfully." << endl;
            cout << endl;
        }
        else if (choice == 11)
        {
            cout << endl;
			string userName = user->getName();
            for (int i = 0; i < movies.getLength(); ++i)
            {
                Movie* movie = movies.get(i);
                cout << i + 1 << ". " << movie->getTitle() << endl;
            }
			cout << "Select a movie by index: ";

			int movieChoice;
			cin >> movieChoice;
            while (cin.fail() || movieChoice < 1 || movieChoice > movies.getLength()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter again: ";
                cin >> movieChoice;
            }

            cout << endl;
			string reportDescription;
			cout << "Enter report description: ";
			cin.ignore();
			getline(cin, reportDescription);
			Report* report = new Report(userName, reportDescription);
			user->addMovieReport(movies.get(movieChoice - 1), report);
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
        cout << "Select an option: ";

        int choice;
        cin >> choice;

        if (choice < 1 || choice > 8) {
            cout << choice << endl;
            cout << "Invalid option. Please try again." << endl;
            continue;
        }

        if (choice == 1)
        {
            string actorName;
            int yearOfBirth, id;
\
			cout << "Enter Actor ID: ";
			cin >> id;

            cout << "Enter actor name: ";
            cin.ignore();
            getline(cin, actorName);

            cout << "Enter year of birth: ";
            cin >> yearOfBirth;

            bool valid = admin->addActor(id, actors, actorName, yearOfBirth);
			if (valid)
			{
				cout << "Actor added successfully." << endl;
			}
        }
        else if (choice == 2) 
        {
            string title, plot;
            int yearOfRelease, id;

			cout << "Enter Movie ID: ";
			cin >> id;

            cout << "Enter movie title: ";
            cin.ignore();
            getline(cin, title);

            cout << "Enter plot: ";
            cin >> plot;

            cout << "Enter year of release: ";
            cin >> yearOfRelease;

			bool valid = admin->addMovie(id, movies, title, plot, yearOfRelease);
            if (valid)
            {
                cout << "Movie added successfully." << endl;
            }
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

            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);

            cout << "Enter new year of birth: ";
            cin >> newYearOfBirth;

            admin->updateActor(actor, newName, newYearOfBirth);
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

            cout << "Enter new title: ";
            cin.ignore();
            getline(cin, newTitle);

            cout << "Enter new plot: ";
            getline(cin, newPlot);

            cout << "Enter new year of release: ";
            cin >> newYearOfRelease;

            admin->updateMovie(movie, newTitle, newPlot, newYearOfRelease);
		}
		else if (choice == 6)
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
				cout << "Invalid choice. Returning to admin options." << endl;
				continue;
			}
			if (!admin->displayActorReports(actors.get(actorChoice - 1))) {
				cout << "No reports for this actor." << endl;
				continue;
			}
			cout << "Select Report to view/resolve: " << endl;
			int reportChoice;
			cin >> reportChoice;
			if (reportChoice < 1 || reportChoice > actors.get(actorChoice - 1)->getReportList().getLength()) {
				cout << "Invalid choice. Returning to admin options." << endl;
				continue;
			}
			admin->displayActorReport(actors.get(actorChoice - 1), actors.get(actorChoice - 1)->getReportList().get(reportChoice - 1));
			int resolveChoice;
			while (true) {
				cout << "1. Resolve Report" << endl;
				cout << "2. Return to Admin Options" << endl;
				cin >> resolveChoice;
				if (resolveChoice == 1) {
					actors.get(actorChoice - 1)->getReportList().get(reportChoice - 1)->resolveReport();
					cout << "Report resolved." << endl;
					break;
				}
				else if (resolveChoice == 2) {
					break; 
				}
				else {
					cout << "Invalid choice. Please try again." << endl;
                    cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
		}
		else if (choice == 7)
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
				cout << "Invalid choice. Returning to admin options." << endl;
				continue;
			}
			if (!admin->displayMovieReports(movies.get(movieChoice - 1))) {
				cout << "No reports for this movie." << endl;
				continue;
			}
			cout << "Select Report to view/resolve: " << endl;
			int reportChoice;
			cin >> reportChoice;
			if (reportChoice < 1 || reportChoice > movies.get(movieChoice - 1)->getReportList().getLength()) {
				cout << "Invalid choice. Returning to admin options." << endl;
				continue;
			}
			admin->displayMovieReport(movies.get(movieChoice - 1), movies.get(movieChoice - 1)->getReportList().get(reportChoice - 1));
			int resolveChoice;
            while (true) {
                cout << "1. Resolve Report" << endl;
                cout << "2. Return to Admin Options" << endl;
                cin >> resolveChoice;

                if (resolveChoice == 1) {
                    movies.get(movieChoice - 1)->getReportList().get(reportChoice - 1)->resolveReport();
                    cout << "Report resolved." << endl;
                    break;
                }
                else if (resolveChoice == 2) {
                    break;
                }
                else {
                    cout << "Invalid choice. Please try again." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
		}
        else if (choice == 8) 
        {
            break;
        }
    }
}