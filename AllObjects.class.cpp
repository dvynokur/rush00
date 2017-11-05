//		Created by Ivan Tsuman and Denys Vynokurov
//					Rush00, Piscine CPP

// #include "ft_retro.hpp"
#include "AllObjects.class.hpp"
#include <iostream>
//constructors and destructor

AllObjects::AllObjects(void) {
	return ;
}

AllObjects::AllObjects(int width, int height)
{
	setType('>');
	set_x1(0);
	set_y1(height / 2);
	set_x2(1);
	set_y2(height / 2 + 1);
	set_x3(1);
	set_y3(height / 2);
	set_x4(1);
	set_y4(height / 2 - 1);
	set_x5(2);
	set_y5(height / 2);
	set_x6(3);
	set_y6(height / 2);
	std::cout << "Aircraft constructor called" << std::endl;
	return ;
}

AllObjects::AllObjects(AllObjects const &src) {
	*this = src;
	return ;
}

AllObjects::~AllObjects(void) {
	return ;
}

// operators:

AllObjects		&AllObjects::operator=(AllObjects const &rhs)
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

// #####################getters#####################

char			AllObjects::getType(void) const {
	return (this->_type);
}

int				AllObjects::get_x1(void) const {
	return (this->_x1);
}
int				AllObjects::get_x2(void) const {
	return (this->_x2);
}
int				AllObjects::get_x3(void) const {
	return (this->_x3);
}
int				AllObjects::get_x4(void) const {
	return (this->_x4);
}
int				AllObjects::get_x5(void) const {
	return (this->_x5);
}
int				AllObjects::get_x6(void) const {
	return (this->_x6);
}
int				AllObjects::get_y1(void) const {
	return (this->_y1);
}
int				AllObjects::get_y2(void) const {
	return (this->_y2);
}
int				AllObjects::get_y3(void) const {
	return (this->_y3);
}
int				AllObjects::get_y4(void) const {
	return (this->_y4);
}
int				AllObjects::get_y5(void) const {
	return (this->_y5);
}
int				AllObjects::get_y6(void) const {
	return (this->_y6);
}


// ##################setters#######################


void			AllObjects::setType(char c) {
	this->_type = c;
	return ;
}

void			AllObjects::set_x1(int n) {
	this->_x1 = n;
	return ;
}
void			AllObjects::set_x2(int n) {
	this->_x2 = n;
	return ;
}
void			AllObjects::set_x3(int n) {
	this->_x3 = n;
	return ;
}
void			AllObjects::set_x4(int n) {
	this->_x4 = n;
	return ;
}
void			AllObjects::set_x5(int n) {
	this->_x5 = n;
	return ;
}
void			AllObjects::set_x6(int n) {
	this->_x6 = n;
	return ;
}
void			AllObjects::set_y1(int n) {
	this->_y1 = n;
	return ;
}
void			AllObjects::set_y2(int n) {
	this->_y2 = n;
	return ;
}
void			AllObjects::set_y3(int n) {
	this->_y3 = n;
	return ;
}
void			AllObjects::set_y4(int n) {
	this->_y4 = n;
	return ;
}
void			AllObjects::set_y5(int n) {
	this->_y5 = n;
	return ;
}
void			AllObjects::set_y6(int n) {
	this->_y6 = n;
	return ;
}

