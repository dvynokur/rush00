//		Created by Ivan Tsuman and Denys Vynokurov
//					Rush00, Piscine CPP

#ifndef ENEMYSMALL_CLASS_HPP
# define ENEMYSMALL_CLASS_HPP

// #include "AllObjects.class.hpp"
// #include <iostream>

#include "ft_retro.hpp"

class EnemySmall : public AllObjects
{
public:
	EnemySmall();
	EnemySmall(int width, int height);
	EnemySmall(EnemySmall const &src);
	~EnemySmall();
	EnemySmall		&operator=(EnemySmall const &rhs);
	
};

#endif
