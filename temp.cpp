#include <ncurses.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "ft_retro.hpp"

WINDOW*	wnd;
// WINDOW* main_wnd;
void	close();
int 	init()
{
	srand(time(0));
	wnd = initscr();
	cbreak();
	noecho();
	clear();
	refresh();

	keypad(wnd, true);
	nodelay(wnd, true);
	curs_set(0);

	start_color();
	init_pair(1, COLOR_BLACK, COLOR_CYAN);
	wbkgd(wnd, COLOR_PAIR(1));
	wattron(wnd, A_BOLD);
	box(wnd, 0,0);
	wattroff(wnd, A_BOLD);
	
	return (0);
}

void	run()
{
	move(5, 5);
	int tick;
	bool exit_requested = false;
	int in_char;
	int x;
	int y;
	tick = 0;
	getmaxyx(wnd, y, x);
	Aircraft	ai(x, y);
	EnemySmall	es(x, y);
	EnemySmall	e[30];
	Weapon		w[500];
	int sp = 0;
	int i = 0;

	while (i < 30)
	{
		e[i] = EnemySmall(x, y);
		i++;
	}
	i = 1;
	while(1) {
		in_char = wgetch(wnd);
		mvaddch(ai.get_y1(), ai.get_x1(), ' ');
		switch(in_char) {
			case 27:
				exit_requested = true;
				break;
			
			case ' ':
				if (sp < 500)
					w[sp] = Weapon(ai.get_x1() + 1, ai.get_y1());
				if (sp > 500)
					sp = 500;
				else
					sp++;
				break;
			case KEY_UP:
			case 'w':
				ai.set_y1(ai.get_y1() - 1);
				break;
			case KEY_DOWN:
			case 's':
				ai.set_y1(ai.get_y1() + 1);
				break;
			case KEY_LEFT:
			case 'a':
				ai.set_x1(ai.get_x1() - 1);
				break;
			case KEY_RIGHT:
			case 'd':
				ai.set_x1(ai.get_x1() + 1);
				break;
			default:
				break;
		}
		if (tick % 10 == 0)
			i++;
		if (i > 20)
			i = 20;

		for (int k = 0; k < i; k++)
		{
			if (ai.get_lives() == 0)
				close();
			if (ai.get_x1() == e[k].get_x1() && ai.get_y1() == e[k].get_y1())
				ai.set_lives(ai.get_lives() - 1);
			for (int j = 0; j < sp; j++)
			{
				if (e[k].get_x1() == w[j].get_x() && e[k].get_y1() == w[j].get_y() && w[j].get_f() == 1)
				{
					w[j].set_f(0);
					e[k].set_x1(x - 1);
					e[k].set_y1(rand() % y);
				}
			}
		}

		for (int k = 0; k < i; k++)
		{
			mvaddch(e[k].get_y1(), e[k].get_x1(), ' ');
			e[k].set_x1(e[k].get_x1() - 1);
			mvaddch(e[k].get_y1(), e[k].get_x1(), e[k].getType());
			if (e[k].get_x1() == 0)
			{
				e[k].set_x1(x - 1);
				e[k].set_y1(rand() % y);
			}
		}
		for (int k = 0; k < sp && k < 500; k++)
		{
			mvaddch(w[k].get_y(), w[k].get_x(), ' ');
			w[k].set_x(w[k].get_x() + 1);
			if (w[k].get_f() == 1)
				mvaddch(w[k].get_y(), w[k].get_x(), w[k].getType());
		}
		mvaddch(es.get_y1(), es.get_x1(), ' ');
		es.set_x1(es.get_x1() - 1);
		mvaddch(es.get_y1(), es.get_x1(), es.getType());

		mvaddch(ai.get_y1(), ai.get_x1(), ai.getType());
		tick++;
		box(wnd, 0,0);

		refresh();
		if (exit_requested) break;
		usleep(40000);

	}
}

void	close()
{
	endwin();
	exit (1);
}

int 	main(int argc, char **argv)
{
	int		init_status = init();

	if (init_status == 0)
		run();
	close();
	return (0);
}
