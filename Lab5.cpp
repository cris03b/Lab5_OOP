// lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <atlstr.h>
#include "Controller.cpp"
#include <sstream>
#include <string>

using namespace std;

int main()
{

	Controller cont;
	cont.repo.create_list();
	string mode, genre, title;
	int option, year;
	cout << "WELCOME! " << "Choose a side(mode):" << endl << "User/Admin: ";
	cin >> mode;
	if (mode == "User") {
		cout << endl << "Bored in the house? Well now you're in the right place! Let's get it started!" << endl << "You can..." << endl;
		while (true) {
			cout << endl << "1. Search movies by genre and add some in your watchlist" << endl << \
				"2. Delete the movie you already saw" << endl << \
				"3. See your watchlist" << endl << \
				"4. Exit";
			cout << endl << "Your option: ";
			cin >> option;
			//Uberpruft ob die Option ein Integer ist
			while (cin.fail()) {
				cout << "Please enter a valid option" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cout << endl << "Your option: ";
				cin >> option;
			}
			if (option == 1) {
				cout << endl << "Search movies" << endl << "Some ideas for genre: SF, comedy, drama, action, mystery, thriller..." << endl << \
					"Hint: If you didn't think of a specific genre, just type '?', and you'll see the entire list of movies" << endl;
				cout << "Genre: ";
				cin >> genre;
				cont.find_movie(genre);
			}
			else if (option == 2) {
				cout << endl << "Delete movies" << endl << \
					"Hint: If you watched the movie and want to delete it from the watchlist, just type its name and year" << endl;
				cout << "Title: ";
				cin >> title;
				cout << "Year: ";
				cin >> year;
				//Uberpruft ob das Yahr gultig ist
				while (cin.fail()) {
					cout << endl << "Please enter a valid year" << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Year: ";
					cin >> year;
				}
				// trebuie sa mai verificam si cazul in care lista e goala sau e doar un singur film 
				cont.repo.delete_movie_watchlist(title, year);
			}
			else if (option == 3) {
				cout << endl << "Your watchlist:" << endl;
				cont.show_watchlist();
				cout << endl;
			}
			else if (option == 4) {
				cout << endl << "So you're not bored anymore, great! We'll see you next time!" << endl;
				break;
			}
			else {
				cout << endl << "Please type a valid option!" << endl;
			}
		}
	}

	else if (mode == "Admin") {

	}

	else {
		cout << "Please choose a valid mode(side) and open the app again" << endl;
	}


	return 0;
}
