SRCS =	Zombie.cpp\
		ZombieHorde.cpp\
		main.cpp

CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = zombie

all: $(NAME)

$(NAME): $(SRCS)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)
