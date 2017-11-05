//		Created by Ivan Tsuman and Denys Vynokurov
//					Rush00, Piscine CPP

#ifndef ALLOBJECTS_CLASS_HPP
# define ALLOBJECTS_CLASS_HPP

// # include "ft_retro.hpp"

class AllObjects
{
public:

// constructors and destructors:
	AllObjects();
	AllObjects(int width, int height);
	AllObjects(AllObjects const &src);
	~AllObjects();

// operators:
	AllObjects		&operator=(AllObjects const &rhs);

// functions:


// getters:
	char			getType(void) const;
	int				get_x1(void) const;
	int				get_x2(void) const;
	int				get_x3(void) const;
	int				get_x4(void) const;
	int				get_x5(void) const;
	int				get_x6(void) const;
	int				get_y1(void) const;
	int				get_y2(void) const;
	int				get_y3(void) const;
	int				get_y4(void) const;
	int				get_y5(void) const;
	int				get_y6(void) const;


// setters:

	void			setType(char c);
	void			set_x1(int n);
	void			set_x2(int n);
	void			set_x3(int n);
	void			set_x4(int n);
	void			set_x5(int n);
	void			set_x6(int n);
	void			set_y1(int n);
	void			set_y2(int n);
	void			set_y3(int n);
	void			set_y4(int n);
	void			set_y5(int n);
	void			set_y6(int n);

protected:
	char			_type;
	int				_x1;
	int				_x2;
	int				_x3;
	int				_x4;
	int				_x5;
	int				_x6;
	int				_y1;
	int				_y2;
	int				_y3;
	int				_y4;
	int				_y5;
	int				_y6;

};

#endif
