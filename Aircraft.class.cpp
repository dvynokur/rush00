//		Created by Ivan Tsuman and Denys Vynokurov
//					Rush00, Piscine CPP

#include "ft_retro.hpp"
// #include "Aircraft.class.hpp"

Aircraft::Aircraft(void)
{
	setType(0);
	set_x1(0);
	set_y1(0);
	set_x2(0);
	set_y2(0);
	set_x3(0);
	set_y3(0);
	set_x4(0);
	set_y4(0);
	set_x5(0);
	set_y5(0);
	set_x6(0);
	set_y6(0);
	return ;
}

Aircraft::Aircraft(int width, int height)
{
	setType('>');
	set_x1(1);
	set_y1(height / 2);
	set_x2(2);
	set_y2(height / 2 + 1);
	set_x3(2);
	set_y3(height / 2);
	set_x4(2);
	set_y4(height / 2 - 1);
	set_x5(3);
	set_y5(height / 2);
	set_x6(4);
	set_y6(height / 2);
	set_lives(3);
	// std::cout << "Aircraft constructor called" << std::endl;
}

Aircraft::Aircraft(Aircraft const &src) {
	*this = src;
	return ;
}

Aircraft::~Aircraft(void)
{
	return ;
}

Aircraft		&Aircraft::operator=(Aircraft const &rhs)
{
	if (this != &rhs)
	{
		setType(rhs.getType());
		set_x1(rhs.get_x1());
		set_x2(rhs.get_x2());
		set_x3(rhs.get_x3());
		set_x4(rhs.get_x4());
		set_x5(rhs.get_x5());
		set_x6(rhs.get_x6());
		set_y1(rhs.get_y1());
		set_y2(rhs.get_y2());
		set_y3(rhs.get_y3());
		set_y4(rhs.get_y4());
		set_y5(rhs.get_y5());
		set_y6(rhs.get_y6());
		set_lives(rhs.get_lives());
	}
	return (*this);
}

int				Aircraft::get_lives(void) const {
	return (this->_lives);
}
void			Aircraft::set_lives(int n) {
	this->_lives = n;
	return ;
}
