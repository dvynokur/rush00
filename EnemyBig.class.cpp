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
	int		array[] = {1, -1};

	r = rand () % height;
	if (r == 0)
		r += 3;
	else if (r == height)
		r -= 3;
	setType('*');
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
	set_x7(width + 2);
	set_y7(r);
	set_x8(width + 2);
	set_y8(r - 1);
	set_x9(width + 3);
	set_y9(r - 1);
	set_x10(width + 2);
	set_y10(r - 2);
	set_x11(width + 1);
	set_y11(r - 2);
	set_x12(width + 1);
	set_y12(r - 3);
	set_x13(width);
	set_y13(r - 2);
	set_flag(0);
	set_lives(5);
	set_direction(array[rand() % 2]);
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
		set_x7(rhs.get_x7());
		set_x8(rhs.get_x8());
		set_x9(rhs.get_x9());
		set_x10(rhs.get_x10());
		set_x11(rhs.get_x11());
		set_x12(rhs.get_x12());
		set_x13(rhs.get_x13());
		set_y7(rhs.get_y7());
		set_y8(rhs.get_y8());
		set_y9(rhs.get_y9());
		set_y10(rhs.get_y10());
		set_y11(rhs.get_y11());
		set_y12(rhs.get_y12());
		set_y13(rhs.get_y13());
		set_flag(rhs.get_flag());
		set_lives(5);
		set_direction(get_direction());
	}
	return (*this);
}



bool		EnemyBig::operator==(AllObjects &rhs)
{
	if (this->check_coords(this->_x1, this->_y1, rhs) || this->check_coords(this->_x2, this->_y2, rhs) ||
		this->check_coords(this->_x3, this->_y3, rhs) || this->check_coords(this->_x4, this->_y4, rhs) || 
		this->check_coords(this->_x5, this->_y5, rhs) || this->check_coords(this->_x6, this->_y6, rhs) ||
		this->check_coords(this->_x7, this->_y7, rhs) || this->check_coords(this->_x8, this->_y8, rhs) ||
		this->check_coords(this->_x9, this->_y9, rhs) || this->check_coords(this->_x10, this->_y10, rhs) ||
		this->check_coords(this->_x11, this->_y11, rhs) || this->check_coords(this->_x12, this->_y12, rhs) ||
		this->check_coords(this->_x13, this->_y13, rhs))
		return (1);
	else
		return (0);
}


void			EnemyBig::rewriting_xy(int x, int y)
{
	int array[] = {1, -1};

	this->set_x1(x - 1);
	this->set_y1(y - 1);
	this->set_x2(x);
	this->set_y2(y);
	this->set_x3(x);
	this->set_y3(y - 1);
	this->set_x4(x + 1);
	this->set_y4(y + 1);
	this->set_x5(x + 1);
	this->set_y5(y);
	this->set_x6(x + 1);
	this->set_y6(y - 1);
	this->set_x7(x + 2);
	this->set_y7(y);
	this->set_x8(x + 2);
	this->set_y8(y - 1);
	this->set_x9(x + 3);
	this->set_y9(y - 1);
	this->set_x10(x + 2);
	this->set_y10(y - 2);
	this->set_x11(x + 1);
	this->set_y11(y - 2);
	this->set_x12(x + 1);
	this->set_y12(y - 3);
	this->set_x13(x);
	this->set_y13(y - 2);
	this->set_flag(0);
	this->set_lives(5);
	this->_direction = array[rand() % 2];
}

void			EnemyBig::set_direction(int n)
{
	this->_direction = n;
	return ;
}
int				EnemyBig::get_direction(void) const
{
	return (this->_direction);
}



void			EnemyBig::set_flag(int n) {
	this->_flag = n;
	return ;
}
void			EnemyBig::set_lives(int n) {
	this->_lives = n;
	return ;
}
int				EnemyBig::get_flag(void) const {
	return (this->_flag);
}
int				EnemyBig::get_lives(void) const {
	return (this->_lives);
}


int				EnemyBig::get_x7(void) const {
	return (this->_x7);
}
int				EnemyBig::get_x8(void) const {
	return (this->_x8);
}
int				EnemyBig::get_x9(void) const {
	return (this->_x9);
}
int				EnemyBig::get_x10(void) const {
	return (this->_x10);
}
int				EnemyBig::get_x11(void) const {
	return (this->_x11);
}
int				EnemyBig::get_x12(void) const {
	return (this->_x12);
}
int				EnemyBig::get_x13(void) const {
	return (this->_x13);
}
int				EnemyBig::get_y7(void) const {
	return (this->_y7);
}
int				EnemyBig::get_y8(void) const {
	return (this->_y8);
}
int				EnemyBig::get_y9(void) const {
	return (this->_y9);
}
int				EnemyBig::get_y10(void) const {
	return (this->_y10);
}
int				EnemyBig::get_y11(void) const {
	return (this->_y11);
}
int				EnemyBig::get_y12(void) const {
	return (this->_y12);
}
int				EnemyBig::get_y13(void) const {
	return (this->_y13);
}



void			EnemyBig::set_x7(int n) {
	this->_x7 = n;
	return ;
}
void			EnemyBig::set_x8(int n) {
	this->_x8 = n;
	return ;
}
void			EnemyBig::set_x9(int n) {
	this->_x9 = n;
	return ;
}
void			EnemyBig::set_x10(int n) {
	this->_x10 = n;
	return ;
}
void			EnemyBig::set_x11(int n) {
	this->_x11 = n;
	return ;
}
void			EnemyBig::set_x12(int n) {
	this->_x12 = n;
	return ;
}
void			EnemyBig::set_x13(int n) {
	this->_x13 = n;
	return ;
}
void			EnemyBig::set_y7(int n) {
	this->_y7 = n;
	return ;
}
void			EnemyBig::set_y8(int n) {
	this->_y8 = n;
	return ;
}
void			EnemyBig::set_y9(int n) {
	this->_y9 = n;
	return ;
}
void			EnemyBig::set_y10(int n) {
	this->_y10 = n;
	return ;
}
void			EnemyBig::set_y11(int n) {
	this->_y11 = n;
	return ;
}
void			EnemyBig::set_y12(int n) {
	this->_y12 = n;
	return ;
}
void			EnemyBig::set_y13(int n) {
	this->_y13 = n;
	return ;
}







// ################### functions #####################


void			EnemyBig::moving(void)
{
	// start_color();
	// init_pair(2, COLOR_BLACK, COLOR_GREEN);
	// wattron(wnd, A_BOLD);
	mvaddch(this->get_y1(), this->get_x1(), this->getType());
	mvaddch(this->get_y2(), this->get_x2(), this->getType());
	mvaddch(this->get_y3(), this->get_x3(), this->getType());
	mvaddch(this->get_y4(), this->get_x4(), this->getType());
	mvaddch(this->get_y5(), this->get_x5(), this->getType());
	mvaddch(this->get_y6(), this->get_x6(), this->getType());
	mvaddch(this->get_y7(), this->get_x7(), this->getType());
	mvaddch(this->get_y8(), this->get_x8(), this->getType());
	mvaddch(this->get_y9(), this->get_x9(), this->getType());
	mvaddch(this->get_y10(), this->get_x10(), this->getType());
	mvaddch(this->get_y11(), this->get_x11(), this->getType());
	mvaddch(this->get_y12(), this->get_x12(), this->getType());
	mvaddch(this->get_y13(), this->get_x13(), this->getType());
	// wattroff(wnd, A_BOLD);
	return ;
}



void			EnemyBig::removing(void)
{
	mvaddch(this->get_y1(), this->get_x1(), ' ');
	mvaddch(this->get_y2(), this->get_x2(), ' ');
	mvaddch(this->get_y3(), this->get_x3(), ' ');
	mvaddch(this->get_y4(), this->get_x4(), ' ');
	mvaddch(this->get_y5(), this->get_x5(), ' ');
	mvaddch(this->get_y6(), this->get_x6(), ' ');
	mvaddch(this->get_y7(), this->get_x7(), ' ');
	mvaddch(this->get_y8(), this->get_x8(), ' ');
	mvaddch(this->get_y9(), this->get_x9(), ' ');
	mvaddch(this->get_y10(), this->get_x10(), ' ');
	mvaddch(this->get_y11(), this->get_x11(), ' ');
	mvaddch(this->get_y12(), this->get_x12(), ' ');
	mvaddch(this->get_y13(), this->get_x13(), ' ');
	return ;
}

void			EnemyBig::changing_xy(int x, int y)
{
	this->set_x1(this->get_x1() + x);
	this->set_x2(this->get_x2() + x);
	this->set_x3(this->get_x3() + x);
	this->set_x4(this->get_x4() + x);
	this->set_x5(this->get_x5() + x);
	this->set_x6(this->get_x6() + x);
	this->set_x7(this->get_x7() + x);
	this->set_x8(this->get_x8() + x);
	this->set_x9(this->get_x9() + x);
	this->set_x10(this->get_x10() + x);
	this->set_x11(this->get_x11() + x);
	this->set_x12(this->get_x12() + x);
	this->set_x13(this->get_x13() + x);

	this->set_y1(this->get_y1() + y);
	this->set_y2(this->get_y2() + y);
	this->set_y3(this->get_y3() + y);
	this->set_y4(this->get_y4() + y);
	this->set_y5(this->get_y5() + y);
	this->set_y6(this->get_y6() + y);
	this->set_y7(this->get_y7() + y);
	this->set_y8(this->get_y8() + y);
	this->set_y9(this->get_y9() + y);
	this->set_y10(this->get_y10() + y);
	this->set_y11(this->get_y11() + y);
	this->set_y12(this->get_y12() + y);
	this->set_y13(this->get_y13() + y);
	return ;
}

void			EnemyBig::setAllX(int n) {
	this->_x1 = n;
	this->_x2 = n;
	this->_x3 = n;
	this->_x4 = n;
	this->_x5 = n;
	this->_x6 = n;
	this->_x7 = n;
	this->_x8 = n;
	this->_x9 = n;
	this->_x10 = n;
	this->_x11 = n;
	this->_x12 = n;
	this->_x13 = n;

	return ;
}

void			EnemyBig::setAllY(int n) {
	this->_y1 = n;
	this->_y2 = n;
	this->_y3 = n;
	this->_y4 = n;
	this->_y5 = n;
	this->_y6 = n;
	this->_y7 = n;
	this->_y8 = n;
	this->_y9 = n;
	this->_y10 = n;
	this->_y11 = n;
	this->_y12 = n;
	this->_y13 = n;
	return ;
}







