//		Created by Ivan Tsuman and Denys Vynokurov
//					Rush00, Piscine CPP

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

// #include "AllObjects.class.hpp"
// #include <iostream>

#include "ft_retro.hpp"

class Weapon : public AllObjects
{
public:
	Weapon();
	Weapon(int x, int y);
	Weapon(Weapon const &src);
	~Weapon();
	Weapon		&operator=(Weapon const &rhs);

	int		get_x(void) const;
	int		get_y(void) const;
	int		get_f(void) const;

	void	set_x(int n);
	void	set_y(int n);
	void	set_f(int n);
private:
	int		_x;
	int		_y;
	int		_f;
	
};

#endif
