//		Created by Ivan Tsuman and Denys Vynokurov
//					Rush00, Piscine CPP

#include "ft_retro.hpp"
// #include "EnemyBig.class.hpp"

EnemyBig::EnemyBig(void)
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

EnemyBig::EnemyBig(int width, int height)
{
	int		r;

	r = rand () % height;
	if (r == 0)
		r += 3;
	else if (r == height)
		r -= 3;
	setType('#');
	set_x1(width - 1);
	set_y1(r - 1);
	set_x2(width);
	set_y2(r);
	set_x3(width);
	set_y3(r - 1);
	set_x4(width + 1);
	set_y4(r + 1);
	set_x5(width + 1);
	set_y5(r);
	set_x6(width + 1);
	set_y6(r - 1);
	std::cout << "EnemyBig constructor called" << std::endl;
}

EnemyBig::EnemyBig(EnemyBig const &src) {
	*this = src;
	return ;
}

EnemyBig::~EnemyBig(void)
{
	return ;
}

EnemyBig		&EnemyBig::operator=(EnemyBig const &rhs)
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
	}
	return (*this);
}
