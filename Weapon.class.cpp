//		Created by Ivan Tsuman and Denys Vynokurov
//					Rush00, Piscine CPP

#include "ft_retro.hpp"
// #include "Weapon.class.hpp"

Weapon::Weapon(void)
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

Weapon::Weapon(int x, int y)
{
	setType('-');
	this->_x = x;
	this->_y = y;
	this->_f = 1;
	return ;
}

Weapon::Weapon(Weapon const &src) {
	*this = src;
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

Weapon		&Weapon::operator=(Weapon const &rhs)
{
	if (this != &rhs)
	{
		setType(rhs.getType());
		set_x(rhs.get_x());
		set_y(rhs.get_y());
		set_f(rhs.get_f());

		// set_x1(rhs.get_x1());
		// set_x2(rhs.get_x2());
		// set_x3(rhs.get_x3());
		// set_x4(rhs.get_x4());
		// set_x5(rhs.get_x5());
		// set_x6(rhs.get_x6());
		// set_y1(rhs.get_y1());
		// set_y2(rhs.get_y2());
		// set_y3(rhs.get_y3());
		// set_y4(rhs.get_y4());
		// set_y5(rhs.get_y5());
		// set_y6(rhs.get_y6());
	}
	return (*this);
}

int		Weapon::get_f(void) const {
	return (this->_f);
}

int		Weapon::get_x(void) const {
	return (this->_x);
}
int		Weapon::get_y(void) const {
	return (this->_y);
}

void	Weapon::set_x(int n) {
	this->_x = n;
	return ;
}
void	Weapon::set_y(int n) {
	this->_y = n;
	return ;
}
void	Weapon::set_f(int n) {
	this->_f = n;
	return ;
}
