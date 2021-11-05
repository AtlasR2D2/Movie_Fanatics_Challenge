#include "Movie.h"
#include <string>
#include <iostream>

Movie::Movie(std::string name_x, std::string rating_x,int watched_x) 
: movie_name{name_x}, movie_rating{rating_x}, watched{watched_x}
{
//	std::cout << "Movie logged." << std::endl;
}

void Movie::increase_watch_cout(int num_times) {
	watched += num_times;
};