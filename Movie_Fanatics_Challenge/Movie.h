#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <vector>
#include <string>

class Movie
{
private:
friend class Movies;
std::string movie_name {};
std::string movie_rating {};
int watched {0};
public:
	// Constructor
	Movie(std::string name_x,std::string rating_x,int watched_x);
	void increase_watch_cout(int num_times);
};



#endif // _MOVIE_H_
