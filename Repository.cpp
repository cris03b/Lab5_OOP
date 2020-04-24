#include "Domain.cpp"
#include <iostream>
using namespace std;

class Repo {
public:
	Movie movies[100];
	Movie watchlist[100];
	int length = 10;
	int wlen = 0;
	
	Repo();

	Movie* create_list() {
		string titles[10] = { "Suicide Squad", "Titanic", "Pirates of the Caribbean", "Murder on the orient express", "Avatar", "The professor", "Dead Poets Society", "Frozen", "Joker", "I Origins" };
		string genres[10] = { "action", "drama", "action", "mystery", "SF", "comedy", "drama", "animation", "thriller", "thriller" };
		int years[10] = { 2016, 1997, 2017, 2017, 2009, 2018, 1989, 2013, 2019, 2014 };
		int likes[10] = { 10, 11, 9, 8, 7, 7, 10, 8, 9, 11 };
		CString trailers[10] = { "https://www.youtube.com/watch?v=CmRih_VtVAs", "https://www.youtube.com/watch?v=2e-eXJ6HgkQ", "https://www.youtube.com/watch?v=naQr0uTrH_s", "https://www.youtube.com/watch?v=Mq4m3yAoW8E", \
			"https://www.youtube.com/watch?v=5PSNL1qE6VY", "https://www.youtube.com/watch?v=IThXCpk3Oc4", "https://www.youtube.com/watch?v=4lj185DaZ_o",\
			"https://www.youtube.com/watch?v=R-cdIvgBCWY", "https://www.youtube.com/watch?v=zAGVQLHvwOY", "https://www.youtube.com/watch?v=Mk4briOLrTQ" };

		for (int i = 0; i < 10; i++) {
			Movie m(titles[i], genres[i], years[i], likes[i], trailers[i]);
			movies[i] = m;
		}

		return movies;
	}

	Movie* add_movie(Movie m, string option) {
		bool found = false;
		for (int i = 0; i < length; i++) {
			if (movies[i].getTitle() == m.getTitle() && movies[i].getYear() == m.getYear()) {
				found = true;
			}
		}
		if (!found && option == "admin") {
			movies[length] = m;
			length++;
			cout << "YAY! You just added " << m.getTitle() << " in the list!" << endl;
			return movies;
		}
		else if (!found && option == "user") {
			cout << "Sorry, the movie doesn't exist :(" << endl;
			return watchlist;
		}
		else if (found && option == "admin") {
			cout << "Sorry, the movie already exists..." << endl;
			return movies;
		}
		else if (found && option == "user") {
			bool wfound = false;
			for (int j = 0; j < wlen; j++) {
				if (watchlist[j].getTitle() == m.getTitle() && watchlist[j].getYear() == m.getYear()) {
					wfound = true;
				}
			}
			if (!wfound) {
				watchlist[wlen] = m;
				wlen++;
				cout << "YAY! You just added " << m.getTitle() << " in your watchlist!" << endl;
			}
			else {
				cout << "Oops... it seems like you really like this movie, because you wanted to add it again in your watchlist!" << endl;
			}
			return watchlist;
		}

	}


	Movie* delete_movie_list(Movie m) {
		bool found = false;
		for (int i = 0; i < length; i++) {
			if (movies[i].getTitle() == m.getTitle() && movies[i].getYear() == m.getYear()) {
				for (int j = i + 1;j < length;j++) {
					movies[i - 1] = movies[i];
				}
				length--;
				found = true;
				cout << "You just deleted the movie: " << m.getTitle() << " from the list! Hope you are happy..." << endl;
				break;
			}
		}
		if (!found) {
			cout << "The movie you wanted to delete was not in the list...Try to delete another movie, if you want to." << endl;
		}
		return movies;
	}

	Movie* delete_movie_watchlist(Movie m) {
		int found = -1;
		for (int i = 0; i < wlen; i++) {
			if (watchlist[i].getTitle() == m.getTitle() && watchlist[i].getYear() == m.getYear()) {
				found = i;
				break;
			}
		}
		if (found==-1) {
			cout << "The movie you wanted to delete was not in the list...Try to delete another movie, if you want to." << endl;
		}
		else {
			for (int j = found + 1;j < wlen;j++) {
				watchlist[j - 1] = watchlist[j];
			}
			wlen--;
			found = true;
			cout << "You just deleted the movie: " << m.getTitle() << " from the list! If you liked it, you can support them with a Like . If you didn't, sorry." << endl;
			cout << "Like/Not";
			string option;
			cin >> option;
			if (option == "Like") {
				for (int i = 0; i < length; i++) {
					if (movies[i].getTitle() == m.getTitle() && movies[i].getYear() == m.getYear()) {
						movies[i].setLikes(movies[i].getLikes() + 1);
						cout << "\nThank you for your support!";
						break;
					}
				}
			}
		}
		return movies;
	}

	Movie* edit_movie(string title, int year, string option) {
		bool found = false;
		if (option == "title") {
			for (int i = 0; i < length; i++) {
				if (movies[i].getTitle() == title || movies[i].getYear() == year) {
					string new_title;
					cin >> new_title;
					movies[i].setTitle(new_title);
					cout << "Great! You just updated the title!" << endl;
					found = true;
				}
			}
		}

		else if (option == "genre") {
			for (int i = 0; i < length; i++) {
				if (movies[i].getTitle() == title || movies[i].getYear() == year) {
					string new_genre;
					cin >> new_genre;
					movies[i].setGenre(new_genre);
					cout << "Great! You just updated the genre!" << endl;
					found = true;
				}
			}
		}

		else if (option == "year") {
			for (int i = 0; i < length; i++) {
				if (movies[i].getTitle() == title || movies[i].getYear() == year) {
					int new_year;
					cin >> new_year;
					movies[i].setYear(new_year);
					cout << "Great! You just updated the year!" << endl;
					found = true;
				}
			}
		}

		else if (option == "like") {
			for (int i = 0; i < length; i++) {
				if (movies[i].getTitle() == title || movies[i].getYear() == year) {
					int new_like;
					cin >> new_like;
					movies[i].setLikes(new_like);
					cout << "Great! You just updated the likes!" << endl;
					found = true;
				}
			}
		}

		/*else if (option == "trailer") {
			for (int i = 0; i < length; i++) {
				if (movies[i].getTitle() == title || movies[i].getYear() == year) {
					CString new_trailer;
					movies[i].setTrailer(new_trailer);
					cout << "Great! You just updated the likes!" << endl;
					found = true;
				}
			}
		}*/

		else {
			cout << "Sorry, the option is not valid :(" << endl;
		}
	}

};
