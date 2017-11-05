CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror
FILES		= main.cpp Aircraft.class.cpp AllObjects.class.cpp EnemyBig.class.cpp EnemySmall.class.cpp Weapon.class.cpp
NAME		= ft_retro
OFILES		= main.o Aircraft.class.o AllObjects.class.o EnemyBig.class.o EnemySmall.class.o Weapon.class.o

all: $(NAME)

$(NAME): $(OFILES)
	clang++ $(CXXFLAGS) -o $@ $^ -lncurses

%.o: %.c
	clang++ -o $@ -c $< 

clean:
	rm -f $(OFILES)

fclean:
	rm -f $(OFILES)
	rm -f $(NAME)

re: fclean all