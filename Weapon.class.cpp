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

bool		Weapon::operator==(AllObjects &rhs)
{
	if (this->check_coords(this->_x, this->_y, rhs) ||
		this->check_coords(this->_x + 1, this->_y, rhs))
		return (1);
	else
		return (0);
}

bool		Weapon::operator==(EnemyBig &rhs)
{
	if (this->check_big_coords(this->_x, this->_y, rhs) ||
		this->check_big_coords(this->_x + 1, this->_y, rhs))
		return (1);
	else
		return (0);
}

bool		Weapon::check_big_coords(int x, int y, EnemyBig &src)
{
	if ((x == src.get_x1() && y == src.get_y1()) || (x == src.get_x2() && y == src.get_y2()) ||
		(x == src.get_x3() && y == src.get_y3()) || (x == src.get_x4() && y == src.get_y4()) || 
		(x == src.get_x5() && y == src.get_y5()) || (x == src.get_x6() && y == src.get_y6()) ||
		(x == src.get_x7() && y == src.get_y7()) || (x == src.get_x8() && y == src.get_y8()) ||
		(x == src.get_x9() && y == src.get_y9()) || (x == src.get_x10() && y == src.get_y10()) || 
		(x == src.get_x11() && y == src.get_y11()) || (x == src.get_x12() && y == src.get_y12()) ||
		(x == src.get_x13() && y == src.get_y13()))
		return (1);
	else
		return (0);
}


Weapon		&Weapon::operator=(Weapon const &rhs)
{
	if (this != &rhs)
	{
		setType(rhs.getType());
		set_x(rhs.get_x());
		set_y(rhs.get_y());
		set_f(1);
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
