//		Created by Ivan Tsuman and Denys Vynokurov
//					Rush00, Piscine CPP

#ifndef ENEMYBIG_CLASS_HPP
# define ENEMYBIG_CLASS_HPP

// #include "AllObjects.class.hpp"
// #include <iostream>

#include "ft_retro.hpp"

class EnemyBig : public AllObjects
{
public:
	EnemyBig();
	EnemyBig(int width, int height);
	EnemyBig(EnemyBig const &src);
	~EnemyBig();
	EnemyBig		&operator=(EnemyBig const &rhs);
	
};

#endif
