#include "Repository.cpp"
#include <string>
#include <Windows.h>
#include <atlstr.h>

class Controller {
public:
	Repo repo;
	Controller() {

	}

	void show_watchlist() {
		if (repo.wlen != 0) {
			cout << endl << "Here are all the movies from your watchlist:";
			for (int i = 0; i < repo.wlen; i++) {
				cout << "Title: " << repo.watchlist[i].getTitle() << ", Genre: " << repo.watchlist[i].getGenre() << \
					", Year: " << repo.watchlist[i].getYear() << ", Likes: " << repo.watchlist[i].getLikes() << endl;
			}
		}
		else {
			cout << endl << "Wow! You have seen all the movies from your watchlist" << endl << "The watchlist is now empty! Good job! :D" << endl;
		}
	}

	void find_movie(string genre) {
		bool found = false;
		for (int j = 0; j < repo.length; j++) {
			if (genre == repo.movies[j].getGenre()) {
				found = true;
				break;
			}
		}
		if (found) {
			cout << endl << "Here are the movies with that specific genre:";
			for (int i = 0; i < repo.length; i++) {
				if (repo.movies[i].getGenre() == genre) {
					cout << endl << "Title: " << repo.movies[i].getTitle() << ", Genre: " << repo.movies[i].getGenre() <<\
						", Year: " << repo.movies[i].getYear() << ", Likes: " << repo.movies[i].getLikes() << endl;
					ShellExecute(0, 0, repo.movies[i].getTrailer(), 0, 0, SW_SHOW);
					cout << endl << "So... Did you find that movie interesting?" << endl << \
						"If you did, hurry up before you don't forget its title! Add it to your watchlist! :D" << endl \
						<< "If not, don't worry. You'll find one you like, keep searching!" << endl;
					cout << endl << "Your choice" << endl << "Add/Continue/Exit: ";
					string choice;
					cin >> choice;
					if (choice == "Add") {
						repo.add_movie(repo.movies[i], "user");
					}
					else if (choice != "Continue") {
						break;
					}
				}
			}
			cout << endl << "That's all we have for you today, hope you found something you like!" << endl << "Come back later for new movies!" << endl;
		}

		else if (genre == "?") {
			cout << endl << "Here are all the movies that we have:" << endl;
			for (int i = 0; i < repo.length; i++) {
				cout << endl << "Title: " << repo.movies[i].getTitle() << ", Genre: " << repo.movies[i].getGenre() << \
					", Year: " << repo.movies[i].getYear() << ", Likes: " << repo.movies[i].getLikes() << endl;
				ShellExecute(0, 0, repo.movies[i].getTrailer(), 0, 0, SW_SHOW);
				cout << endl << "So... Did you find that movie interesting?" << endl << \
					"If you did, hurry up before you don't forget the title! Add it to your watchlist! :D" << endl \
					<< "If not, don't worry. You'll find one you like, keep searching!" << endl;
				cout << endl << "Your choice" << endl << "Add/Continue/Exit: ";
				string choice;
				cin >> choice;
				if (choice == "Add") {
					repo.add_movie(repo.movies[i], "user");
				}
				else if (choice != "Continue") {
					break;
				}
			}
			cout << endl << "That's all we have for you today, hope you found something you like!" << endl << "Come back later for new movies!" << endl;
		}

		else if (!found) {
			cout << endl << "Sorry, we don't have that movie genre :(" << endl;
		}
	}
};

