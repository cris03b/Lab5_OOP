#include "Repository.cpp"
#include <string>
#include <Windows.h>
#include <atlstr.h>

class Controller {
public:
	Repo repo;
	Controller();

	void show_movies();

	void show_watchlist(string genre) {
		if (genre != "") {
			cout << "Here are the movies with that specific genre" << endl;
			for (int i = 0; i < repo.length; i++) {
				if (repo.movies[i].getGenre() == genre) {
					cout << "Title: " << repo.movies[i].getTitle() << ", Genre: " << repo.movies[i].getGenre() <<\
						", Year: " << repo.movies[i].getYear() << ", Likes: " << repo.movies[i].getLikes() << endl;
					ShellExecute(0, 0, repo.movies[i].getTrailer(), 0, 0, SW_SHOW);
					cout << "So... Did you find that movie interesting?" << endl << \
						"If you did, hurry up before you don't forget the title! Add it to your watchlist! :D" << endl \
						<< "If not, don't worry. You'll find one you like, don't lose your hope!" << endl;
					cout << "Your choice" << endl << "Add/Continue: ";
					string choice;
					cin >> choice;
					if (choice == "Add") {
						repo.add_movie(repo.movies[i], "user");
					}
				}
			}
		}
		else {
			cout << "Here are all the movies that we have" << endl;
			for (int i = 0; i < repo.length; i++) {
				cout << "Title: " << repo.movies[i].getTitle() << ", Genre: " << repo.movies[i].getGenre() << \
					", Year: " << repo.movies[i].getYear() << ", Likes: " << repo.movies[i].getLikes() << endl;
				ShellExecute(0, 0, repo.movies[i].getTrailer(), 0, 0, SW_SHOW);
				cout << "So... Did you find that movie interesting?" << endl << \
					"If you did, hurry up before you don't forget the title! Add it to your watchlist! :D" << endl \
					<< "If not, don't worry. You'll find one you like, don't lose your hope!" << endl;
				cout << "Your choice" << endl << "Add/Continue: ";
				string choice;
				cin >> choice;
				if (choice == "Add") {
					repo.add_movie(repo.movies[i], "user");
				}
			}
		}
		cout << endl << "That's all we have for you today, hope you found something to watch!" << endl << "Come back later for new movies!" << endl;
	}
};