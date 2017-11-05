//		Created by Ivan Tsuman and Denys Vynokurov
//					Rush00, Piscine CPP

#include "ft_retro.hpp"
// #include "EnemySmall.class.hpp"

EnemySmall::EnemySmall(void)
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

EnemySmall::EnemySmall(int width, int height)
{
	int		r;

	r = rand () % height;
	if (r == 0)
		r += 3;
	else if (r > height - 3)
		r -= 6;
	setType('#');
	set_x1(width - 1);
	set_y1(r + 1);
	set_x2(width - 1);
	set_y2(r);
	set_x3(width - 1);
	set_y3(r - 1);
	set_x4(width);
	set_y4(r + 1);
	set_x5(width);
	set_y5(r - 1);
	set_x6(width + 1);
	set_y6(r);
	set_flag(0);
}

EnemySmall::EnemySmall(EnemySmall const &src) {
	*this = src;
	return ;
}

EnemySmall::~EnemySmall(void)
{
	return ;
}

EnemySmall		&EnemySmall::operator=(EnemySmall const &rhs)
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
		set_flag(rhs.get_flag());
	}
	return (*this);
}

void			EnemySmall::rewriting_xy(int x, int y)
{
	this->set_x1(x - 1);
	this->set_x2(x - 1);
	this->set_x3(x - 1);
	this->set_x4(x);
	this->set_x5(x);
	this->set_x6(x + 1);

	this->set_y1(y + 1);
	this->set_y2(y);
	this->set_y3(y - 1);
	this->set_y4(y + 1);
	this->set_y5(y - 1);
	this->set_y6(y);
	this->set_flag(0);
}

void			EnemySmall::set_flag(int n) {
	this->_flag = n;
	return ;
}
int				EnemySmall::get_flag(void) const {
	return (this->_flag);
}




