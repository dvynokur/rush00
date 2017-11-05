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
	bool			operator==(AllObjects &rhs);
	void			rewriting_xy(int x, int y);
	void			moving(void);
	void			removing(void);
	void			changing_xy(int x, int y);
	void			setAllX(int n);
	void			setAllY(int n);

	int				get_flag(void) const;
	int				get_lives(void) const;
	int				get_x7(void) const;
	int				get_x8(void) const;
	int				get_x9(void) const;
	int				get_x10(void) const;
	int				get_x11(void) const;
	int				get_x12(void) const;
	int				get_x13(void) const;
	int				get_y7(void) const;
	int				get_y8(void) const;
	int				get_y9(void) const;
	int				get_y10(void) const;
	int				get_y11(void) const;
	int				get_y12(void) const;
	int				get_y13(void) const;


	void			set_flag(int n);
	void			set_lives(int n);
	void			set_x7(int n);
	void			set_x8(int n);
	void			set_x9(int n);
	void			set_x10(int n);
	void			set_x11(int n);
	void			set_x12(int n);
	void			set_x13(int n);
	void			set_y7(int n);
	void			set_y8(int n);
	void			set_y9(int n);
	void			set_y10(int n);
	void			set_y11(int n);
	void			set_y12(int n);
	void			set_y13(int n);


	void			set_direction(int n);
	int				get_direction(void) const;

private:
	int				_flag;
	int				_x7;
	int				_x8;
	int				_x9;
	int				_x10;
	int				_x11;
	int				_x12;
	int				_x13;
	int				_y7;
	int				_y8;
	int				_y9;
	int				_y10;
	int				_y11;
	int				_y12;
	int				_y13;

	int				_lives;
	int				_direction;
};

#endif
