#include "Movies.h"
#include "Movie.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

void Movies::add_movie(std::string movie_name, std::string movie_rating, int watched)
{
	bool movie_exists {false};
	Movie movie_x {movie_name,movie_rating,watched};
	for (Movie movie:movie_list) {
		if (movie.movie_name == movie_name)	
		{
			movie_exists = true;
			break;
		}
	}
	if (movie_exists) {
			// movie already exists
			std::cout << "Movie already exists. You can increment the watch count instead. Would you like to increment the watch count for this movie (" << movie_x.movie_name << ")? (Y/N): ";
			std::string ans {};
			std::cin >> ans;
			if (ans == "Y")
			{
				increase_watch_count(movie_x.movie_name,movie_x.watched);
			}
	}
	else
	{
		movie_list.push_back(movie_x);
	}
};

void Movies::increase_watch_count(std::string movie_name,int num_times){
	bool movie_found {false};
	for (Movie &movie: movie_list) {
		if (movie.movie_name == movie_name) {
			movie_found = true;
			movie.increase_watch_cout(num_times);
			break;
		}
	}
	if (!movie_found) {
		std::cout << movie_name << " wasn't found in Movie List. Try adding the movie." << std::endl;
	}
	
};

void Movies::display_movies(){
	std::cout << "Movie List" << std::endl;
	if (movie_list.size() != 0) {
	for (const auto elem: movie_list)
		std::cout << "Movie: " << elem.movie_name << " | Movie Rating: " << elem.movie_rating << " | No. Times Watched: " << elem.watched << std::endl;
		
	}
	else {
		std::cout << "There are no listed movies." << std::endl;
	}
};