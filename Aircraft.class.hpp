//		Created by Ivan Tsuman and Denys Vynokurov
//					Rush00, Piscine CPP

#ifndef AIRCRAFT_CLASS_HPP
# define AIRCRAFT_CLASS_HPP

#include "AllObjects.class.hpp"
#include <iostream>

// #include "ft_retro.hpp"

class Aircraft : public AllObjects
{
public:
	Aircraft();
	Aircraft(int width, int height);
	Aircraft(Aircraft const &src);
	~Aircraft();
	Aircraft		&operator=(Aircraft const &rhs);
	int				get_lives(void) const;
	void			set_lives(int n);
private:
	int				_lives;
};

#endif
