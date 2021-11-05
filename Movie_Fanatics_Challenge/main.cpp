#include <iostream>
#include "Movies.h"
#include <string>
#include <algorithm>

int main(){
	Movies my_movies;
	
	bool exit_program {false};
	int ans_num {0};
	std::string movie_name {};
	std::string movie_rating {};
	bool rating_exists {false};
	std::string movie_ratings[] = {"G", "PG", "PG-13", "R"};
	int movie_watched {0};
	std::cout << "Welcome to the Movies List Program" << std::endl;
	while (!exit_program) {
		std::cout << "Select an option." << std::endl;
		std::cout << "1: Add a Movie." << std::endl;
		std::cout << "2: Increase Watched Count for a Movie." << std::endl;
		std::cout << "3: Display Movie List." << std::endl;
		std::cout << "4: Exit Program." << std::endl;
		std::cin >> ans_num;
		switch (ans_num) {
		case 1:
			std::cout << "What's the name of the movie: ";
			std::getline(std::cin >> std::ws,movie_name);
			rating_exists=false;
			while (!rating_exists) {
				std::cout << "What's the rating of the movie (G, PG, PG-13, R): ";
				std::getline(std::cin >> std::ws, movie_rating);
				for (auto elem: movie_ratings){
					if (elem == movie_rating) {
						rating_exists = true;
						break;
					}
				};
			if (!rating_exists)
				std::cout << "Please enter a valid rating." << std::endl;
			};
			std::cout << "How many times have you seen the movie: ";
			std::cin >> movie_watched;
			// Add Movie to Movies List
			my_movies.add_movie(movie_name,movie_rating,movie_watched);
			break;
		case 2:
			std::cout << "What movie have you watched?: ";
			std::getline(std::cin >> std::ws,movie_name);
			std::cout << "How many times have you seen it?: ";
			std::cin >> movie_watched;
			// Increment Movie watched count
			my_movies.increase_watch_count(movie_name,movie_watched);
			break;
		case 3:
			my_movies.display_movies();
			break;
		case 4:
			exit_program = true;
			break;
		default:
			std::cout << "Enter a valid option." << std::endl;
		}
	}
	
	return 0;
}