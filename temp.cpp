#include <ncurses.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "ft_retro.hpp"

WINDOW*	wnd;
int score;
// WINDOW* main_wnd;
void	close();
int 	init()
{
	score = 0;
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
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	wbkgd(wnd, COLOR_PAIR(1));
	wattron(wnd, A_BOLD);
	box(wnd, 0,0);
	wattroff(wnd, A_BOLD);
	
	return (0);
}

void	run()
{
	int tick;
	bool exit_requested = false;
	int in_char;
	int x;
	int y;
	tick = 0;
	getmaxyx(wnd, y, x);
	Aircraft	ai(x, y);
	EnemySmall	e[30];
	Weapon		w[500];
	int sp = 0;
	for (int i = 0; i < 30; i++)
		e[i] = EnemySmall(x, y);
	int i = 0;
	clear();
	while(1) {
		mvwprintw(wnd, 2, x/2, "Score = %d   Lives = %d", score, ai.get_lives());
		in_char = wgetch(wnd);
		ai.removing();
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
				ai.changing_xy(0, -1);
				break;
			case KEY_DOWN:
			case 's':
				ai.changing_xy(0, 1);
				break;
			case KEY_LEFT:
			case 'a':
				ai.changing_xy(-1, 0);
				break;
			case KEY_RIGHT:
			case 'd':
				ai.changing_xy(1, 0);
				break;
			default:
				break;
		}


		for (int k = 0; k < i; k++)
		{
			if (ai.get_lives() == 0)
				close();
			if (ai == e[k] && e[k].get_flag() == 0)
			{
				e[k].set_flag(1);
				ai.set_lives(ai.get_lives() - 1);
			}
			
			for (int j = 0; j < sp; j++)
			{
				// if (w[j] == e[k])
				// 	printf("!!!\n");
				if (w[j] == e[k] && w[j].get_f() == 1)
				{
					score++;
					w[j].set_f(0);
					e[k].removing();
					e[k].rewriting_xy(x, rand() % y);
				}
			}
		}


		for (int k = 0; k < i; k++)
		{
			e[k].removing();
			e[k].changing_xy(-1, 0);
			e[k].moving();
			if (e[k].get_x6() == 0)
				e[k].rewriting_xy(x, (rand() % y) - 3);
		}




		for (int k = 0; k < sp && k < 500; k++)
		{
			// w[k].removing();
			mvaddch(w[k].get_y(), w[k].get_x(), ' ');
			// w[k].changing_xy(1, 0);
			w[k].set_x(w[k].get_x() + 1);
			if (w[k].get_f() == 1)
				// w[k].moving();
				mvaddch(w[k].get_y(), w[k].get_x(), w[k].getType());
		}



		ai.moving();

		tick++;
		if (tick % 10 == 0)
			i++;
		if (i > 20)
			i = 20;

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
