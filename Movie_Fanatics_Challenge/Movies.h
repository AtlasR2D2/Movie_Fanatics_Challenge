#ifndef MOVIES_H
#define MOVIES_H
#include "Movie.h"

class Movies
{
private:
	std::vector<Movie> movie_list;
public:
	void add_movie(std::string movie_name, std::string movie_rating, int watched);
	void increase_watch_count(std::string movie_name,int num_times);
	void display_movies();
	
};

#endif // MOVIES_H
