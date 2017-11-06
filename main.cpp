#include <ncurses.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "ft_retro.hpp"

WINDOW*	wnd;
int score;
// WINDOW* main_wnd;
void	close();
int 	main(void);
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
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	wbkgd(wnd, COLOR_PAIR(1));
	wattron(wnd, A_BOLD);
	box(wnd, 0,0);
	wattroff(wnd, A_BOLD);
	
	return (0);
}

void    setup(){
    int x;
    int y;
    getmaxyx(wnd, y, x);
    mvwprintw(wnd, y/2, x/2 - 25, "Use keys: \"UP\", \"DOWN\", \"RIGHT\", \"LEFT\" to control.");
    mvwprintw(wnd, y/2 + 2, x/2 - 25, "Use keys \"P\" for pause and \"ESC\" for finish game.");
    mvwprintw(wnd, y/2 + 10, x/2 - 18, "Press \"ENTER\" to start the game.");
    int n_char = wgetch(wnd);
    while(n_char != '\n'){
        n_char = wgetch(wnd);
        if (n_char == 27)
            close();
    }
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
	y -= 5;
	Aircraft	ai(x, y);
	EnemySmall	e[30];
	EnemyBig	eb[10];
	Weapon		w[500];
	int sp = 0;
	for (int i = 0; i < 30; i++)
		e[i] = EnemySmall(x, y);
	for (int i = 0; i < 10; i++)
		eb[i] = EnemyBig(x, y);
	int i = 0;
	int l = 0;
	clear();
	while(1) {
		mvwprintw(wnd, y + 3, x/2 - 18, "Score = %d   Lives = %d   Bullets = %d", score, ai.get_lives(), 500 - sp);
		in_char = wgetch(wnd);
		ai.removing();
		switch(in_char) {
			case 27:
				exit_requested = true;
				break;
			case 'p':
				mvprintw( 2, 10,"[ PAUSED ]");
				// refresh();p
				while (1)
				{
					in_char = getch();
					if (in_char == 27)
					{
						exit_requested = true;
						break ;
					}
					if (in_char == 'p')
						break;
				}
				break;
			case ' ':
				if (sp < 500)
					w[sp] = Weapon(ai.get_x1() + 1, ai.get_y1());
				if (sp > 500)
				{
					close();
					sp = 500;
				}
				else
					sp++;
				break;
			case KEY_UP:
			case 'w':
				if (ai.get_y1() < 3)
					ai.changing_xy(0, 0);
				else
					ai.changing_xy(0, -1);
				break;
			case KEY_DOWN:
			case 's':
				if (ai.get_y4() > y - 5)
					ai.changing_xy(0, 0);
				else
					ai.changing_xy(0, 1);
				break;
			case KEY_LEFT:
			case 'a':
				if (ai.get_x1() < 3)
					ai.changing_xy(0, 0);
				else
					ai.changing_xy(-1, 0);
				break;
			case KEY_RIGHT:
			case 'd':
				if (ai.get_x6() > x - 3)
					ai.changing_xy(0, 0);
				else
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
				if (w[j] == e[k] && w[j].get_f() == 1)
				{
					score++;
					w[j].set_f(0);
					e[k].removing();
					e[k].rewriting_xy(x, rand() % y);
				}
			}
		}


		for (int k = 0; k < l; k++)
		{
			if (ai.get_lives() == 0)
				close();
			if (eb[k] == ai && eb[k].get_flag() == 0)
			{
				eb[k].set_flag(1);
				ai.set_lives(ai.get_lives() - 1);
			}
			
			for (int j = 0; j < sp; j++)
			{
				if (w[j] == eb[k] && w[j].get_f() == 1)
				{
					score++;
					w[j].set_f(0);
					eb[k].set_lives(eb[k].get_lives() - 1);
					if (eb[k].get_lives() <= 0)
					{
						eb[k].removing();
						eb[k].rewriting_xy(x, rand() % y);
					}
				}
			}
		}



		for (int k = 0; k < l; k++)
		{
			// start_color();
			// init_pair(2, COLOR_BLACK, COLOR_GREEN);
			wattron(wnd, A_BOLD);
			eb[k].removing();
			if (eb[k].get_y13() == 5)
				eb[k].set_direction(1);
			else if (eb[k].get_y13() == y - 5)
				eb[k].set_direction(-1);
			eb[k].changing_xy(-1, eb[k].get_direction());
			eb[k].moving();
			if (eb[k].get_x9() == 0)
				eb[k].rewriting_xy(x, (rand() % y) - 3);
			wattroff(wnd, A_BOLD);
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
			mvaddch(w[k].get_y(), w[k].get_x(), ' ');
			w[k].set_x(w[k].get_x() + 1);
			if (w[k].get_f() == 1)
			{
				attron(COLOR_PAIR(2));
				mvaddch(w[k].get_y(), w[k].get_x(), w[k].getType());
				attrset(A_NORMAL);
			}
		}
		ai.moving();
		tick++;
		if (tick % 10 == 0)
			i++;
		if (tick % 50 == 0)
			l++;
		if (l > 7)
			l = 7;
		if (i > 15)
			i = 15;
		box(wnd, 0,0);
		refresh();
		if (exit_requested) break;
		usleep(40000);

	}
}

void    close()
{
    clear();
    int x, y;
    getmaxyx(wnd, y, x);
    refresh();

    mvwprintw(wnd, y/2, x/2 - 5, "Game over.");
    mvwprintw(wnd, y/2 + 2, x/2 - 12, "Yore score is %d points.", score);
    mvwprintw(wnd, y/2 + 10, x/2 - 25, "Press \"ENTER\" to start new game or \"ESC\" for finish game.");
    int n_char = wgetch(wnd);
    while(1){
        if (n_char == '\n')
            main();
        else if (n_char == 27){
            endwin();
            exit (1);
        }
        n_char = wgetch(wnd);
    }
}

int 	main()
{
	int		init_status = init();

	setup();
	if (init_status == 0)
		run();
	close();
	return (0);
}
