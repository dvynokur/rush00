//		Created by Ivan Tsuman and Denys Vynokurov
//					Rush00, Piscine CPP

#include "ft_retro.hpp"
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
	width = 0;
	return ;
}

AllObjects::AllObjects(AllObjects const &src) {
	*this = src;
	return ;
}

AllObjects::~AllObjects(void) {
	return ;
}

// #################### operators ###########################

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

bool		AllObjects::operator==(AllObjects &rhs)
{
	if (this->check_coords(this->_x1, this->_y1, rhs) || this->check_coords(this->_x2, this->_y2, rhs) ||
		this->check_coords(this->_x3, this->_y3, rhs) || this->check_coords(this->_x4, this->_y4, rhs) || 
		this->check_coords(this->_x5, this->_y5, rhs) || this->check_coords(this->_x6, this->_y6, rhs))
		return (1);
	else
		return (0);
}


// ################### functions #####################

bool			AllObjects::check_coords(int x, int y, AllObjects &src)
{
	if ((x == src.get_x1() && y == src.get_y1()) || (x == src.get_x2() && y == src.get_y2()) ||
		(x == src.get_x3() && y == src.get_y3()) || (x == src.get_x4() && y == src.get_y4()) || 
		(x == src.get_x5() && y == src.get_y5()) || (x == src.get_x6() && y == src.get_y6()))
		return (1);
	else
		return (0);
}

void			AllObjects::moving(void)
{
	mvaddch(this->get_y1(), this->get_x1(), this->getType());
	mvaddch(this->get_y2(), this->get_x2(), this->getType());
	mvaddch(this->get_y3(), this->get_x3(), this->getType());
	mvaddch(this->get_y4(), this->get_x4(), this->getType());
	mvaddch(this->get_y5(), this->get_x5(), this->getType());
	mvaddch(this->get_y6(), this->get_x6(), this->getType());
	return ;
}



void			AllObjects::removing(void)
{
	mvaddch(this->get_y1(), this->get_x1(), ' ');
	mvaddch(this->get_y2(), this->get_x2(), ' ');
	mvaddch(this->get_y3(), this->get_x3(), ' ');
	mvaddch(this->get_y4(), this->get_x4(), ' ');
	mvaddch(this->get_y5(), this->get_x5(), ' ');
	mvaddch(this->get_y6(), this->get_x6(), ' ');
	return ;
}

void			AllObjects::changing_xy(int x, int y)
{
	this->set_x1(this->get_x1() + x);
	this->set_x2(this->get_x2() + x);
	this->set_x3(this->get_x3() + x);
	this->set_x4(this->get_x4() + x);
	this->set_x5(this->get_x5() + x);
	this->set_x6(this->get_x6() + x);

	this->set_y1(this->get_y1() + y);
	this->set_y2(this->get_y2() + y);
	this->set_y3(this->get_y3() + y);
	this->set_y4(this->get_y4() + y);
	this->set_y5(this->get_y5() + y);
	this->set_y6(this->get_y6() + y);
	return ;
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

void			AllObjects::setAllX(int n) {
	this->_x1 = n;
	this->_x2 = n;
	this->_x3 = n;
	this->_x4 = n;
	this->_x5 = n;
	this->_x6 = n;
	return ;
}

void			AllObjects::setAllY(int n) {
	this->_y1 = n;
	this->_y2 = n;
	this->_y3 = n;
	this->_y4 = n;
	this->_y5 = n;
	this->_y6 = n;
	return ;
}

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

